#include "TestArray.h"
#include "Adaline.h"
#include "Stages.h"
void main()
{
	cout<<"Input data:"<<endl;
	TestArray data = TestArray::getFromMFile("mega.dat");
	data.test_print();
	cout<<endl;
	
	TestArray data_b = data.getBack(1);
	double proba[42];
	Stages network(7,14);
	//network.print();
	network.getStage(data_b);
	//network.print();
	network.getLinearProba(data_b,proba);
	int names[42];
	for (int i = 0; i < 42; i++)names[i]=i+1;
	
	/*for (int i = 0; i < 42;i++)
	{

		cout<<names[i]<<'\t'<<proba[i]<<endl;
	}
	cout<<endl<<endl;
*/

	for (int i = 0; i < 42; i++)
	{
		int mini = i;
		for(int j = i; j<42; j++)
			if(proba[mini]<proba[j])mini=j;
		double tmpd = proba[mini];
		proba[mini] = proba[i];
		proba[i] = tmpd;
		int tmpi = names[mini];
		names[mini] = names[i];
		names[i] = tmpi;
	}
	

	for (int i = 0; i < 10;i++)
	{

		cout<<names[i]<<'\t';//<<proba[i]<<endl;
	}

}