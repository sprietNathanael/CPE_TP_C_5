/**
 * CPE-TP5 : Tri par éclatement-fusion
 *
 * @file main.c
 * @brief      Implement sorting of a simple char chained list
 * @author     Nathanaël SPRIET
 * @date       15/02/2017
 */

#include <stdio.h>
#include <stdlib.h>
#include "char_list.h"
#include "sort_splitMerge.h"

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_RESET "\x1b[0m"

void unit_test();

int main(int argc, char const *argv[])
{
	unit_test();
	Element* myList = malloc(sizeof(Element));
	char* myString = malloc(sizeof(char)*(strlen("3")+1));
	strcpy(myString,"3");
	myList->value = myString;
	myList->next = NULL;
	char* newElements[] = {"5","6","2","8","9","11","7","4","10","12","15","20","1","19","13","17"};
	myList = fillList(myList,newElements,16);
	printf(ANSI_COLOR_BLUE"Unsorted list :\n"ANSI_COLOR_RESET);
	printList(myList);
	myList = sortList(myList);
	printf(ANSI_COLOR_BLUE"Sorted list :\n"ANSI_COLOR_RESET);
	printList(myList);

	emptyList(&myList);
	if(myList != NULL)
	{
		printf(ANSI_COLOR_RED"ERROR ! myList = %x\n"ANSI_COLOR_RESET,myList);
	}
	return 0;
}

void unit_test()
{
	printf(ANSI_COLOR_BLUE"Test of string comparison :\n"ANSI_COLOR_RESET);
	int res = compare_char("1","2");
	if( res == 2)
	{
		printf(ANSI_COLOR_GREEN"\t1 > 2\n"ANSI_COLOR_RESET);
	}
	else
	{
		printf(ANSI_COLOR_RED"\t1 > 2 => %d\n"ANSI_COLOR_RESET, res);
	}
	res = compare_char("2","1");
	if( res == 1)
	{
		printf(ANSI_COLOR_GREEN"\t2 < 1\n"ANSI_COLOR_RESET);
	}
	else
	{
		printf(ANSI_COLOR_RED"\t2 < 1 => %d\n"ANSI_COLOR_RESET, res);
	}
	res = compare_char("1","1");
	if( res == 0)
	{
		printf(ANSI_COLOR_GREEN"\t1 = 1\n"ANSI_COLOR_RESET);
	}
	else
	{
		printf(ANSI_COLOR_RED"\t1 = 1 => %d\n"ANSI_COLOR_RESET, res);
	}
	res = compare_char("10","1");
	if( res == 1)
	{
		printf(ANSI_COLOR_GREEN"\t10 > 1\n"ANSI_COLOR_RESET);
	}
	else
	{
		printf(ANSI_COLOR_RED"\t10 > 1 => %d\n"ANSI_COLOR_RESET, res);
	}
	res = compare_char("10","2");
	if( res == 1)
	{
		printf(ANSI_COLOR_GREEN"\t10 > 2\n"ANSI_COLOR_RESET);
	}
	else
	{
		printf(ANSI_COLOR_RED"\t10 > 2 => %d\n"ANSI_COLOR_RESET, res);
	}
	res = compare_char("1","10");
	if( res == 2)
	{
		printf(ANSI_COLOR_GREEN"\t1 < 10\n"ANSI_COLOR_RESET);
	}
	else
	{
		printf(ANSI_COLOR_RED"\t1 < 10 => %d\n"ANSI_COLOR_RESET, res);
	}
	res = compare_char("2","10");
	if( res == 2)
	{
		printf(ANSI_COLOR_GREEN"\t2 < 10\n"ANSI_COLOR_RESET);
	}
	else
	{
		printf(ANSI_COLOR_RED"\t2 < 10 => %d\n"ANSI_COLOR_RESET, res);
	}
	res = compare_char("a","b");
	if( res == 0)
	{
		printf(ANSI_COLOR_GREEN"\ta ; b\n"ANSI_COLOR_RESET);
	}
	else
	{
		printf(ANSI_COLOR_RED"\ta ; b => %d\n"ANSI_COLOR_RESET, res);
	}
}
