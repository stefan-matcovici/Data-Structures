#include <iostream>
#include <fstream>
#include "ArboriL.h"
using namespace std;

#define MAX_ARRAY_LENGTH 100

struct vector
{
	int length;
	int values[MAX_ARRAY_LENGTH];
};

void readVector(vector& v)
{
	ifstream fin("Search.txt");
	fin >> v.length;
	for (int i = 0; i < v.length; i++)
		fin >> v.values[i];
	fin.close();
}

void printVector(vector v, int i, int j)
{
	for (int k = i; k <= j; k++)
		cout << v.values[k] << " ";
	cout << endl;
}
int binarySearch(vector v, int x)
{
	int right, left;
	int mid;
	left = 0;
	right = v.length - 1;
	while (left < right)
	{
		mid = (left + right) / 2;
		if (x == v.values[mid])
			return mid;
		else if (x>v.values[mid])
			left = mid + 1;
		else right = mid - 1;
	}
	return -1;
}
NodA* poz(ArbBin t, int x)
{
	NodA* p = t.rad;
	while (p != NULL && p->inf != x)
	{
		if (x < p->inf)
			p = p->stg;
		else
			p = p->drp;
	}
	return p;
}

NodA* treeSearch(NodA* t, int x)
{
	if (t == NULL || t->inf==x)
		return t;
	if (t->inf>x)
		treeSearch(t->stg, x);
	else
		treeSearch(t->drp, x);
}

void treeInsert(ArbBin& t,int x)
{
	if (t.rad == NULL)
		t.rad=newNodA(x);
	else
	{
		NodA *p,*predp;
		predp = nullptr;
		p = t.rad;
		while (p != NULL)
		{
			predp = p;
			if (x < p->inf)
				p=p->stg;
			else
			{
				if (x > p->inf)
					p = p->drp;
				else
					p = NULL;
			}
		}
		if (predp->inf != x)
		{
			if (x < predp->inf)
				predp->stg = newNodA(x);
			else
				predp->drp = newNodA(x);
		}
	}
}
void succesor(NodA* root,NodA*& suc,int key)
{
	if (root == NULL)
		return ;
	if (root->inf == key)
	{
		if (root->drp != NULL)
		{
			NodA* aux = root->drp;
			while (aux->stg != NULL)
				aux = aux->stg;
			suc = aux;
		}
		return;
	}
	if (root->inf > key)
	{
		suc = root;
		succesor(root->stg, suc, key);
	}
	else
		succesor(root->drp, suc, key);
}
void predecesor(NodA* root, NodA*& pre, int key)
{
	if (root == NULL)
		return;
	if (root->inf == key)
	{
		if (root->stg != NULL)
		{
			NodA *aux = root->stg;
			while (aux->drp != NULL)
				aux = aux->drp;
			pre = aux;
		}
		return;
	}

	if (root->inf > key)
		predecesor(root->stg, pre, key);
	else
	{
		pre = root;
		predecesor(root->drp, pre, key);
	}
}
NodA* minValueNode(NodA* root)
{
	NodA* current = root;
	while (current->stg != NULL)
		current = current->stg;
	return current;
}
NodA* treeDelete(NodA *root, int key)
{
	if (root == NULL)
		return root;
	if (root->inf > key)
		root->stg = treeDelete(root->stg, key);
	else if (root->inf <key)
		root->drp= treeDelete(root->drp, key);
	else
	{
		if (root->stg == NULL)
		{
			NodA * temp = root->drp;
			delete(root);
			return temp;
		}
		else if (root->drp == NULL)
		{
			NodA * temp = root->stg;
			delete(root);
			return temp;
		}
		else
		{
			NodA* temp = minValueNode(root->drp);
			root->inf = temp->inf;
			root->drp = treeDelete(root->drp, temp->inf);
		}
	}
	
	return root;
}
bool isBSTUtil(NodA* root, int min, int max)
{
	if (root == NULL)
		return 1;
	if (root->inf<min || root->inf>max)
		return 0;
	return isBSTUtil(root->drp, root->inf + 1, max) && isBSTUtil(root->stg,min,root->inf-1);
}
bool isBST(NodA* root)
{
	return isBSTUtil(root, -1000, 1000);
}
NodA* lca(NodA* root, int n1, int n2)
{
	if (root == NULL)
		return root;
	if (root->inf > n1 && root->inf > n2)
		return lca(root->stg, n1, n2);
	if (root->inf < n1 && root->inf < n2)
		return lca(root->drp, n1, n2);
	return root;
}
void kthLargest(NodA* root, int k, int& count)
{
	if (root != NULL && count <= k)
	{
		kthLargest(root->drp, k, count);
		count++;
		if (count == k)
			cout<< root->inf;
		kthLargest(root->stg, k, count);
	}
}
void range(NodA* root, int k1, int k2)
{
	if (root != NULL)
	{
		if (k1 < root->inf)
			range(root->stg,k1,k2);
		if (k1 < root->inf && root->inf < k2)
			cout << root->inf << " ";
		if (k2 > root->inf)
			range(root->drp, k1, k2);
	}
}
void second(NodA* root, int& count)
{
	if (root != NULL && count<2)
	{
		second(root->drp,count);
		count++;
		if (count == 2)
			cout << root->inf;
		second(root->stg, count);
	}
}
void greater(NodA* root, int& sum)
{
	if (root != NULL)
	{
		greater(root->drp, sum);
		sum = sum + root->inf;
		root->inf = sum-root->inf;
		greater(root->stg, sum);
	}
}
NodA* deleteOfRange(NodA* root, int min, int max)
{
	if (root == NULL)
		return NULL;
	root->stg = deleteOfRange(root->stg, min, max);
	root->drp = deleteOfRange(root->drp, min, max);

	NodA* aux;
	if (root->inf < min)
	{
		if (root->drp != NULL)
		{
			aux = root->stg;
			root = root->drp;
			root->stg = aux;
			return root;
		}
		else if (root->stg != NULL)
		{
			aux = root->drp;
			root = root->stg;
			root->drp = aux;
			return root;
		}
		return NULL;
	}
	else if (root->inf >max)
	{
		if (root->drp != NULL)
		{
			aux = root->stg;
			root = root->drp;
			root->stg = aux;
			return root;
		}
		else if (root->stg != NULL)
		{
			aux = root->drp;
			root = root->stg;
			root->drp = aux;
			return root;
		}
		return NULL;
	}
	return root;
}
int lowerThan(NodA* p, int n)
{
	if (p == NULL)
		return 0;
	if (p->inf < n)
	{
		int left = lowerThan(p->stg, n);
		int right = lowerThan(p->drp, n);
		return left + right + 1;
	}
	return lowerThan(p->stg,n);
}
int greaterThan(NodA* p, int n)
{
	if (p == NULL)
		return 0;
	if (p->inf > n)
	{
		int left = greaterThan(p->stg, n);
		int right = greaterThan(p->drp, n);
		return left + right + 1;
	}
	return greaterThan(p->drp, n);
}