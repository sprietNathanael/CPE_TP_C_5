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

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_RESET "\x1b[0m"

int main(int argc, char const *argv[])
{
	Element* myList = malloc(sizeof(Element));
	char* myString = malloc(sizeof(char)*(strlen("3")+1));
	strcpy(myString,"3");
	myList->value = myString;
	myList->next = NULL;
	char* test[] = {"5","6","2","8","9","11","7","4","10","12","15","20","1","19","13","17"};
	myList = fillList(myList,test,16);
	printf(ANSI_COLOR_BLUE"First display :\n"ANSI_COLOR_RESET);
	printList(myList);
	emptyList(&myList);
	if(myList != NULL)
	{
		printf(ANSI_COLOR_RED"ERROR ! myList = %x\n"ANSI_COLOR_RESET,myList);
	}
	return 0;
}
