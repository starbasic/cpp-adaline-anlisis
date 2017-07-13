#include "Stages.h"
#include "TestArray.h"
Stages::Stages(int min, int max)
{
	this->min_size = min;
	this->max_size = max;
	int height = max-min+1;
	int width = min;
	this->weights = new double*[height];
	for (int i = 0; i < height; i++)
	{
		width = min + i;
		this->weights[i] = new double[width];
		for (int j = 0; j < width; j++)
		{
			this->weights[i][j] = 0.0;
		}
	}
}
Stages::Stages(const Stages &other)
{
	this->min_size = other.min_size;
	this->max_size = other.max_size;
	int height = this->max_size-this->min_size+1;
	int width = this->min_size;
	this->weights = new double*[height];
	for (int i = 0; i < height; i++)
	{
		width = this->min_size + i;
		this->weights[i] = new double[width];
		for (int j = 0; j < width; j++)
		{
			this->weights[i][j] = other.weights[i][j];
		}
	}
}
Stages::Stages(const Stages &&other)
{

	this->min_size = other.min_size;
	this->max_size = other.max_size;
	int height = this->max_size-this->min_size+1;
	int width = this->min_size;
	this->weights = new double*[height];
	for (int i = 0; i < height; i++)
	{
		width = this->min_size + i;
		this->weights[i] = new double[width];
		for (int j = 0; j < width; j++)
		{
			this->weights[i][j] = other.weights[i][j];
		}
	}
}
Stages::~Stages()
{
	int height = this->max_size-this->min_size+1;
	for (int i = 0; i < height; i++)
	{
		delete [] this->weights[i];
	}
	delete this->weights;
	this->max_size = 0;
	this->min_size = 0; 
}

//
void Stages::getStage(TestArray data_ta)
{
	int height = this->max_size-this->min_size+1;
	int width = this->min_size;
	int last_t =data_ta.get_test_time();
	int k = data_ta.get_range_size();
	for (int i = 0; i < height; i++, width++)
	{
		//body for each stage
		int * local_data = new int[width];
		for (int j = 0; j < width; j++)local_data[j] = 0;
		
		int total = (last_t - width)*data_ta.get_select_size();
		for (int t = width; t < last_t; t++)
		{
			for (int w= 0; w < k; w++)
			{	
				if(data_ta.getData()[t][w])
				{
					int count = 0;
					for (int j = t-width; j < t; j++)
					{
						count += data_ta.getData()[j][w];
					}
					local_data[count]++;
				}
			}
		}
		for (int j = 0; j < width; j++)
		{
			this->weights[i][j] = double(local_data[j])/total;
		}
		delete [] local_data;
	}
}


void Stages::print()
{
	int height = this->max_size-this->min_size+1;
	int width = this->min_size;
	for (int i = 0; i < height; i++,width++)
	{
		for (int j = 0; j < width; j++)
		{
			cout<<this->weights[i][j] <<" ";
		}
		cout<<endl;
	}
}
void Stages::getLinearProba(TestArray data_ta, double * res)
{
	int height = this->max_size - this->min_size + 1;
	int last_t =data_ta.get_test_time();
	int n = data_ta.get_range_size();
	for (int i = 0; i < n;  i++) 
	{
		int width = this->min_size;
		res[i] = 0.0;
		for (int j = 0; j < height; j++, width++)
		{
			int next_count = 0;
			for (int k = last_t - width; k < last_t; k++)
				next_count += data_ta.getData()[k][i];
			res[i] += (this->weights[j][next_count])/height;
		}
	}
		
	
}