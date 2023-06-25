#pragma once
#include "Command.h"
#include "Array.h"
#include "Primitive.h"

class OpenCommand : public Command
{
	SharedPtr<Object> mainObj;
	MyString fileName;
public:
	OpenCommand(SharedPtr<Object> mainObj, MyString fileName);
	void execute() override;
private:
	Type* buildType(const MyString& typeStr, size_t indent); //typeStr - singular type string to be added to an object
	Primitive* buildPrimitive(const MyString& typeStr, size_t indent);
	//Object buildObject(const MyString& typeStr, size_t indent);
	//Array buildArray(const MyString& typeStr, size_t indent);
};