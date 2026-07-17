#include "GeneralList.h"


void InitializeList(GeneralList* list)
{
    list->count = 0;
    list->firstElement = NULL;
    list->lastElement = NULL;
}

void PushList(GeneralList* list, void* content)
{
    // Serial.println("list passed\n");
    if (list == NULL)
    {
        Serial.println("list is null\n");
        return;
    }
    if (list->lastElement == NULL)
    {
        // Serial.println("createing first\n");
        list->firstElement = (GeneralListNode*)malloc(sizeof(GeneralListNode));
        // Serial.println("createing malloced\n");
        list->lastElement = list->firstElement;
        list->lastElement->next = NULL;
        list->lastElement->previous = NULL;
        list->count = 1;
        // Serial.println("done\n");
    }
    else
    {
        GeneralListNode* newElement = (GeneralListNode*)malloc(sizeof(GeneralListNode));
        list->lastElement->next = newElement;
        newElement->previous = list->lastElement;
        newElement->next = NULL;

        list->lastElement = newElement;
        list->count++;
    }

    list->lastElement->content = content;
}

void* PopList(GeneralList* list)
{
    if (list->count == 0)
        return NULL;

    void* content = list->lastElement->content;
    // Serial.println("got content\n");

    if (list->count > 1)
    {
        list->lastElement = list->lastElement->previous;
        free(list->lastElement->next);
        list->lastElement->next = NULL;
    }
    else
    {
        free(list->firstElement);
        list->firstElement = NULL;
        list->lastElement = NULL;
    }

    list->count--;

    return content;
}

void* PopListFirst(GeneralList* list)
{
    if (list->count == 0)
        return NULL;

    void* content = list->firstElement->content;
    // Serial.println("got content\n");

    if (list->count > 1)
    {
        list->firstElement = list->firstElement->next;
        free(list->firstElement->previous);
        list->firstElement->previous = NULL;
    }
    else
    {
        free(list->firstElement);
        list->firstElement = NULL;
        list->lastElement = NULL;
    }

    list->count--;

    return content;
}

void* ListGetIndex(GeneralList* list, int index)
{
    if (index >= list->count)
    {
        Serial.println("out of bounds\n");
        return NULL;
    }

    GeneralListNode* currentNode = list->firstElement;
    // Serial.println("ggot\n");
    for (int i = 0; i < index; i++)
    {
        // Serial.println("next\n");
        currentNode = currentNode->next;
    }
    // Serial.println("returning");
    return currentNode->content;
}

void* DeleteListElement(GeneralList* list, int index)
{
    if (index >= list->count)
    {
        Serial.println("out of bounds\n");
        return NULL;
    }

    GeneralListNode* currentNode = list->firstElement;
    // Serial.println("ggot\n");
    for (int i = 0; i < index; i++)
    {
        // Serial.println("next\n");
        currentNode = currentNode->next;
    }

    // Serial.println("found\n");

    list->count--;

    if (currentNode->previous != NULL && currentNode->next != NULL)
    {
        // Serial.println("prev and next\n");
        currentNode->previous->next = currentNode->next;
        currentNode->next->previous = currentNode->previous;
    }
    else if (currentNode->previous != NULL)
    {
        // Serial.println("prev\n");
        currentNode->previous->next = NULL;
        list->lastElement = currentNode->previous;
    }
    else if (currentNode->next != NULL)
    {
        // Serial.println("next\n");
        currentNode->next->previous = NULL;
        list->firstElement = currentNode->next;
    }
    else {
        list->firstElement = NULL;
        list->lastElement = NULL;
    }

    // Serial.println("stitched list\n");

    void* content = currentNode->content;

    free(currentNode);

    // Serial.println("freed node \n");
    return content;
}


void TransferList(GeneralList* to, GeneralList* from)
{
    while (from->count > 0)
    {
        Serial.println("transfered list element\n");
        PushList(to, DeleteListElement(from, 0));
    }
}
void CpyList(GeneralList* to, GeneralList* from, size_t contentSize)
{
    for (int i = 0; i < from->count; i++)
    {

        void* valueToCopy = ListGetIndex(from, i);
        void* cpy = malloc(contentSize);
        memcpy(cpy, valueToCopy, contentSize);

        PushList(to, cpy);
    }
    to->count += from->count;
}

