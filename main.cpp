#include <iomanip>
#include <cstdlib>
#include <fstream>
// This program takes a number provided by the user, and then returns a 
// statement declaring whether or not said number is divisible by 9. It
// repeats until the sentinel value 0 is entered, then exits.
// 
// Programmer:    Andrew Coviello
// Homework 9
// Project 1
// Problem Statement: Write a program that reads each item on a grocery 
// list from a text file, then displays that item on the console.
// Then, prepare and write a report of the grocery list onto another text 
// file.
//
// The text file containing the grocery list should be named grocery.txt
// (You can find this file at the bottom of this homework assignment, or 
// make up your own.). Each item on the grocery list should occupy 4 
// lines in the file.
//
// Line 1:  A description of the grocery item, such as "Green Apples", 
// "Orange Juice", or "Soup".  (Notice that the item description can 
// contain blanks.)
// Line 2:  The quantity of the item to purchase (a whole number)
// Line 3:  The estimated price for each item (a real number)
// Line 4:  A unit-of-measure for an item (e.g., "ea.", "lbs.", "pack").
//
// 1. Place the name of the input text file (grocery.txt) in a constant 
// at the top of your program.
// 2. Open the input text file.
// 3. If there is an error opening the file, then print a message and 
// exit the program.
// 4. Use a while loop to read each grocery item on the list.
// 5. Using the getline function, read the description of the grocery 
// item into a string.
// 6. If the read fails (i.e., returns false) exit the loop.
// 7. Using the >> operator, read the quantity of the item to purchase 
// into an  int.
// 8. Using the >> operator, read the estimated unit price into a double.
// 9. Using the getline function, read the unit-of-measure into a string.
// 10. Get rid of the dangling \n between this step and the prior step 
// using another getline statement.
// 11. Display the item description, estimated unit price, 
// unit-of-measure, and quantity on the console.
// 12. When the loop is finished, close the input file.
// 13. Stop the program.
//
#include <iostream>
using namespace std;

int main() {

  // file input stream to receive input 
  ifstream infile;
  // file output stream to receive output
  ofstream outfile;
  int itemCt;
  double price;
  // strings used in reading process
  string itemName, units, itemDesc, val;
  const string FILE_NAME_1 = "grocery.txt";

  // beginning display prompts user for baby name  
  cout << setw(30) << "****** The Grocery File ******\n" << endl;
  // if the sentinel value is entered, exit the program
  // otherwise, prompt the user for the name they'd like to rank
  infile.open(FILE_NAME_1);

  while(getline(infile, itemName) && itemName.length() > 0)
  {
    infile >> itemCt;
    infile >> price;
    // whenever changing the data type that a file reads in, always use
    // infile.ignore() to clear the buffer(and toss \ns)
    infile.ignore();
    getline(infile, units);
    cout << itemName << "\n\n" << itemCt << "\n\n" << price << "\n\n" << units << "\n\n" << endl;
  }
  infile.close();
}
