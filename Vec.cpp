#include "Vec.h"
#include <iostream>

int Vec::size() {
	return vec_size;
}

int Vec::get(int index) {
	if (vec_size == 0 || index >= vec_size || index < 0) {
		std::cout << "ERROR GETTING VEC ITEM\n";
		return -999;
	}

	if (array1 == nullptr) {
		return array2[index];
	}
	else if (array2 == nullptr) {
		return array1[index];
	}
}

//OK, the way this works is that one of the two pointers in the class declaration will always be nullptr, and the other will be pointing to a dynamically created array
//So, I used two pointers to pointers that will perform the operations to create new memory and copy the arrays over depending on which original pointer is null
void Vec::push_back(int num) {


	int** new_array_pointer{};
	int** old_array_pointer{};


	if (vec_size == 0) {
		array1 = new int[1];
		array1[0] = num;
	}

	if (array1 == nullptr) {
		new_array_pointer = &array1;
		old_array_pointer = &array2;
	}
	else if (array2 == nullptr) {
		new_array_pointer = &array2;
		old_array_pointer = &array1;
	}

	*new_array_pointer = new int[vec_size + 1];		//warning b/c initialized in an if-else, but it will always run

	if (vec_size > 0) {
		for (int i = 0; i < vec_size; i++) {
			(*(*new_array_pointer + i)) = (*(*old_array_pointer + i));	//same as before
		}
	}

	(*new_array_pointer)[vec_size] = num;
	delete[] * old_array_pointer;
	*old_array_pointer = nullptr;
	++vec_size;
}

void Vec::pop() {
	int** new_array_pointer{};
	int** old_array_pointer{};


	if (array1 == nullptr) {
		new_array_pointer = &array1;
		old_array_pointer = &array2;
	}
	else if (array2 == nullptr) {
		new_array_pointer = &array2;
		old_array_pointer = &array1;
	}

	*new_array_pointer = new int[vec_size - 1];

	if (vec_size > 0) {
		for (int i = 0; i < vec_size - 1; i++) {
			(*(*new_array_pointer + i)) = (*(*old_array_pointer + i));
		}
	}

	delete[] * old_array_pointer;
	*old_array_pointer = nullptr;

	--vec_size;
}

Vec::Vec() {
	vec_size = 0;
	array1 = new int[vec_size];
}

Vec::~Vec() {
	delete[] array1;
	delete[] array2;
}