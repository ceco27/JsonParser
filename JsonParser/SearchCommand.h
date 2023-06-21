#pragma once
#include "Command.h"
#include "MyString.h"

class SearchCommand : public Command
{
	SharedPtr<Object> mainObj;
	MyString key;
public:
	SearchCommand(SharedPtr<Object> mainObj, MyString&& key);
	void execute() override;
};