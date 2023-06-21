#pragma once
#include "Command.h"
#include "MyString.h"

class MoveCommand : public Command
{
	SharedPtr<Object> mainObj;
	MyString from;
	MyString to;
public:
	MoveCommand(SharedPtr<Object> mainObj, MyString&& from, MyString&& to);
	void execute() override;
};