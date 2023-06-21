#include "CreateCommand.h"

CreateCommand::CreateCommand(SharedPtr<Object> mainObj, MyString&& path, MyString&& value) : mainObj(mainObj), path(std::move(path)), value(std::move(value))
{

}

void CreateCommand::execute()
{
}
