#include "gaussianNode.hpp"

#include <maya/MFnPlugin.h>

MStatus initializePlugin( MObject obj )
{
    MStatus status;
    MFnPlugin fnPlugin(obj, "Joonho", "1.0", "Any");

    return status;
}


MStatus uninitializePlugin( MObject obj )
{
    Mstatus status;

    MFnPlugin fnPlugin( obj );


    return status;
}