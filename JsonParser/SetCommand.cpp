#include "SetCommand.h"
#include "StrFunctions.h"

SetCommand::SetCommand(SharedPtr<Object> mainObj, MyString&& path, MyString&& value) : mainObj(mainObj), path(std::move(path)), value(std::move(value))
{
}

void SetCommand::execute()
{
	MyString* pathArr;
	size_t pathSize = 0;

	buildPath(path, pathArr, pathSize);

	mainObj->setValue(pathArr, pathSize, std::move(value));
}
