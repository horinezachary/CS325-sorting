#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <stdlib.h>
#include <cmath>
#include <vector>

using namespace std;

vector<int*> fileInput(int* intarrsize);
void fileOutput(vector<int*> intarrarr, int* arrsize);
void printArray(int* arr, int arrsize);
void stoogeSort(int* arr, int start, int end);

int main(){
  int* intarrsize = new int[20]; //storage for sizes of arrays
  vector<int*> intarrarr = fileInput(intarrsize); //get vector containing arrays to be sorted
  cout << intarrarr.size()<<endl;
  for (int arrnum = 0; arrnum < intarrarr.size(); arrnum++){  //complete sort for each array
    //print num elements
    cout << "Elements: " << intarrsize[arrnum] << endl;

    //print unsorted list
    printArray(intarrarr.at(arrnum),intarrsize[arrnum]);

    stoogeSort(intarrarr.at(arrnum),0,intarrsize[arrnum]-1);

    //print sorted list
    printArray(intarrarr.at(arrnum),intarrsize[arrnum]);
  }
  //write sorted lists to file
  fileOutput(intarrarr,intarrsize);
}

void printArray(int* arr, int arrsize){ //takes in one array, and prints out all of the elements
  cout << arr[0];
  for (int i = 1; i < arrsize; i++){
    cout << "," << arr[i];
  }
  cout << endl;
}
vector<int*> fileInput(int* intarrsize){
  vector<int*> intarrarr;

  ifstream inFile;  //set up the file reader and attempt to read the file
  inFile.open("data.txt");
  if (!inFile) {  //make sure the file exists
    cout << "Unable to open data.txt";
    exit(1);   // EXIT PROGRAM
  }
  string line;
  while(getline(inFile,line)){ //gets one line
    stringstream lineStream(line);
    string cell;
    vector<string> parsedRow;
    while(getline(lineStream,cell,' ')){  //parses line and puts numbers into string vector
      parsedRow.push_back(cell);
    }
    int* temp = new int[stoi(parsedRow.at(0))]; //set length of array
    intarrsize[intarrarr.size()] = stoi(parsedRow.at(0)); //save length of array
    for (int i = 1; i < parsedRow.size(); i++){ //add rest of values to the array
      temp[i-1] = stoi(parsedRow.at(i));
    }
    intarrarr.push_back(temp);  //push the array onto the array vector
  }
  return intarrarr;
}
void fileOutput(vector<int*> intarrarr, int* arrsize){
  ofstream outfile;
  outfile.open("stooge.out");
  if (!outfile) {  //make sure the file exists
    cout << "Unable to open insert.out";
    exit(1);   // EXIT PROGRAM
  }
  for (int arrnum = 0; arrnum < intarrarr.size(); arrnum++){  //print all of the arrays available
    outfile << intarrarr.at(arrnum)[0];  //write first number
    for (int i = 1; i < arrsize[arrnum]; i++){  //write the rest of the values, with a space before them
      outfile << " " << intarrarr.at(arrnum)[i];
    }
    outfile << endl;  //terminate the string
  }
  outfile.close();  //close the file
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
