#include <iostream>
#include <ctime>

using namespace std;

#ifndef TESTARRAY
#define TESTARRAY

class learn_sample
{
private:
	int size;
	int *bites;
	double result;
public:
	learn_sample(){}
	learn_sample(int size);
	learn_sample(const learn_sample& other);
	learn_sample(const learn_sample&& other);
	learn_sample operator=(learn_sample other);
	~learn_sample();
	int& operator[](int i);
	double getResult() const;
	int getSize() const{ return this->size;}
	void setResult(double);
};

class TestArray
{
private:
	int test_time;
	int range_size;
	int select_size;
	int ** array;
public:
	//TestArray() = delete;
	TestArray(int t, int k, int n);
	TestArray(const TestArray &);
	TestArray(const TestArray &&);
	void random_generate();
	void test_print();
	~TestArray();

	learn_sample getSample(int time, int n, int size) const;
};


#endif

