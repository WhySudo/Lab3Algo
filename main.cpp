#include <iostream>
#include <windows.h>
#include "sort.h"

using namespace std;
double PCFreq = 0.0;
__int64 CounterStart = 0;
void StartCounter()
{
    LARGE_INTEGER li;
    if (!QueryPerformanceFrequency(&li))
        cout << "Performance test failed" << endl;

    PCFreq = double(li.QuadPart) / 1000.0;

    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}
double GetCounter()
{
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart - CounterStart) / PCFreq;
}
const int repeatsTest = 10000;
const int maxSize = 100;

void fillTestArray(int* array,int requiredSize){
    for(int i = 0; i < requiredSize; i++){
        //array[i] = i; // best case
        //array[i] = rand()%maxSize;//random array
        array[i] = maxSize - i;//worst case
    }
}

int main() {
    int *array = (int*)malloc(sizeof(int)*100);
    double insertSortTime = 0.0;
    double quickSortTime = 0.0;
    double sortTime = 0.0;
    for(int i = 1; i < maxSize; i++){
        insertSortTime = 0.0;
        quickSortTime = 0.0;
        sortTime = 0.0;
        for (int k = 0; k < repeatsTest; k++)
        {
            fillTestArray(array, i);
            StartCounter();
            sort(array, array - 1 + i, [](int a, int b) { return a < b; }, false);
            quickSortTime += GetCounter();
        }
        for (int k = 0; k < repeatsTest; k++)
        {
            fillTestArray(array, i);
            StartCounter();
            insertion_sort(array, array - 1 + i, [](int a, int b) { return a < b; });
            insertSortTime += GetCounter();
        }
        for (int k = 0; k < repeatsTest; k++)
        {
            fillTestArray(array, i);
            StartCounter();
            sort(array, array - 1 + i, [](int a, int b) { return a < b; });
            sortTime += GetCounter();
        }
        cout << i << ";" << insertSortTime << ";" << quickSortTime<<";" << sortTime << ";" <<endl;
    }
    free(array);
    return 0;
}
