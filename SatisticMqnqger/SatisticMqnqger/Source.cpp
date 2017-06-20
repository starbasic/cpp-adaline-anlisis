#include "TestArray.h"
void main()
{
	cout<<"Hello, statistics!"<<endl;
	TestArray data(20, 4, 10);
	data.random_generate();
	data.test_print();

}