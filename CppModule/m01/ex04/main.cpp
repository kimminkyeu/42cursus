#include <fstream>
#include <iostream>
#include <string>

int main(int ac, char** av)
{
	if (ac != 4)
		return (1);

	std::string		fileName(av[1]);
	std::string 	toFind(av[2]);
	std::string 	toReplace(av[3]);
	std::ifstream 	openFile(fileName);
	std::ofstream 	writeFile(fileName.append(".replace"));

	if (openFile.is_open() && writeFile.is_open())
	{
		std::string buf;
		while(std::getline(openFile, buf))
		{
			std::string::size_type found_location = buf.find(toFind);
			if (found_location != std::string::npos) // if not found (-1)
			{
				// WARN:  Forbidden function.
				// buf.replace(found_location, toFind.length(), toReplace);
				std::string buf_modified;
				buf_modified.append(buf, 0, found_location);
				buf_modified.append(toReplace);
				buf_modified.append(buf, found_location + toFind.length());
				writeFile << buf_modified;
			}
			else
				writeFile << buf;
		}
		openFile.close();
		writeFile.close();
	}
	return (0);
}
