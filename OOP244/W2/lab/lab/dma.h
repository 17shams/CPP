//
//  dma.h
//  lab
//
//  Created by shams on 2025-09-18.
//
#ifndef SENECA_DMA_H
#define SENECA_DMA_H

namespace seneca {
// Declarations and prototypes go here

struct Samples {
    char* m_title;   // Dynamically allocated title
    int* m_data;     // Dynamically allocated array of integers
    int m_size;   // Number of elements in m_data
};

Samples* CreateSamples(const char* title);

void add(Samples& S, const int data[], int size);
void append(int*& data, int size, const int appendData[], int dataSize);
void freemem(Samples*& s);

}
#endif // !SENECA_DMA_H
