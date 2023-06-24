#include "SaveCommand.h"
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
		//todo: add for path
	}
	else
	{
		std::ofstream ofs(mainObj->getFieldName().c_str());

		if (!ofs.is_open())
			throw std::exception("Could not save file");

		mainObj->print(ofs);

		ofs.close();
	}

	throw - 1;
}
