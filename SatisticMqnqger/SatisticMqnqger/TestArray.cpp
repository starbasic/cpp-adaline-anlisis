#include "TestArray.h"

TestArray::TestArray(int t, int k, int n)
{
	test_time = t;
	range_size = n;
	select_size = k;
	array =  new int*[t];
	for (int i = 0; i < t; i++)
	{
		array[i] = new int[n];
	}
}

TestArray::~TestArray()
{
	if(test_time)
	{
		for (int i = 0; i < test_time; i++)
		{
			delete [] array[i];
		}
		delete [] array;
	}

}

TestArray::TestArray(const TestArray & other)
{
	this->test_time = other.test_time;
	this->range_size = other.range_size;
	this->select_size = other.select_size;
	this->array =  new int*[test_time];
	for (int i = 0; i < test_time; i++)
	{
		array[i] = new int[range_size];
		for (int j = 0; j < range_size; j++)
		{
			array[i][j] = other.array[i][j];
		}
	}
}

TestArray::TestArray(const TestArray && other)
{
	this->test_time = other.test_time;
	this->range_size = other.range_size;
	this->select_size = other.select_size;
	this->array =  new int*[test_time];
	for (int i = 0; i < test_time; i++)
	{
		array[i] = new int[range_size];
		for (int j = 0; j < range_size; j++)
		{
			array[i][j] = other.array[i][j];
		}
	}
}

void TestArray::random_generate()
{
    srand(time(NULL));
    for (int i = 0; i < test_time; i++)
    {
        for (int j = 0; j < range_size; j++)
        {
            array[i][j] = 0;
        }
        int next;
        for (int total_gener = 0; total_gener < select_size;) 
		{
            next = rand() % (range_size - total_gener);
			for(int j = 0; j<next;j++)
				if (array[i][j])next++;
			while(array[i][next])next++;
			array[i][next]= 1;
			total_gener++;
        }
    }
}
 
void TestArray::test_print()
{
    for (int i = 0; i < test_time; i++)
    {
        for (int j = 0; j < range_size; j++)
        {
            if(array[i][j]) cout<<j+1<<"  ";
        }
        cout<<endl;
    }
 
}


learn_sample TestArray::getSample(int time, int n, int size) const
	{
		
		// 0 based names of elements!!! n  to n+1
		learn_sample result(size);
		if(time>test_time-(size+1) || time<0)
			cout<<"wrong learning example at time="<<time<<endl;
		else
		{
			for (int i = 0; i < size; i++)
			{
				result[i] = array[time+i][n];
			}
			result.setResult(array[time+size][n]);
		}
		return result;
	}

 

	learn_sample::learn_sample(int size)
	{
		this->size = size;
		bites = new int[size+1];
		for (int i = 0; i < size+1; i++)
		{
			this->bites[i] = 0;
		}
	}
	learn_sample::learn_sample(const learn_sample& other)
	{
		this->size = other.size;
		bites = new int[size+1];
		for (int i = 0; i < size+1; i++)
		{
			this->bites[i] = other.bites[i];
		}
	}

	learn_sample::learn_sample(const learn_sample&& other)
	{
		this->size = other.size;
		bites = new int[size+1];
		for (int i = 0; i < size+1; i++)
		{
			this->bites[i] = other.bites[i];
		}
	}
	learn_sample::~learn_sample()
	{
		this->size = 0;
		delete [] this->bites ;
	}

	int& learn_sample::operator[](int i) 
	{
		if(i>=0 && i< size)
		return this->bites[i];
		
	}

	int learn_sample::getResult() const
	{
		return this->bites[size];
	}

	void learn_sample::setResult(int n)
	{
		this->bites[size] = n;
	}

	