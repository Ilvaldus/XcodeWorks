#include <stdio.h>
#include <string.h>

//By Charles Zhuang

/*This was a silly program I wrote that asked the user whether or not they were working on their paper.
 Anything short of the specific answer "Yes." warranted the program to scold the user and then ask them
 the same question again.*/

int main(){
    char buf[BUFSIZ];
    char *p;
    char *example;
    int procrastinate = 1;
    
    while (procrastinate == 1){
        printf ("Are you working on your paper?\n");
        //This gets the user input.
        if (fgets(buf, sizeof(buf), stdin) != NULL) {
            /*Because the buffer may sometimes include the "Enter" key when the
             user submits their input, we have to check the array to remove that
             and replace it with a null value, otherwise the compare function
             is not going to do its job right.
             */
            p = strchr(buf, '\n');
            if (*p == '\n'){
                *p = '\0';
            }
            //This is the compare function that checks for the specific answer.
            if (strcmp(buf, "Yes.") == 0){
                printf ("Okay.\n");
                procrastinate = 0;
            }else{
                printf ("Do your paper!\n");
            }
        }
    }
    return 0;
}