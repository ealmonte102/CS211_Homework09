// main.cpp
// Created by Evan Almonte
//  
#include "File.hpp"
#include <vector>
#include <iostream>
#include "ImageFile.hpp"
#include "TextFile.hpp"

using std::vector;
using std::cout;


void outputProperties (vector<File*>& files);

int main() {
	vector<File*> vecOfFiles;
	vecOfFiles.push_back (new ImageFile ("Evan's First File", 10, 10, 16));
	vecOfFiles.push_back (new TextFile ("Evan's Second File"));
	vecOfFiles.push_back (new ImageFile ("Evan's Third File", 20, 10, 32));
	outputProperties (vecOfFiles);
	return 0;
}

void outputProperties(vector<File*>& files) {
	if(files.size() != 0) {
		File* lastElement = files.back ( );
		cout << lastElement->getName ( ) << "\n";
		cout << lastElement->getExtension ( ) << "\n";
		cout << lastElement->getSize ( ) << "\n";
		files.pop_back ( );
		outputProperties (files);
		files.push_back (lastElement);
	}
}
