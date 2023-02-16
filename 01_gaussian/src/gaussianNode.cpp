#include "gaussianNode.hpp"

// Declare static variables
MObject GaussianNode::aOutValue;
MObject GaussianNode::aInValue;
MObject GaussianNode::aMagnitude;
MObject GaussianNode::aMean;
MObject GaussianNode::aVariance;
MTypeId GaussianNode::id( 0x000000134 );

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

MStatus GaussianNode::compute( const MPlug& plug, MDataBlock& data)
{
    /**
     * MPlug is specific instance of attribute.  Attribute defines interface of node.
     * 
     * MDataBlock chunk of memory that holds data.  Use the values in the datablock.
     */
    MStatus status;

    if (plug != aOutValue)
    {
        return MS::kUnknownParameter;
    }

    // Access input values from data block
    float inputValue = data.inputValue( aInValue, &status).asFloat();
    float magnitude  = data.inputValue( aMagnitude, &status).asFloat();
    float mean       = data.inputValue( aMean, &status).asFloat();
    float variance   = data.inputValue( aVariance, &status).asFloat();
    
    // Calculate gaussian value
    if (variance <= 0.0f ) {
        variance = 0.001f;
    }

    float numerator = inputValue - mean;
    float output = magnitude * exp(-(numerator * numerator)/(2.0f * variance));
    
    // Store output back into datablock
    MDataHandle hOutput = data.outputValue( aOutValue, &status );
    CHECK_MSTATUS_AND_RETURN_IT( status );
    hOutput.setFloat( output );
    hOutput.setClean();
    data.setClean( plug );

    return MS::kSuccess;
}