
#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>


using namespace std;

int* fileInput(int* size);
void fileOutput(int* arr, int arrsize);
void printArray(int* arr, int arrsize);
void insertionSort(int* arr, int arrsize);

int main(){
  int* intarrsize = new int[1];
  int* intarr = fileInput(intarrsize);

  //print num elements
  cout << "Elements: " << intarrsize[0] << endl;

  //print unsorted list
  printArray(intarr,intarrsize[0]);

  insertionSort(intarr,intarrsize[0]);

  //print sorted list
  printArray(intarr,intarrsize[0]);
  //write sorted list to file
  fileOutput(intarr,intarrsize[0]);
}

void printArray(int* arr, int arrsize){
  cout << arr[0];
  for (int i = 1; i < arrsize; i++){
    cout << "," << arr[i];
  }
  cout << endl;
}
int* fileInput(int* intarrsize){
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
void fileOutput(int* arr, int arrsize){
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

void insertionSort(int* arr, int arrsize){
  int i = 1;
  while (i < arrsize){  //step through array and sort each value
    int j = i;
    while (j > 0 && arr[j-1] > arr[j]){ //alk through array with one value and move it down into place
      int temp = arr[j];
      arr[j] = arr[j-1];
      arr[j-1] = temp;
      j--;
    }
    i++;
  }
}
