
#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <time.h>


using namespace std;

int* fileInput(int* size);
void fileOutput(int* arr, int arrsize);
void printArray(int* arr, int arrsize);
int* randomArray(int numelements);
void insertionSort(int* arr, int arrsize);

int main(){
  int sampleSize = 10;
  int* testValues = new int[sampleSize];  //array of test values
  testValues[0] = 5000;
  testValues[1] = 10000;
  testValues[2] = 15000;
  testValues[3] = 20000;
  testValues[4] = 25000;
  testValues[5] = 30000;
  testValues[6] = 35000;
  testValues[7] = 40000;
  testValues[8] = 45000;
  testValues[9] = 50000;
  for (int i = 0; i < sampleSize; i++){
    //generate random array
    int* intarr = randomArray(testValues[i]);
    //print num elements
    cout << "Elements: " << testValues[i] << endl;
    //print unsorted list
    printArray(intarr,testValues[i]);
    testTimes[i] = clock();
    insertionSort(intarr,testValues[i]);
    //print sorted list
    printArray(intarr,testValues[i]);
    //write sorted list to file
    //fileOutput(intarr,testValues[i]);
  }
}

void printArray(int* arr, int arrsize){ //function to print out an array
  cout << arr[0];
  for (int i = 1; i < arrsize; i++){
    cout << "," << arr[i];
  }
  cout << endl;
}
int* fileInput(int* intarrsize){ //takes in a file and outputs the array inside, as well as the number of elements
  int* intarr;
  int intcounter = 0;

  ifstream inFile;  //set up the file reader and attempt to read the file
  inFile.open("data.txt");
  if (!inFile) {  //make sure the file exists
    cout << "Unable to open data.txt";
    exit(1);   // EXIT PROGRAM
  }
  char* xarr = new char[10];
  char x;
  int xcounter = 0;
  bool first = true;
  while (inFile >> x) { //open the file and read every character
    xarr[xcounter] = x; //add the character read to the buffer
    xcounter++;
    if (inFile.peek() < 48 || inFile.peek() > 57){  //check to see if the next character is a space, if so, terminate the number
      int newnum = atoi(xarr);  //convert the read characters into an integer
      if (first){ //Check if this is the first number, and then set up the array
        first = false;
        intarr = new int[newnum];
        intarrsize[0] = newnum;
      }
      else {  //Add the new number to the integer array
        intarr[intcounter] = newnum;
        intcounter++;
      }
      xarr = new char[10];  //wipe the input array
      xcounter = 0;
    }
  }
  inFile.close(); //Close the file

  return intarr;
}
void fileOutput(int* arr, int arrsize){ //outputs an array to a file
  ofstream outfile;
  outfile.open("insert.out");
  if (!outfile) {  //make sure the file exists
    cout << "Unable to open insert.out";
    exit(1);   // EXIT PROGRAM
  }
  outfile << arr[0];  //write first number
  for (int i = 1; i < arrsize; i++){  //write the rest of the values, with a space before them
    outfile << " " << arr[i];
  }
  outfile << endl;  //terminate the string
  outfile.close();  //close the file
}
int* randomArray(int numelements){  //generates an array of random integers between zero and 10000
  int* arr = new int[numelements];
  for (int i = 0; i < numelements; i++){
    arr[i] = rand() % 10000;
    //cout << arr[i] << endl;
  }
  return arr;
}
void insertionSort(int* arr, int arrsize){
  int i = 1;
  while (i < arrsize){  //step through array and sort each value
    int j = i;
    while (j > 0 && arr[j-1] > arr[j]){ //walk through array with one value and move it down into place
      int temp = arr[j];
      arr[j] = arr[j-1];
      arr[j-1] = temp;
      j--;
    }
    i++;
  }
}
