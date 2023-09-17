#include <fstream>
#include <iostream>
#include <string>

#include "BigInt.h"
#include "functions.h"

using std::cout;
using std::endl;

int main(int argc, char* argv[]) {
  std::ifstream FILE;
  FILE.open("mydata.txt");

  std::string tes = "0";

  std::string temp;
  std::getline(FILE, temp);
  // cout << temp.length();
  // if (temp.length() == 0 || temp[0] == '-') {
  //   cout << "Wrong input!";
  //   exit(1);
  // }

  // cout << temp;
  BigInt FirstNumber(temp);
  // cout << endl << Length(FirstNumber) << endl;
  //  cout << temp;
  cout << FirstNumber.toString();
  cout << endl;
  //Print(FirstNumber);
  // cout << temp;
  

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
  //Print(SecondNumber);
  cout << SecondNumber.toString();
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
  cout << Summa.toString();
  //Print(Summa);
  cout << endl;

  if (FirstNumber < SecondNumber) {
    cout << "Underflow, no substraction available." << endl;
  } else {
    cout << "Difference: ";
    BigInt Razn = FirstNumber - SecondNumber;
    cout << Razn.toString();
    cout << endl;
  }

  // cout << endl << toString(Summa) << endl;

  // Print(FirstNumber);

  FILE.close();
}
