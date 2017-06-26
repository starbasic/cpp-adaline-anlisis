#include "Adaline.h"

Adaline::Adaline(int n)
	{
		size = n;
		weight=new double[n];
		for (int i = 0; i < size; i++)
		{
			weight[i] = 1.0/size;
		}
		y = 0;
		learn_speed = SPEED;
	}
Adaline::Adaline(const Adaline& other)
	{
		this->size = other.size;
		this->weight=new double[size];
		for (int i = 0; i < size; i++)
		{
			this->weight[i] = other.weight[i];
		}
		this->y = other.y;
		this->learn_speed = other.learn_speed;

	}
Adaline::Adaline(const Adaline&& other)
	{
		this->size = other.size;
		this->weight=new double[size];
		for (int i = 0; i < size; i++)
		{
			this->weight[i] = other.weight[i];
		}
		this->y = other.y;
		this->learn_speed = other.learn_speed;

	}

void Adaline::print_weights()
{
	cout<<"Weights: "<<endl;
	for (int i = 0; i < this->size; i++)
		{
			cout<<this->weight[i]<<endl;
		}
}

void Adaline::learn_widrow(learn_sample ls)
{
	if(this->size!=ls.getSize())
		{
			cout<< "Bad example size";
			return;
	}
	else
	{


	}
}