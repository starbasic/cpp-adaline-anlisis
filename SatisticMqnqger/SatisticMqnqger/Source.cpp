#include "TestArray.h"
#include "Adaline.h"
void main()
{
	cout<<"Hello, statistics!"<<endl;
	TestArray data = TestArray::getFromMFile();
	//TestArray data(50, 4, 10);
	//data.random_generate();
	//data.test_print();

	////learn_sample ls;
	Adaline ada(15);
	//cout<<endl<<"weights before learning"<<endl;
	//ada.print_weights();
	for (int i = 900; i < 989; i++)
	{
		ada.learn_statistic(data,i);
		cout<<endl<<"weights after learning"<<endl;
		ada.print_weights();

	}

}