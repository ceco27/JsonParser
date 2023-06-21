#pragma once
#include "Command.h"
#include "MyString.h"

class CreateCommand : public Command
{
	SharedPtr<Object> mainObj;
	MyString path;
	MyString value;
public:
	CreateCommand(SharedPtr<Object> mainObj, MyString&& path, MyString&& value);
	void execute() override;
};