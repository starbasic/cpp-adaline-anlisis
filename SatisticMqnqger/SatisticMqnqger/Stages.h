#ifndef STAGES
#define STAGES
#include <iostream>
#include "TestArray.h"
using namespace std;

class Stages
{
private:
	int min_size, max_size;
	double **weights;
public:
	Stages(int min, int max);
	Stages(const Stages &);
	Stages(const Stages &&);
	int getMin(){return min_size;}
	int grtMax(){return max_size;}
	~Stages();
	void getStage(TestArray data_ta);
	void print();
	void getLinearProba(TestArray data_ta, double * res);
};



#endif