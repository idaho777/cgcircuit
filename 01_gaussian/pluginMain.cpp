#include "gaussianNode.hpp"

#include <maya/MFnPlugin.h>

MStatus initializePlugin( MObject obj )
{
    MStatus status;
    MFnPlugin fnPlugin(obj, "Joonho", "1.0", "Any");

    status = fnPlugin.registerNode( "gauss",
            GaussianNode::id,
            GaussianNode::creator,
            GaussianNode::initialize );
    CHECK_MSTATUS_AND_RETURN_IT( status );

    return status;
}


MStatus uninitializePlugin( MObject obj )
{
    MStatus status;

    MFnPlugin fnPlugin( obj );
    status = fnPlugin.deregisterNode( GaussianNode::id );
    CHECK_MSTATUS_AND_RETURN_IT( status );

    return status;
}