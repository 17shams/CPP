/* Citation and Sources...
Final Project Milestone 5:
Module: [Drink]
Filename: Drink.cpp
Version 1.0
Author: Shamar Harmon, StNo: 126746239, Email: sharmon@myseneca.ca
Revision History
-----------------------------------------------------------
Date        Reason
2025/11/18  Completed .cpp implementation
-----------------------------------------------------------
 I have done all the coding by myself and only copied the code
 that my professor provided to complete my work for function whatever.
-----------------------------------------------------------*/
#include <iostream>
#include <fstream>
#include <cstring>
#include "Drink.h"
#include "Utils.h"
 
using namespace std;

namespace seneca {

    std::ifstream& Drink::read(std::ifstream& file){
        
        char temp[26]{};
        double tempPrice{};

            file.getline(temp, 25, ',');
            if (!file) {
                file.setstate(std::ios::failbit);
                return file;
            }

            file >> tempPrice;
            if (!file) {
                file.setstate(std::ios::failbit);
                return file;
            }

            file.ignore(1000, '\n');
            
            if (temp[0] != '\0' && temp[0] != ' ') {
                
                Billable::name(temp);
                Billable::price(tempPrice);
                m_size = '\0';

            } else {
                file.setstate(std::ios::failbit);
            }
        return file;
    }

   
    ostream& Drink::print(ostream& ostr)const{
        
    // Name
        ostr.width(28);
        ostr.fill('.');
        ostr.setf(ios::left, ios::adjustfield);
        ostr << (const char*)*this;
        ostr.unsetf(ios::adjustfield);
       
    //Size
        if (!ordered()){
            ostr << ".....";
        } else {
            switch (m_size) {
            case 'S':
                ostr << "SML..";
                break;
            case 'M':
                ostr << "MID..";
                break;
            case 'L':
                ostr << "LRG..";
                break;
            case 'X':
                ostr << "XLR..";
                break;
            }
        }
        
    //Price
        ostr.width(7);
        ostr.fill(' ');
        ostr.setf(ios::right, ios::adjustfield);
        ostr.setf(ios::fixed, ios::floatfield);
        ostr.precision(2);
        ostr << price();
        ostr.unsetf(ios::adjustfield);
 
    return ostr;
    }

    bool Drink::order(){

        int choice{};

        // Title
        cout << "         Drink Size Selection\n";

        // Options
        cout << "          1- Small\n";
        cout << "          2- Medium\n";
        cout << "          3- Larg\n";
        cout << "          4- Extra Large\n";
        cout << "          0- Back\n";

        // Prompt
        cout << "         > ";
        
        choice = ut.getInt(0, 4);
        
        switch (choice) {
        case 1 :
            m_size = 'S';
                break;
        case 2:
            m_size = 'M';
                break;
        case 3:
            m_size = 'L';
                break;
        case 4:
            m_size = 'X';
                break;
            case 0:
                m_size = '\0';
                return false;
        }
        return true;
    }

    bool Drink::ordered()const{
        if (m_size == 'S' || m_size == 'M' || m_size == 'L' || m_size == 'X'){
            return true;
        } else {
            return false;
        }
    }

    double Drink::price() const{
        if (!ordered()){
            return Billable::price();
        }
            switch (m_size) {
                case 'S':
                    return Billable::price() * 0.5;
                case 'M':
                    return Billable::price() * 0.75;
                case 'L':
                return Billable::price();
                case 'X':
                    return Billable::price() * 1.25;
            }
        return Billable::price();
    }
}
