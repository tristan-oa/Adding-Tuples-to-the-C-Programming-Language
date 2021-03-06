/* Including the tuple2a source file which consists of the libraries being used, */
/* all the fuctions created and the tuple2a.h header file too                    */
#include "tuple2a.c"

/* Including the testdriver2a header which contains the menu prototype and       */
/* function                                                                      */
#include "testdriver2a.h"

/*                              MAIN FUNCTION                                    */

/* The main function is the entry point of program. The program starts executing */
/* from here. This function returns an integer value of 0 if executed correctly  */
int main(void){

    /* Creating a pointer tupleArray of type tuple                               */
    tuple * tupleArray;

    /* tupleArray points to a memory location of size tuple which has just been  */
    /* allocated on the heap                                                     */
    tupleArray = (tuple *) malloc(sizeof(tuple));

    /* Creating a local variable choice to be used as a placeholder to store the */
    /* return of the function menu() when it is called                           */
    int choice;

    /* Creating a pointer to be used as a placeholder for the memory address*/
    /* returned in the getTupleByID() function     */
    tuple * pTuple2;

    /* Creating a character pointer to point to the returned string ID*/
    char * returnID3;

    /* Creating a local variable cmp6 to be used as a placeholder to store the   */
    /* return of the function cmpTuples() when it is called                      */
    int cmp6;

    /* Calling the create tuple function to force the user to create 2 tuples at */
    /* the start of the program                                                  */
    createTuple(tupleArray);
    createTuple(tupleArray);

    /* Start of the do while loop                                                */
    do{

        /* Calling the menu() function while storing the returned integer to the */
        /* variable choice declared previously                                   */
        choice = menu();

        /* Start of switch case                                                  */
        switch (choice) {

            case 0 : {

                printf("Bye!\n");

                /* Breaks out of the switch case back to the start of the do       */
                /* while loop and if the condition for looping is valid, then the  */
                /* loop runs again                                                 */
                break;
            }

                /* This piece of code runs if choice == 1                          */
            case 1 : {

                /* Calling the createTuple() function*/
                createTuple(tupleArray);

                /* Breaks out of the switch case back to the start of the do       */
                /* while loop and if the condition for looping is valid, then the  */
                /* loop runs again                                                 */
                break;
            }

                /* This piece of code runs if choice == 2                              */
            case 2 : {

                /* Calling the getTupleByID() function and storing the returned pointer*/
                /* in placeholder pTuple2*/
                pTuple2 = getTupleByID(tupleArray);

                /* Printing out returned pointer*/
                printf("This tuple has a pointer %p", pTuple2);

                /* Breaks out of the switch case back to the start of the do       */
                /* while loop and if the condition for looping is valid, then the  */
                /* loop runs again                                                 */
                break;
            }

                /* This piece of code runs if choice == 3                              */
            case 3: {

                /* Calling the getTupleID() function and storing result into returnID*/
                returnID3 = getTupleID(tupleArray);

                /* Printing out the returned tuple ID*/
                printf("This tuple has an ID : %s", returnID3);


                /* Breaks out of the switch case back to the start of the do       */
                /* while loop and if the condition for looping is valid, then the  */
                /* loop runs again                                                 */
                break;
            }

                /* This piece of code runs if choice == 4                              */
            case 4: {

                /* Calling the showTuple() function                                 */
                showTuple(tupleArray);

                /* Breaks out of the switch case back to the start of the do       */
                /* while loop and if the condition for looping is valid, then the  */
                /* loop runs again                                                 */
                break;
            }

                /* This piece of code runs if choice == 5                              */
            case 5: {

                /* Calling the deleteTuple() function                              */
                deleteTuple(tupleArray);

                /* Breaks out of the switch case back to the start of the do       */
                /* while loop and if the condition for looping is valid, then the  */
                /* loop runs again                                                 */
                break;
            }

                /* This piece of code runs if choice == 6                              */
            case 6: {

                /* Calling the cmpTuples() function and storing the integer value  */
                /* returned in placeholder cmp6*/
                cmp6 = cmpTuples(tupleArray);

                /* Printing out the returned cmp6*/
                printf("The value returned is %d", cmp6);


                /* Breaks out of the switch case back to the start of the do       */
                /* while loop and if the condition for looping is valid, then the  */
                /* loop runs again                                                 */
                break;
            }

                /* This piece of code runs if choice == 7                              */
            case 7: {

                /* Calling the cmpTuples() function                                */
                joinTuples(tupleArray);

                /* Breaks out of the switch case back to the start of the do       */
                /* while loop and if the condition for looping is valid, then the  */
                /* loop runs again                                                 */
                break;
            }

                /* This piece of code runs if choice == 8                              */
            case 8: {

                /* Calling the saveAllTuples() function                                */
                saveAllTuples(tupleArray);


                /* Breaks out of the switch case back to the start of the do       */
                /* while loop and if the condition for looping is valid, then the  */
                /* loop runs again                                                 */
                break;
            }

                /* This piece of code runs if choice == 9                              */
            case 9: {

                /* Calling the loadAllTuples() function                                */
                loadAllTuples();

                /* Breaks out of the switch case back to the start of the do       */
                /* while loop and if the condition for looping is valid, then the  */
                /* loop runs again                                                 */
                break;
            }

                /* This piece of code runs if the user enters any other number but 0-9 */
            default: {

                printf("Incorrect input!\nMake sure you enter a valid number between 0-9 from the list below.\n");

                /* Breaks out of the switch case back to the start of the do       */
                /* while loop and if the condition for looping is valid, then the  */
                /* loop runs again                                                 */
                break;
            }
        }

        /*Condition for looping. If choice == 0, the program stops looping          */
    }while(choice != 0);

    printf("\t--End of program--\n");

    /* The memory previously allocated to store the tuples on the heap is freed     */
    free(tupleArray);

    /* Program returns 0 just before finishing execution to indicate that it was    */
    /* successfully implemented                                                     */
    return 0;
}
