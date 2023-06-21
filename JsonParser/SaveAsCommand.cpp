#include "SaveAsCommand.h"
#include <fstream>

SaveAsCommand::SaveAsCommand(SharedPtr<Object> mainObj, MyString&& fileName) : mainObj(mainObj), fileName(std::move(fileName))
{
}

SaveAsCommand::SaveAsCommand(SharedPtr<Object> mainObj, MyString&& fileName, MyString&& path) : mainObj(mainObj), fileName(std::move(fileName)), path(std::move(path))
{
}

void SaveAsCommand::execute()
{
	if (path.length() > 0)
	{
		//todo: add for path
	}
	else
	{
		std::ofstream ofs(fileName.c_str());

		mainObj->print(ofs);

		ofs.close();
	}
}
