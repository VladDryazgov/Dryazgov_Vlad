#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <chrono>
#include <fstream>
using namespace std;
void swap(int* arr, int i, int j) {
    // Swap elements at indices i and j using a temporary variable
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;}
void output(int arr[]){swap(arr,1,2);
    for (int i=1;i<6;i++){cout<<arr[i];}}

int main()
{

    int size = 5;
        int *arr = new int[size];
    for (int i=1;i<6;i++){arr[i]=i;}

    output(arr);
}