/* Citation and Sources...
Final Project Milestone 2:
Module: [Menu]
Filename: Menu.cpp
Version 1.0
Author: Shamar Harmon, StNo: 126746239, Email: sharmon@myseneca.ca
Revision History
-----------------------------------------------------------
Date        Reason
2025/11/13  Completed implementation
-----------------------------------------------------------
 All work done by myself
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>
#include "constants.h"
#include "Menu.h"
#include "Utils.h"

namespace seneca {


    MenuItem::MenuItem(const char* content, unsigned int indents, unsigned int size, int row) {
        if (indents > 3u) indents = 0;
        if (row < -1 || row > (int)MaximumNumberOfMenuItems) row = -1;
        
        if (content) {
            m_content = new char[strlen(content) + 1];
            strcpy(m_content, content);
        } else {
            m_content = new char[1];
            m_content[0] = '\0';
        }
        m_numofIndents = indents;
        m_size = size;
        m_row = row;
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
        return (m_content != nullptr);
    }

    std::ostream& MenuItem::display(std::ostream& ostr) const {
        if (m_content != nullptr && !(m_row == -1 && m_content[0] == '\0')) {

            size_t indent = m_numofIndents * m_size;

            if (m_row >= 0 && indent >= 9) {
                indent--;
            }

            for (size_t i = 0; i < indent; i++) {
                ostr << ' ';
            }

            if (m_row >= 0) {
                ostr.width(2);
                ostr.fill(' ');
                ostr << std::right << m_row << "- ";
            }

            ostr << m_content;
        }
        else {
            ostr << "??????????";
        }
        return ostr;
    }

    Menu::Menu(const char* title, const char* exit, unsigned int indentNum, unsigned int indentSize)
        : m_indentNum(indentNum)
        , m_indentSize(indentSize)
        , m_numofItems(0)
        , m_title(title, indentNum, indentSize, -1)
        , m_exit(exit, indentNum, indentSize, 0)
        , m_prompt("> ", indentNum, indentSize, -1)
    {
        if (title == nullptr) {
            m_indentNum++;
            m_indentSize = 3;

            m_title.~MenuItem();
            new (&m_title) MenuItem("", m_indentNum, m_indentSize, -1);
        }

        for (unsigned i = 0; i < MaximumNumberOfMenuItems; i++)
            m_items[i] = nullptr;
    }
       
        Menu::~Menu(){
            for (unsigned i = 0; i < MaximumNumberOfMenuItems; i++){
              delete m_items[i];
              m_items[i] = nullptr;
            }
        }
       
    Menu& Menu::operator<<(const char* menuItemcontent){
        if (m_numofItems < MaximumNumberOfMenuItems){
            unsigned row = m_numofItems + 1;
            
            m_items[m_numofItems] = new MenuItem(menuItemcontent,
                                                 m_indentNum,
                                                 m_indentSize,
                                                 row);
            m_numofItems++;
        }
        return *this;
    }

    size_t Menu::select() const {
        
        if (m_title.m_content && m_title.m_content[0] != '\0') {
            m_title.display() << std::endl;
        }
        for (unsigned i = 0; i < m_numofItems; i++) {
            if (m_items[i] != nullptr) {
                m_items[i]->display() << std::endl;
            }
        }
        MenuItem exitItem(m_exit.m_content, m_indentNum, m_indentSize, 0);
        exitItem.display() << std::endl;
        
        m_prompt.display();
        
        Utils u;
        int userChoice = u.getInt(0, m_numofItems);
        return userChoice;
    }

    size_t operator<<(std::ostream& ostr, const Menu& m){
        
        if (&ostr == &std::cout){
             return m.select();
        } else {
            return 0;
        }
    }

}


