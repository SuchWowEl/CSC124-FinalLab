#include <bits/stdc++.h>
using namespace std;


// Driver method to test map class
int main()
{

	// Linear ---------------------------------------------------------------------------
	HashMap<int, int> *h = new HashMap<int, int>;
	int probeCountTotal = 0;

	cout << "Inserting and counting how many probes are done in each insert:" << endl;

	probeCountTotal += h->insertNode(25, 2021);
	probeCountTotal += h->insertNode(88, 2000);
	probeCountTotal += h->insertNode(3, 2011);
	probeCountTotal += h->insertNode(38, 2012);
	probeCountTotal += h->insertNode(20, 2009);
	probeCountTotal += h->insertNode(71, 2002);
	probeCountTotal += h->insertNode(55, 2003);
	// probeCountTotal += h->insertNode(55, 2017);
	probeCountTotal += h->insertNode(56, 2015);
	probeCountTotal += h->insertNode(50, 2007);
	probeCountTotal += h->insertNode(105, 2023);

	cout << endl;

	cout << "Total probes: " << probeCountTotal;

	h->display();
	cout << endl
		 << "----------------------------------------------------" << endl;

	// Quadratic ---------------------------------------------------------------------------

	int arr[] = {25, 88, 3, 38, 20, 71, 55, 56, 50, 105};
	int N = 10;

	// Size of the hash table
	int L = 17;
	int hash_table[17];

	// Initializing the hash table
	for (int i = 0; i < L; i++)
	{
		hash_table[i] = -1;
	}

	// Function call
	hashing_quadratic(hash_table, L, arr, N);
	cout << endl
		 << endl;

	// Double ------------------------------------------------------------------------------

	// Set all values to -1
	for (int i = 0; i < L; i++)
	{
		hash_table[i] = -1;
	}
	hashing_double(hash_table, L, arr, N);

	return 0;
}
