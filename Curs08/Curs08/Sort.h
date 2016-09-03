#include <iostream>
#include <fstream>
using namespace std;

#define MAX_ARRAY_LENGTH 100

struct vector
{
	int length;
	int values[MAX_ARRAY_LENGTH];
};

void readVector(vector& v)
{
	ifstream fin("Sort.txt");
	fin >> v.length;
	for (int i = 0; i < v.length; i++)
		fin >> v.values[i];
	fin.close();
}

void printVector(vector v,int i,int j)
{
	for (int k = i; k <= j; k++)
		cout << v.values[k] << " ";
	cout << endl;
}
/////////sort
void bubbleSort(vector &v)
{
	int n=v.length,aux,i,ultim;
	while (n>0)
	{
		ultim = n;
		n = 0;
		for (i = 0; i < ultim-1; i++)
		{
			if (v.values[i]>v.values[i + 1])
			{
				aux = v.values[i+1];
				v.values[i + 1] = v.values[i];
				v.values[i] = aux;
				n = i+1;
			}
		}
	}
}
void par_imparSort(vector v)
{
	int i,j;
	for (i = 0; i < v.length; i++)
	{
		if (i % 2 == 0)
			for (j = 0; j < v.length - 1; j=j+2)
				swap(v.values[j],v.values[j+1]);
		if (i%2==1)
			for (j = 1; j < v.length - 1; j=j+2)
				swap(v.values[j], v.values[j + 1]);
	}
}
void insertSort(vector &v)
{
	int i, j, val;
	for (i = 1; i < v.length; i++)
	{
		j = i-1;
		val = v.values[i];
		while (j >= 0 && v.values[j] > val)
		{
			v.values[j + 1] = v.values[j];
			j--;
		}
		if (v.values[j + 1] != val)
			v.values[j + 1] = val;

	}
}
////////mergesort
void interclasare(vector &v, int left, int mid, int right)
{
	int i = left, j = mid + 1;
	vector s;
	s.length = 0;
	while (i <= mid && j <= right)
	{
		if (v.values[i] < v.values[j])
			s.values[s.length++] = v.values[i++];
		else
			s.values[s.length++] = v.values[j++];
	}
	while (i <= mid)
		s.values[s.length++] = v.values[i++];
	while (j <= right)
		s.values[s.length++] = v.values[j++];
	for (i = left; i <= right; i++)
	{
		v.values[i] = s.values[i - left];
	}
}
void mergeSort(vector &v,int left,int right)
{
	if (left < right)
	{
		int m = (left + right) / 2;
		mergeSort(v, left, m);
		mergeSort(v, m + 1, right);
		interclasare(v, left, m, right);

	}
}
////////quicksort
void partitioneaza(vector &v, int left, int right, int& k)
{
	int i, j, x;
	x = v.values[left];
	i = left+1;
	j = right;
	while (i <= j)
	{
		if (v.values[i] <= x)
			i++;
		if (v.values[j] >= x)
			j--;
		if (i<j && v.values[i]>x && x>v.values[j])
		{
			swap(v.values[i], v.values[j]);
			i++;
			j--;
		}
	}
	k = i - 1;
	v.values[left] = v.values[k];
	v.values[k] = x;
}
void quickSort(vector &v, int left, int right)
{
	if (left < right)
	{
		int k;
		partitioneaza(v, left, right,k);
		quickSort(v, left, k - 1);
		quickSort(v,k+1, right);
	}
}
////////heapsort
int parent(int i)
{
	return i / 2;
}
int left(int i)
{
	return 2 * i + 1;
}
int right(int i)
{
	return 2 * i + 2;
}
void maxHeapifyRec(vector &v, int i, int length)
{
	int l = left(i);
	int r = right(i);
	int largest;

	if (l < length && v.values[i] < v.values[l])
		largest = l;
	else largest = i;

	if (r < length && v.values[largest] < v.values[r])
		largest = r;
	
	if (largest != i)
	{
		swap(v.values[i], v.values[largest]);
		maxHeapifyRec(v, largest,length);
	}
}
void maxHeapifyIt(vector &v, int i,int length)
{
	bool heap=0;
	int j,k;
	j = i;
	while (left(j) < length && !heap)
	{
		k = left(j);
		if (k < (length - 1) && v.values[k] < v.values[k + 1])
			k++;
		if (v.values[j] < v.values[k])
		{
			swap(v.values[j], v.values[k]);
			j = k;
		}
		else heap = true;
	}
}
void buildHeap(vector &v)
{
	for (int i = v.length / 2; i >= 0; i--)
	{
		maxHeapifyRec(v,i, v.length);
	}
}
void heapSort(vector &v)
{
	int i, n;
	buildHeap(v);
	n = v.length - 1;
	for (int i = 0; i < v.length; i++)
	{
		swap(v.values[0], v.values[n]);
		n--;
		maxHeapifyRec(v,0,n);
	}
}