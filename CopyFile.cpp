#include <iostream>
#include <fstream>
#include <vector>
#include <Windows.h>

int main()
{
	LPCSTR existingFileName = "D:\\test.txt";
	LPCSTR newFileName = "D:\\Test\\test.txt";
	BOOL funcSuccess = CopyFileA(
		existingFileName,
		newFileName,
		false
	);
	if (!funcSuccess)
	{
		std::cout << "Something went wrong" << std::endl;
	}
}