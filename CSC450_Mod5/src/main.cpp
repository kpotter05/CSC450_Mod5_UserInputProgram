#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string reverseText(string text)
{
	string reversed = "";

	for (int i = text.length() - 1; i>=0; i--)
	{
		reversed += text[i];
	}
	return reversed;
}

int main()
{
	string userInput;

	cout << "Enter text to add the file: ";
	getline(cin, userInput);

	ofstream outputFile("CSC450_CT5_mod5.txt", ios::app);

	if (outputFile.is_open())
	{
		outputFile << userInput << endl;

		outputFile.close();

		cout << "Text successfully added to file." << endl;
	}
	else
	{
		cout << "Unable to open file." << endl;
	}

	ifstream inputFile("CSC450_CT5_mod5.txt");

	string fileContents = "";
	string line;

	while (getline(inputFile, line))
	{
		fileContents += line + "\n";
	}

	inputFile.close();

	cout << "\nContents of file:\n";
	cout << fileContents << endl;

	string reversedContents = reverseText(fileContents);

	ofstream reverseFile("CSC450-mod5-reverse.txt");

	if (reverseFile.is_open())
	{
		reverseFile << reversedContents;

		reverseFile.close();

		cout << "\nReverse file created successfully." << endl;
	}
	else
	{
		cout << "\nUnable to create reverse file," << endl;
	}
	return 0;
}
