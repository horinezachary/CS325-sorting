#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <time.h>
#include <cmath>

using namespace std;

void printArray(int* arr, int arrsize);
int* randomArray(int numelements);
void stoogeSort(int* arr, int start, int end);

int main(){
  int sampleSize = 9;
  int* testValues = new int[sampleSize];  //array of test values
  testValues[0] = 1000;
  testValues[1] = 2000;
  testValues[2] = 3000;
  testValues[3] = 4000;
  testValues[4] = 5000;
  testValues[5] = 6000;
  testValues[6] = 7000;
  testValues[7] = 8000;
  testValues[8] = 9000;
  clock_t* testTimes = new clock_t[sampleSize]; //array of times
  for (int i = 0; i < sampleSize; i++){
    //generate random array
    int* intarr = randomArray(testValues[i]);
    //print num elements
    cout << "Elements: " << testValues[i] << endl;
    //print unsorted list
    printArray(intarr,testValues[i]);
    testTimes[i] = clock();
    stoogeSort(intarr,0,testValues[i]-1);
    testTimes[i] = (((float)clock() - testTimes[i]));
    //print sorted list
    printArray(intarr,testValues[i]);
    //write sorted list to file
    //fileOutput(intarr,testValues[i]);
  }
  //display timing table
  cout << "|| # ELEM. || CLOCK CYCLES " << endl;
  cout << "++---------++--------------" << endl;
  for (int i = 0; i < sampleSize; i++){
    cout << "|| " << testValues[i] << "   || " << testTimes[i] << endl;
  }
}

void printArray(int* arr, int arrsize){ //function to print out an array
  cout << arr[0];
  for (int i = 1; i < arrsize; i++){
    cout << "," << arr[i];
  }
  cout << endl;
}

int* randomArray(int numelements){  //generates an array of random integers between zero and 10000
  int* arr = new int[numelements];
  for (int i = 0; i < numelements; i++){
    arr[i] = rand() % 10000;
    //cout << arr[i] << endl;
  }
  return arr;
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
