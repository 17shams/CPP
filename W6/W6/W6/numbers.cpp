/* Citation and Sources...
-----------------------------------------------------------
Workshop 6
Module: Numbers
Filename: Numbers.cpp
-----------------------------------------------------------
Author: Shamar Harmon
Student number: 126746239
Email: sharmon@myseneca.ca
Subject: OOP244
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V0.7    2025/11/01  Completing some implementation
V1.0    2025/11/02  Finished implementation
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include "Numbers.h"

using namespace std;

namespace seneca {

    int Numbers::numberCount() const {
        ifstream file(m_filename);
        int count = 0;
        char ch;
        while (file.get(ch)) {
            if (ch == '\n') count++;
        }
        return count;
    }

    bool Numbers::loadCount() {
        bool ok = false;
        if (m_numCount > 0) {
            m_numbers = new double[m_numCount];
            ifstream file(m_filename);
            int i = 0;
            while (file && i < m_numCount) {
                file >> m_numbers[i];
                if (file) i++;
            }
            if (i != m_numCount) {
                delete[] m_numbers;
                m_numbers = nullptr;
                setEmpty();
                ok = false;
            } else {
                ok = true;
            }
        }
        return ok;
    }

    void Numbers::saveCount() {
        if (m_isOriginal && !isEmpty()) {
            ofstream file(m_filename);
            for (int i = 0; i < m_numCount; i++) {
                file << m_numbers[i] << endl;
            }
        }
    }

    Numbers::~Numbers() {
        saveCount();
        delete[] m_numbers;
        delete[] m_filename;
    }

    Numbers::Numbers(const Numbers& src) {
        setEmpty();
        m_isOriginal = false;
        *this = src; 
    }

    Numbers& Numbers::operator=(const Numbers& src) {
        if (this != &src) {
            delete[] m_numbers;
            m_numbers = nullptr;
            delete[] m_filename;
            m_filename = nullptr;

            if (!src.isEmpty()) {
                m_numCount = src.m_numCount;
                m_numbers = new double[m_numCount];
                for (int i = 0; i < m_numCount; i++) {
                    m_numbers[i] = src.m_numbers[i];
                }
                if (src.m_filename) {
                    m_filename = new char[strlen(src.m_filename) + 1];
                    strcpy(m_filename, src.m_filename);
                }
            } else {
                setEmpty();
            }
        }
        return *this;
    }

    Numbers& Numbers::operator+=(double value) {
        if (!isEmpty()) {
            double* temp = new double[m_numCount + 1];
            for (int i = 0; i < m_numCount; i++) {
                temp[i] = m_numbers[i];
            }
            temp[m_numCount++] = value;

            delete[] m_numbers;
            m_numbers = temp;
            sort();
        }
        return *this;
    }

    ostream& Numbers::display(ostream& ostr) const {
        if (isEmpty()) {
            ostr << "Empty list";
        } else {
            ostr.setf(ios::fixed);
            ostr.precision(2);
            ostr << "=========================" << endl;
            if (m_isOriginal)
                ostr << m_filename << endl;
            else
                ostr << "*** COPY ***" << endl;

            for (int i = 0; i < m_numCount; i++) {
                ostr << m_numbers[i];
                if (i < m_numCount - 1) ostr << ", ";
            }
            ostr << endl << "-------------------------" << endl;
            ostr << "Total of " << m_numCount << " number(s)" << endl;
            ostr << "Largest number:  " << max() << endl;
            ostr << "Smallest number: " << min() << endl;
            ostr << "Average:         " << average() << endl;
            ostr << "=========================";
        }
        return ostr;
    }

    ostream& operator<<(ostream& os, const Numbers& N) {
        return N.display(os);
    }

    istream& operator>>(istream& is, Numbers& N) {
        double val;
        if (is >> val) {
            N += val;
        }
        return is;
    }
}

