#include "blendMeshDeformer.hpp"

#include <maya/MFnPlugin.h>

MStatus initializePlugin( MObject obj )
{
    MStatus status;
    MFnPlugin fnPlugin(obj, "Joonho", "1.0", "Any");

    status = fnPlugin.registerNode( "blendMesh",
            BlendMesh::id,
            BlendMesh::creator,
            BlendMesh::initialize,
            MPxNode::kDeformerNode);
    CHECK_MSTATUS_AND_RETURN_IT( status );

    return status;
}


MStatus uninitializePlugin( MObject obj )
{
    MStatus status;

    MFnPlugin fnPlugin( obj );
    status = fnPlugin.deregisterNode( BlendMesh::id );
    CHECK_MSTATUS_AND_RETURN_IT( status );

    return status;
}