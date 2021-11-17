#include <iostream>
#include <fstream>
#include <vector>
#include <Windows.h>

int main()
{
	try
	{
		LPCSTR newFileName;
		BOOL funcSuccess = CopyFileA(
			"D:\\test.txt",
			"D:\\Test\\test.txt",
			false
		);
		if (!funcSuccess)
		{
			throw std::exception("Error: file is not copied");
		}

		std::vector<std::string> v;
		std::fstream file;

		file.open("D:\\Test\\Test.txt");
		if (!file.is_open())
		{
			throw std::exception("Error: file is not opened");
		}
		std::string temp;
		while (file >> temp)
		{
			v.push_back(temp);
		}
		file.close();

		auto password = find(v.begin(), v.end(), "some_password");
		if (password == v.end())
		{
			std::cout << "\"some_password\" not found" << std::endl;
		}
		else
		{
			*password = "123456789";
		}

		file.open("D:\\Test\\test.txt", std::fstream::out);
		if (!file.is_open())
		{
			throw std::exception("Error: file is not opened");
		}
		for (size_t i = 0; i < v.size(); ++i)
		{
			file << v[i];
			if (i % 2 != 0)
			{
				file << "\n";
			}
			else
			{
				file << " ";
			}
		}

		file.close();
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
}