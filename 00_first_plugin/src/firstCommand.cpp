#include "firstCommand.h"

firstCommand::firstCommand()
{
}

void* firstCommand::creator()
{
    /**
     * Required for Maya for Plugins
     * 
     */
    return new firstCommand;
}

MStatus firstCommand::doIt(const MArgList& arglist)
{
    MGlobal::displayInfo("This is it");
    return MS::kSuccess;
}