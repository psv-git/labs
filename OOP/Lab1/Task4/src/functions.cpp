#include "functions.hpp"

// print program info
void PrintProgramInfo()
{
	std::wcout << std::endl;
	std::wcout << L"Приложение выполняет RLE-компрессию бинарных файлов с сильно разреженным содержимым, а также декомпрессию упакованных ею файлов." << std::endl
			   << std::endl;
	std::wcout << L"Упаковка: rle pack <input file> <output file>" << std::endl;
	std::wcout << L"Распаковка: rle unpack <input file> <output file>" << std::endl
			   << std::endl;
}

// print program exit status
void PrintExitInfo(int exitCode)
{
	switch (exitCode)
	{
	case 0:
		break;
	case 1:
		std::wcout << L"Error code " << exitCode << L": bad arguments count." << std::endl;
		break;
	case 2:
		std::wcout << L"Error code " << exitCode << L": error opening input file." << std::endl;
		break;
	case 3:
		std::wcout << L"Error code " << exitCode << L": error opening output file." << std::endl;
		break;
	case 4:
		std::wcout << L"Error code " << exitCode << L": undefined program mode." << std::endl;
		break;
	case 5:
		std::wcout << L"Error code " << exitCode << L": unsupported symbol was finded." << std::endl;
		break;
	case 6:
		std::wcout << L"Error code " << exitCode << L": incorrect symbol sequence length was finded." << std::endl;
		break;
	case 7:
		std::wcout << L"Error code " << exitCode << L": incorrect pair was finded." << std::endl;
		break;
	default:
		std::wcout << L"Error code " << exitCode << L": undefined error." << std::endl;
	}
}

const int BYTE_RANGE = 254;

//
int PackingFile(std::ifstream& inFile, std::ofstream& outFile)
{
	char byte;
	char bytesBuf[BYTE_RANGE];
	uint8_t bytesCounter = 0;
	while (!inFile.eof())
	{
		inFile.read(&byte, sizeof(char));
		// if ((int)byte < 0)
		// {
		// 	return 5; // unsupported symbol
		// }
		if (inFile.gcount())
		{
			bytesBuf[bytesCounter] = byte;
			bytesCounter++;
		}
		if (bytesCounter == BYTE_RANGE || inFile.eof())
		{
			int seqLength = 1;
			char prevByte;
			for (int i = 0; i <= bytesCounter; i++)
			{
				byte = bytesBuf[i];
				if (i > 0)
				{
					if (i < bytesCounter && byte == prevByte)
					{
						seqLength++;
					}
					else
					{
						outFile.write((char*)&seqLength, sizeof(char));
						outFile.write(&prevByte, sizeof(char));
						seqLength = 1;
					}
				}
				prevByte = byte;
			}
			bytesCounter = 0;
		}
	}
	return 0;
}

//
int UnpackingFile(std::ifstream& inFile, std::ofstream& outFile)
{
	char byte;
	uint8_t seqLength;
	while (!inFile.eof())
	{
		inFile.read(&byte, sizeof(char));
		if (inFile.gcount())
		{
			seqLength = (uint8_t)byte;
			if (seqLength < 1)
			{
				return 6; // incorrect seq length
			}
			inFile.read(&byte, sizeof(char));
			if (inFile.gcount())
			{
				for (int i = 0; i < seqLength; i++)
				{
					outFile.write(&byte, sizeof(char));
				}
			}
			else
			{
				return 7; // odd elements count
			}
		}
	}
	return 0;
}