
#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>


using namespace std;

int* fileInput(int* size);
void fileOutput(int* arr, int arrsize);
void mergeSort(int* arr, int min, int max);
void merge(int* arr, int min, int mid, int max);
void printArray(int* arr, int arrsize);
int main(){
  int* intarrsize = new int[1];
  int* intarr = fileInput(intarrsize);

  //print num elements
  cout << "Elements: " << intarrsize[0] << endl;

  //print unsorted list
  printArray(intarr,intarrsize[0]);

  mergeSort(intarr,0,intarrsize[0]);

  //print sorted list
  printArray(intarr,intarrsize[0]);
  //write sorted list to file
  fileOutput(intarr,intarrsize[0]);
}

void printArray(int* arr, int arrsize){
  cout << arr[0];
  for (int i = 1; i < arrsize; i++){
    if (arr[i] == NULL){
      cout << "," << "N";
    }
    else{
      cout << "," << arr[i];
    }
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
  outfile.open("merge.out");
  if (!outfile) {  //make sure the file exists
    cout << "Unable to open merge.out";
    exit(1);   // EXIT PROGRAM
  }
  outfile << arr[0];  //write first number
  for (int i = 1; i < arrsize; i++){  //write the rest of the values, with a space before them
    outfile << " " << arr[i];
  }
  outfile << endl;  //terminate the string
  outfile.close();  //close the file
}
void mergeSort(int* arr, int min, int max){
  if (max - min > 1){
    int mid = (min+max)/2;
    mergeSort(arr,min,mid);
    mergeSort(arr,mid,max);
    merge(arr,min,mid,max);
  }
}

void merge(int* arr, int min, int mid, int max){
  int* temp = new int[max-min];
  int left_low = min;
  int right_low = mid;
  int count;
  for (count = 0; left_low < mid && right_low < max; count++){
    if (arr[left_low] > arr[right_low]){
      temp[count] = arr[right_low];
      right_low++;
    }
    else{
      temp[count] = arr[left_low];
      left_low++;
    }
  }
  while(left_low < mid){
    temp[count] = arr[left_low];
    count++;
    left_low++;
  }
  while(right_low < max){
    temp[count] = arr[right_low];
    count++;
    right_low++;
  }
  for(int i = 0; i < max-min; i++){
    arr[min+i] = temp[i];
  }
  delete[] temp;
}
