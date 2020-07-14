#include "FilesListManagement.h"

FilesListManagement::FilesListManagement(std::string directory)
{
	for (const auto &file : std::filesystem::directory_iterator(directory))
		m_files_list.push_back(file.path().string());
}

std::string FilesListManagement::GiveRandomName()
{
	srand(time(NULL));
	return m_files_list.at(rand() % m_files_list.size());
}

