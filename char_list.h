/**
 * CPE-TP4 : Implémentation d'une liste dans une liste chaînée
 *
 * @file char_list.h
 * @brief      Useful tools to manage string chained list
 * @author     Nathanaël SPRIET
 * @date       14/02/2017
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef CHAR_LIST_H
#define CHAR_LIST_H


/*
***************************** Structures *************************
*/

/**
 * @brief      A type defined over the element structure
 */
typedef struct element Element;

/**
 * @brief      Represents a chained list of element
 */
struct element
{
	char* value;/*!< The item value */
	Element* next;/*!< The item next neighbour */
};

/*
***************************** Functions *************************
*/

/**
 * @brief      Prints recursively a list
 *
 * @param      headOfList  The list to print
 */
void printList(Element *headOfList);

/**
 * @brief      Adds an element at the end of the list.
 *
 * @param      headOfList  The list where the element will be added
 * @param[in]  value       The value of the element to add
 *
 * @return     The new list
 */
Element* addAtEnd(Element* headOfList, char* value);

/**
 * @brief      Adds an element at the begining of the list.
 *
 * @param      headOfList  The list where the element will be added
 * @param[in]  value       The value of the element to add
 *
 * @return     The new list
 */
Element* addAtBegining(Element* headOfList, char* value);

/**
 * @brief      Adds an element at a given index in the list.
 *
 * @param      headOfList  The list where the element will be added
 * @param[in]  value       The value of the element to add
 * @param[in]  index       The index of the list where the element will be added
 *
 * @return     The new list
 */
Element* addAtIndex(Element* headOfList, char* value, unsigned int index);

/**
 * @brief      Append to a list a value array.
 *
 * @param      headOfList   The list to be filled
 * @param      array        The array of value that will be append to the list
 * @param[in]  arrayLength  The array length
 *
 * @return     The new list
 */
Element* fillList(Element* headOfList, char* array[], unsigned int arrayLength);

/**
 * @brief      Find the first occurrence of a given value
 *
 * @param      headOfList   The list where the value will be searched
 * @param[in]  valueToFind  The value to find
 *
 * @return     The index of the found value, or -1 if the value has not been
 *             found
 */
int findInList(Element* headOfList, char* valueToFind);

/**
 * @brief      Removes the first occurrence of a given value
 *
 * @param      headOfList     The list where the value will be remove
 * @param[in]  valueToRemove  The value to remove
 *
 * @return     The new list
 */
Element* removeFromList(Element* headOfList, char* valueToRemove);

/**
 * @brief      Remove the list from the memory
 *
 * @param      headOfList  The list to be removed
 */
void emptyList(Element** headOfList);

/*
***************************** Static Functions *************************
*/

/**
 * @brief      Finds recursively the end of the list
 *
 * @param      headOfList  The list
 *
 * @return     The last element of the list
 */
static Element* findTheEndOfList(Element* headOfList);

/**
 * @brief      Creates an element
 *
 * @param[in]  value  The value of the new element
 *
 * @return     The new element
 */
static Element* createElement(char* value);
#endif
