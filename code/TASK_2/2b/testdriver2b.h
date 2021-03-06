
int menu();

int menu(){

    /* Initialising this local variable to store the user's choice                 */
    int choice;

    printf("\n\n\t\tTuples Program\n");
    printf("-------------------------------------------------\n");
    printf("Please choose one of the following options below:\n");
    printf(" 1) Create a Tuple\n");
    printf(" 2) Get a Tuple's Pointer\n");
    printf(" 3) Get a Tuple's ID\n");
    printf(" 4) Display Tuple\n");
    printf(" 5) Delete Tuple\n");
    printf(" 6) Compare Tuples\n");
    printf(" 7) Join Tuples\n");
    printf(" 8) Save all Tuples\n");
    printf(" 9) Load all Tuples\n");
    printf(" 0) EXIT \n\n");

    printf("Tuples created up till now: %d", tuplec);

    printf("\n\nCHOICE: ");

    /* If something other than an integer is entered, this while loop runs prompting*/
    /* the user to enter the appropriate data type                                  */
    while(scanf(" %d", &choice) != 1){
        printf("Ivalid data!! \nPlease enter a number from 0 - 9 : \n");

        /* Clears input buffer from previously entered invalid data                 */
        while(getchar()!='\n');
    }

    /* Puts the escape character \n onto the screen                                 */
    putchar('\n');

    /* Returns the value entered by the user back to the main() function            */
    return choice;
}