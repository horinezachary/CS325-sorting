#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <cmath>
using namespace std;

void printArray(int* arr, int arrsize);
void stoogeSort(int* arr, int start, int end);
void printArray(int* arr, int arrsize){ //function to print out an array
  cout << arr[0];
  for (int i = 1; i < arrsize; i++){
    cout << "," << arr[i];
  }
  cout << endl;
}
void stoogeSort(int* arr, int start, int end){
  if (arr[start] > arr[end]){ //if there are two values left, make sure they are in order
    //cout << "SWAP!" << endl;
    int temp = arr[end];
    arr[end] = arr[start];
    arr[start] = temp;
  }
  if (end-start+1 > 2){ //set 2/3 point
    int m = ceil((end-start+1)/3);
    stoogeSort(arr,start,end-m);  //run on lower 2/3
    stoogeSort(arr,start+m,end);  //run on upper 2/3
    stoogeSort(arr,start,end-m);  //run on lower 2/3 (again)
  }
}
