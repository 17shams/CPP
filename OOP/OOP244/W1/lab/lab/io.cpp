//
//  io.cpp
//  lab
//
//  Created by shams on 2025-09-13.
//
#include <iomanip>
#include <cstring>
#include <iostream>
#include "io.h"


using namespace std;

namespace seneca {

void read() {
    char name[15];
    cout << "Name" << endl;
    cout << "> ";
    cin >> name;
}

bool read(PhoneRec& rec, FILE* fp){
    return fscanf(fp, "%s %s %lld", rec.firstName, rec.lastName, &rec.phoneNumber) == 3;
}


void print(long long phoneNumber){
    long areaCode, mid3numbers, last4Numbers;
    
    last4Numbers=phoneNumber%10000;
    mid3numbers=(phoneNumber/10000)%1000;
    areaCode = phoneNumber / 10000000;
    
    cout << "(" << areaCode << ") "
    << setw(3) << setfill('0') << mid3numbers << "-"
    << setw(4) << setfill('0') << last4Numbers
    << endl;
    
}

void print(PhoneRec* arr[], size_t size, const char* filter) {
    size_t row = 1;
    for (size_t i = 0; i < size; ++i) {
        print(*arr[i], row, filter); 
    }
}

void print(const PhoneRec& rec, size_t& row, const char* filter) {
    bool match = (filter == nullptr) ||
                 (strstr(rec.firstName, filter) != nullptr) ||
                 (strstr(rec.lastName, filter) != nullptr);

    if (match) {
        cout << row << ": "
             << rec.firstName << " " << rec.lastName << " ";
        print(rec.phoneNumber);
        ++row;
    }
}


void setPointers(PhoneRec* pointers[], PhoneRec records[], size_t arrSz){
    for (size_t i = 0;i < arrSz; ++i){
        pointers[i] = &records[i];
    }
}

void sort(PhoneRec* arr[], size_t size, bool sortName) {
    for (size_t i = 0; i < size; i++) {
        for (size_t j = i + 1; j < size; j++) {
            if (sortName == true ) {
                
                if (strcmp(arr[i]->lastName, arr[j]->lastName) > 0) {
                    PhoneRec* temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            } else {

                if (strcmp(arr[i]->firstName, arr[j]->firstName) > 0) {
                    PhoneRec* temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
}

}
