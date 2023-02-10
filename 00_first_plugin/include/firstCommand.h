#ifndef FIRSTCOMMAND_H
#define FIRSTCOMMAND_H

#include <maya/MPxCommand.h>
#include <maya/MGlobal.h>

class firstCommand : public MPxCommand
{
public:
    firstCommand();
    virtual MStatus doIt(const MArgList& arglist);
    static void* creator();
};

#endif // FIRSTCOMMAND_H