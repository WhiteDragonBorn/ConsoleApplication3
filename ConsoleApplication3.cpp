#include <fstream>
#include <iostream>
#include <string>

#include "header.h"

using namespace std;

int main(int argc, char* argv[]) {
  ifstream FILE;
  FILE.open("mydata.txt");

  string tes = "0";

  string temp;
  getline(FILE, temp);
  // cout << temp.length();
  // if (temp.length() == 0 || temp[0] == '-') {
  //   cout << "Wrong input!";
  //   exit(1);
  // }

  // cout << temp;
  BigInt FirstNumber(temp);
  // cout << endl << Length(FirstNumber) << endl;
  //  cout << temp;
  Print(FirstNumber);
  // cout << temp;
  cout << endl;

  // BigInt test(FirstNumber);
  // Print( test );
  // cout << endl << Length(FirstNumber) << endl;

  getline(FILE, temp);
  // if (temp.length() == 0 || temp[0] == '-') {
  //   cout << "Wrong input!" << endl;
  //   exit(1);
  // }

  // cout << temp;

  BigInt SecondNumber(temp);
  // cout << endl << Length(SecondNumber) << endl;
  Print(SecondNumber);
  cout << endl;
  // cout << "reached";

  // cout << endl << int(FirstNumber > SecondNumber) << endl;
  // cout << endl << int(FirstNumber < SecondNumber) << endl;
  // cout << endl << int(FirstNumber >= SecondNumber) << endl;
  // cout << endl << int(FirstNumber <= SecondNumber) << endl;

  // cout << endl << Length(SecondNumber);

  // FirstNumber += SecondNumber;
  cout << "Sum: ";
  BigInt Summa = FirstNumber + SecondNumber;
  Print(Summa);
  cout << endl;

  if (FirstNumber < SecondNumber) {
    cout << "Underflow, no substraction available." << endl;
  } else {
    cout << "Difference: ";
    BigInt Razn = FirstNumber - SecondNumber;
    Print(Razn);
    cout << endl;
  }

  // cout << endl << toString(Summa) << endl;

  // Print(FirstNumber);

  FILE.close();
}
