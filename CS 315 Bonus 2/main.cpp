//Christopher Will
// CS315 Bonus 2
// 4/18/2016

//Program may be executed by pressing F5
// Program will ask for integers until a non-integer value is input. Then it will ask which of the 4 sorting methods to use
// to sort these numbers. It will then proceed with using each of the 4 sorting algorithms for ascending and descending sequences
// of integers. Then it will find the average number of comparisons made for different values of n when the n integers
// are shuffled.

#include<ctime>
#include "Sort.h"
#include<iostream>
using namespace std;
int main()
{
	int comparisons; // int to keep track of # of comparisons made
	vector<int> vec; // vector to store the integers to be sorted
	srand(time(0));// seed the RNG
	int input;
	cout << "Please enter the integers to be sorted (one on each line). Type any non-integer input to quit" << endl;
	cin >> input;
	while (true)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(256, '\n');
			break;
		}
		vec.push_back(input);
		cin >> input;
	}
	cout << endl;

	int user_in;
	cout << "Please enter the integer value associated with the sorting algorithm you wish to use :" << endl;
	display();
	cin >> user_in;
	if (user_in == 1)
	{
		cout << "Vector before sorting " << endl;
		print(vec);
		insertion_sort(vec, comparisons);
		cout << "Vector after using Insertion Sort" << endl;
		print(vec);
	}

	else if (user_in == 2)
	{
		cout << "Vector before sorting " << endl;
		print(vec);
		selection_sort(vec, comparisons);
		cout << "Vector after using Selection Sort" << endl;
		print(vec);
	}
	else if (user_in == 3)
	{
		cout << "Vector before sorting " << endl;
		print(vec);
		quicksort(vec, 0, vec.size() - 1, comparisons);
		cout << "Vector after using Quicksort " << endl;
		print(vec);
	}
	else
	{
		cout << "Vector before sorting " << endl;
		print(vec);
		merge_sort(vec, 0, vec.size() - 1, comparisons);
		cout << "Vector after using Mergesort" << endl;
		print(vec);
	}


	int n = 100;
	while (n <= 6400) // set n to 100 and double it at the end of each iteration
	{
		cout << "************* Comparisons made for n = " << n << " in descending order *************" << endl;
		for (int i = 0; i < 4; i++) // sort the n # for each of the 4 algorithms
		{
			int comparisons = 0;
			vector<int> vec;
			for (int k = n; k >= 1; k--)
				vec.push_back(k);

			if (i == 0)
			{
				insertion_sort(vec, comparisons);
				cout << "Insertion Sort made " << comparisons << " comparisons" << endl;
			}
			else if (i == 1)
			{
				selection_sort(vec, comparisons);
				cout << "Selection Sort made " << comparisons << " comparisons" << endl;
			}

			else if (i == 2)
			{
				quicksort(vec, 0, vec.size() - 1, comparisons);
				cout << "Quicksort made " << comparisons << " comparisons" << endl;
			}
			else
			{
				merge_sort(vec, 0, vec.size() - 1, comparisons);
				cout << "Mergesort made " << comparisons << " comparisons" << endl;
			}
		}
		cout << endl;
		n *= 2; // double n and continue until n > 6400
	}

	n = 100;
	while (n <= 6400) // do the same as above, but now the integers are inserted in ascending order
	{
		cout << "************* Comparisons made for n = " << n << " in ascending order *************" << endl;
		for (int i = 0; i < 4; i++)
		{
			int comparisons = 0;
			vector<int> vec;
			for (int k = 1; k <= n; k++)
				vec.push_back(k);
			if (i == 0)
			{
				insertion_sort(vec, comparisons);
				cout << "Insertion Sort made " << comparisons << " comparisons" << endl;
			}
			else if (i == 1)
			{
				selection_sort(vec, comparisons);
				cout << "Selection Sort made " << comparisons << " comparisons" << endl;
			}

			else if (i == 2)
			{
				quicksort(vec, 0, vec.size() - 1, comparisons);
				cout << "Quicksort made " << comparisons << " comparisons" << endl;
			}
			else
			{
				merge_sort(vec, 0, vec.size() - 1, comparisons);
				cout << "Mergesort made " << comparisons << " comparisons" << endl;
			}
		}
		cout << endl;
		n *= 2;
	}

	n = 100;
	while (n <= 6400) // add n ints to the vector, shuffle it and keep track of the # of comparisons made. Do this 20 times and
		// find the avg # of comparisons for each of the 4 sorting algorithms
	{
		for (int i = 1; i <= 4; i++)
		{
			vector<int> vec;
			vector<int> compare_vec; // vector to keep track of the comparisons made
			for (int k = 1; k <= n; k++)
				vec.push_back(k);
			for (int j = 1; j <= 20; j++)
			{
				srand(time(0));
				int comparisons = 0;
				shuffle(vec);
				if (i == 1)
				{
					insertion_sort(vec, comparisons);
					compare_vec.push_back(comparisons);
				}
				else if (i == 2)
				{
					selection_sort(vec, comparisons);
					compare_vec.push_back(comparisons);
				}
				else if (i == 3)
				{
					quicksort(vec, 0, vec.size() - 1, comparisons);
					compare_vec.push_back(comparisons);
				}
				else
				{
					merge_sort(vec, 0, vec.size() - 1, comparisons);
					compare_vec.push_back(comparisons);
				}
			}
			int sum = 0;
			for (int i = 0; i < 20; i++) // find total # of comparisons for the 20 shuffles
			{
				sum += compare_vec[i];
			}
			if (i == 1)
				cout << "For n = " << n << " & using Insertion Sort we had an average of " << sum / 20 << " comparisons" << endl;
			else if (i == 2)
				cout << "For n = " << n << " & using Selection Sort we had an average of " << sum / 20 << " comparisons" << endl;
			else if (i == 3)
				cout << "For n = " << n << " & using Quicksort we had an average of " << sum / 20 << " comparisons" << endl;
			else
				cout << "For n = " << n << " & using Mergesort we had an average of " << sum / 20 << " comparisons" << endl;
		}
		cout << endl;
		n *= 2;
	}

	system("pause");
	return 0;
}