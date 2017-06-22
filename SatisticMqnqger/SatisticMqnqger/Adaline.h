#include "TestArray.h"
#ifndef ADALINE
#define ADALINE

class Adaline
{
private:
		int size;
		double * weight;
public:
	Adaline(){size = 0; weight=NULL;}
	Adaline(int );
	Adaline(const Adaline& other);
	Adaline(const Adaline&& other);
	void print_weights();


};



#endif