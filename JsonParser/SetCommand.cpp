#include "SetCommand.h"

SetCommand::SetCommand(SharedPtr<Object> mainObj, MyString&& path, MyString&& value) : mainObj(mainObj), path(path), value(value)
{
}

void SetCommand::execute()
{
}
