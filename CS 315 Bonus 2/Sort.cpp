#include "Sort.h"
#include <fstream>
#include <cstdlib>
#include <ctime>

void insertion_sort(vector<int>& vec, int& comparisons) // sort the integers in the vector using insertion sort
{
	for (int i = 0; i < vec.size(); i++) //loop over the vector
	{
		int k = i; // set k to the current iteration #
		while (k >0 && vec[k] < vec[k-1]) // loop so long as k is not 0 and the current kth value is less than the previous
		{
			comparisons++;
			int temp = vec[k]; // swap the kth and kth-1 elements
			vec[k] = vec[k - 1];
			vec[k - 1] = temp;
			k--; // decrement k
		}
	}
}

void selection_sort(vector<int>& vec, int& comparisons)
{
	for (int i = 0; i < vec.size(); i++) // loop over the vector 
	{
		int min = i; // set min index to the current iteration #
		for (int j = i + 1; j < vec.size(); j++) // loop over the i+1 to end of list elements
		{
			comparisons++;
			if (vec[j] < vec[min])// find the current min
			{
				min = j;
			}
		}
		
		if (min != i) //swap if the min and i are different
		{
			int temp = vec[i];
			vec[i] = vec[min];
			vec[min] = temp;
		}
	}
}

int partition(vector<int>& vec, int left, int right, int& comparisons)
{
	int pivot_index = left + rand() % (right - left + 1); // pick a random value as the pivot
	int pivot = vec[pivot_index]; // find the value at the pivot index
	int temp = vec[pivot_index];
	vec[pivot_index] = vec[right];  //swap the values at the right and pivot indices
	vec[right] = temp;
	pivot_index = right;

	int i = left - 1;
	for (int j = left; j <= right - 1; j++)
	{
		comparisons++;
		if (vec[j] <= pivot) // compare the value at j to the pivot
		{
			i++;
			int temp = vec[i]; // swap i and j if vec[j] is <= the pivot
			vec[i] = vec[j];
			vec[j] = temp;
		}
	}

	temp = vec[i + 1]; // swap the values at the pivot index and at the ith+1 index
	vec[i + 1] = vec[pivot_index];
	vec[pivot_index] = temp;
	return i + 1; // return the value where this swap occured
}
void quicksort(vector<int>& vec, int left, int right, int& comparisons)
{
	if (left < right) // base case 
	{
		int middle = partition(vec, left, right, comparisons); // set the middle to i +1 value returned from partition
		quicksort(vec, left, middle - 1, comparisons); // do quicksort on the left half of the list
		quicksort(vec, middle + 1, right, comparisons); //do quicksort on the right half of the list
	}
}


void display() //display the choices for sorting
{

	cout << "1. Insertion Sort " << endl;
	cout << "2. Selection Sort " << endl;
	cout << "3. Quicksort " << endl;
	cout << "4. Mergesort " << endl;
	cout << "Enter any other key to quit " << endl;
}

void merge_sort(vector<int>& vec, int left, int right, int& comparisons)
{
	int middle;
	if (left < right)
	{
		middle = (left + right) / 2;
		merge_sort(vec, left, middle,comparisons);
		merge_sort(vec, middle + 1, right,comparisons);
		merge(vec, left, middle, right,comparisons);
	}
}
void merge(vector<int>& vec, int left, int middle, int right, int& comparisons)
{
	int k;
	vector<int> vec2(vec.size());
	int h = left;
	int i = left;
	int j = middle + 1;

	while ((h <= middle) && (j <= right))
	{
		comparisons++;
		if (vec[h] <= vec[j])
		{
			vec2[i] = vec[h];
			h++;
		}
		else
		{
			vec2[i] = vec[j];
			j++;
		}
		i++;
	}
	comparisons++;
	if (h > middle)
	{
		for (k = j; k <= right; k++)
		{
			vec2[i] = vec[k];
			i++;
		}
	}
	else
	{
		for (k = h; k <= middle; k++)
		{
			vec2[i] = vec[k];
			i++;
		}
	}
	for (k = left; k <= right; k++)
		vec[k] = vec2[k];
}

void print(vector<int> vec) // display the contents of the vector
{
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
}

void shuffle(vector<int>& vec) // shuffle the vector
{ 
	srand(time(0)); // seed the RNG
	for (int i = vec.size() - 1; i >= 1; i--)
	{
		int j = rand() % (i + 1); // pick a random index from those still in the list
		int temp = vec[i]; // swap this random index with the current index
		vec[i] = vec[j];
		vec[j] = temp;
	}
}