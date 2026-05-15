/* Citation and Sources...
-----------------------------------------------------------
Workshop 9
Module: Transcript
Filename: Transcript.cpp
-----------------------------------------------------------
Author: Shamar Harmon
Student number: 126746239
Email: sharmon@myseneca.ca
Subject: OOP244 NBB
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V0.7    2025/11/20  Completing .cpp file
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------
*/
#include <iostream>
#include <cstring>
#include "Transcript.h"
#include "Utils.h"
 
using namespace std;
 
namespace seneca {
   
    Transcript::Transcript(const char* stuName, unsigned int stuNum) : Marks() {
        m_stuNum = stuNum;
        m_stuName = nullptr;
       
        if (stuName != nullptr) {
            m_stuName = new char[strlen(stuName) + 1];
            strcpy(m_stuName, stuName);
        } else {
            m_stuName = nullptr;
        }
    }
   
    void Transcript::init(const Transcript& T){
        m_stuNum = T.m_stuNum;
       
        if (T.m_stuName != nullptr) {
            m_stuName = new char[strlen(T.m_stuName) + 1];
            strcpy(m_stuName, T.m_stuName);
        } else {
            m_stuName = nullptr;
        }
    }
    Transcript::Transcript(const Transcript& T) : Marks(T) {
        init(T);
    }
   
    Transcript& Transcript::operator=(const Transcript& T){
        if (this != &T) {
            (Marks&)*this = T;
            delete[] m_stuName;
            init(T);
        }
        return *this;
    }
   
    Transcript::~Transcript(){
        delete[] m_stuName;
        m_stuName = nullptr;
    }
   
    std::ostream& Transcript::display(std::ostream& ostr)const{
    ostr << m_stuName << " (" << m_stuNum << ")" << endl;
        ostr << "--------------------------------------------------------------------------" << endl;
       
    Marks::display(ostr);
        return ostr;
    }
}

