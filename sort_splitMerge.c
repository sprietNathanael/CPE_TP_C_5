/**
 * CPE-TP5 : Tri par éclatement-fusion
 *
 * @file char_list.c
 * @brief      Manage sorting by split-merge
 * @author     Nathanaël SPRIET
 * @date       15/02/2017
 */

#include "sort_splitMerge.h"

int compare_char(char* a, char* b)
{
	int a_int = atoi(a);
	int b_int = atoi(b);
	if(a_int > b_int)
	{
		return(1);
	}
	else if(a_int < b_int)
	{
		return(2);
	}
	else if(a_int == b_int)
	{
		return(0);
	}
}

Element* sortList(Element* list)
{
	return(list);
}
