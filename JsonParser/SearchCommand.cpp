#include "SearchCommand.h"

SearchCommand::SearchCommand(SharedPtr<Object> mainObj, MyString&& key) : mainObj(mainObj), key(std::move(key))
{
}

void SearchCommand::execute()
{
	//Array array;

	//mainObj->searchKey(array, key);

	//array.print(std::cout);
}
