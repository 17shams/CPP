/* Citation and Sources...
Final Project Milestone 5:
Module: [Menu]
Filename: Menu.cpp
Version 1.0
Author: Shamar Harmon, StNo: 126746239, Email: sharmon@myseneca.ca
Revision History
-----------------------------------------------------------
Date        Reason
2025/11/13  Completed implementation
-----------------------------------------------------------
 I have done all the coding by myself and only copied the code
 that my professor provided to complete my work for function whatever.
-----------------------------------------------------------*/
#include "Menu.h"
#include "Utils.h"
#include <iostream>
#include <cstring>
using namespace std;

namespace seneca {

    MenuItem::MenuItem(const char* content, unsigned indent, unsigned size, int row) {
        m_numofIndents = indent;
        m_size = size;
        m_row = row;

        if (content) {
            m_content = new char[strlen(content) + 1];
            strcpy(m_content, content);
        } else {
            m_content = new char[1];
            m_content[0] = '\0';
        }
    }

    MenuItem::~MenuItem() {
        delete[] m_content;
        m_content = nullptr;
    }

    ostream& MenuItem::display(ostream& ostr) const {
        unsigned totalSpaces = m_numofIndents * m_size;
        for (unsigned i = 0; i < totalSpaces; i++) {
            ostr << ' ';
        }

        if (m_row >= 0) {
            ostr.width(2);
            ostr.fill(' ');
            ostr << m_row << "- ";
        }

        ostr << m_content;
        
        
        return ostr;
    }

    Menu::Menu(const char* title, const char* exit, unsigned indents, unsigned size)
        : m_indentNum(indents), m_indentSize(size), m_numofItems(0),
        m_title(title, indents, size, -1),
        m_exit(exit, indents, size, 0),
        m_prompt("> ", indents, size, -1)
    {
        for (unsigned i = 0; i < MaximumNumberOfMenuItems; i++)
            m_items[i] = nullptr;
    }

    Menu::~Menu() {
        for (unsigned i = 0; i < m_numofItems; i++)
            delete m_items[i];
    }

    Menu& Menu::operator<<(const char* text) {
        if (m_numofItems < MaximumNumberOfMenuItems) {
            m_items[m_numofItems] = new MenuItem(
                text,
                m_indentNum,
                m_indentSize,
                m_numofItems + 1
            );
            m_numofItems++;
        }
        return *this;
    }

    size_t Menu::select() const {
        m_title.display() << endl;

        for (unsigned i = 0; i < m_numofItems; i++) {
            m_items[i]->display() << endl;
        }

        m_exit.display() << endl;
        m_prompt.display();

        cin.clear();
        
        return ut.getInt(0, (int)m_numofItems);
    }

    
    size_t operator<<(ostream& ostr, const Menu& m) {
        if (&ostr == &cout) {
            return m.select();
        }
        return 0;
    }
}

