#include "ArrayTests.h"

#include <iostream>
#include <Windows.h>
#include "Array.hpp"
#include "PrintC.hpp"

bool ArrayTests::PushBackOnArray() {
	printf("No Implementation\n");
	return false;
}

bool ArrayTests::PopBackOnArray() {
	printf("No Implementation\n");
	return false;
}


bool ArrayTests::CheckArraySize() {
	Array<int> array;
	if (array.GetSize() != 0) {
		PrintC("Failed: Array size not initialized to 0\n", TextColor::red);
		return false;
	}

	array = Array<int>(50);
	if (array.GetSize() != 50) {
		PrintC("Failed: Array size not properly set\n", TextColor::red);
		return false;
	}

	PrintC("Success: Array size properly modified\n", TextColor::green);
	return true;
}

bool ArrayTests::CheckArrayLength() {
	printf("No Implementation\n");
	return false;
}


bool ArrayTests::AssignArray() {
	printf("No Implementation\n");
	return false;
}

bool ArrayTests::AccessArray() {
	printf("No Implementation\n");
	return false;
}


bool ArrayTests::AddPastArraySize() {
	printf("No Implementation\n");
	return false;
}

bool ArrayTests::AddBelowArraySize() {
	printf("No Implementation\n");
	return false;
}


bool ArrayTests::RunAllTests() {
	
	std::cout << "Begining Array Tests..." << std::endl;
	
	int testCount = 0;
	int successCount = 0;

	auto runTest = [&](bool (*test)(void)) {
		testCount++;
		std::cout << "Test " << testCount << ".....";
		if ((*test)() == true)
			successCount++;
	};

	runTest(CheckArraySize);

	return false;
}