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

#endif
