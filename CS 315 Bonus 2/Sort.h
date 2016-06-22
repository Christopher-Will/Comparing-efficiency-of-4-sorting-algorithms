// Define all the functions to be used in this project in a header file

#ifndef SORT_H
#define SORT_H

#include<iostream>
using namespace std;
#include <vector>

void insertion_sort(vector<int>& vec, int& comparisons);
void selection_sort(vector<int>& vec, int& comparisons);
int partition(vector<int>& vec, int left, int right,int& comparisons);
void quicksort(vector<int>& vec, int left, int right,int& comparisons);
void display();
void merge_sort(vector<int>& vec, int low, int high, int& comparisons);
void merge(vector<int>& vec, int low, int mid, int high, int& comparisons);
void print(vector<int> vec);
void shuffle(vector<int>& vec);
#endif
