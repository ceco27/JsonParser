#include "SaveAsCommand.h"
#include "StrFunctions.h"
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
		std::ofstream ofs(fileName.c_str());

		MyString* pathArr;
		size_t pathSize = 0;

		buildPath(path, pathArr, pathSize);

		ofs << "{" << std::endl;

		mainObj->getTypeFromPath(pathArr, pathSize).print(ofs);

		ofs << std::endl << "}" << std::endl;

		ofs.close();

	}
	else
	{
		std::ofstream ofs(fileName.c_str());

		ofs << "{" << std::endl;

		mainObj->print(ofs);

		ofs << std::endl << "}" << std::endl;

		ofs.close();
	}

	throw - 1;
}
