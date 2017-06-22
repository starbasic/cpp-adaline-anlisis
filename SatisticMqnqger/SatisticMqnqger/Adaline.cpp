#include "Adaline.h"

Adaline::Adaline(int n)
	{
		size = n;
		weight=new double[n];
		for (int i = 0; i < size; i++)
		{
			weight[i] = 1.0/size;
		}

	}
Adaline::Adaline(const Adaline& other)
	{
		this->size = other.size;
		this->weight=new double[size];
		for (int i = 0; i < size; i++)
		{
			this->weight[i] = other.weight[i];
		}
	}
Adaline::Adaline(const Adaline&& other)
	{
		this->size = other.size;
		this->weight=new double[size];
		for (int i = 0; i < size; i++)
		{
			this->weight[i] = other.weight[i];
		}
	}

void Adaline::print_weights()
{
	cout<<"Weights: "<<endl;
	for (int i = 0; i < this->size; i++)
		{
			cout<<this->weight[i]<<endl;
		}
}