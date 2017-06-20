#include "TestArray.h"

TestArray::TestArray(int t, int k, int n)
{
	test_time = t;
	range_size = n;
	select_size = k;
	array =  new int*[t];
	for (int i = 0; i < t; i++)
	{
		array[i] = new int[n];
	}
}

TestArray::~TestArray()
{
	if(test_time)
	{
		for (int i = 0; i < test_time; i++)
		{
			delete [] array[i];
		}
		delete [] array;
	}

}

TestArray::TestArray(const TestArray & other)
{
	this->test_time = other.test_time;
	this->range_size = other.range_size;
	this->select_size = other.select_size;
	this->array =  new int*[test_time];
	for (int i = 0; i < test_time; i++)
	{
		array[i] = new int[range_size];
		for (int j = 0; j < range_size; j++)
		{
			array[i][j] = other.array[i][j];
		}
	}
}

TestArray::TestArray(const TestArray && other)
{
	this->test_time = other.test_time;
	this->range_size = other.range_size;
	this->select_size = other.select_size;
	this->array =  new int*[test_time];
	for (int i = 0; i < test_time; i++)
	{
		array[i] = new int[range_size];
		for (int j = 0; j < range_size; j++)
		{
			array[i][j] = other.array[i][j];
		}
	}
}

void TestArray::test_print()
{
	for (int i = 0; i < test_time; i++)
	{
		for (int j = 0; j < range_size; j++)
		{
			if(array[i][j]) cout<<j+1;
		}
		cout<<endl;
	}

}