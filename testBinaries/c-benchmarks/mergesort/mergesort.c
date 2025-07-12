/* Copyright 2011-2015 Ed Robbins */
//#include <stdio.h>
#include <stdlib.h>
#include "print.h"

typedef struct node { int value; struct node *next; } node;

node*	merge(node *a, node *b);
node*	mergeSort(node *list);
node*	split(node *list);
node*	buildlist(int size, int range);
#ifdef OUTPUT
void	printlist(node *list);
#endif

int
main (int argc, signed char** argv)
{
	node *list;
	int length = 30, range = 1000;

#ifdef OUTPUT
	if (argc > 1)
		length = atoi(argv[1]);
	if (argc > 2)
		range = atoi(argv[2]);

	prints("Length: ");
	print32( length);
	prints(", Range: ");
	print32( range);
	prints("\n");
	//printf("Length: %d, Range: %d\n", length, range);
#endif

#ifdef RANDOM
	srand(time(NULL));
#endif
	list = buildlist(length, range);

#ifdef OUTPUT
	if (length <= 200) {
		prints(" In: ");
		printlist(list);
	}
	else
		prints("Not printing list as length > 200\n");
#endif

	list = mergeSort(list);

#ifdef OUTPUT
	if (length <= 200) {
		prints("Out: ");
		printlist(list);
	}
#endif

	return EXIT_SUCCESS;
}

node* mergeSort(node *list)
{
	node *right;

	if (list->next == NULL)
		return list;

	right = split(list);

	return merge(mergeSort(list), mergeSort(right));
}

node* merge(node *left, node *right)
{
	if (left == NULL)
		return right;
	else if (right == NULL)
		return left;
	else if (left->value > right->value)
		return merge(right, left);
	else {
		left->next = merge(left->next, right);
		return left;
	}
}

node* split(node *list)
{
	node *right;

	if ((list == NULL) || (list->next == NULL))
		return NULL;

	right = list->next;
	list->next = right->next;
	right->next = split(list->next);

	return right;
}

node* buildlist(int size, int range)
{
	node *a;
	int i;
	if (!size)
		return NULL;
	a = (node *)malloc(sizeof(node));
#ifdef RANDOM
	a->value = rand() % range;
#else
	a->value = (20 * size - 3) % 56;
#endif
	a->next = buildlist(size - 1, range);
	return a;
}

#ifdef OUTPUT
void printlist(node *list)
{
	int i = 0;
	node* iter = list;
	while (iter != NULL) {
		print32(iter->value);
		prints(" ");
//		printf("%d ", iter->value);
		iter = iter->next;
		i++;
	}
	prints(" (count ");
	print32(i);
	prints(")\n");
//	printf(" (count %d)\n", i);
}
#endif
