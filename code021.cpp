#include<iostream>
using namespace std;

int main()
{
	int a[] = { 1,2,3,45,80 };

	cout << "List of arrays\n";

	for (int i = 0; i < sizeof(a) / sizeof a[0]; i++)
	{
		cout << a[i] << endl;
	}
	return 0;
}