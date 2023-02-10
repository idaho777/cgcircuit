#include "firstCommand.h"

#include <maya/MFnPlugin.h>

MStatus initializePlugin( MObject obj )
{
    MStatus status;

    MFnPlugin fnPlugin( obj, "Joonho", "1.0", "Any");

    status = fnPlugin.registerCommand( "myCommand", firstCommand::creator );
    CHECK_MSTATUS_AND_RETURN_IT(status);

    return status;
}

MStatus uninitializePlugin( MObject obj )
{
    MStatus status;

    MFnPlugin fnPlugin(obj);

    status = fnPlugin.deregisterCommand( "myCommand" );
    CHECK_MSTATUS_AND_RETURN_IT(status);

    return status;
}