#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <stdlib.h>
using namespace std;
void printArray(int* arr, int arrsize);
void printArray(int* arr, int arrsize){ //takes in one array, and prints out all of the elements
  cout << arr[0];
  for (int i = 1; i < arrsize; i++){
    cout << "," << arr[i];
  }
  cout << endl;
}
