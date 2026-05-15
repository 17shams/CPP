//
//  io.h
//  lab
//
//  Created by shams on 2025-09-13.
//
#ifndef SENECA_IO_H
#define SENECA_IO_H

namespace seneca {

struct PhoneRec{
    char firstName[15];
    char lastName[25];
    long long phoneNumber;
};

void read(char name[]);
bool read(PhoneRec& rec, FILE* fp);

void print(long long phoneNumber);
void print(PhoneRec* arr[], size_t size, const char* filter = nullptr);


void print(const PhoneRec& rec, size_t& row, const char* filter = nullptr);

void setPointers(PhoneRec* pointers[], PhoneRec records[], size_t arrSz);
void sort(PhoneRec* arr[], size_t size, bool sortName);
}

#endif
