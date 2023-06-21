#include "SaveCommand.h"
#include <fstream>

SaveCommand::SaveCommand(SharedPtr<Object> mainObj, MyString&& fileName) : mainObj(mainObj), fileName(std::move(path))
{
}

SaveCommand::SaveCommand(SharedPtr<Object> mainObj, MyString&& fileName, MyString&& path) : mainObj(mainObj), fileName(std::move(path)), path(std::move(path))
{
}

void SaveCommand::execute()
{
	if (path.length() > 0)
	{
		//todo: add for path
	}
	else
	{
		std::ofstream ofs(path.c_str());

		mainObj->print(ofs);

		ofs.close();
	}
}
