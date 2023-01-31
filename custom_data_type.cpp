#include <iostream>
#include "Vec.h"

int main() {


	/*
	Current Limitations:
							Can only increment Vec size by 1 at a time by using push_back() method. Can't just say int_vector[10] like a the std::vector class
	*/

	Vec int_vector;
	int_vector.push_back(5);
	int_vector.push_back(10);
	int_vector.push_back(20);
	int_vector.push_back(500);
	int_vector.push_back(23);

	std::cout << "Current vec size: " << int_vector.size() << std::endl;

	for (int i = 0; i < int_vector.size(); i++) {
		std::cout << int_vector.get(i) << " ";
	}
	std::cout << std::endl;

	int_vector.pop();
	int_vector.pop();

	std::cout << "Current vec size: " << int_vector.size() << std::endl;


	for (int i = 0; i < int_vector.size(); i++) {
		std::cout << int_vector.get(i) << " ";
	}
	std::cout << std::endl;




	return 0;
}

