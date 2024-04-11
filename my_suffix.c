#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 128 /* Maximum input string length including null terminator. */

/* Function Prototypes */

/* Prints all the suffixes of the string 'str' that start with the character 'c'. */
int my_suffix(char str[], char c);

/* Main program */
int main() {
    char inputString[MAX_STRING_LENGTH]; /* Input string from the user. */
    char c; /* Character to search for in the input string. */
    char choice; /* User's choice to continue or exit the program. */
    int numOfSuffixes; /* Number of suffixes found. */
    int ch; /* Variable to capture character for input buffer clearing and EOF checking. */

    do { /* The program will run at least once; after the first run, it will ask the user if they wish to quit or re-run. */
    
        printf("Please enter a character: ");
        if (scanf(" %c", &c) != 1) { /* Checks for character input and handles EOF. */
            printf("\nEnd of input detected. Exiting program.\n");
            return 0; /* Exit if EOF is detected. */
        }/* end if. */

        printf("Please enter a string (max 127 characters): ");
        scanf(" %127[^\n]", inputString); /* Reads the string from the input. */
        
        /* Clears the input buffer; also checks for EOF to avoid getting stuck. */
        while ((ch = getchar()) != '\n' && ch != EOF);

        printf("\nCharacter: %c, String: %s\n", c, inputString);

        numOfSuffixes = my_suffix(inputString, c);
        printf("Number of suffixes found: %d\n", numOfSuffixes);

        printf("Do you want to restart the program? (y/n): ");
        if (scanf(" %c", &choice) != 1) { /* Directly checks for EOF or input error. */
            printf("\nEnd of input detected or input error. Exiting program.\n");
            return 0; /* Exits the loop if EOF is detected or an input error occurs. */
        } /* end if. */
        /* Again, clears the input buffer; also checks for EOF. */
        while ((ch = getchar()) != '\n' && ch != EOF);

    } while(choice == 'y' || choice == 'Y');

    printf("You decided to quit the program, thank you for using *my_suffix*\n");
    return 0; /* Program exits normally. */
} /* end main */

/**
 * Function: my_suffix
 * -------------------
 * Description: This function prints all the suffixes of the string 'str' that start with the character 'c'
 * and returns the count of such suffixes. It iterates through the string, checking for occurrences of 'c' 
 * and prints from that point to the end of the string.
 *
 * Parameters:
 *   str - The input string from which suffixes are to be printed.
 *   c - The character that the suffixes must start with.
 * 
 * Returns:
 *   The number of suffixes found that start with character 'c'.
 */
int my_suffix(char str[], char c) {
    int count = 0; /* Variable to count suffixes starting with character 'c'. */
    size_t strLen = strlen(str); /* Length of the input string. */
    size_t i; /* Loop counter. */

    /* Iterates through the string to find occurrences of 'c'. */
    for (i = 0; i < strLen; ++i) {
        if (str[i] == c) {
            /* Prints the suffix starting from the current character. */
            printf("%s\n", &str[i]);
            ++count; /* Increments the suffix count. */
        }
    }

    return count; /* Returns the total count of suffixes found. */
} /* end my_suffix */
