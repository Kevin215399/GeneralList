#pragma once
#include "Arduino.h"

struct GeneralListNode
{
    struct GeneralListNode* next;
    struct GeneralListNode* previous;
    void* content;
};

struct GeneralList
{
    GeneralListNode* firstElement;
    GeneralListNode* lastElement;
    int count;
};

void InitializeList(GeneralList* list);

void PushList(GeneralList* list, void* content);

void* PopList(GeneralList* list);

void* PopListFirst(GeneralList* list);

void* ListGetIndex(GeneralList* list, int index);

void* DeleteListElement(GeneralList* list, int index);


void TransferList(GeneralList* to, GeneralList* from);

void CpyList(GeneralList* to, GeneralList* from, size_t contentSize);
