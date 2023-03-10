/** ***********************
* C Programming Style for Algorithms and Data Structures (COMP20003_2022_SM2)
* Created by Chang Xu (xucm@student.unimelb.edu.au) 11/08/2022
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "data.h"
#include "dict.h"

int main(int argc, char *argv[]) {
	//check if there are 3 arguments in command line
	if (argc < 4) {
		return EXIT_FAILURE;
	} 

	//stageNum used to determine the current stage of the function
    int stageNum = atoi(argv[1]);
 
    //opens input and output file
	FILE *inFile = fopen(argv[2], "r"),
		 *outFile = fopen(argv[3], "w");
	//exit if fails to open files
	assert(inFile && outFile);    

	//store the query entered from stdin 
	char *query = (char *)malloc(sizeof(char) * (MAX_CHAR_LEN + 1));
	char *query2 = (char *)malloc(sizeof(char) * (MAX_CHAR_LEN + 1));

	//store the head of the linkedlist built based on the input file 
	void *lsHead = buildFootpathDict(inFile);
	node_t *ptrDict;
	fclose(inFile);

	//stage 1
	if(stageNum == 1){
		//read the query from stdin
		while((fgets(query, MAX_CHAR_LEN + 1, stdin)) != NULL){
			//remove the trailing newline char from fgets
			query[strlen(query) - 1] = '\0';
			//set the temporary ptrDict 
			ptrDict = (node_t*)lsHead;
			//search the address/query 
			searchAddress(ptrDict, query, outFile);
		}

	}
	
	//stage 2 
	if(stageNum == 2){	
		//set the temporary ptrDict 
		ptrDict = (node_t*)lsHead;
		int nFootpath = nFootpathRead(ptrDict);

		//build an array of pointers to footpaths based from the linkedlist 
		node_t** arr = buildArr(ptrDict, nFootpath);
		
		//sort the array 
		arrSort(arr, nFootpath);

		//read the query from stdin
		while((fgets(query2, MAX_CHAR_LEN + 1, stdin)) != NULL){
			query2[strlen(query2) - 1] = '\0';
			//accept the (double)input from stdin
			search(arr, nFootpath, query2, outFile);
		}
		free(arr);
	}

	freeNode((node_t*)lsHead);
	free(query);
	free(query2);
	fclose(outFile);
	return EXIT_SUCCESS;
}






