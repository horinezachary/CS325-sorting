vector<int*> fileInput(int* intarrsize){
  vector<int*> intarrarr;
  int arrctr = 0;
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
    if ((inFile.peek() < 48 || inFile.peek() > 57) && inFile.peek() != '\n'){  //check to see if the next character is a space, if so, terminate the number
      int newnum = atoi(xarr);  //convert the read characters into an integer
      if (first){ //Check if this is the first number, and then set up the array
        first = false;
        intarr = new int[newnum];
        intarrsize[arrctr] = newnum;
      }
      else {  //Add the new number to the integer array
        intarr[intcounter] = newnum;
        intcounter++;
      }
      xarr = new char[10];  //wipe the input array
      xcounter = 0;
    }
    else if (inFile.peek() == '\n'){
      cout << "newline" << endl;
      first = true;
      printArray(intarr,intarrsize[arrctr]);
      intarrarr.push_back(intarr);
      arrctr++;
    }
  }
  inFile.close(); //Close the file
  return intarrarr;
}
