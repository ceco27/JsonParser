#pragma once
#include "Command.h"
#include "MyString.h"

class SaveAsCommand : public Command
{
	SharedPtr<Object> mainObj;
	MyString fileName;
	MyString path;
public:
	SaveAsCommand(SharedPtr<Object> mainObj, MyString&& file);
	SaveAsCommand(SharedPtr<Object> mainObj, MyString&& file, MyString&& path);
	void execute() override;
};