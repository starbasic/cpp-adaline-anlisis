#include "TestArray.h"
#ifndef ADALINE
#define ADALINE
#define SPEED 0.1
class Adaline
{
private:
		int size;
		double * weight;
		double y;
		double learn_speed;
public:
	Adaline(){size = 0; weight=NULL;}
	Adaline(int );
	Adaline(const Adaline& other);
	Adaline(const Adaline&& other);
	void print_weights();
	void learn_widrow(learn_sample);
	void learn_statistic(TestArray);
	void learn_statistic(TestArray, int);

};



#endif