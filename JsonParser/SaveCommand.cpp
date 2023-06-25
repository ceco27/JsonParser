#include "SaveCommand.h"
#include "StrFunctions.h"
#include <fstream>

SaveCommand::SaveCommand(SharedPtr<Object> mainObj) : mainObj(mainObj), path()
{
}

SaveCommand::SaveCommand(SharedPtr<Object> mainObj, MyString&& path) : mainObj(mainObj), path(std::move(path))
{
}

void SaveCommand::execute()
{
	if (path.length() > 0)
	{
		std::ofstream ofs(mainObj->getFileName().c_str());

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
		std::ofstream ofs(mainObj->getFileName().c_str());

		if (!ofs.is_open())
			throw std::exception("Could not save file");

		mainObj->print(ofs);

		ofs.close();
	}

	throw - 1;
}
