/* Citation and Sources...
-----------------------------------------------------------
Workshop 7
Module: Main
Filename: main.cpp
-----------------------------------------------------------
Author: Shamar Harmon
Student number: 126746239
Email: sharmon@myseneca.ca
Subject: OOP244 NBB
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V0.7    2025/11/09  No changes
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------
*/

#include <iostream>
#include <fstream>
#include "Professor.h"
using namespace std;
using namespace seneca;

void prnProf();

int main() {
   cout << "Workshop 7 tester Version 1.1.\nCorrected the order of data in console entery test\n"
                                           "==================================================" << endl;
   Professor P( "Edna Krabappel", "OOP345 - Object-Oriented Software Development Using C++", 3, 11222, 76543.0 );
   P.title() << endl;
   P.write() << endl;
   cout << "Enter the following:" << endl;
   cout << "John Doe, 12312, 65432,IPC144 - Introduction to Programming Using C,3<ENTER>\n> ";
   cin >> P;
   cin.ignore( 1000, '\n' );
   cout << "You enterd:" << endl;
   P.title() << endl;
   cout << P << endl;
   prnProf();
   return 0;
}
void prnProf() {
   ifstream file("professors.csv");
   Professor P;
   cout << "List of professors in file!" << endl;
   P.title() << endl;
   while (file) {
      P.read(file).ignore(1000, '\n');
      if (file) cout << P << endl;
   }
}
