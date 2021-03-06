/* Defining the macro LENGTH to 80 to be used as a constant for the ID array size    */
#define LENGTH 80

/* Setting the global variable tuplec to be 0 when the program is started     */
int tuplec = 0;

/* Creating a union of elements to be used in the struct tuple_t     */
typedef union type_t{

    char c;
    int i;
    long int l;
    char s[10];
    float f;
    double d;

}type;

/* Creating a struct for the tuples to be created      */
typedef struct tuple_t{

    char ID[LENGTH];
    char colon[19];
    type elements[9];
    int howMany;

}tuple;


/*                              FUNCTION PROTOTYPES                              */

void resizeArray(tuple * tupleArray);

void createTuple(tuple * tupleArray);

tuple * getTupleByID(tuple * tupleArray);

char * getTupleID(tuple * tupleArray);

void showTuple(tuple * tupleArray);

void deleteTuple(tuple * tupleArray);

int cmpTuples(tuple * tupleArray);

void joinTuples(tuple * tupleArray);

void saveAllTuples(tuple * tupleArray);

void loadAllTuples();


