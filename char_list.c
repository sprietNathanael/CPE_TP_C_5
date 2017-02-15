/**
 * CPE-TP4 : Implémentation d'une liste dans une liste chaînée
 *
 * @file char_list.c
 * @brief      Useful tools to manage char chained list
 * @author     Nathanaël SPRIET
 * @date       14/02/2017
 */
#include "char_list.h"

/*
***************************** Functions *************************
*/

void printList(Element* headOfList)
{
	printf("%s",headOfList->value);
	if(headOfList->next != NULL)
	{
		printf("->");
		printList(headOfList->next);
	}
	else
	{
		printf("\n");
	}
}

Element* addAtEnd(Element* headOfList, char* value)
{
	Element* lastElement = findTheEndOfList(headOfList);
	lastElement->next = createElement(value);
	return(headOfList);
}

Element* addAtBegining(Element* headOfList, char* value)
{
	Element* newElement = createElement(value);
	newElement->next=headOfList;
	return(newElement);
}

Element* addAtIndex(Element* headOfList, char* value, unsigned int index)
{
	Element* newElement = createElement(value);
	if(index == 0)
	{
		newElement->next = headOfList;
		headOfList = newElement;
	}
	else
	{
		int i = 0;
		Element* intermediateElement = headOfList;
		while(intermediateElement->next != NULL && i < index-1)
		{
			intermediateElement = intermediateElement->next;
			i++;
		}
		newElement->next = intermediateElement->next;
		intermediateElement->next = newElement;
	}
	return(headOfList);
}

Element* fillList(Element* headOfList, char* array[], unsigned int arrayLength)
{
	Element* firstElement = createElement(array[0]);
	Element* intermediateElement = firstElement;
	int i = 1;
	for(i = 1; i < arrayLength; i++)
	{
		intermediateElement->next = createElement(array[i]);
		intermediateElement = intermediateElement->next;
	}
	intermediateElement = findTheEndOfList(headOfList);
	intermediateElement->next = firstElement;
	return(headOfList);
}

int findInList(Element* headOfList, char* valueToFind)
{
	Element* intermediateElement = headOfList;
	int result = 0;
	while(intermediateElement != NULL && strcmp(intermediateElement->value,valueToFind))
	{
		result++;
		intermediateElement = intermediateElement->next;
	}
	if(intermediateElement == NULL)
	{
		return(-1);
	}
	else
	{
		return(result);
	}
}

Element* removeFromList(Element* headOfList, char* valueToRemove)
{
	Element* intermediateElement = headOfList;
	if(!strcmp(intermediateElement->value,valueToRemove))
	{
		headOfList = intermediateElement->next;
		free(intermediateElement);
	}
	else
	{
		while(intermediateElement->next != NULL && strcmp(intermediateElement->next->value,valueToRemove))
		{
			intermediateElement = intermediateElement->next;
		}
		if(intermediateElement->next != NULL)
		{
			free(intermediateElement->next);
			intermediateElement->next = intermediateElement->next->next;
		}
	}
	return(headOfList);

}

void emptyList(Element** headOfList)
{
	if(*headOfList != NULL)
	{
		emptyList(&((*headOfList)->next));
		free(*headOfList);
		*headOfList = NULL;
	}
}
/*
***************************** Static Functions *************************
*/

static Element* findTheEndOfList(Element* headOfList)
{
	if(headOfList->next != NULL)
	{
		Element* intermediateElement = findTheEndOfList(headOfList->next);
	}
	else
	{
		return(headOfList);
	}
}

static Element* createElement(char* value)
{
	Element* newElement = malloc(sizeof(Element));
	char* newString = malloc(sizeof(char)*(strlen(value)+1));
	strcpy(newString,value);
	newElement->value = newString;
	newElement->next = NULL;
	return(newElement);
}
