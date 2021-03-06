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
#include "tuple2b.h"



/*                               FUNCTIONS                                       */

/* When resizeArray() function is called, execution continues from here           */
void resizeArray(tuple * tupleArray) {

    /* The dynamic array is resized on the heap the size of another tuple     */
    tupleArray = (tuple * ) realloc( tupleArray, tuplec * sizeof(tupleArray) );
}

/* When createTuple() function is called, execution continues from here           */
void createTuple(tuple * tupleArray){

    /* Counter which loops in the for loop     */
    int i;

    /* Stores the type identifier entered by the user */
    char type;

    /* Increments tuple count by 1     */
    ++tuplec;

    /* If statement executes only if one tuple already exists to make space for another     */
    if(tuplec != 1) {

        /* Calling of resizeArray function to widen the dynamic array size for another tuple*/
        resizeArray(tupleArray);

        /* Clears input buffer from previously entered invalid data                 */
        while(getchar()!='\n');
    }

    printf("Please enter the tuple's string identifier (not more than 80 characters) :\n");

    /* fgets is used to store what is entered by the user into the tupleArray[tuplec-1].ID    */
    fgets(tupleArray[tuplec-1].ID, LENGTH, stdin);

    for(i = 0 ; i < tuplec - 1 ; i++){
        if( strcmp(tupleArray[tuplec - 1].ID, tupleArray[i].ID) == 0){
            deleteTuple(&tupleArray[i]);
        }
    }


    printf("\n-----Creating Tuple #%d----- \n\n", tuplec);
    printf("How many elements would you like to store in this tuple? \n");
    printf("(Not less than 1 and not more than 9)\n");

    /* If something other than an integer is entered or a value which is larger than 9 */
    /* or smaller than 1, this while loop runs prompting the user to enter the appropriate data type and value */
    while((scanf(" %d", &tupleArray[tuplec-1].howMany) != 1) || (tupleArray[tuplec-1].howMany < 1) || (tupleArray[tuplec-1].howMany > 9)){
        printf("Ivalid data!! \nPlease enter a number from 1 - 9 : \n");

        /* Clears input buffer from previously entered invalid data                 */
        while(getchar()!='\n');
    }

    /* A function which converts the integer value entered by the user to a null-terminated string    */
    itoa(tupleArray[tuplec-1].howMany, tupleArray[tuplec-1].colon, 10);

    /* A legend is printed out on the screen to explain to the user what data to enter     */
    printf("----------------------------------------\n");
    printf("\t\tLEGEND \n");
    printf("\tEnter 'c' for char\n");
    printf("\tEnter 'i' for int\n");
    printf("\tEnter 'l' for long int\n");
    printf("\tEnter 's' for string\n");
    printf("\tEnter 'f' for float\n");
    printf("\tEnter 'd' for double\n");
    printf("----------------------------------------\n\n");

    /* A for loop runs based on the value howMany entered by the user     */
    for(i = 0 ; i < tupleArray[tuplec-1].howMany ; i++) {
        printf("ELEMENT #%d: \n", i + 1);
        printf("What data type do you want to store?\n");
        printf("Enter (c/i/l/s/f/d)\n");

        /* Clears input buffer from previously entered data                 */
        while (getchar() != '\n');

        /* Validation is performed to ensure that the user enters the available options     */
        while ((scanf(" %c", &type) != 1) || ((type != 'c') && (type != 'i') && (type != 'l')
                                              && (type != 's') && (type != 'f') && (type != 'd'))) {

            printf("Ivalid input!! \nPlease enter a character from the legend above : \n");

            /* Clears input buffer from previously entered invalid data                 */
            while (getchar() != '\n');
        }

        /* if user enters 'c', this part of the if statement will run     */
        if (type == 'c') {

            printf("Enter the character: ");

            /* Clears input buffer from previously entered data                 */
            while (getchar() != '\n');

            /* If something other than a character is entered, this while loop runs prompting*/
            /* the user to enter the appropriate data type                                   */
            while (scanf(" %c", &tupleArray[tuplec-1].elements[i].c) != 1) {
                printf("\nIvalid info!! \nPlease enter a character : \n");

                /* Clears input buffer from previously entered data                 */
                while (getchar() != '\n');
            }

            /* Concatenates :c to the rest of the colon delimited string     */
            strcat(tupleArray[tuplec-1].colon, ":c");

            /* else if user enters 'i', this part of the if statement will run     */
        } else if (type == 'i') {

            printf("Enter the integer: ");

            /* Clears input buffer from previously entered data                 */
            while (getchar() != '\n');

            /* If something other than an integer is entered, this while loop runs prompting*/
            /* the user to enter the appropriate data type                                  */
            while (scanf(" %d", &tupleArray[tuplec-1].elements[i].i) != 1) {
                printf("\nIvalid data!! \nPlease enter an integer : \n");

                /* Clears input buffer from previously entered invalid data                 */
                while (getchar() != '\n');
            }

            /* Concatenates :c to the rest of the colon delimited string     */
            strcat(tupleArray[tuplec-1].colon, ":i");

            /* else if user enters 'l', this part of the if statement will run     */
        } else if (type == 'l') {

            printf("Enter the long integer: ");

            /* Clears input buffer from previously entered data                 */
            while (getchar() != '\n');

            /* If something other than a long integer is entered, this while loop runs prompting*/
            /* the user to enter the appropriate data type                                  */
            while (scanf(" %ld", &tupleArray[tuplec-1].elements[i].l) != 1) {
                printf("\nIvalid data!! \nPlease enter a long integer : \n");

                /* Clears input buffer from previously entered invalid data                 */
                while (getchar() != '\n');
            }

            /* Concatenates :l to the rest of the colon delimited string     */
            strcat(tupleArray[tuplec-1].colon, ":l");

            /* else if user enters 's', this part of the if statement will run     */
        } else if (type == 's') {

            printf("Enter the string: \n");
            printf("(Do not enter more than 10 characters)\n");

            /* Clears input buffer from previously entered data                 */
            while (getchar() != '\n');

            /* Stores what the user enters up till the 10th character to the tupleArray */
            fgets(tupleArray[tuplec-1].elements[i].s, 10, stdin);

            /* Concatenates :s to the rest of the colon delimited string     */
            strcat(tupleArray[tuplec-1].colon, ":s");

            /* else if user enters 'f', this part of the if statement will run     */
        } else if (type == 'f') {

            printf("Enter the float value: ");

            /* Clears input buffer from previously entered data                 */
            while (getchar() != '\n');

            /* If something other than a float is entered, this while loop runs prompting*/
            /* the user to enter the appropriate data type                                  */
            while (scanf(" %f", &tupleArray[tuplec-1].elements[i].f) != 1) {
                printf("\nIvalid data!! \nPlease enter a float : \n");

                /* Clears input buffer from previously entered invalid data                 */
                while (getchar() != '\n');
            }

            /* Concatenates :f to the rest of the colon delimited string     */
            strcat(tupleArray[tuplec-1].colon, ":f");

            /* else if user enters 'd', this part of the if statement will run     */
        } else if (type == 'd') {

            printf("Enter the double value: ");

            /* Clears input buffer from previously entered data                 */
            while (getchar() != '\n');

            /* If something other than a double value is entered, this while loop runs prompting*/
            /* the user to enter the appropriate data type                                  */
            while (scanf(" %lf", &tupleArray[tuplec-1].elements[i].d) != 1) {
                printf("\nIvalid data!! \nPlease enter a double value : \n");

                /* Clears input buffer from previously entered invalid data                 */
                while (getchar() != '\n');
            }

            /* Concatenates :d to the rest of the colon delimited string     */
            strcat(tupleArray[tuplec-1].colon, ":d");

        }
    }

}

/* When * getTupleByID() function is called, execution continues from here           */
tuple * getTupleByID(tuple * tupleArray){

    /* Clears input buffer from previously entered data                 */
    while (getchar() != '\n');

    /* Local variable i to be used in the for loop     */
    int i;

    /* Space big enough to store a whole string ID is allocated to be freed later on     */
    char * tupleid = (char *) malloc(LENGTH * sizeof(char));

    /* While loop runs infinitely unless the user enters the correct string ID      */
    /* and it returns a pointer to the main function     */
    while (1) {

        printf("Enter the string identifier of the tuple:\n");
        fgets(tupleid, LENGTH, stdin);

        /* for loop which loops through all existing tuple IDs until it finds a matching one     */
        for (i = 0; i < tuplec; i++) {

            /* if statement which runs if the entered string matches some other tuple     */
            /* string ID already stored on the dynamic array     */
            if (strncmp(tupleid, tupleArray[i].ID, LENGTH) == 0) {

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
        for (i = 0 ; i < tuplec ; i++) {

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

    /* Local variables i and j to be used in the for loops    */
    int i, j;

    /* A pointer of type tuple is declared     */
    tuple * pTuple;

    /* A pointer of type char is declared     */
    char * delim;

    printf("Enter the tuple's pointer for the tuple you want to display:\n");
    /* Stores the pointer entered by the user to be compared     */
    scanf(" %p", &pTuple);

    for (i = 0; i < tuplec; i++) {
        if (pTuple == &tupleArray[i]) {
            printf("---------------------------------------------------------------------------------------\n");
            printf("Tuple # %d\n", i+1);
            printf("String ID : %s\n", tupleArray[i].ID);
            printf("Colon Delimited String: %s\n", tupleArray[i].colon );
            delim = strtok(tupleArray[i].colon, ":");
            delim = strtok(NULL, ":");
            printf("There are a total of %s elements stored in this tuple\n", delim);
            printf("These are: \n");

            for (j = 0; j < tupleArray[i].howMany; j++) {

                if (delim != NULL) {
                    printf("%s : ", delim);

                    if(*delim == 'c'){

                        //Prints out value stored in tupleArray[i].elements[j].c

                        printf(" %c \n", tupleArray[i].elements[j].c);

                    }else if(*delim == 'i'){

                        //Prints out value stored in tupleArray[i].elements[j].i

                        printf(" %d \n", tupleArray[i].elements[j].i);

                    }else if(*delim == 'l'){

                        //Prints out value stored in tupleArray[i].elements[j].l

                        printf(" %ld \n", tupleArray[i].elements[j].l);

                    }else if(*delim == 's'){

                        //Prints out value stored in tupleArray[i].elements[j].s

                        printf(" %s \n", tupleArray[i].elements[j].s);

                    }else if(*delim == 'f'){

                        //Prints out value stored in tupleArray[i].elements[j].f

                        printf(" %f \n", tupleArray[i].elements[j].f);

                    }else if(*delim == 'd') {

                        //Prints out value stored in tupleArray[i].elements[j].d

                        printf(" %lf \n", tupleArray[i].elements[j].d);

                    }
                    //This makes the pointer of delim to skip past the next separator
                    delim = strtok(NULL, ":");
                }
            }
            printf("---------------------------------------------------------------------------------------\n");
        }
    }
}

/* When deleteTuple() function is called, execution continues from here           */
void deleteTuple(tuple * tupleArray){

    /* Clears input buffer from previously entered data                 */
    while (getchar() != '\n');

    /* Local variables i and j to be used in the for loops    */
    int i, j;

    /* A pointer to character is created*/
    char * delim;

    /* Memory is allocated on the heap*/
    char * del;
    del = (char*) malloc(LENGTH * sizeof(char));

    while(1) {

        printf("Enter the string identifier of the tuple you want to delete:\n");
        fgets(del, LENGTH, stdin);

        for (i = 0 ; i < tuplec ; i++) {

            if (strncmp(del, tupleArray[i].ID, LENGTH) == 0) {

                printf("Tuple #%d found!! \n", i+1);
                printf("Deleting %s \n", del);

                while (i < tuplec) {
                    strcpy(tupleArray[i].ID, tupleArray[i+1].ID);
                    strcpy(tupleArray[i].colon, tupleArray[i+1].colon);
                    tupleArray[i].howMany = tupleArray[i+1].howMany;

                    delim = strtok(tupleArray[i].colon, ":");

                    //loops the amount of elements stored in i+1
                    for(j = 0 ; j < tupleArray[i+1].howMany ; j++){

                        //runs only if the value pointed to by delim is != NULL
                        if (delim != NULL) {

                            //if the dereferenced value of delim == c run this
                            if(*delim == 'c'){

                                 tupleArray[i].elements[j].c = tupleArray[i+1].elements[j].c;

                                //if the dereferenced value of delim == i run this
                            }else if(*delim == 'i'){

                                tupleArray[i].elements[j].i = tupleArray[i+1].elements[j].i;

                                //if the dereferenced value of delim == l run this
                            }else if(*delim == 'l'){

                                tupleArray[i].elements[j].l = tupleArray[i+1].elements[j].l;

                                //if the dereferenced value of delim == s run this
                            }else if(*delim == 's'){

                                strcpy(tupleArray[i].elements[j].s, tupleArray[i+1].elements[j].s);

                                //if the dereferenced value of delim == f run this
                            }else if(*delim == 'f'){

                                tupleArray[i].elements[j].f = tupleArray[i+1].elements[j].f;

                                //if the dereferenced value of delim == d run this
                            }else if(*delim == 'd') {

                                tupleArray[i].elements[j].d = tupleArray[i+1].elements[j].d;

                            }
                            delim = strtok(NULL, ":");
                        }

                    }

                    /* i is incremented by 1*/
                    i++;
                }

                /* The tuple count is decremented by 1*/
                --tuplec;

                /* The resizeArray() function is called once more to remove the extra space */
                resizeArray(tupleArray);

                /* The previously allocated space on the heap is now freed */
                free(del);

                /* Program is returned back to the main function */
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

    /* Clears input buffer from previously entered data                 */
    while (getchar() != '\n');

    char *cmp1 = (char *) malloc(LENGTH * sizeof(char));
    char *cmp2 = (char *) malloc(LENGTH * sizeof(char));

    char *str1;

    int i, j, k=0, m, n=0;

    do {
        printf("Please enter the 1st string ID to compare:\n");
        fgets(cmp1, LENGTH, stdin);
        for (i = 0; i < tuplec; i++) {
            if ((strncmp(cmp1, tupleArray[i].ID, LENGTH) == 0)) {

                printf("Tuple #%d found!! \n", i+1);
                k++;
                break;
            }
        }
    }while(k != 1);

    do {
        printf("Please enter the 2nd string ID to compare:\n");
        fgets(cmp2, LENGTH, stdin);
        for (j = 0; j < tuplec; j++) {
            if ((strncmp(cmp2, tupleArray[j].ID, LENGTH) == 0)) {

                printf("Tuple #%d found!! \n", j+1);
                k++;
                break;
            }
        }
    }while(k != 2);

    free(cmp1);
    free(cmp2);

    if(strcmp(tupleArray[i].colon, tupleArray[j].colon) == 0){

        printf("The tuples %s and %s are of a compatible type to be compared", tupleArray[i].ID, tupleArray[j].ID);

        str1 = strtok(tupleArray[i].colon, ":");
        for (m = 0; m < tupleArray[i].howMany; m++) {

            if (str1 != NULL) {

                str1 = strtok(NULL, ":");

                if(*str1 == 'c'){

                    if(tupleArray[i].elements[m].c > tupleArray[j].elements[m].c){
                        return 1;
                    }else if(tupleArray[i].elements[m].c < tupleArray[j].elements[m].c){
                        return -1;
                    }else if(tupleArray[i].elements[m].c == tupleArray[j].elements[m].c){
                        n++;
                        if(n == tupleArray[j].howMany) {
                            return 0;
                        }
                        continue;
                    }

                }else if(*str1 == 'i'){

                    if(tupleArray[i].elements[m].i > tupleArray[j].elements[m].i){
                        return 1;
                    }else if(tupleArray[i].elements[m].i < tupleArray[j].elements[m].i){
                        return -1;
                    }else if(tupleArray[i].elements[m].i == tupleArray[j].elements[m].i){
                        n++;
                        if(n == tupleArray[i].howMany) {
                            return 0;
                        }
                        continue;
                    }

                }else if(*str1 == 'l'){

                    if(tupleArray[i].elements[m].l > tupleArray[j].elements[m].l){
                        return 1;
                    }else if(tupleArray[i].elements[m].l < tupleArray[j].elements[m].l){
                        return -1;
                    }else if(tupleArray[i].elements[m].l == tupleArray[j].elements[m].l){
                        n++;
                        if(n == tupleArray[i].howMany) {
                            return 0;
                        }
                        continue;
                    }

                }else if(*str1 == 's'){

                    if(tupleArray[i].elements[m].s > tupleArray[j].elements[m].s){
                        return 1;
                    }else if(tupleArray[i].elements[m].s < tupleArray[j].elements[m].s){
                        return -1;
                    }else if (strcmp(tupleArray[i].elements[m].s, tupleArray[j].elements[m].s) == 0){
                        n++;
                        if(n == tupleArray[i].howMany) {
                            return 0;
                        }
                        continue;
                    }

                }else if(*str1 == 'f'){

                    if(tupleArray[i].elements[m].f > tupleArray[j].elements[m].f){
                        return 1;
                    }else if(tupleArray[i].elements[m].f < tupleArray[j].elements[m].f){
                        return -1;
                    }else if (tupleArray[i].elements[m].f == tupleArray[j].elements[m].f){
                        n++;
                        if(n == tupleArray[i].howMany) {
                            return 0;
                        }
                        continue;
                    }

                }else if(*str1 == 'd') {

                    if(tupleArray[i].elements[m].d > tupleArray[j].elements[m].d){
                        return 1;
                    }else if(tupleArray[i].elements[m].d < tupleArray[j].elements[m].d){
                        return -1;
                    }else if(tupleArray[i].elements[m].d == tupleArray[j].elements[m].d){
                        n++;
                        if(n == tupleArray[i].howMany) {
                            return 0;
                        }
                    }

                }
            }

        }

    }else{

        printf("Tuples are of different types and therefore cannot be compared!\n");
        return 9999999;
    }

        return 9999999;
}

/* When joinTuples() function is called, execution continues from here           */
void joinTuples(tuple * tupleArray) {

    /* Clears input buffer from previously entered data                 */
    while (getchar() != '\n');

    /* Declaring some variables local to this function*/
    int i, j, k = 0, m;


    tuple *pTuple1, *pTuple2;


    char *str1;
    char *str2;


    char * join = (char *) malloc(LENGTH * sizeof(char));

    printf("Enter the String ID of the new tuple to be created: \n");
    fgets(join, LENGTH, stdin);


    /* Start of do while loop     */
    do {

        printf("Enter the 1st tuple's pointer:\n");
        /* Stores the pointer entered by the user to be compared     */
        scanf(" %p", &pTuple1);

        /* Loops through all the existing tuple pointers     */
        for (i = 0; i < tuplec; i++) {

            /* If the pointer entered matches an existing tuple pointer     */
            /* the code included in this block is executed     */
            if (pTuple1 == &tupleArray[i]) {

                printf("Tuple #%d found!! \n", i+1);

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
        for (j = 0; j < tuplec; j++) {

            /* If the pointer entered matches an existing tuple pointer     */
            /* the code included in this block is executed     */
            if (pTuple2 == &tupleArray[j]) {

                printf("Tuple #%d found!! \n", j+1);

                /* Increments k by 1     */
                k++;

                /* breaks out of the statement if this part is reached     */
                break;
            }
        }


        /* Clears input buffer from previously entered invalid data                 */
        while (getchar() != '\n');

    }while(k != 2);

    if((tupleArray[i].howMany + tupleArray[i].howMany) > 10 ){

        free(join);

        printf("The tuples cannot be joined since their elements together exceed 9, the max expected size");

        return;
    }else{

        ++tuplec;

        resizeArray(tupleArray);

        strcpy(tupleArray[tuplec-1].ID, join);

        tupleArray[tuplec-1].howMany = tupleArray[i].howMany + tupleArray[j].howMany;

        /* A function which converts the integer value for the size to a string    */
        itoa(tupleArray[tuplec-1].howMany, tupleArray[tuplec-1].colon, 10);

        str1 = strtok(tupleArray[i].colon, ":");
        str2 = strtok(tupleArray[j].colon, ":");


        for(m = 0 ; m < tupleArray[i].howMany ; m++){

            if (str1 != NULL) {

                str1 = strtok(NULL, ":");

                if(*str1 == 'c'){

                    tupleArray[tuplec-1].elements[m].c = tupleArray[tuplec-1].elements[i].c;

                    /* Concatenates :c to the rest of the colon delimited string     */
                    strcat(tupleArray[tuplec-1].colon, ":c");

                }else if(*str1 == 'i'){

                    tupleArray[tuplec-1].elements[m].i = tupleArray[tuplec-1].elements[i].i;

                    /* Concatenates :i to the rest of the colon delimited string     */
                    strcat(tupleArray[tuplec-1].colon, ":i");

                }else if(*str1 == 'l'){

                    tupleArray[tuplec-1].elements[m].l = tupleArray[tuplec-1].elements[i].l;

                    /* Concatenates :l to the rest of the colon delimited string     */
                    strcat(tupleArray[tuplec-1].colon, ":l");

                }else if(*str1 == 's'){

                    strcpy(tupleArray[tuplec-1].elements[m].s, tupleArray[tuplec-1].elements[i].s);

                    /* Concatenates :s to the rest of the colon delimited string     */
                    strcat(tupleArray[tuplec-1].colon, ":s");

                }else if(*str1 == 'f'){

                    tupleArray[tuplec-1].elements[m].f = tupleArray[tuplec-1].elements[i].f;

                    /* Concatenates :f to the rest of the colon delimited string     */
                    strcat(tupleArray[tuplec-1].colon, ":f");

                }else if(*str1 == 'd') {

                    tupleArray[tuplec-1].elements[m].d = tupleArray[tuplec-1].elements[i].d;

                    /* Concatenates :d to the rest of the colon delimited string     */
                    strcat(tupleArray[tuplec-1].colon, ":d");

                }
            }

        }

        for(m = tupleArray[i].howMany ; m < tupleArray[j].howMany ; m++){

            if (str2 != NULL) {

                str2 = strtok(NULL, ":");

                if(*str2 == 'c'){

                    tupleArray[tuplec-1].elements[m].c = tupleArray[tuplec-1].elements[j].c;

                    /* Concatenates :c to the rest of the colon delimited string     */
                    strcat(tupleArray[tuplec-1].colon, ":c");

                }else if(*str2 == 'i'){

                    tupleArray[tuplec-1].elements[m].i = tupleArray[tuplec-1].elements[j].i;

                    /* Concatenates :i to the rest of the colon delimited string     */
                    strcat(tupleArray[tuplec-1].colon, ":i");

                }else if(*str2 == 'l'){

                    tupleArray[tuplec-1].elements[m].l = tupleArray[tuplec-1].elements[j].l;

                    /* Concatenates :l to the rest of the colon delimited string     */
                    strcat(tupleArray[tuplec-1].colon, ":l");

                }else if(*str2 == 's'){

                    strcpy(tupleArray[tuplec-1].elements[m].s, tupleArray[tuplec-1].elements[j].s);

                    /* Concatenates :s to the rest of the colon delimited string     */
                    strcat(tupleArray[tuplec-1].colon, ":s");

                }else if(*str2 == 'f'){

                    tupleArray[tuplec-1].elements[m].f = tupleArray[tuplec-1].elements[j].f;

                    /* Concatenates :f to the rest of the colon delimited string     */
                    strcat(tupleArray[tuplec-1].colon, ":f");

                }else if(*str2 == 'd') {

                    tupleArray[tuplec-1].elements[m].d = tupleArray[tuplec-1].elements[j].d;

                    /* Concatenates :d to the rest of the colon delimited string     */
                    strcat(tupleArray[tuplec-1].colon, ":d");

                }
            }

        }

        free(join);

    }
}

/* When saveAllTuples() function is called, execution continues from here           */
void saveAllTuples(tuple * tupleArray){

    /* Local variables i and j to be used in the for loops    */
    int i, j;

    /* A character pointer */
    char * delim;

    /* Creating a file pointer     */
    FILE *fp;

    /* Opens/creates the file in write mode and if already exits, then data is overwritten */
    fp = fopen("SaveTuples2B.txt", "w");
    fputs("The tuples which have been saved are shown below\n", fp);
    fputs("-------------------------------------------------\n", fp);

    /* Loops based on the number of tuples and stores their contents into this file*/
    for(i = 0 ; i < tuplec ; i++){

        /* Prints out the following into the file */
        fprintf(fp, "Tuple %d \n", i+1);
        fprintf(fp, "String ID: %s \n", tupleArray[i].ID);
        fprintf(fp, "Colon Delimited String : %s \n", tupleArray[i].colon);

        delim = strtok(tupleArray[i].colon, ":");

        /* Loops as many times as howMany*/
        for(j = 0 ; j < tupleArray[i].howMany ; j++){

            if (delim != NULL) {

                /* Prints out the following into the file */
                fprintf(fp, "\nElement %d : ", j+1);


                delim = strtok(NULL, ":");

                /* If the dereferenced char stored in delim is equivalent to 'c',  */
                /* the code within the block is executed     */
                if(*delim == 'c'){

                    fprintf(fp ," %c \n", tupleArray[i].elements[j].c);

                    /* If the dereferenced char stored in delim is equivalent to 'i',  */
                    /* the code within the block is executed     */
                }else if(*delim == 'i'){

                    fprintf(fp, " %d \n", tupleArray[i].elements[j].i);

                    /* If the dereferenced char stored in delim is equivalent to 'l',  */
                    /* the code within the block is executed     */
                }else if(*delim == 'l'){

                    fprintf(fp, " %ld \n", tupleArray[i].elements[j].l);

                    /* If the dereferenced char stored in delim is equivalent to 's',  */
                    /* the code within the block is executed     */
                }else if(*delim == 's'){

                    fprintf(fp, " %s \n", tupleArray[i].elements[j].s);

                    /* If the dereferenced char stored in delim is equivalent to 'f',  */
                    /* the code within the block is executed     */
                }else if(*delim == 'f'){

                    fprintf(fp, " %f \n", tupleArray[i].elements[j].f);

                    /* If the dereferenced char stored in delim is equivalent to 'd',  */
                    /* the code within the block is executed     */
                }else if(*delim == 'd') {

                    fprintf(fp, " %lf \n", tupleArray[i].elements[j].d);

                }
            }

        }
        /* Prints out the following into the file */
        fputs("\n\n", fp);
    }

    /* Prints out the following into the file */
    fputs("-------------------------------------------------\n", fp);

    /* Closes a stream (in this case a file) and all the structure associated with it */
    fclose(fp);

    printf("Tuples Saved Successfully!!\n\n");

}

/* When loadAllTuples() function is called, execution continues from here           */
void loadAllTuples() {

    /* Creating a file pointer     */
    FILE *fp;

    /* Setting the local variable length the size of 2*(all the pointers)     */
    int length = 2 * (tuplec * (sizeof(tuple)));

    /* Allocating memory on the heap big enough to load contents from file     */
    char *temp = (char *) malloc(sizeof(length));

    /* if the file doesn't exist the code in the block runs */
    if ((fp = fopen("SaveTuples2B.txt", "r")) == NULL) {
        printf("Can't open \"SaveTuples.txt\" file.\n");
        printf("No tuples have been created yet\n");

        /* Closes a stream (in this case a file) and all the structure associated with it */
        fclose(fp);

        /* Freeing the previously allocated memory from the heap     */
        free(temp);

        /* Returns back to main */
        return;

    } else {

        /* Opens the file in read mode */
        fp = fopen("SaveTuples2B.txt", "r");

        /* while the end of the file hasn't been reached, characters will be stored onto the heap*/
        /* and then printed out through the puts function */
        while (!feof(fp)) {
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