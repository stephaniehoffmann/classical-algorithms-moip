//#define PRG_NAME "A Simple,  Efficient and Versatile Objective Space Algorithm for Multiobjective Integer Programming" 
//#define CPY_RGHT "Copyright © 2019-2021" 
//#define AUTHOR "Kerstin Daechert and Tino Fleuren and Kathrin Klamroth" 

#include "classes/include/DefiningPoint.h"
#include <string>
#include <numeric>
#include <deque> 
#include <iostream>
#include "classes/include/main.h"
#include <chrono>

using namespace std;

char* GetFileName(const char* argument) {
	char *fileName = new char[150];
	strcpy(fileName, argument);
	return fileName;
}

int main(int argc, char** argv) {


	if (argc < 2) {
		std::cerr << "Usage: " << argv[0] << " <file name> [-v]" << std::endl;
		std::cerr << "       " << " -v .. verbose" << std::endl;
		std::cerr << "       " << " -a .. augmented" << std::endl;
		return 1;
	}

	std::cout << "Processing: " << argv[1] << std::endl;

	const char* fileName = GetFileName(argv[1]);
    const char* output = GetFileName(argv[3]);
    const double timeout = atoi(GetFileName(argv[4]));
	bool augmented = false;
	bool verbose = false;

	if (argc > 2 && strcmp(argv[2], "-v") == 0)
		verbose = true;
	if (argc > 2 && strcmp(argv[2], "-a") == 0)
		augmented = true;


	DefiningPoint df = DefiningPoint(verbose);
	try {
		df.ImportProblemSpecification(fileName);

        std::cout << "num objectives: " << df.numObjectives << std::endl;
        auto start = std::chrono::high_resolution_clock::now();
		df.Compute(true, augmented, df.numObjectives - 1, timeout);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::seconds>(stop - start);
        df.solutionTime = duration.count();

		std::string resultFileName(output);
		df.ExportNonDominatedPointsToFile(resultFileName);
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return -1;
	}

	return 0;
}


