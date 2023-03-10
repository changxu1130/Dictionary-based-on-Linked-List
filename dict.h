/** ***********************
* C Programming Style for Algorithms and Data Structures (COMP20003_2022_SM2)
* Created by Chang Xu (xucm@student.unimelb.edu.au) 11/08/2022
*/

#ifndef _ARRAY_H_
#define _ARRAY_H_

#include "data.h"

#define MAX_LINE_LEN 512
#define MAX_CHAR_LEN 128


//define the linked list structure 
typedef struct node node_t;
struct node{
    // the key will contain the address of the foorpath
    char *key;
    footpath_t *ptr2Footpath;
    node_t *next;
}; 


//function prototypes for stage1 
/*
buildFootpathDict reads data from file f and builds a linkedlist/dictionary 
of all the footpaths and return a pointer to its head
*/
void *buildFootpathDict(FILE *f);

/*
searchAddress takes a pointer, head, to the head of the linkedlist and search 
for the footpath with its address identical to the query from stdin. The 
result of the search will be printed to the outFile.
*/
int searchAddress(node_t *head, char *query, FILE *outFile);

/*
makeNewNode is a helper function that creates new node 
and returns a pointer to it
*/
node_t *makeNewNode();

/*
printStage1Format is a helper function that print all 
the stage1 required output to the outFile
*/
void printStage1Format(node_t *node, FILE *outFile);

//additional function prototypes for Stage2
/*
buildArr takes a pointer to the head of the linkedlist, and the number
of footpath in the linkedlist. It then traverse the whole linkedlist and 
return an array of pointers to each node
*/
node_t **buildArr(node_t *head, int nFootpath);

/*
nFootpathRead is a helper functino that travers the whole linkedlist to find 
and return the number of footpath as int 
*/
int nFootpathRead(node_t *head);

/*
arrSortm is an insertion sort alogorithm that sort the array of 
pointer to each footpath based on its attribute, grade1in's value
*/
void arrSort(node_t **arr, int n);

/*
search performs a linear search of the entry with the closest grade1in 
value as the query from stdin in the sorted array of the pointers to 
footpath. The result of the search will then be printed to the outFile. 
*/
void search(node_t **arr, int nFootpath, char* query, FILE *outFile);

/*
freeNode free the memory allocated to the node_t
*/
void freeNode(node_t *head);

/*
absoluteValue is a helper function that return the abosulte value of 
the input double as a double 
*/
double absoluteValue(double n);

#endif
