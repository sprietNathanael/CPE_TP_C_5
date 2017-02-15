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
	while(!isListSorted(list))
	{
		printf("NOT SORTED YET !\n");
		splitList(list);
		printf("List 1 :\n");
		printList(intermediate_list1);
		printf("List 2 :\n");
		printList(intermediate_list2);
		list = mergeLists(intermediate_list1,intermediate_list2);
		printf("Merged list : \n");
		printList(list);
	}
	printf("SORTED !\n");

	return(list);
}

void splitList(Element* unsortedList)
{
	Element* list1 = NULL;
	Element* list2 = NULL;
	int listNumber = 1;
	// Browse unsorted list
	while(unsortedList != NULL)
	{
		// If the list number is odd, use list 1
		if((listNumber%2) == 1)
		{
			// If list 1 is empty
			if(list1 == NULL)
			{
				list1 = unsortedList;
				// Set the head of main list 1 to save it
				intermediate_list1 = list1;
			}
			// Else, append the current element of unsorted list
			else
			{
				list1->next = unsortedList;
				list1 = list1->next;
			}
		}
		// If the list number is even, use list 2
		else
		{
			// If list 2 is empty
			if(list2 == NULL)
			{
				list2 = unsortedList;
				// Set the head of main list 2 to save it
				intermediate_list2 = list2;
			}
			// Else, append the current element of unsorted list
			else
			{
				list2->next = unsortedList;
				list2 = list2->next;
			}
		}
		// If the next value of the unsorted list is smaller than the current value, change list
		if(unsortedList->next != NULL && (compare_char(unsortedList->next->value,unsortedList->value) == 2))
		{
			listNumber++;
		}
		// Go to the next element of the unsorted list
		unsortedList = unsortedList->next;
	}
	// End the intermediate lists
	list1->next = NULL;
	list2->next = NULL;
}

Element* mergeLists(Element* list1, Element* list2)
{
	Element* resultList = NULL;
	Element* intermediate_reslut_list = NULL;
	int list1_end, list2_end = 0;
	printf("Merging \n");

	while(list1 != NULL || list2 != NULL)
	{
		list1_end = (list1 == NULL);
		list2_end = (list2 == NULL);
		while(!list1_end || !list2_end)
		{
			if(list2_end || (!list1_end && compare_char(list1->value,list2->value) == 2))
			{
				if(intermediate_reslut_list == NULL)
				{
					intermediate_reslut_list = list1;
					resultList = intermediate_reslut_list;
				}
				else
				{
					intermediate_reslut_list->next = list1;
					intermediate_reslut_list = intermediate_reslut_list->next;
				}
				if(list1->next == NULL || compare_char(list1->value,list1->next->value) == 1)
				{
					list1_end = 1;
				}
				list1 = list1->next;
			}
			else
			{
				if(intermediate_reslut_list == NULL)
				{
					intermediate_reslut_list = list2;
					resultList = intermediate_reslut_list;
				}
				else
				{
					intermediate_reslut_list->next = list2;
					intermediate_reslut_list = intermediate_reslut_list->next;
				}
				if(list2->next == NULL || compare_char(list2->value,list2->next->value) == 1)
				{
					list2_end = 1;
				}
				list2 = list2->next;
			}
		}
	}
	return(resultList);
}

int isListSorted(Element* list)
{
	Element* intermediateList;
	while(intermediateList != NULL)
	{
		if(intermediateList->next != NULL && compare_char(intermediateList->value,intermediateList->next->value) == 1)
		{
			return(0);
		}
		intermediateList = intermediateList->next;
	}
	return(1);
}
