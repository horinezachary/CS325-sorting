# CS325-sorting
4)	(10 pts) Merge Sort and Insertion Sort Programs   
Implement merge sort and insertion sort to sort an array/vector of integers.  Implement your algorithms in C++ and name your programs “mergesort.cpp” and “insertsort.cpp”.  Your programs should compile with the commands g++ mergesort.cpp and g++ insertsort.cpp.  Both programs should read inputs from a file called “data.txt” where the first value of each line is the number of integers that need to be sorted, followed by the integers.
Example values for data.txt: \n
	 	4 19 2 5 11  \n
	 	8 1 2 3 4 5 6 1 2 \n
The output will be written to files called “merge.out” and “insert.out”.
For the above example the output would be:\n
	 	2 5 11 19\n
	 	1 1 2 2 3 4 5 6  \n

To receive full credit all code must be commented.

Submit a copy of your insertsort.cpp and mergesort.cpp in a ZIP file to TEACH.  We will test execution with an input file named data.txt.

5)	(10 pts) Merge Sort vs Insertion Sort Running time analysis
a)	Modify code- Now that you have verified that your code runs correctly using the data.txt input file, you can modify the code to collect running time data.  Instead of reading arrays from the file data.txt and sorting, you will now generate arrays of size n containing random integer values from 0 to 10,000 to sort.  Use the system clock to record the running times of each algorithm for n = 5000, 10000, 15000, 20,000, ….  You may need to modify the values of n if an algorithm runs too fast or too slow to collect the running time data. Output the array size n and time to the terminal.  Name these new programs insertTime and mergeTime.   

Submit a copy of the timing programs to TEACH in the Zip file from problem 4, also include a “text” copy of the modified timing code in the written HW submitted in Canvas.

b)	Collect running times - Collect your timing data on the engineering server. You will need at least seven values of t (time) greater than 0.  If there is variability in the times between runs of the same algorithm you may want to take the average time of several runs for each value of n.  Create a table of running times for each algorithm.
c)	Plot data and fit a curve - For each algorithm plot the running time data you collected on an individual graph with n on the x-axis and time on the y-axis.  You may use Excel, Matlab, R or any other software.  What type of curve best fits each data set?  Give the equation of the curves that best “fits” the data and draw that curves on the graphs.
d)	Combine - Plot the data from both algorithms together on a combined graph.  If the scales are different you may want to use a log-log plot.
e)	Comparison - Compare your experimental running times to the theoretical running times of the algorithms?  Remember, the experimental running times were the “average case” since the input arrays contained random integers.
EXTRA CREDIT: A Tale of Two Algorithms: It was the best of times, it was the worst of times…
  Generate best case and worst case inputs for the two algorithms and repeat the analysis in parts b) to e) above.  To receive credit you must discuss how you generated your inputs and your results.  Submit your code to TEACH in a zip file with the code from Problem 4 & 5.
