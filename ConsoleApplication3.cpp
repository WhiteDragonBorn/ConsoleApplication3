#include <fstream>
#include <iostream>

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
  BigInt FirstNumber(temp);
  cout << FirstNumber.toString() << endl;


  std::getline(FILE, temp);
  BigInt SecondNumber(temp);
  cout << SecondNumber.toString() << endl;

  //cout << endl << int(FirstNumber > SecondNumber) << endl;
  //cout << endl << int(FirstNumber < SecondNumber) << endl;
  //cout << endl << int(FirstNumber >= SecondNumber) << endl;
  //cout << endl << int(FirstNumber <= SecondNumber) << endl;


  BigInt Summa(tes);
  Summa = (FirstNumber + SecondNumber);
  cout << "Sum: " << Summa.toString() << endl;


  if (FirstNumber < SecondNumber) {
    cout << "Underflow, no substraction available." << endl;
  } else {
    BigInt Razn(tes);
    Razn = (FirstNumber - SecondNumber);
    cout << "Dif: " << Razn.toString();
  }


  FILE.close();
}
