#include<iostream>

using namespace std;

class TestArray
{
private:
	int test_time;
	int range_size;
	int select_size;
	int ** array;
public:
	TestArray() = delete;
	TestArray(int t, int k, int n);
	TestArray(const TestArray &);
	TestArray(const TestArray &&);
	void random_generate();
	void test_print();
	~TestArray();

};

