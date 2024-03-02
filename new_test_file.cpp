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
    arr[j] = temp;
}

int linsearch(int ind[],int arr[], unsigned long long size, int key,int strat)
{
    for (int i = 0; i < size; i++)
        if (arr[i] == key)
            {
                if(strat == 1 && i!=0){swap(arr,0,i);}
                if(strat == 2 && i!=0){swap(arr,i,i-1);}
                if(strat == 3 ){ind[i]+=1;
                    if(i!=0 && ind[i]>ind[i-1]){swap(arr,i,i-1);swap(ind,i,i-1);}
                    }
                
                return i;}
    return -1;
}
int binsearch(int ind[],int arr[], unsigned long long size, int val,int strat)
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
        {               if(strat == 1 && m!=0){swap(arr,0,m);}
                if(strat == 2 && m!=0){swap(arr,m,m-1);}
                if(strat == 3 ){ind[m]+=1;
                    if(m!=0 && ind[m]>ind[m-1]){swap(arr,m,m-1);swap(ind,m,m-1);}
                    }
            return m;
        }
    }
    if (arr[l] == val)
    {
        if(strat == 1 && l!=0){swap(arr,0,l);}
                if(strat == 2 && l!=0){swap(arr,l,l-1);}
                if(strat == 3 ){ind[l]+=1;
                    if(l!=0 && ind[l]>ind[l-1]){swap(arr,l,l-1);swap(ind,l,l-1);}
                    }
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
    // fout.open("data.csv", ios::out | ios::trunc);
    // fout.close();
    fout.open("data.csv", ios::out);
    int ver = 2;  // with that you control the version of the task (1-lin,2-bin,3-silly sum,4-smart sum)
    int rand = 0; // with that you control either use chosen case or random(1-chosen,0-random)
    for (int y=0;y<4;y++){
        int strat = y;
    int ran[] = {std::rand(),std::rand(),std::rand(),std::rand()};
    for (unsigned long long j = 10; j < 1000000000; j *= 2)
    {

        unsigned long long size = j;
        int *arr = new int[size];
        int *ind = new int[size];
        for (int i = 0; i < size; i++)
        {ind[i]=0;}
        for (int i = 0; i < size; i++)
        {
            if (ver == 1)
            {
                arr[i] = std::rand();
            }
            else
            {
                arr[i] = i;
            }
        }



        int u;
        if(rand==1){u=ran[std::rand()%4];}
        else{u=std::rand();}
        
        long long w = 0;
        for (int k =0;k<6001;k++){
        if(rand==1){u=ran[std::rand()%4];}
        else{u=std::rand();}
        auto begin = chrono::high_resolution_clock::now();
        if (ver == 1)
        {
            int k = linsearch(ind,arr, size, u,strat);
        }
        if (ver == 2)
        {
            int k = binsearch(ind,arr, size, u,strat);
        }
        auto end = chrono::high_resolution_clock::now();

        auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
        auto t = elapsed_ms.count();
        if(k>5000){w+=t;}
        }
        long long t = w/1000;

        fout << size << "; " << t << endl;
    }}
    fout.close();
}
