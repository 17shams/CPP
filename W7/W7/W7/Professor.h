/* Citation and Sources...
-----------------------------------------------------------
Workshop 7
Module: Professor
Filename: Professor.h
-----------------------------------------------------------
Author: Shamar Harmon
Student number: 126746239
Email: sharmon@myseneca.ca
Subject: OOP244 NBB
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V0.7    2025/11/09  Completing .h file
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------
*/
#ifndef SENECA_PROFESSOR_H
#define SENECA_PROFESSOR_H
#include <iostream>
#include "Employee.h"

namespace seneca {

    class Professor : public Employee {
        char* m_subject{};
        int m_numSections{};
    public:
        Professor();
        Professor(const char* name, const char* subject, int numSections, size_t empNum, double salary);
        ~Professor();

        double devPay() const;

        std::istream& read(std::istream& istr = std::cin);
        std::ostream& write(std::ostream& ostr = std::cout) const;
        std::ostream& title(std::ostream& ostr = std::cout) const;
    };

    std::ostream& operator<<(std::ostream& ostr, const Professor& P);
    std::istream& operator>>(std::istream& istr, Professor& P);

}

#endif // !SENECA_PROFESSOR_H
