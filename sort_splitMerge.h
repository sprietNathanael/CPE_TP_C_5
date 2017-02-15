/**
 * CPE-TP5 : Tri par éclatement-fusion
 *
 * @file char_list.h
 * @brief      Manage sorting by split-merge
 * @author     Nathanaël SPRIET
 * @date       15/02/2017
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "char_list.h"

#ifndef SORT_SPLIT_MERGE_H
#define SORT_SPLIT_MERGE_H

/**
 * @brief      Compares the numeric equivalent of a and b.
 *
 * @param      a     First operand
 * @param      b     Second operand
 *
 * @return     0 if a=b, 1 if a>b, 2 if a<b, 0 if the strings cannot be parsed
 *             as integer
 */
int compare_char(char* a, char* b);

/**
 * @brief      Sort an unordered char list
 *
 * @param[in]  unsortedList  The unsorted list
 *
 * @return     A sorted list
 */
Element* sortList(Element* unsortedList);

/**
 * @brief      Splits a list in two other lists.
 *
 * @param[in]  mainList  The main list
 */
void splitList(Element* mainList);

/**
 * @brief      Merges two lists
 *
 * @param[in]  list1  The list 1
 * @param[in]  list2  The list 2
 *
 * @return     The merged list
 */
Element* mergeLists(Element* list1, Element* list2);

#endif
