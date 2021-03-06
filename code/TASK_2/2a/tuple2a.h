
/* Defining the macro SIZE to 15 to be used as a constant for the array ID size    */
#define LENGTH 15

/* Initialising the global variable counter to 0 for now     */
int counter = 0;

/* The structure being used for the tuple being created in this task     */
typedef struct tuple_t{

    char ID[LENGTH];
    int element1;
    int element2;
    int element3;

}tuple;

/*                              FUNCTION PROTOTYPES                              */

/* A void function which does not return anything but makes use of the realloc   */
/* function to resize the size of the array based on the amount of tuples        */
void resizeArray(tuple * tupleArray);

/* A void function which creates a tuple based on the defined struct above       */
/* The user is asked to enter a string ID for the tuple being created and 3      */
/* integer elements in all which are then all stored on the heap to be accessed  */
/* whenever needed                                                               */
void createTuple(tuple * tupleArray);

/* A function which asks the user to input an existing string ID and returns the */
/* corresponding pointer                                                         */
tuple * getTupleByID(tuple * tupleArray);

/* A function which returns a tuple's string ID after being given it's pointer   */
/* by the user                                                                   */
char * getTupleID(tuple * tupleArray);

/* A void function which simply displays the contents of a particular tuple after*/
/* the user provides it with the correct pointer */
void showTuple(tuple * tupleArray);

/* A function which deletes a tuple object when the user enters it's string ID   */
void deleteTuple(tuple * tupleArray);

/* The user is asked to enter the string ID of 2 tuples to be compared           */
/* An in-order comparison of their elements follows and a 1 is returned if the   */
/* first non-equal element pair is larger for the first entered tuple, a -1 if   */
/* the opposite case is encountered and 0 if all elements are equal              */
int cmpTuples(tuple * tupleArray);

/* A void function which asks for 2 existing string IDs and creates a copy of the*/
/* contents stored in the first and saves this copy as a new tuple               */
void joinTuples(tuple * tupleArray);

/* A function which stores all the created tuples in a folder                    */
void saveAllTuples(tuple * tupleArray);

/* A function which loads all the previously stored functions from a folder      */
void loadAllTuples();