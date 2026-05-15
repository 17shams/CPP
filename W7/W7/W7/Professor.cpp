/* Citation and Sources...
-----------------------------------------------------------
Workshop 7
Module: Professor
Filename: Professor.cpp
-----------------------------------------------------------
Author: Shamar Harmon
Student number: 126746239
Email: sharmon@myseneca.ca
Subject: OOP244 NBB
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V0.7    2025/11/09  Completing .cpp file
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------
*/

#include <iostream>
#include <cstring>
#include "Professor.h"
#include "Employee.h"
#include "Utils.h"

using namespace std;

namespace seneca {

    Professor::Professor() {
        m_subject = nullptr;
        m_numSections = 0;
    }

    Professor::Professor(const char* name, const char* subject, int numSections, size_t empNum, double salary)
        : Employee(name, empNum, salary)
    {
        if (subject && subject[0] != '\0') {
            m_subject = new char[strlen(subject) + 1];
            strcpy(m_subject, subject);
        } else {
            m_subject = nullptr;
        }
        m_numSections = numSections;
    }

    Professor::~Professor() {
        delete[] m_subject;
        m_subject = nullptr;
    }

    double Professor::devPay() const {
        return salary() * 0.01 * m_numSections;
    }

std::istream& Professor::read(std::istream& istr) {
    Employee::read(istr);

    while (istr.peek() == ',' || istr.peek() == ' ' || istr.peek() == '\n' || istr.peek() == '\r') {
        istr.ignore();
    }

    delete[] m_subject;
    m_subject = nullptr;

    char buffer[1024]{};

    istr.getline(buffer, 1024, ',');
    if (buffer[0] == '\0' && !istr.eof()) {
        istr.clear();
        istr.getline(buffer, 1024, '\n');
    }
    if (buffer[0] != '\0') {
        ut.alocpy(m_subject, buffer);
    }
    while (istr.peek() == ' ') {
        istr.ignore();
    }
    istr >> m_numSections;
    return istr;
}


std::ostream& Professor::write(std::ostream& ostr) const {
    Employee::write(ostr);

    char subj2print[21]{};
    if (m_subject) {
        ut.strcpy(subj2print, m_subject, 20);
    }

    ostr << " ";
    ostr.setf(std::ios::left);
    ostr.width(20);
    ostr.fill(' ');
    ostr << subj2print;
    ostr.unsetf(std::ios::left);

    ostr << " | ";
    ostr.setf(std::ios::right);
    ostr.width(5);
    ostr << m_numSections;
    ostr.unsetf(std::ios::right);

    ostr << " | ";
    ostr.setf(std::ios::fixed);
    ostr.precision(2);
    ostr.width(8);
    ostr << devPay();
    ostr.unsetf(std::ios::fixed);

    ostr << " |";

    return ostr;
}


    std::ostream& Professor::title(std::ostream& ostr) const {
        Employee::title(ostr);
        return ostr << "  Teaching Subject    | Sec # | $Dev Pay |";
    }


    std::ostream& operator<<(std::ostream& ostr, const Professor& P) {
        return P.write(ostr);
    }

    std::istream& operator>>(std::istream& istr, Professor& P) {
        return P.read(istr);
    }

}
