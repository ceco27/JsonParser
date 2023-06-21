#include "MoveCommand.h"

MoveCommand::MoveCommand(SharedPtr<Object> mainObj, MyString&& from, MyString&& to) : mainObj(mainObj), from(std::move(from)), to(std::move(to))
{
}

void MoveCommand::execute()
{
}
