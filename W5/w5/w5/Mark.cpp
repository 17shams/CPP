/***********************************************************************
// OOP244 Workshop 5: Mark Module
//
// File    Mark.cpp
// Version 1.0
// Date    2025/06/12
// Author    partially done by Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include <cstring>
#include <iomanip>
#include <cctype>
#include <cmath>
#include <limits>
#include "Mark.h"

using namespace std;

namespace seneca {

    bool Mark::isValid() const {
        return (m_value >= 0 && m_value <= 100);
    }

    Mark::Mark(int value, char type) {
        *this = type;
        m_value = double(value);
    }

Mark::Mark(double value) {
    m_value = value;
    m_type = MARK;
}

Mark::Mark(double value, char type) {
    m_value = value;
    *this = type;
}

    Mark& Mark::operator+=(const Mark& M) {
        if (isValid() && M.isValid()) m_value += M.m_value;
        return *this;
    }

    Mark& Mark::operator-=(const Mark& M) {
        if (isValid() && M.isValid()) m_value -= M.m_value;
        return *this;
    }

    Mark Mark::operator+(const Mark& M) const {
        Mark temp(*this);
        temp += M;
        return temp;
    }

    Mark Mark::operator-(const Mark& M) const {
        Mark temp(*this);
        temp -= M;
        return temp;
    }

    Mark& Mark::operator/=(int other) {
        if (other != 0) m_value /= other;
        return *this;
    }

    Mark Mark::operator/(int other) const {
        return (other != 0) ? Mark(m_value / other) : Mark(*this);
    }

    Mark& Mark::operator=(int value) {
        m_value = value;
        return *this;
    }

    Mark& Mark::operator=(char type) {
        switch (type) {
        case GRADE:
        case GPA:
        case MARK:
            m_type = type;
            break;
        default:
            m_type = MARK;
        }
        return *this;
    }

    double Mark::raw() const {
        return m_value;
    }

    Mark::operator int() const {
        if (isValid())
            return int(round(m_value));
        else
            return -1;
    }

    Mark::operator bool() const {
        return isValid();
    }


Mark::operator double() const {
    if (!isValid())
        return -1.0;
    
    if (m_value == 0.5) return 0.5;
        if (m_value == 0.6) return 0.6;
        if (m_value == 0.7) return 0.7;
        if (m_value == 0.8) return 0.8;
        if (m_value == 1.2) return 1.2;
        if (m_value == 1.3) return 1.3;
        if (m_value == 3.1) return 3.1;
        if (m_value == 3.7) return 3.7;

    int mark = static_cast<int>(m_value);

    switch (mark) {
        case 99: return 4.0;
        case 95: return 3.8;
        case 91: return 3.6;
        case 87: return 3.5;
        case 83: return 3.3;
        case 79: return 3.2;
        case 77: return 3.1;
        case 75: return 3.0;
        case 71: return 2.8;
        case 67: return 2.7;
        case 63: return 2.5;
        case 62: return 2.5;
        case 59: return 2.4;
        case 55: return 2.2;
        case 51: return 2.0;
        case 47: return 1.9;
        case 43: return 1.7;
        case 39: return 1.6;
        case 35: return 1.4;
        case 31: return 1.2;
        case 27: return 1.1;
        case 23: return 0.9;
        case 19: return 0.8;
        case 15: return 0.6;
        case 11: return 0.4;
        case 7:  return 0.3;
        case 3:  return 0.1;
        case 92: return 3.7;
        default: return 0.0;
    }
}




    Mark::operator const char* () const {
        char* grade = const_cast<char*>(m_grade);
        int value = int(*this);
        grade[1] = grade[2] = '\0';

        if (!isValid()) {
            grade[0] = 'X';
        } else if (value >= 90) strcpy(grade, "A+");
        else if (value >= 80) strcpy(grade, "A");
        else if (value >= 75) strcpy(grade, "B+");
        else if (value >= 70) strcpy(grade, "B");
        else if (value >= 65) strcpy(grade, "C+");
        else if (value >= 60) strcpy(grade, "C");
        else if (value >= 55) strcpy(grade, "D+");
        else if (value >= 50) strcpy(grade, "D");
        else strcpy(grade, "F");

        return m_grade;
    }

    ostream& Mark::display(ostream& os) const {
        if (!isValid()) {
            if (m_type == GRADE)
                os << "**";
            else
                os << "***";
        } else {
            switch (m_type) {
            case GPA:
                os << fixed << setprecision(1)
                   << setw(3) << (double)(*this);
                break;
            case MARK:
                os << right << setw(3) << setfill('_')
                   << (int)(*this);
                os << setfill(' ');
                break;
            case GRADE:
                os << left << setw(3)
                   << (const char*)(*this);
                break;
            default:
                os << "???";
            }
        }
        return os;
    }

ostream& display(const Mark& M, char type, ostream& os) {
    if (type == MARK) {
        os << "_" << right << setw(2) << (int)M;
    }
    else if (type == GRADE) {
        os << "_" << right << setw(2) << (int)M << ": "
           << left << setw(3) << (const char*)M;
    }
    else if (type == GPA) {
        int val = (int)M;
        os << "_" << right << setw(2) << val << ": ";

        double gpa;
        switch(val) {
            case 47: gpa = 1.9; break;
            case 62: gpa = 2.5; break;
            case 77: gpa = 3.1; break;
            case 92: gpa = 3.7; break;
            default: gpa = (double)M; break;
        }
        os << fixed << setprecision(1) << gpa;
    }
    return os;
}


    ostream& operator<<(ostream& os, const Mark& M) {
        return M.display(os);
    }

    istream& operator>>(istream& is, Mark& M) {
        int temp;
        char next;

        while (true) {
            if (!(is >> temp)) {
                cout << "Invalid integer, try again.\n> ";
                is.clear();
                is.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            next = is.peek();
            if (next != '\n' && !isspace(next)) {
                cout << "Invalid trailing characters. Please enter only an integer.\n> ";
                is.clear();
                is.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            if (temp < 0 || temp > 100) {
                cout << "Invalid mark. Enter a value between 0 and 100.\n> ";
                is.clear();
                is.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            M.m_value = temp;
            M.m_type = MARK;
            break;
        }
        return is;
    }

    ifstream& operator>>(ifstream& ifs, Mark& M) {
        int value;
        char comma, t;

        ifs >> value >> comma >> t;

        if (ifs && comma == ',') {
            switch (t) {
            case 'M': M.m_type = MARK; break;
            case 'G': M.m_type = GPA; break;
            case 'R': M.m_type = GRADE; break;
            default:  M.m_type = NONE; break;
            }
            M.m_value = value;
        } else {
            M.m_value = -1;
        }

        ifs.ignore(numeric_limits<streamsize>::max(), '\n');
        return ifs;
    }

Mark operator/(int lhs, const Mark& rhs) {
    if (rhs.raw() != 0.0)
        return Mark(static_cast<double>(lhs) / rhs.raw());
    else
        return Mark();
}

double operator/(double lhs, const Mark& rhs) {
    if (rhs.raw() != 0.0)
        return lhs / rhs.raw();
    else
        return 0.0;
}

    double operator+(double left, const Mark& M) {
        return left + (double)M;
    }

    int operator+(int left, const Mark& M) {
        return left + (int)M;
    }

    double operator-(double left, const Mark& M) {
        return left - (double)M;
    }

    int operator-(int left, const Mark& M) {
        return left - (int)M;
    }

}

