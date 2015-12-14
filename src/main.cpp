// main.cpp
// Created by Evan Almonte
//  
#include "File.hpp"
#include "ImageFile.hpp"
#include "TextFile.hpp"
#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::cout;

vector<File*> filterFiles (const vector<File*>& files, std::string extension);
void filterFilesRec (vector<File*>& sourceVector, vector<File*>& destVector, std::string extension);
void outputProperties (const vector<File*>& files);
void outputPropertiesRec (vector<File*>& files);

int main( ) {
	vector<File*> vecOfFiles;
	vecOfFiles.push_back(new ImageFile("Evan's First File", 10, 10, 16));
	vecOfFiles.push_back(new TextFile("Evan's Second File"));
	vecOfFiles.push_back(new ImageFile("Evan's Third File", 20, 10, 32));

	cout << "Testing outputProperties():\n";
	outputProperties(vecOfFiles);

	cout << "\n\nTesting filterFiles():\n";
	vector<File*> testingFilter = filterFiles(vecOfFiles, "txt");
	outputProperties(testingFilter);
	return 0;
}

void outputProperties(const vector<File*>& files) {
	vector<File*> tempFiles(files);
	outputPropertiesRec(tempFiles);
}

void outputPropertiesRec(vector<File*>& files) {
	if (files.size() != 0) {
		File* lastElement = files.back();
		files.pop_back();
		outputProperties(files);
		cout << "Type: " + lastElement->getExtension() + "\n";
		cout << "Name: " + lastElement->getName() + "\n";
		if (lastElement->getExtension() == "gif") {
			ImageFile* anImageFile = dynamic_cast<ImageFile*>(lastElement);
			cout << "Dimension: " << anImageFile->getDimensionHeight() << " x "
					<< anImageFile->getDimensionWidth() << "\n";
		}
		cout << "Size: " << lastElement->getSize() << " bytes\n\n";
	}
}

vector<File*> filterFiles(const vector<File*>& files, std::string extension) {
	vector<File*> tempFiles(files), filesToReturn;
	filterFilesRec(tempFiles, filesToReturn, extension);
	return filesToReturn;
}

void filterFilesRec(vector<File*>& sourceVector, vector<File*>& destVector, std::string extension) {
	if (sourceVector.size() == 0) {
		return;
	}
	File* fileAtEnd = sourceVector.back();
	sourceVector.pop_back();
	filterFilesRec(sourceVector, destVector, extension);
	if (fileAtEnd->getExtension() == extension) {
		destVector.push_back(fileAtEnd);
	}
}
