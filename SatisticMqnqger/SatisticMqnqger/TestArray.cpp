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

TestArray TestArray::getFromMFile(const char* f_name)
{
	ifstream data_file(f_name,ios::in|ios::binary);
	int count = 0;
	char buf[110];
	while(!data_file.eof())
	{
		data_file.getline(buf,110);
		count++;
	}
	TestArray res(count-1,6,42);
	data_file.close();
	data_file.open(f_name,ios::in|ios::binary);
	for (int i = 0; i < count-1; i++)
	{
		 for (int j = 0; j < res.range_size; j++)
        {
            res.array[i][j] = 0;
        }
        for (int j = 0; j< res.select_size; j++)
		{
				int next;
				data_file>>next;
				//cout<<next<<"  ";
				res.array[i][next-1]= 1;
		}
	    }
		

	data_file.close();
	return res;

}


TestArray TestArray::getBack(int dist)
{
	if(dist<this->test_time)
	{
		TestArray res(this->test_time-dist,this->select_size, this->range_size);
		for (int i = 0; i < this->test_time-dist; i++)
		{
			for (int j = 0; j < this->range_size; j++)
			{
				res.array[i][j] = this->array[i][j];

			}
		}
		return res;
	}
	else
	{
		cout<<"Test array is too small";
		return *this;
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
		
		// 0 based names of elements!!! k  to k+1
		// n - number of row in test
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
		bites = new int[size];
		for (int i = 0; i < size; i++)
		{
			this->bites[i] = 0;
		}
		this->result=0.0;
	}
	learn_sample::learn_sample(const learn_sample& other)
	{
		this->size = other.size;
		bites = new int[size];
		for (int i = 0; i < size; i++)
		{
			this->bites[i] = other.bites[i];
		}
		this->result= other.result;
	}

	learn_sample::learn_sample(const learn_sample&& other)
	{
		this->size = other.size;
		bites = new int[size];
		for (int i = 0; i < size; i++)
		{
			this->bites[i] = other.bites[i];
		}
		this->result= other.result;
	}

	learn_sample learn_sample::operator=(learn_sample other)
	{
		this->size = other.size;
		bites = new int[size];
		for (int i = 0; i < size; i++)
		{
			this->bites[i] = other.bites[i];
		}
		this->result= other.result;
		return *this;
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

	double learn_sample::getResult() const
	{
		return this->result;
	}

	void learn_sample::setResult(double p)
	{
		this->result = p;
	}

	