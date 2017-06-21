#include "TestArray.h"
void main()
{
	cout<<"Hello, statistics!"<<endl;
	TestArray data(20, 4, 10);
	data.random_generate();
	data.test_print();

// test of sample extraction
	learn_sample ls = data.getSample(0, 5, 5);

	cout<<"Test example 0, 5, 5 "<<endl;

	for (int i = 0; i < 7; i++)
	{
		cout<<ls[i]<<"  ";
	}
	cout<<endl;

	cout<<ls.getResult()<<endl;



}