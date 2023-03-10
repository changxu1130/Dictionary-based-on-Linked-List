/** ***********************
* C Programming Style for Algorithms and Data Structures (COMP20003_2022_SM2)
* Created by Chang Xu (xucm@student.unimelb.edu.au) 11/08/2022
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "dict.h"
#include "data.h"

/*
buildFootpathDict reads data from file f and builds a linkedlist
/dictionary of all the footpaths and return a pointer to its head
*/
void *buildFootpathDict(FILE *f){
	//get rid of the header line 
	char header[MAX_LINE_LEN + 1];
	fscanf(f, "%[^\n] ", header);

	footpath_t *s;

	//initilize the head of the linked list
	node_t *head = makeNewNode();
	//stores the address of the head for further implementation 
	node_t *ptrDict = head;
	//store the previous one
	node_t *previousPtrDict = ptrDict;

	//store all the input into a linked list 
	while(1){
		s = readFootpath(f);
		//if reach the end of the file, seal the linked list
		if(!s){
			previousPtrDict->next = NULL;
			free(ptrDict);
			break;
		}
		//node initialization
		//store the key infor for each node 
		ptrDict->key = s->address;
		ptrDict->ptr2Footpath = s;
		//store the next one
		ptrDict->next = makeNewNode();
		previousPtrDict = ptrDict;
		ptrDict = ptrDict->next;
		
	}
	return (void*)head;
}

/*
searchAddress takes a pointer, head, to the head of the
linkedlist and search for the footpath with its address
identical to the query from stdin. The result of the 
search will be printed to the outFile.
*/
int searchAddress(node_t *head, char *query, FILE *outFile){
	//nFound records the number of matched data found 
	int nFound = 0, founded = 0;

	//empty linked list  
	node_t *currNode = head;
	if(currNode != NULL){
		//traverse the list untill the last 

		while (currNode != NULL){
			//if the query is found, print it out straight away
			if(strcmp(currNode->key, query) == 0){
				
				if(!founded){
					fprintf(outFile, "%s\n", query);
					founded = 1;
				}
				
				nFound++;
				printStage1Format(currNode, outFile);
			} 
			currNode = currNode->next;
		}
	}

	//output to stdout:	
	if(nFound == 0){
		printf("%s --> NOTFOUND\n", query);
        fprintf(outFile, "%s\n", query);
	} 
	else {
		printf("%s --> %d\n", query, nFound);
	}
	return 0;	
}

/*
makeNewNode is a helper function that creates new node 
and returns a pointer to it
*/
node_t *makeNewNode(){
	node_t *newNode;
	newNode = (node_t*)malloc(sizeof(node_t));
	assert(newNode);
	return newNode;
}


/*
printStage1Format is a helper function that print all 
the stage1 required output to the outFile
*/
void printStage1Format(node_t* node, FILE *outFile){
	
	fprintf(outFile, "%s", "--> ");	
	fprintf(outFile, "footpath_id: %d || ",
	 atoi(node->ptr2Footpath->footpath_id));

	//check whether the original string was just an empty string
	if((node->ptr2Footpath->address[0]) == ' '){
		fprintf(outFile, "address: %s|| ", node->ptr2Footpath->address);
	}
	//else, print out the original formatting
	else {
		fprintf(outFile, "address: %s || ", node->ptr2Footpath->address);
	}


	if((node->ptr2Footpath->clue_sa[0]) == ' '){
		fprintf(outFile, "clue_sa: %s|| ", node->ptr2Footpath->clue_sa);
	}
	else{
		fprintf(outFile, "clue_sa: %s || ", node->ptr2Footpath->clue_sa);
	}

	
	if((node->ptr2Footpath->asset_type)[0] == ' '){
		fprintf(outFile, "asset_type: %s|| ", node->ptr2Footpath->asset_type);
	}
	else{
		fprintf(outFile, "asset_type: %s || ", node->ptr2Footpath->asset_type);
	}

	fprintf(outFile, "deltaz: %s || ", node->ptr2Footpath->deltaz);
	fprintf(outFile, "distance: %s || ", node->ptr2Footpath->distance);
	fprintf(outFile, "grade1in: %s || ", node->ptr2Footpath->grade1in);
	fprintf(outFile, "mcc_id: %d || ", atoi(node->ptr2Footpath->mcc_id));
	fprintf(outFile, "mccid_int: %d || ", atoi(node->ptr2Footpath->mccid_int));
	fprintf(outFile, "rlmax: %s || ", node->ptr2Footpath->rlmax);
	fprintf(outFile, "rlmin: %s || ", node->ptr2Footpath->rlmin);

	if((node->ptr2Footpath->segside)[0] == ' '){
		fprintf(outFile, "segside: %s|| ", node->ptr2Footpath->segside);
	}
	else{
		fprintf(outFile, "segside: %s || ", node->ptr2Footpath->segside);
	}
	
	fprintf(outFile, "statusid: %d || ", atoi(node->ptr2Footpath->statusid));
	fprintf(outFile, "streetid: %d || ", atoi(node->ptr2Footpath->streetid));
	fprintf(outFile, "street_group: %d || ", 
			atoi(node->ptr2Footpath->street_group));
	fprintf(outFile, "start_lat: %s || ", node->ptr2Footpath->start_lat);
	fprintf(outFile, "start_lon: %s || ", node->ptr2Footpath->start_lon);
	fprintf(outFile, "end_lat: %s || ", node->ptr2Footpath->end_lat);
	fprintf(outFile, "end_lon: %s || \n", node->ptr2Footpath->end_lon);
}

/*
buildArr takes a pointer to the head of the linkedlist, and the number
of footpath in the linkedlist as input. It then traverse the whole 
linkedlist and return an array of pointers to each node
*/
node_t **buildArr(node_t *head, int nFootpath){
	node_t *currNode = head;	
	//malloc exact amount of space required for the array
	node_t ** arr = (node_t**)malloc(sizeof(node_t*) * nFootpath); 
	//traverse the linkedlist and store the pointers to the array 
	currNode = head;
	int i = 0;
	while(currNode != NULL){
		arr[i] = currNode;
		i++;
		currNode = currNode->next;
	}

	return arr;
}

/*
nFootpathRead is a helper functino that travers the whole linkedlist to find 
and return the number of footpath as int 
*/
int nFootpathRead(node_t *head){
	int nFootpath = 0;
	node_t *currNode = head;
	//go through the linkedlist to find the number of footpath stored
	while(currNode != NULL){
		nFootpath++;
		currNode = currNode->next;
	}
	return nFootpath;
}

/*
arrSortm is an insertion sort alogorithm that sort the array of 
pointer to each footpath based on its attribute, grade1in's value
*/
void arrSort(node_t **arr, int n){
    
	int i, j;
	node_t *key;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;
		// move elements of arr[0..i-1], that are
		// greater than key, to one position ahead
		// of their current position 
		while (j >= 0 && 
				(atof(arr[j]->ptr2Footpath->grade1in) >
						 atof(key->ptr2Footpath->grade1in))){
			arr[j + 1] = arr[j];
			j = j - 1;
		}	
		arr[j + 1] = key;
	}
}

/*
search performs a linear search of the entry with the closest grade1in 
value as the query from stdin in the sorted array of the pointers to 
footpath. The result of the search will then be printed to the outFile. 
*/
void search(node_t **arr, int nFootpath, char* query, FILE *outFile){

	//initilize the absoluteDiff
	double absoluteDiff = absoluteValue(atof(query) - 
								atof(arr[0]->ptr2Footpath->grade1in));
	int closestIndex = 0;
	double temp;

	//linear search
	for(int i = 1; i < nFootpath; i++){
		temp = absoluteValue(atof(query) - atof(arr[i]->ptr2Footpath->grade1in));

		if( temp < absoluteDiff){
			absoluteDiff = temp;
			closestIndex = i;
		}
	}
	
	//print to the output file printStage1Format(node_t* node, FILE *outFile)
	fprintf(outFile, "%s\n", query);	
	printStage1Format(arr[closestIndex], outFile);
	printf("%s --> %s\n", query, arr[closestIndex]->ptr2Footpath->grade1in);
}

/*
absoluteValue is a helper function that return the abosulte value of 
the input double as a double 
*/
double absoluteValue(double n){
	if(n >= 0){
		return n;
	}
	else {
		return (n * (-1.0));
	} 
}

/*
freeNode free the memory allocated to the node_t
*/
void freeNode(node_t *head){
	assert(head != NULL);
	node_t *curr = head;
	int nTmp=0;
	while(curr){
		
		node_t *tmp = curr;  
		//curr points to the first node	   
		//advance curr to the next next node
		curr = curr->next;		
		//frees the previous node including
		freeFootpath(tmp->ptr2Footpath);    
		//freeing the space used by data
		free(tmp);      
	}
}
