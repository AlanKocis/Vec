#pragma once

class Vec {
private:
	int* array1 = nullptr;
	int* array2 = nullptr;
	int vec_size = 0;
public:
	int get(int index);
	void push_back(int num);
	void pop();
	int size();
	Vec();
	~Vec();
};
