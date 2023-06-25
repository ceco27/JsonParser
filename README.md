# JsonParser
The project is an app for parsing a JSON file
It includes the following functionalities:
## print
Prints the loaded json object.
## search <key>
Prints an array with all values that have this key.
## set <path> <string> 
Sets the value of the field at the path to the input string.
## create <path> <string> 
Sets the value of the field at the path to the input string. If the path does not exist, it is created.
## delete <path> 
Deletes the field at that path.
## move <from> <to> 
Moves the field from the <from> location to the <to> location.
## save [<path>] 
Saves the current state of the json. If path is inputed the json object at that path is saved.
## saveas <file> [<path>] 
Saves the current state of the json as <filename>. If path is inputed the json object at that path is saved.
## close 
Closes the opened file without saving
## exit
Terminates the program
