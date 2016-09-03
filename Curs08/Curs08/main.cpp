#include "Sort.h"
int main()
{
	vector v;
	readVector(v);
	printVector(v,0,v.length-1);
	heapSort(v);
	printVector(v, 0, v.length - 1);
}