#include "gaussianNode.hpp"

// Declare static variables
MObject GaussianNode::aOutValue;
MObject GaussianNode::aInValue;
MObject GaussianNode::aMagnitude;
MObject GaussianNode::aMean;
MObject GaussianNode::aVariance;

GaussianNode::GaussianNode()
{
}

GaussianNode::~GaussianNode()
{
}

void *GaussianNode::creator()
{
    return new GaussianNode;
}

MStatus GaussianNode::initialize()
{
    MStatus status;
    MFnNumericAttribute fnAtter;

    aOutValue = fnAtter.create( "outValue", "outValue", MFnNumericData::kFloat );
    fnAtter.setWritable( false );   // setting output attribute
    fnAtter.setStorable( false );
    addAttribute( aOutValue );

    // Function set is working on new MObject
    aInValue = fnAtter.create( "inValue", "inValue", MFnNumericData::kFloat );
    fnAtter.setKeyable( true );
    addAttribute( aInValue );
    attributeAffects( aInValue, aOutValue );    // Allowing dirty flag to recompute.
    // Some attributes can be set by the user, but others can be a function of another.

    aMagnitude = fnAtter.create( "magnitude", "magnitude", MFnNumericData::kFloat );
    fnAtter.setKeyable( true );
    addAttribute( aMagnitude );
    attributeAffects( aMagnitude, aOutValue );

    aMean = fnAtter.create( "mean", "mean", MFnNumericData::kFloat );
    fnAtter.setKeyable( true );
    addAttribute( aMean );
    attributeAffects( aMean, aOutValue );

    aVariance = fnAtter.create( "variance", "variance", MFnNumericData::kFloat );
    fnAtter.setKeyable( true );
    addAttribute( aVariance );
    attributeAffects( aVariance, aOutValue );

    return status;
}