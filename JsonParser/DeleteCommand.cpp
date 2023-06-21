#include "DeleteCommand.h"
#include "StrFunctions.h"

DeleteCommand::DeleteCommand(SharedPtr<Object> mainObj, MyString&& path) : mainObj(mainObj), path(std::move(path))
{
}

void DeleteCommand::execute()
{
	
	MyString* pathArr;
	size_t pathSize = 0;

	buildPath(path, pathArr, pathSize);

	mainObj->deleteAt(pathArr, pathSize);
	
}
