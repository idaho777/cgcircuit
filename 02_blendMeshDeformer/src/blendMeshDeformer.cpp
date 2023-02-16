#include "blendMeshDeformer.hpp"

// Declare static variables
MTypeId BlendMesh::id( 0x000000134 );
MObject BlendMesh::aBlendMesh;
MObject BlendMesh::aBlendWeight;

BlendMesh::BlendMesh()
{
}

BlendMesh::~BlendMesh()
{
}

void *BlendMesh::creator()
{
    return new BlendMesh();
}

MStatus BlendMesh::deform( MDataBlock& data, MItGeometry& itGeo, 
        const MMatrix& localToWorldMatrix, unsigned int geomIndex )
{
    MStatus status;
    // Access mesh with data handler
    MDataHandle hBlendMesh = data.inputValue( aBlendMesh, &status );
    CHECK_MSTATUS_AND_RETURN_IT(status);
    MObject oBlendMesh = hBlendMesh.asMesh();
    if ( oBlendMesh.isNull() )  // Check if mesh exists.
    {
        return MS::kSuccess;
    }

    // Get points from blendshape mesh.
    MFnMesh fnMesh( oBlendMesh, &status );
    CHECK_MSTATUS_AND_RETURN_IT(status);
    MPointArray blendPoints;
    fnMesh.getPoints(blendPoints);
    
    // get blendweight and env using data handler.
    MDataHandle hBlendWeight = data.inputValue( aBlendWeight, &status );
    float blendWeight = hBlendWeight.asFloat();
    float env = data.inputValue( envelope ).asFloat();  // 0-1 weight Value to turn on/off deformer.

    // Deformation Algo
    // Iterate over each point and coresponding blendshape point,
    // calculate weighted difference
    // set point.
    // This assumes points between current geometry and blendshape mesh 
    // maintain index correspondence.
    MPoint point;
    for ( ; !itGeo.isDone(); itGeo.next() ) {
        point = itGeo.position();
        point += (blendPoints[itGeo.index()] - point) * blendWeight * env;
        itGeo.setPosition( point ); // iterator handles clean
    }

    return status;
}

MStatus BlendMesh::initialize()
{
    MStatus status;

    MFnNumericAttribute nAttr;
    MFnTypedAttribute tAttr;

    aBlendMesh = tAttr.create( "blendMesh", "blendMesh", MFnData::kMesh );
    addAttribute( aBlendMesh );
    attributeAffects( aBlendMesh, outputGeom );

    aBlendWeight = nAttr.create( "blendValue", "blendValue", MFnNumericData::kFloat );
    nAttr.setKeyable( true );
    nAttr.setMin( 0.0 );
    nAttr.setMax( 1.0 );
    addAttribute( aBlendWeight );
    attributeAffects( aBlendWeight, outputGeom );

    MGlobal::executeCommand( "makePaintable -attrType multiFloat -sm deformer blendNode weights;" );

    return MS::kSuccess;
}

