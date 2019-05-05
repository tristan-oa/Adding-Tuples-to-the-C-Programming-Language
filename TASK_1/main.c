/*                              PREPROCESSOR DIRECTIVES                         */

/* Incluing the stdio.h library which is C's Standard Input and Output          */
/* Library comprising of basic functions                                        */
#include <stdio.h>

/* Including the string.h library which defines several functions that          */
/* manipulate C strings and arrays                                              */
#include <string.h>

/* Including the ctype.h library which contains a set of functions to           */
/* classify and even transform individual characters                            */
#include <ctype.h>

/* Defining the macro SIZE to 100 to be used as a constant for the array size    */
#define SIZE 100


/*                              FUNCTION PROTOTYPES                              */

/* Displays a greeting message and prints out the available options to the user. */
/* Prompts the user to enter his choice between 1-3. If invalid, the user is     */
/* informed and asked once again. If the entered int value is in the given range,*/
/* it is returned back to the main function from where the function was called   */
int menu();

/* The following 3 functions are called if the user selects option '1' from the  */
/* menu. Each option prompts the user to enter a single dimension of the 3D      */
/* array being created. If invalid data is entered, the user is informed and     */
/* asked to enter data once again. These functions all return an integer value   */
/* back to the main function to be used to create the array                      */
int dimension1();
int dimension2();
int dimension3();

/* A void function which prompts the user to populate the created 3D array based */
/* on the previously inputted dimensions. To further aid the user, coordinates   */
/* for the {block, row, column} are shown with every prompt for data to ensure   */
/* that the user enters the correct data in the desired position. Data validation*/
/* is also implemented to ensure that the user stores int values in the array.   */
/* Parameters are passed through the function for the 3 dimensions of the array  */
/* (s1,s2 and s3) followed by the array itself. Being a void function, nothing   */
/* is returned back to the main function                                         */
void insertContents(int s1, int s2, int s3, int ar[s1][s2][s3]);

/* A void function which simply copies the contents of the 3D array created by   */
/* the user to a new array with the same dimensions. Five arguments are passed   */
/* this time with the first 3 being the array dimensions s1, s2 and s3 and the   */
/* remaining 2 being the original array and the newly created copy array. Being  */
/* a void function, nothing is returned back to the main function                */
void copyContents(int s1, int s2, int s3, int ar[s1][s2][s3], int copy[s1][s2][s3]);

/* A void function which displays the final version of the newly copied array.   */
/* This contains the 3 array dimensions passed as arguments as well as the copy  */
/* array itself. Being a void function, nothing is returned back to the main     */
/* function                                                                      */
void pasteContents(int s1, int s2, int s3, int copy[s1][s2][s3]);

/* This function is called if the user selects option 2 from the menu. It passes */
/* an array of strings previously entered by the user as an argument. It then    */
/* switches the order of individual words by printing out the first entered word */
/* at the end and vice versa. Being a void function, nothing is returned back to */
/* the main function                                                             */
void reverseString(char string[SIZE]);


/*                              MAIN FUNCTION                                    */

/* The main function is the entry point of program. The program starts executing */
/* from here. This function returns an integer value of 0 if executed correctly  */
int main(void) {

    /* Initialising the choice variable to use it as a placeholder when calling  */
    /* the menu() function                                                       */
    int choice;

    /* Initialising the 3 dimensions of the array to be created as integers      */
    /* These are then used as placeholders for each of the dimension functions   */
    int size1, size2, size3;

    /* Creating a string array with a capacity of 100 characters to store user   */
    /* input from choice 2                                                       */
    char str[SIZE];

    /* Start of the do while loop                                                */
    do {

        /* Calling the menu() function while storing the returned integer to the */
        /* variable choice declared previously                                   */
        choice = menu();

        /* Start of switch case                                                  */
        switch (choice) {

            /* This piece of code runs if choice == 1                            */
            case 1 : {

                printf("In this program a 3D array with dimensions of your choice will be created.\n");
                printf("Let's get started.\n\n");

                /* Calling all 3 dimension functions while storing the returned  */
                /* result in the placeholders declared previously                */
                size1 = dimension1();
                size2 = dimension2();
                size3 = dimension3();

                printf("All 3 dimensions were entered successfully.\n\n");

                /* Initialising an empty 3D array based on the dimensions entered*/
                /* by the user       */
                int array3d[size1][size2][size3];

                /* Another empty array is initialised with the same dimensions   */
                int copyArray[size1][size2][size3];


                /* Calls the insertContents() function while passing the 3       */
                /* dimension parameters as well as the original 3D array itself  */
                insertContents(size1, size2, size3, array3d);

                /* Calls the copyContents() function while passing once again the*/
                /* 3 dimensions as arguments together with the original array and*/
                /* the copy array too         */
                copyContents(size1, size2, size3, array3d, copyArray);

                /* Calls the pasteContents() function which has the 3 dimensions */
                /* and the newly copied array passed as arguments                */
                pasteContents(size1, size2, size3, copyArray);

                /* Breaks out of the switch case back to the start of the do       */
                /* while loop and if the condition for looping is valid, then the  */
                /* loop runs again                                                 */
                break;
            }

            /* This piece of code runs if choice == 2                            */
            case 2 : {

                printf("In this program a string of characters entered will have \n");
                printf("whole individual words reversed.\n\n");

                /* Using the puts function instead of printf() which prints out a */
                /* new line to the screen automatically                           */
                puts("To get started, enter a string of not more than 100 characters:");

                /* Clearing the output buffer from the \n automatically printed out*/
                /* by the puts function. If this line of code is not inserted here,*/
                /* the program assumes \n as input into the fgets() function       */
                fflush(stdin);

                /* Accepts standard input from the keyboard up till 100 characters */
                /* and stores what is entered in the string str         */
                fgets(str, SIZE, stdin);

                /* Calls the reverseString() function and passes str as argument   */
                reverseString(str);

                /* Breaks out of the switch case back to the start of the do       */
                /* while loop and if the condition for looping is valid, then the  */
                /* loop runs again                                                 */
                break;
            }

            /* This piece of code runs if choice == 3                              */
            case 3: {
                printf("Bye!\n");

                /* Breaks out of the switch case back to the start of the do       */
                /* while loop and if the condition for looping is valid, then the  */
                /* loop runs again                                                 */
                break;
            }

            /* This piece of code runs if choice is anything else but 1,2 or 3     */
            default: {

                printf("Incorrect input!\nMake sure you enter a valid number between 1-3 from the list below.\n");

                /* Clears input buffer from previously entered invalid data in menu*/
                while(getchar()!='\n');

                /* Breaks out of the switch case back to the start of the do       */
                /* while loop and if the condition for looping is valid, then the  */
                /* loop runs again                                                 */
                break;
            }
        }
     /*Condition for looping. If choice == 3, the program stops looping            */
    }while(choice != 3);

    printf("\t--End of program--");

    /* Program returns 0 just before finishing execution to indicate if it was     */
    /* successfully implemented                                                    */
    return 0;
}

/*                               FUNCTIONS                                          */

/* When menu() function is called, execution continues from here                   */
int menu(){

    /* Initialising this local variable to store the user's choice                 */
    int choice;

    printf("\n\n\n\t\tWelcome to this 3D Array program!\n");
    printf("------------------------------------------------------------------\n");
    printf("Choose one of the options below: \n\n");
    printf(" 1) Create a 3D array with dimensions and content of your choice and its\n");
    printf("    contents will be copied onto another array of the same dimensions.\n");
    printf("    A copy of the array created is then displayed.\n");
    printf(" 2) Reverse the order of individual words entered.\n");
    printf(" 3) QUIT\n\n");

    printf("CHOICE: ");

    /* If something other than an integer is entered, this while loop runs prompting*/
    /* the user to enter the appropriate data type                                  */
    while(scanf(" %d", &choice) != 1){
        printf("Ivalid data!! \nPlease enter a number from 1 - 3 : \n");

        /* Clears input buffer from previously entered invalid data                 */
        while(getchar()!='\n');
    }

    /* Puts the escape character \n onto the screen                                 */
    putchar('\n');

    /* Returns the value entered by the user back to the main() function            */
    return choice;
}

/* When dimension1() function is called, execution continues from here              */
int dimension1(){

    /* Initialising this local variable to store the user's choice                  */
    int s1;

    printf("Please enter the first dimension : ");

    /* If something other than an integer is entered, this while loop runs prompting*/
    /* the user to enter the appropriate data type                                  */
    while(scanf(" %d", &s1) != 1){
        printf("Incorrect input!! \nPlease input a number and press enter : \n");

        /* Clears input buffer from previously entered invalid data                 */
        while(getchar()!='\n');
    }

    /* Returns the value entered by the user back to the main() function            */
    return s1;
}

/* When dimension2() function is called, execution continues from here              */
int dimension2(){

    /* Initialising this local variable to store the user's choice                  */
    int s2;

    printf("Please enter the second dimension : ");

    /* If something other than an integer is entered, this while loop runs prompting*/
    /* the user to enter the appropriate data type                                  */
    while(scanf(" %d", &s2) != 1){
        printf("Incorrect input!! \nPlease input a number and press enter : \n");

        /* Clears input buffer from previously entered invalid data                 */
        while(getchar()!='\n');
    }

    /* Returns the value entered by the user back to the main() function            */
    return s2;
}

/* When dimension3() function is called, execution continues from here              */
int dimension3(){

    /* Initialising this local variable to store the user's choice                  */
    int s3;

    printf("Please enter the third dimension : ");

    /* If something other than an integer is entered, this while loop runs prompting*/
    /* the user to enter the appropriate data type                                  */
    while(scanf(" %d", &s3) != 1){
        printf("Incorrect input!! \nPlease input a number and press enter : \n");

        /* Clears input buffer from previously entered invalid data                 */
        while(getchar()!='\n');
    }

    /* Returns the value entered by the user back to the main() function            */
    return s3;
}

/* When insertContents() function is called, execution continues from here          */
void insertContents(int s1, int s2, int s3, int ar[s1][s2][s3]){

    /* Initialising these local variables to be used in the for loops               */
    int block, row, col;

    printf("The array contents need to be inserted next.\n");

    /* For loops loop through the empty array to allow the user to fill up the array*/
    for(block = 0 ; block < s1 ; block++){
        for(row = 0 ; row < s2 ; row++) {
            for (col = 0; col < s3; col++) {

                /* Displays the coordinates of where the user will be storing       */
                printf("Enter the contents for {%d, %d, %d}: \n", block + 1, row + 1, col + 1);


                /* If something other than an integer is entered, this while loop   */
                /* runs prompting the user to enter the appropriate data type       */
                while(scanf(" %d", &ar[block][row][col]) != 1){
                    printf("Invalid input!! \nPlease input an integer : \n");

                    /* Clears input buffer from previously entered invalid data     */
                    while(getchar()!='\n');
                }

            }
        }
    }
    /* Nothing is returned back to main because this is a void function             */
}

/* When copyContents() function is called, execution continues from here            */
void copyContents(int s1, int s2, int s3, int ar[s1][s2][s3], int copy[s1][s2][s3]){

    /* Initialising these local variables to be used in the for loops               */
    int block, row, col;

    /* For loops loop through the original array to copy its contents onto the      */
    /* copy array                                                                   */
    for(block = 0 ; block < s1 ; block++){
        for(row = 0 ; row < s2 ; row++){
            for(col = 0 ; col < s3 ; col++){

                /* Copying the contents of the original onto the copy array         */
                copy[block][row][col] = ar[block][row][col];
            }
        }
    }
    /* Nothing is returned back to main because this is a void function             */
}

/* When pasteContents() function is called, execution continues from here           */
void pasteContents(int s1, int s2, int s3, int copy[s1][s2][s3]) {

    /* Initialising these local variables to be used in the for loops               */
    int block, row, col;

    /* For loops loop through the copy array to display its contents                */
    for (block = 0; block < s1; block++) {
        for (row = 0; row < s2; row++) {
            for (col = 0; col < s3; col++) {

                /* Displaying the contents of the copy array                        */
                printf("%4d", copy[block][row][col]);
            }
            /* Puts the escape character \n onto the screen                         */
            putchar('\n');
        }
        /* Puts the escape characters \n onto the screen                            */
        putchar('\n');
        putchar('\n');
    }

    /* Puts the escape character \n onto the screen                                 */
    putchar('\n');
    /* Nothing is returned back to main because this is a void function             */
}

/* When reverseString() function is called, execution continues from here           */
void reverseString(char string[SIZE]){

    /* Initialising this local variable to be used in the for loop                  */
    int i;

    /* Initialising length to be the length of the entered string                   */
    int length = strlen(string);

    /* Changes the escape character \n to a \0                                      */
    if( string[length-1] == '\n' ){
        string[length-1] = '\0';
    }

    /* Loops throughout all the string of entered words                             */
    for(i = length-1 ; i >= 0 ; i--){

        /* Runs if a blank space is encountered                                     */
        if( isblank(string[i]) ){

            /* Places the escape character \0 instead of a space                    */
            string[i] = '\0';

            /* Prints out words in reverse order except for the last word           */
            printf(" %s", (&(string[i])+1) );
        }

    }
    /* Prints out the last reversed word in the string which initially was the      */
    /* the first word entered by the user                                           */
    printf(" %s", string);

    /* Nothing is returned back to main because this is a void function             */
}