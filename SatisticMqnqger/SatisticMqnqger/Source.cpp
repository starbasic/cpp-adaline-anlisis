#include "TestArray.h"
#include "Adaline.h"
void main()
{
	cout<<"Hello, statistics!"<<endl;
	TestArray data(20, 4, 10);
	data.random_generate();
	data.test_print();

	learn_sample ls;
	Adaline ada(10);
	cout<<endl<<"weights before learning"<<endl;
	ada.print_weights();

	for (int i = 0; i < 10; i++)
	{
		ls = data.getSample(8, i, 10);
		
		cout<<"After "<<i<<" sample:"<<endl;
		for (int i = 0; i < 10; i++)
		{
			cout<<data.getSample(8, i, 10)[i]<<"    "<<ls[i]<<endl;
		}
		
		ada.learn_widrow(ls);
		ada.print_weights();

		system("pause");
	}

}