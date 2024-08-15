//Glenn Parrreno
//geparreno@myseneca.ca
//115814196
//Date

#ifndef sdds_WORD_H
#define sdds_WORD_H

#define _CRT_SECURE_NO_WARNINGS

#include <iomanip>
#include <iostream>
#include <cstdio>
#include "cStrTools.h"

namespace sdds
{
    const int MAX_WORD_LEN = 21;
    const int MAX_NO_OF_WORDS = 500;
    const int SORT_BY_OCCURANCE = 1;
    const int SORT_ALPHABETICALLY = 0;

    struct Word {
        char letters[MAX_WORD_LEN];
        int count;
    };

    int searchWords(const Word [], int, const char []);
    void addWord(Word [], int* , const char []);
    int readWord(char*, FILE* , int);
    void title(const char*, int);
    void endList();
    void totalWordsStat(int, int, int);
    void print(const Word*, int, int);
    int findMaxLen(const Word, int);
    void listWords(const Word [], int, const char*);
    void swap(Word*, Word*);
    void sort(Word [], int, int);
    int totalCount(const Word*, int);
    void wordStats(const char*);
    void programTitle();
}
#endif // !sdds_WORD_H
