/*                              PREPROCESSOR DIRECTIVES                         */

/* Incluing the stdio.h library which is C's Standard Input and Output          */
/* Library comprising of basic functions                                        */
#include <stdio.h>

/* Including the string.h library which defines several functions that          */
/* manipulate C strings and arrays                                              */
#include <string.h>

/* Including the stdlib.h library which contains a set of functions to general  */
/* purpose functions including memory management functions                      */
#include <stdlib.h>

/* Including the header file complementary to this source file                  */
/* This contains the defined macros, global variables and all function prototypes*/
#include "tuple2a.h"



/*                               FUNCTIONS                                       */

/* When resizeArray() function is called, execution continues from here           */
void resizeArray(tuple * tupleArray) {
    tupleArray = (tuple * ) realloc( tupleArray, counter * (sizeof(tuple)));
}

/* When createTuple() function is called, execution continues from here           */
void createTuple(tuple * tupleArray){

    /* Counter which loops in the for loop     */
    int i;

    /* Increments tuple count by 1     */
    ++counter;
    if(counter != 1){
        resizeArray(tupleArray);

        /* Clears input buffer from previously entered invalid data                 */
        while(getchar()!='\n');
    }

    printf("Creating Tuple #%d: \n\n", counter);
    printf("Please enter the tuple's string identifier (not more than 15 characters) :\n");

    fgets(tupleArray[counter - 1].ID, LENGTH, stdin);

    for(i = 0 ; i < counter - 1 ; i++){
        if( strcmp(tupleArray[counter - 1].ID, tupleArray[i].ID) == 0){
            deleteTuple(&tupleArray[i]);
        }
    }

    printf("Now enter the elements going to be stored in TUPLE #%d\n", counter);
    printf("You must enter 3 elements for each tuple\n\n");

    printf("Please enter element #1: ");
    while(scanf(" %d", &tupleArray[counter - 1].element1) != 1){
        printf("Ivalid data!! \nPlease enter an integer : \n");

        /* Clears input buffer from previously entered invalid data                 */
        while(getchar()!='\n');
    }

    printf("Please enter element #2: ");
    while(scanf(" %d", &tupleArray[counter - 1].element2) != 1){
        printf("Ivalid data!! \nPlease enter an integer : \n");

        /* Clears input buffer from previously entered invalid data                 */
        while(getchar()!='\n');
    }

    printf("Please enter element #3: ");
    while(scanf(" %d", &tupleArray[counter - 1].element3) != 1){//0
        printf("Ivalid data!! \nPlease enter an integer : \n");

        /* Clears input buffer from previously entered invalid data                 */
        while(getchar()!='\n');
    }

}

/* When * getTupleByID() function is called, execution continues from here           */
tuple * getTupleByID(tuple * tupleArray){

    /* Clears input buffer from previously entered invalid data                 */
    while (getchar() != '\n');

    /* Local variable i to be used in the for loop     */
    int i;

    /* Space big enough to store a whole string ID is allocated to be freed later on     */
    char * tupleid = (char *) malloc(LENGTH * sizeof(char));


    /* While loop runs infinitely unless the user enters the correct string ID      */
    /* and it returns a pointer to the main function     */
    while (1) {

        printf("Please enter the tuple string ID\n");
        fgets(tupleid, LENGTH, stdin);

        /* for loop which loops through all existing tuple IDs until it finds a matching one     */
        for (i = 0; i < counter; i++) {

            /* if statement which runs if the entered string matches some other tuple     */
            /* string ID already stored on the dynamic array     */
            if (strcmp(tupleid, tupleArray[i].ID) == 0) {

                printf("Tuple #%d found!! \n", i+1);

                /* The memory allocated earlier on the heap is now freed     */
                free(tupleid);

                /* A pointer associated to the entered string ID is returned back to main     */
                return &tupleArray[i];
            }
        }

        printf("Tuple with string ID %s not found.\n", tupleid);
        printf("Please try again.\n\n");


        /* Clears input buffer from previously entered invalid data                 */
        while (getchar() != '\n');
    }

}

/* When * getTupleID() function is called, execution continues from here           */
char * getTupleID(tuple * tupleArray){

    /* Local variable i to be used in the for loop     */
    int i;

    /* Pointer of type tuple is created     */
    tuple * pTuple;

    /* While loop runs infinitely unless the user enters the correct pointer      */
    /* and its corresponding string ID is returned back to the main function     */
    while (1) {

        printf("Enter the pointer of the tuple to get its ID:\n");
        scanf(" %p", &pTuple);

        /* for loop which loops through all existing tuple pointers until it finds a matching one     */
        for (i = 0; i < counter; i++) {

            /* if the entered pointer matches an existing one the code in the block executes */
            if ( pTuple == &tupleArray[i]) {

                printf("Tuple #%d found!! \n", i+1);

                /* The string ID corresponding to the matching pointer is returned back to main */
                return tupleArray[i].ID;
            }
        }

        printf("Tuple with memory address %p not found.\n", &pTuple);
        printf("Please try again.\n\n");

        /* Clears input buffer from previously entered invalid data                 */
        while (getchar() != '\n');


    }

}

/* When showTuple() function is called, execution continues from here           */
void showTuple(tuple * tupleArray) {

    /* Local variable i to be used in the for loop    */
    int i;

    /* A pointer of type tuple is declared     */
    tuple *pTuple;

    printf("Enter the tuple's pointer for the tuple you want to display:\n");
    /* Stores the pointer entered by the user to be compared     */
    scanf(" %p", &pTuple);

    /* A for loop which loops to find if the pointer entered by the user matches*/
    /* the pointer of an existing tuple*/
    for (i = 0 ; i < counter; i++) {

        /* If the pointer the user entered matches an existing one, a tuples contents are displayed*/
        if (pTuple == &tupleArray[i]) {
            printf("Tuple\tString Identifier\t\t\tElements\n");
            printf("---------------------------------------------------------------------------------------\n");

            printf("#%-3d \t%-17s\t\t\t\t\t(%d, %d, %d)", i+1, tupleArray[i].ID,
                    tupleArray[i].element1, tupleArray[i].element2, tupleArray[i].element3);

            printf("\n---------------------------------------------------------------------------------------\n");
        }
    }

}

/* When deleteTuple() function is called, execution continues from here           */
void deleteTuple(tuple * tupleArray){

    /* Clears input buffer from previously entered invalid data                 */
    while (getchar() != '\n');

    /* Initialises a local variable i to 0     */
    int i = 0;

    /* A pointer of type character is created to allocate memory on the heap   */
    char * del;
    del = (char*) malloc(LENGTH * sizeof(char));

    /* While loop runs infinitely unless the user enters the correct string ID      */
    /* and it returns back to the main function     */
    while(1) {

        printf("Enter the string identifier of the tuple you want to delete:\n");

        /* User enters the string ID of a tuple which is stored up till the     */
        /* 15th character entered on the heap     */
        fgets(del, LENGTH, stdin);

        /* A for loop which goes through all tuple IDs created     */
        for (i = 0 ; i < counter ; i++) {

            /* If a compared tuple ID matches what was entered by the user,     */
            /* the tuple is then deleted     */
            if (strncmp(del, tupleArray[i].ID, LENGTH) == 0) {

                printf("Tuple #%d found!! \n", i+1);

                /* The tuples content to be deleted are displayed one last time     */
                printf("Deleting %s containing (%d, %d, %d)\n", del, tupleArray[i].element1, tupleArray[i].element2,
                       tupleArray[i].element3);

                /* While loop which loops until i < counter     */
                while (i < counter) {

                    /* All that is stored in i+1 is written over what is stored in i     */
                    strcpy(tupleArray[i].ID, tupleArray[i+1].ID);
                    tupleArray[i].element1 = tupleArray[i+1].element1;
                    tupleArray[i].element2 = tupleArray[i+1].element2;
                    tupleArray[i].element3 = tupleArray[i+1].element3;

                    /* The value stored in i is incremented by one     */
                    i++;
                }

                /* The number of tuples is decremented by 1 since a tuple has been deleted     */
                --counter;

                /* Now that 1 less tuple is available, the memory allocated on the heap is resized     */
                resizeArray(tupleArray);

                /* The memory allocated on the heap for del is now freed     */
                free(del);

                /* The function returns nothing back to main     */
                return;
            }
        }

        printf("Tuple with string ID %s not found.\n", del);
        printf("Please try again.\n\n");

        /* Clears input buffer from previously entered invalid data                 */
        while (getchar() != '\n');

    }

}

/* When cmpTuples() function is called, execution continues from here           */
int cmpTuples(tuple * tupleArray) {

    /* Clears input buffer from previously entered invalid data                 */
    while (getchar() != '\n');

    /* 2 arrays of size LENGTH are created*/
    char cmp1[LENGTH];
    char cmp2[LENGTH];

    /* These local variables are initialised     */
    int i, j, k = 0;

    /* start of do while loop     */
    do {
    printf("Please enter the 1st string to compare:\n");
    /* The string entered up till the 15th character is stored in cmp1     */
    fgets(cmp1, LENGTH, stdin);

        /* for loop loops through all the existing tuple IDs */
        for (i = 0; i < counter; i++) {

            /* If the values entered by the user matches an existing ID, the code in the block runs */
            if ((strncmp(cmp1, tupleArray[i].ID, LENGTH) == 0)) {

                printf("Tuple #%d found!! \n", i + 1);

                /* The value of k is incremented by 1 */
                k++;

                /* breaks out of the statement if this part is reached     */
                break;
            }
        }
        /* While condition for looping is still valid, the loop continues looping */
    }while(k != 1);

    /* start of do while loop     */
    do {
        printf("Please enter the 2nd string to compare:\n");
        /* The string entered up till the 15th character is stored in cmp1     */
        fgets(cmp2, LENGTH, stdin);

        /* for loop loops through all the existing tuple IDs */
        for (j = 0; j < counter; j++) {

            /* If the values entered by the user matches an existing ID, the code in the block runs */
            if ((strncmp(cmp2, tupleArray[j].ID, LENGTH) == 0)) {

                printf("Tuple #%d found!! \n", j + 1);

                /* The value of k is incremented by 1 */
                k++;

                /* breaks out of the statement if this part is reached     */
                break;
            }
        }
        /* While condition for looping is still valid, the loop continues looping */
    }while(k != 2);

    /* Block of code whicch determines what should be returned based on the values     */
    /* stored in the elements of the tuples being compared     */
    if (tupleArray[i].element1 > tupleArray[j].element1) {

        return 1;
    } else if (tupleArray[i].element1 < tupleArray[j].element1) {

        return -1;
    } else {

        if (tupleArray[i].element2 > tupleArray[j].element2) {

            return 1;
        } else if (tupleArray[i].element2 < tupleArray[j].element2) {

            return -1;
        } else {

            if (tupleArray[i].element3 > tupleArray[j].element3) {

                return 1;
            } else if (tupleArray[i].element3 < tupleArray[j].element3) {

                return -1;
            } else {

                return 0;
            }
        }
    }
}

/* When joinTuples() function is called, execution continues from here           */
void joinTuples(tuple * tupleArray) {

    /* Three local variables are initialised     */
    int i, j, k=0;

    /* 2 tuple pointers of type tuple are created     */
    tuple *pTuple1, *pTuple2;

    /* An array called join of size LENGTH is initialised     */
    char join[LENGTH];

    /* Clears input buffer from previously entered invalid data                 */
    while (getchar() != '\n');

    printf("Enter the String ID of the new tuple to be created: \n");
    fgets(join, LENGTH, stdin);


    /* Start of do while loop     */
    do {
        printf("Enter the 1st tuple's pointer:\n");
        /* Stores the pointer entered by the user to be compared     */
        scanf(" %p", &pTuple1);

        /* Loops through all the existing tuple pointers     */
        for (i = 0; i < counter; i++) {

            /* If the pointer entered matches an existing tuple pointer     */
            /* the code included in this block is executed     */
            if (pTuple1 == &tupleArray[i]) {

                printf("Tuple #%d found!! \n", i + 1);

                /* Increments k by 1     */
                k++;

                /* breaks out of the statement if this part is reached     */
                break;
            }
        }

        /* Clears input buffer from previously entered invalid data                 */
        while (getchar() != '\n');

    }while(k != 1);

    /* Start of do while loop     */
    do {

        printf("Enter the 2nd tuple's pointer:\n");
        /* Stores the pointer entered by the user to be compared     */
        scanf(" %p", &pTuple2);

        /* Loops through all the existing tuple pointers     */
        for (j = 0; j < counter; j++) {

            /* If the pointer entered matches an existing tuple pointer     */
            /* the code included in this block is executed     */
            if (pTuple2 == &tupleArray[j]) {

                printf("Tuple #%d found!! \n", j + 1);

                /* Increments k by 1     */
                k++;

                /* breaks out of the statement if this part is reached     */
                break;
            }
        }

        /* Clears input buffer from previously entered invalid data                 */
        while (getchar() != '\n');

        /* Loops while k is not equal to 2     */
    }while(k != 2);

    /* Increments counter by 1     */
    ++counter;

    /* Calls resize array function now that an extra tuple is created     */
    resizeArray(tupleArray);

    /* Copies the string stored in join as the string ID of the new tuple     */
    strcpy(tupleArray[counter-1].ID, join);

    /* Copies the elements stored in the first entered tuple to the newly created one*/
    tupleArray[counter-1].element1 = tupleArray[i].element1;
    tupleArray[counter-1].element2 = tupleArray[i].element2;
    tupleArray[counter-1].element3 = tupleArray[i].element3;
}

/* When saveAllTuples() function is called, execution continues from here           */
void saveAllTuples(tuple * tupleArray){

    /* Local variable i to be used in the for loop    */
    int i;

    /* Creating a file pointer     */
    FILE *fp;

    /* Opens/creates the file in write mode and if already exits, then data is overwritten */
    fp = fopen("SaveTuples.txt", "w");

    /* Prints out the following into the file */
    fputs("Tuple\tString Identifier\n", fp);
    fputs("------------------------------------------\n", fp);

    /* Loops based on the number of tuples and stores their contents into this file*/
    for(i = 0 ; i < counter ; i++){
        fprintf(fp, "%-5d\t%-10s\t%-6d\t%-6d\t%-6d\n", i+1, tupleArray[i].ID,
                tupleArray[i].element1, tupleArray[i].element2, tupleArray[i].element3);
    }

    /* Prints out the following into the file */
    fputs("\n-----------------------------------------\n", fp);

    /* Closes a stream (in this case a file) and all the structure associated with it */
    fclose(fp);

    printf("Tuples Saved Successfully!!\n\n");

}

/* When loadAllTuples() function is called, execution continues from here           */
void loadAllTuples(){

    /* Creating a file pointer     */
    FILE *fp;

    /* Setting the local variable length the size of 2*(all the pointers)     */
    int length = 2*(counter * (sizeof(tuple)));

    /* Allocating memory on the heap big enough to load contents from file     */
    char * temp = (char*) malloc(sizeof(length));

    /* if the file doesn't exist the code in the block runs */
    if ((fp = fopen("SaveTuples.txt", "r")) == NULL)
    {
        printf("Can't open \"SaveTuples.txt\" file.\n");
        printf("No tuples have been created yet\n");

        /* Closes a stream (in this case a file) and all the structure associated with it */
        fclose(fp);

        /* Freeing the previously allocated memory from the heap     */
        free(temp);

        /* Returns back to main */
        return;
    }else{

        /* Opens the file in read mode */
        fp = fopen("SaveTuples.txt", "r");

        /* while the end of the file hasn't been reached, characters will be stored onto the heap*/
        /* and then printed out through the puts function */
        while(!feof(fp)){
            fgets(temp, length, fp);
            puts(temp);
        }

    }
    putchar('\n');
    printf("--------------END OF FILE--------------\n");

    /* Closes a stream (in this case a file) and all the structure associated with it */
    fclose(fp);

    /* Freeing the previously allocated memory from the heap     */
    free(temp);

}
