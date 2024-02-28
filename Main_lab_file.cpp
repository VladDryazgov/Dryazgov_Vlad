#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <chrono>
#include <fstream>
#include "data.csv"
using namespace std;
int sumsearch(int arr[], unsigned long long size, int key){
    for (int i=size-1; i>-1;i--){
        if(i==1){return -1;}
for(int j = 0; j< i;j++){
    if(arr[i]+arr[j]==key){return i+j;}
}
    }
}
int smartsumsearch(int arr[], unsigned long long size, int key)
{
    int i = 0;
    int j = size - 1;
    int f = 0;
    while (f == 0)
    {
        if (arr[i] + arr[j] > key)
        {
            j -= 1;
        }
        if (arr[i] + arr[j] < key)
        {
            i += 1;
        }
        if (arr[i] + arr[j] == key)
        {
            return i + j;
        }
         if (i == j)
        {
            return -1;
        }
    }
    return -100;
}

int linsearch(int arr[], unsigned long long size, int key)
{
    for (int i = 0; i < size; i++)
        if (arr[i] == key)
            return i;
    return -1;
}
int binsearch(int arr[], unsigned long long size, int val)
{
    int l = 0, r = size - 1;

    while (r > l)
    {
        int m = (l + r) / 2; 

        if (arr[m] < val)
        {
            l = m + 1;
        }
        else if (arr[m] > val)
        {
            r = m - 1;
        }
        else
        {
            return m;
        }
    }
    if (arr[l] == val)
    {
        return l;
    }
    else
    {
        return -1;
    }
}

int main()
{
    std::srand(std::time(nullptr));
    fstream fout;
    //fout.open("data.csv", ios::out | ios::trunc);
    //fout.close();
    fout.open("data.csv", ios::out);
    int ver = 3; //with that you control the version of the task (1-lin,2-bin,3-silly sum,4-smart sum)
    int rand = 0;//with that you control either use average case or the worst (1-avg, anything except that - worst)
    for (unsigned long long j = 100; j < 100000; j += 1000)
    {

        unsigned long long size = j;
        int * arr = new int[size];

        for (int i = 0; i < size; i++)
        {
           if(ver == 1 || ver == 3){ arr[i] = std::rand();}
           else{arr[i] = i;}
        }
        int u;
        if (rand == 1){ u = std::rand();}
        else{ u = -1;}
        auto begin = chrono::steady_clock::now();
        if (ver==1){int k = linsearch(arr, size, u);}
        if (ver==2){int k = binsearch(arr, size, u);}
        if (ver==3){int k = sumsearch(arr, size, u);}
        if (ver==4){int k = smartsumsearch(arr, size, u);}
        auto end = chrono::steady_clock::now();

        auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
        auto t = elapsed_ms.count();

        fout << size << "; " << t << endl;
    }
    fout.close();
}
