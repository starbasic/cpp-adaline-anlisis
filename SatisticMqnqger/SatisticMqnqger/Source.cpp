#include "TestArray.h"
#include "Adaline.h"
void main()
{
	cout<<"Hello, statistics!"<<endl;
	TestArray data(250, 4, 10);
	data.random_generate();
	data.test_print();

	//learn_sample ls;
	Adaline ada(20);
	cout<<endl<<"weights before learning"<<endl;
	ada.print_weights();

	ada.learn_statistic(data);

	cout<<endl<<"weights after learning"<<endl;
	ada.print_weights();



}