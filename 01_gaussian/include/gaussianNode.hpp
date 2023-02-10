#ifndef GAUSSIANNODE_HPP
#define GAUSSIANNODE_HPP

#include <maya/MPxNode.h>
#include <maya/MFnNumericAttribute.h>

class GaussianNode : publid MPxNode
{
public:
    GaussianNode();
    virtual ~GaussianNode();
    static void* creator();

    virtual MStatus compute( const MPlug& plug, MDataBlock& data ); // Required for all Nodes

    static MStatus initialize();    // setup node attributes
    
    // Every GaussianNode will have these attributes.
    static MObject aOutValue;
    static MObject aInValue;
    static MObject aMagnitude;
    static MObject aMean;
    static MObject aVariance;

}

#endif // GAUSSIANNODE_HPP