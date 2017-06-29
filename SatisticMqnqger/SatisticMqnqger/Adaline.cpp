#include "Adaline.h"

Adaline::Adaline(int n)
	{
		size = n;
		weight=new double[n];
		for (int i = 0; i < size; i++)
		{
			weight[i] = 1.0/size;
		}
		y = 0.0;
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
			cout<<this->weight[i]<<'\t';
		}
	cout<<endl;
}

void Adaline::learn_widrow(learn_sample ls)
{
	if(this->size!=ls.getSize())
		{
			cout<< "Bad example size"<<endl;
			cout<<"Adaline Size: "<<this->size<<endl;
			cout<<"Sample size: "<<ls.getSize()<<endl;

			return;
	}
	else
	{
		//obtain prediatable result 
		y = 0.0;
		for (int i = 0; i < this->size; i++)
		{
			y+=this->weight[i]*ls[i];
			cout<<ls[i]<<endl;
		}
		//calculate new weights
		for (int i = 0; i < this->size; i++)
		{
			this->weight[i] -= learn_speed*ls[i]*(y-ls.getResult());
		}

	}
}


void Adaline::learn_statistic(TestArray datas)
{
	int * sum_positive = new int[this->size];
	for (int i = 0; i < this->size; i++)sum_positive[i]=0;
	{

	}
	//int * sum_negative = new int[this->size];
	int total = datas.get_test_time()-(this->size+1);
	int n= datas.get_range_size();
	int k = datas.get_select_size();
	int count = 0;
	for (int i = 0; i < total; i++)
	{
		for (int j= 0; j <n; j++)
		{
		learn_sample ls = datas.getSample(i, j, this->size);
			if(ls.getResult())
			{
				for (int ij = 0; ij < this->size; ij++)
				{
					if(ls[ij])
					{
						sum_positive[ij]++;
						count++;
					}
				}
			}
		}
	}
	if(count)
	{
		for (int i = 0; i < this->size; i++)
		{
			this->weight[i] = (double)sum_positive[i]/count;
		}
	}

	delete [] sum_positive;
}