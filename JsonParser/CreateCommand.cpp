#include "CreateCommand.h"
#include "StrFunctions.h"

CreateCommand::CreateCommand(SharedPtr<Object> mainObj, MyString&& path, MyString&& value) : mainObj(mainObj), path(std::move(path)), value(std::move(value))
{

}

void CreateCommand::execute()
{
	MyString* pathArr;
	size_t pathSize = 0;

	buildPath(path, pathArr, pathSize);

	mainObj->create(pathArr, pathSize, std::move(value));
}
