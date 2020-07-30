#include <fstream>
#include <iostream>
#include <iomanip>
#include <climits>
/* Ishani Chakraborty
Homework 7
This program reads the file data, then calculates 
and displays the average, the smallest, and the
largest number. The program displays count of 
numbers that are larger than the average number 
and displays the count of numbers thatare smaller
than the average number
*/

using namespace std;
int main()
{
    ifstream in;
    int count = 0; 
    string str; 
    int num; 
    int min = INT_MAX;
    int max = INT_MIN;
    int sum = 0;

    double average; 
    int belowAvg = 0;
    int aboveAvg = 0;

    in.open("numbers.txt"); 
    if (!in) {
        cout << "File numbers.txt does not exist";
       return 0;
    }

    getline(in, str); //read the first line of the file which is a string 
    while (!in.eof()) { //reads - iterates through all integer data until it reaches end of file
        in >> num; 

        if (num > max)
            max = num;

        if (num < min)
            min = num;
        sum = sum + num; 
        count++;
    }

    average = (double) sum / count; //calculates the average
    in.close(); 

    in.open("numbers.txt");
    getline(in, str);
    while (!in.eof()) {
        in >> num; 
        if (num > average)
            aboveAvg++;
        else
            if (num < average)
            belowAvg++;
    }
    in.close();
    
    cout << endl;
    cout << right << setw(25) << "Smallest" << right << setw(20) << min << endl;
    cout << right << setw(25) << "Largest" << right << setw(20) << max << endl;
    cout << right << setw(25) << "Average" << right << setw(20) << average << endl << endl << endl;
    cout << right << setw(25) << "Numbers below the average" << right << setw(20) << belowAvg << endl;
    cout << right << setw(25) << "Numbers above the average" << right << setw(20) << aboveAvg << endl;
    return 0;
}

