/** ***********************
* C Programming Style for Algorithms and Data Structures (COMP20003_2022_SM2)
* Created by Chang Xu (xucm@student.unimelb.edu.au) 11/08/2022
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "data.h"

/*
read from input file for details regarding each footpath
the function aims to build an linkedlist/dictionary of 
all the footpaths and returns the pointer to the head 
or NULL if reading is unsuccessful
*/
footpath_t *readFootpath(FILE *f) {
	
	footpath_t *fp;
	fp = (footpath_t *) malloc(sizeof(footpath_t)); 
	assert(fp); 

	// temperory string to store the line input from inFile  
    char line[MAX_LINE_LEN + 1]; 

	//read all fields in as a string 
	if(!fgets(line, MAX_LINE_LEN + 1, f)){
		free(fp);
		return NULL;
	}

	//tempStr to store the data that is about to be store to the Structure
	char* tempStr;
	tempStr = reformatString(line);

	//keep track of which field is being read to the structure 
	int nField = 0;

	//use temp as a local variable as we only need it 
	//within the scope of this function
	char temp[MAX_LINE_LEN + 1];
	int tempIndex = 0;

	//if true, skip the quotation mark and store the ,
	int quotation = 0; 

	//go through each char && store things into fields 
	for(int nChar = 0; nChar < strlen(tempStr); nChar++){

		//reach the end of the current line 
		if(!tempStr[nChar]){
			break;
		}

		//quotation mark present
		if(tempStr[nChar] == '"'){
			//encountered the first quotation mark
			if(quotation == 0){
				//set the quotation flag to true
				quotation = 1;
			//encountered the secoind quotation mark, don't need to store ,
			} 
			
			else {
				quotation = 0;
			}			
		}

		
		//base case 
		if(quotation == 0){
			//encountered ',' store the string into field 
			if(tempStr[nChar] == ',' || tempStr[nChar] == '\n'){
				
				//nField keeps track of which field it is reading
				if(nField == 0){
					//bound the temp
					temp[tempIndex] = '\0';
					//malloc a temperory string to store the input 
					char* tempString0 = (char *)malloc(sizeof(char) * (MAX_LINE_LEN + 1));
					strcpy(tempString0, temp);
					//store the input into the Structure
					fp->footpath_id = tempString0;
					nField++;
					tempIndex = 0;
				}

				//else follows the same logic as above
				else if(nField == 1){
					temp[tempIndex] = '\0';
					char* tempString1 = (char *)malloc(sizeof(char) * (MAX_LINE_LEN + 1));
					strcpy(tempString1, temp);
					fp->address = tempString1;
					nField++;
					tempIndex = 0;	
				}

				else if(nField == 2){
					temp[tempIndex] = '\0';
					char* tempString2 = (char *)malloc(sizeof(char) * (MAX_LINE_LEN + 1));
					strcpy(tempString2, temp);
					fp->clue_sa = tempString2;
					nField++;
					tempIndex = 0;
				}

				else if(nField == 3){
					temp[tempIndex] = '\0';
					char* tempString3 = (char *)malloc(sizeof(char) * (MAX_LINE_LEN + 1));
					strcpy(tempString3, temp);
					fp->asset_type = tempString3;
					nField++;
					tempIndex = 0;					
				}

				else if(nField == 4){
					temp[tempIndex] = '\0';
					char* tempString4 = (char *)malloc(sizeof(char) * (MAX_LINE_LEN + 1));
					strcpy(tempString4, temp);
					fp->deltaz = tempString4;
					nField++;
					tempIndex = 0;
				}

				else if(nField == 5){
					temp[tempIndex] = '\0';
					char* tempString5 = (char *)malloc(sizeof(char) * (MAX_LINE_LEN + 1));
					strcpy(tempString5, temp);
					fp->distance = tempString5;
					nField++;
					tempIndex = 0;
				}

				else if(nField == 6){
					temp[tempIndex] = '\0';
					char* tempString6 = (char *)malloc(sizeof(char) * (MAX_LINE_LEN + 1));
					strcpy(tempString6, temp);
					fp->grade1in = tempString6;
					nField++;
					tempIndex = 0;
				}

				else if(nField == 7){
					temp[tempIndex] = '\0';
					char* tempString7 = (char *)malloc(sizeof(char) * (MAX_LINE_LEN + 1));
					strcpy(tempString7, temp);
					fp->mcc_id = tempString7;
					nField++;
					tempIndex = 0;				
				}

				else if(nField == 8){
					temp[tempIndex] = '\0';
					char* tempString8 = (char *)malloc(sizeof(char) * (MAX_LINE_LEN + 1));
					strcpy(tempString8, temp);
					fp->mccid_int = tempString8;
					nField++;
					tempIndex = 0;
				}

				else if(nField == 9){				
					temp[tempIndex] = '\0';
					char* tempString9 = (char *)malloc(sizeof(char) * (MAX_LINE_LEN + 1));
					strcpy(tempString9, temp);
					fp->rlmax = tempString9;
					nField++;
					tempIndex = 0;
				}

				else if(nField == 10){
					temp[tempIndex] = '\0';
					char* tempString10 = (char *)malloc(sizeof(char) * (MAX_LINE_LEN + 1));
					strcpy(tempString10, temp);
					fp->rlmin = tempString10;
					nField++;
					tempIndex = 0;			
				}

				else if(nField == 11){			
					temp[tempIndex] = '\0';
					char* tempString11 = (char *)malloc(sizeof(char) * (MAX_LINE_LEN + 1));
					strcpy(tempString11, temp);
					fp->segside = tempString11;
					nField++;
					tempIndex = 0;	
				}

				else if(nField == 12){		
					temp[tempIndex] = '\0';
					char* tempString12 = (char *)malloc(sizeof(char) * (MAX_LINE_LEN + 1));
					strcpy(tempString12, temp);
					fp->statusid = tempString12;
					nField++;
					tempIndex = 0;
				}

				else if(nField == 13){
					temp[tempIndex] = '\0';
					char* tempString13 = (char *)malloc(sizeof(char) * (MAX_LINE_LEN + 1));
					strcpy(tempString13, temp);
					fp->streetid = tempString13;
					nField++;
					tempIndex = 0;
				}

				else if(nField == 14){					
					temp[tempIndex] = '\0';
					char* tempString14 = (char *)malloc(sizeof(char) * (MAX_LINE_LEN + 1));
					strcpy(tempString14, temp);
					fp->street_group = tempString14;
					nField++;
					tempIndex = 0;
				}

				else if(nField == 15){
					temp[tempIndex] = '\0';
					char* tempString15 = (char *)malloc(sizeof(char) * (MAX_LINE_LEN + 1));
					strcpy(tempString15, temp);
					fp->start_lat = tempString15;
					nField++;
					tempIndex = 0;
				}

				else if(nField == 16){
					temp[tempIndex] = '\0';
					char* tempString16 = (char *)malloc(sizeof(char) * (MAX_LINE_LEN + 1));
					strcpy(tempString16, temp);
					fp->start_lon = tempString16;
					nField++;
					tempIndex = 0;
				}

				else if(nField == 17){
					temp[tempIndex] = '\0';
					char* tempString17 = (char *)malloc(sizeof(char) * (MAX_LINE_LEN + 1));
					strcpy(tempString17, temp);
					fp->end_lat = tempString17;
					nField++;
					tempIndex = 0;
				}

				else if(nField == 18){
					temp[tempIndex] = '\0';
					char* tempString18 = (char *)malloc(sizeof(char) * (MAX_LINE_LEN + 1));
					strcpy(tempString18, temp);
					fp->end_lon = tempString18;
					nField++;
					tempIndex = 0;
				}			
			}		
		}

		//skip the quotation marks
		if(tempStr[nChar] != '"'){
			if(quotation == 1){
				temp[tempIndex] = tempStr[nChar];
				tempIndex++;
			}

			else {
				//haven't finished the content of one field, continue reading
				if(tempStr[nChar] != ','){
					temp[tempIndex] = tempStr[nChar];
					tempIndex++;
				}
			}
			
		}				
	}

	free(tempStr);
	return fp;
}


/*
read a string and add a space between two neighbouring 
commas if if was empty in between
e.g. input string: "a,b,,c", 
the return output: "a,b, ,c"
*/
char *reformatString(char *str1){
    //initialize string2
    char *str2 = (char *)malloc(sizeof(char) * 4); 
	
	int strSize2 = 4;
    int strIndex = 0;
    //match the first character
    if (str1[strIndex] == ','){
        str2[strIndex] = ' ';
        strIndex++;
    }
	
    str2[strIndex] = str1[0];
    strIndex++;
    
    for (int i = 1; i < strlen(str1); i++){
        // realloc space if not enough space
        if (strIndex + 3 >= strSize2){
            strSize2 *= 2;
			str2 = realloc(str2, strSize2);
        }
        // insert space between commas if nothing between them
        if (str1[i-1] == ',' && str1[i] == ','){
            str2[strIndex] = ' ';
            strIndex++;
        }
        str2[strIndex] = str1[i];
        strIndex++;
    }
    // seal string2
    str2[strIndex] = '\0';
    return str2;
}

/*
freeFootpath free the memory allocated to the footpath_t
*/
void freeFootpath(footpath_t *fp){
	//free all the attributes 
	free(fp->footpath_id);
	free(fp->address);
	free(fp->clue_sa);
	free(fp->asset_type);
	free(fp->deltaz);
	free(fp->distance);
	free(fp->grade1in);
	free(fp->mcc_id);
	free(fp->mccid_int);
	free(fp->rlmax);
	free(fp->rlmin);
	free(fp->segside);
	free(fp->statusid);
	free(fp->streetid);
	free(fp->street_group);
	free(fp->start_lat);
	free(fp->start_lon);
	free(fp->end_lat);
	free(fp->end_lon);

	free(fp);
}
