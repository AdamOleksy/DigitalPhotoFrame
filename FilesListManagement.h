#pragma once

#include <filesystem>
#include <vector>
#include <stdlib.h>


class FilesListManagement
{
public:
	std::vector<std::string> m_files_list;
	FilesListManagement(std::string directory);
	std::string GiveRandomName();
};

