#ifndef BLENDMESHDEFORMER_HPP
#define BLENDMESHDEFORMER_HPP

#include <maya/MPxDeformerNode.h>
#include <maya/MFnNumericAttribute.h>
#include <maya/MFnTypedAttribute.h>
#include <maya/MFnMesh.h>
#include <maya/MPointArray.h>
#include <maya/MItGeometry.h>
#include <maya/MGlobal.h>

class BlendMesh : public MPxDeformerNode
{
public:
						BlendMesh();
	virtual				~BlendMesh(); 
	static  void*		creator();

    virtual MStatus     deform( MDataBlock& data,
                                MItGeometry& itGeo,
                                const MMatrix& localToWorldMatrix,
                                unsigned int geomIndex );

    static MStatus initialize();    // setup node attributes
    
    static MTypeId id;  // Unique Node Id

    static MObject aBlendMesh;
    static MObject aBlendWeight;
};

#endif // BLENDMESHDEFORMER_HPP