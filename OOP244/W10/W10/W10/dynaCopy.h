/* Citation and Sources...
-----------------------------------------------------------
Workshop 10
Module: dynaCopy
Filename: dynaCopy.h
-----------------------------------------------------------
Author: Shamar Harmon
Student number: 126746239
Email: sharmon@myseneca.ca
Subject: OOP244 NBB
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V0.7    2025/11/23  Completing .h file
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------
*/
#ifndef SENECA_DYNACOPY_H
#define SENECA_DYNACOPY_H
#include <iostream>

namespace seneca {

    template <typename T, typename U>
    T* dynaCopy(const T* a, U b) {
        T* c = nullptr;

        if (a != nullptr) {
            c = new T[b];
            for (U i = 0; i < b; i++) {
                c[i] = a[i];
            }
        }
        return c;
    }

    template <typename T, typename U>
    T* dynaCopy(T*& a, const T* b, U c) {
        delete[] a;
        a = nullptr;

        if (b != nullptr) {
            a = new T[c];
            for (U i = 0; i < c; i++) {
                a[i] = b[i];
            }
        }
        return a;
    }

    template <typename T, typename U>
    void prnArray(const T* a, U b) {
        for (U i = 0; i < b; i++) {
            std::cout << a[i];
            if (i < b - 1) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
    }

}

#endif // !SENECA_DYNACOPY_H
