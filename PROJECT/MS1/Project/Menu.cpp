/* Citation and Sources...
Final Project Milestone 1:
Module: [Menu]
Filename: Menu.cpp
Version 1.0
Author: Shamar Harmon, StNo: 126746239, Email: sharmon@myseneca.ca
Revision History
-----------------------------------------------------------
Date        Reason
2025/11/05  Completed implementation
-----------------------------------------------------------
I have done all the work myself
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cctype>
#include "constants.h"
#include "Menu.h"

using namespace std;

namespace seneca {

    MenuItem::MenuItem() {
        m_content = nullptr;
        m_numofIndents = 0;
        m_size = 0;
        m_row = 0;
    }

    MenuItem::MenuItem(const char* content, unsigned int indents, unsigned int size, int row) {
        bool invalidContent = false;

        if (content == nullptr || content[0] == '\0') {
            invalidContent = true;
        } else {
            invalidContent = true;
            for (size_t i = 0; content[i] != '\0'; i++) {
                if (!isspace(static_cast<unsigned char>(content[i]))) {
                    invalidContent = false;
                    break;
                }
            }
        }

        if (invalidContent || indents > 4u || size > 4u || row > static_cast<int>(MaximumNumberofMenuItems)) {
            setEmpty();
        } else {
            m_content = new char[strlen(content) + 1];
            strcpy(m_content, content);
            m_numofIndents = indents;
            m_size = size;
            m_row = row;
        }
    }

    MenuItem::~MenuItem() {
        delete[] m_content;
        m_content = nullptr;
    }

    void MenuItem::setEmpty() {
        delete[] m_content;
        m_content = nullptr;
        m_numofIndents = m_size = m_row = 0;
    }

    MenuItem::operator bool() const {
        return (m_content != nullptr && m_content[0] != '\0');
    }

std::ostream& MenuItem::display(std::ostream& ostr) const {
    if (*this) {
        for (size_t i = 0; i < m_numofIndents * m_size; i++) {
            ostr << ' ';
        }

        if (m_row >= 0) {
            ostr.width(2);
            ostr.fill(' ');
            ostr << std::right << m_row << "- ";
        }

        const char* p = m_content;
        while (*p && std::isspace(static_cast<unsigned char>(*p))) {
            ++p;
        }

        ostr << p;
    }
    else {
        ostr << "??????????";
    }

    return ostr;
}

    std::ostream& operator<<(std::ostream& os, const MenuItem& M) {
        M.display();
        return os;
    }

}


