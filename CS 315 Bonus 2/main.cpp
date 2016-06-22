//Christopher Will
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
		vec.push_back(input); // add the input to the vector
		cin >> input;
	}
	cout << endl;

	int user_in;
	cout << "Please enter the integer value associated with the sorting algorithm you wish to use :" << endl;
	display();
	cin >> user_in;
	if (user_in == 1) // sort using insertion sort
	{
		cout << "Vector before sorting " << endl;
		print(vec);
		insertion_sort(vec, comparisons);
		cout << "Vector after using Insertion Sort" << endl;
		print(vec);
	}

	else if (user_in == 2) //sort using selection sort
	{
		cout << "Vector before sorting " << endl;
		print(vec);
		selection_sort(vec, comparisons);
		cout << "Vector after using Selection Sort" << endl;
		print(vec);
	}
	else if (user_in == 3) // sort using quicksort
	{
		cout << "Vector before sorting " << endl;
		print(vec);
		quicksort(vec, 0, vec.size() - 1, comparisons);
		cout << "Vector after using Quicksort " << endl;
		print(vec);
	}
	else // sort using mergesort
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
			int comparisons = 0; // have not made any comparisons in the algorithm yet
			vector<int> vec; // vector to store the descending numbers
			for (int k = n; k >= 1; k--)
				vec.push_back(k); // add the numbers to the vector in descending order

			if (i == 0) //use insertion sort
			{
				insertion_sort(vec, comparisons);
				cout << "Insertion Sort made " << comparisons << " comparisons" << endl;
			}
			else if (i == 1) //use selection sort
			{
				selection_sort(vec, comparisons);
				cout << "Selection Sort made " << comparisons << " comparisons" << endl;
			}

			else if (i == 2) //use quicksort
			{
				quicksort(vec, 0, vec.size() - 1, comparisons);
				cout << "Quicksort made " << comparisons << " comparisons" << endl;
			}
			else //use mergesort
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
		for (int i = 1; i <= 4; i++) //sort method will depend on the value of i 
		{
			vector<int> vec; // vector to store the random numbers to be sorted
			vector<int> compare_vec; // vector to keep track of the comparisons made
			for (int k = 1; k <= n; k++)
				vec.push_back(k); // add n numbers to the vector in ascending order
			for (int j = 1; j <= 20; j++) // will randomly shuffle the vector 20 times
			{
				srand(time(0)); //seed the RNG
				int comparisons = 0;
				shuffle(vec); //randomly shuffle the vectors contents
				if (i == 1) //use insertion sort
				{
					insertion_sort(vec, comparisons);
					compare_vec.push_back(comparisons);
				}
				else if (i == 2) //use selection sort
				{
					selection_sort(vec, comparisons);
					compare_vec.push_back(comparisons);
				}
				else if (i == 3) //use quicksort
				{
					quicksort(vec, 0, vec.size() - 1, comparisons);
					compare_vec.push_back(comparisons);
				}
				else //use mergesort
				{
					merge_sort(vec, 0, vec.size() - 1, comparisons);
					compare_vec.push_back(comparisons);
				}
			}
			int sum = 0; //int to hold the number of comparisons made 
			for (int i = 0; i < 20; i++) // find total # of comparisons for the 20 shuffles
			{
				sum += compare_vec[i]; //add the # of comparisons made for the ith iteration to the sume
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
		n *= 2; //double the value of n until it is > 6400
	}

	system("pause");
	return 0;
}
