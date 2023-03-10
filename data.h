/** ***********************
* C Programming Style for Algorithms and Data Structures (COMP20003_2022_SM2)
* Created by Chang Xu (xucm@student.unimelb.edu.au) 11/08/2022
*/

#ifndef _DATA_H_
#define _DATA_H_

//constant defnitions
#define MAX_LINE_LEN 512
#define MAX_CHAR_LEN 128

//footpath structure definition
//store all the values as string
//only convert the double data to double format for computation

struct footpath {
	char *footpath_id;  
    char *address; 
    char *clue_sa;     
    char *asset_type;   
    char *deltaz;     
    char *distance;    
    char *grade1in; 
    char *mcc_id;  
    char *mccid_int;    
    char *rlmax;       
    char *rlmin; 
    char *segside;
    char *statusid;
    char *streetid;
    char *street_group;
    char *start_lat;   
    char *start_lon;
    char *end_lat;    
    char *end_lon;
};
typedef struct footpath footpath_t;

//function prototypes
/*
read from input file for details regarding each footpath
the function aims to build an linkedlist/dictionary of 
all the footpaths and returns the pointer to the head 
or NULL if reading is unsuccessful
*/
footpath_t *readFootpath(FILE *f);

/*
read a string and add a space between two neighbouring 
commas if if was empty in between
e.g. input string: "a,b,,c", 
the return output: "a,b, ,c"
*/
char *reformatString(char *str1);

/*
freeFootpath free the memory allocated to the footpath_t
*/
void freeFootpath(footpath_t *fp);

#endif
