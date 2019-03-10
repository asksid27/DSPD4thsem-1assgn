#include <stdio.h>
#include <stdlib.h>
#include "initialize.h"

COUNT total;

int main()
{
    Restaurant * rlist;
    USER * ulist = NULL;
    ORDER * olist = NULL;
    Agent * alist = NULL;
    rlist = initializeR(rlist);
    ulist = initializeU(ulist);
    olist = initializeO(olist);
    alist = initializeA(alist);

    int c = -1;
    char ch = 'y';

    while(c != 0)
    {
        printf("<----------WELCOME TO HUNGRY APP---------->\n        Choose from the following options: ");
        printf("\n\n");
        printf("1. Add OR Modify Restaurant and its details\n2. Sign up for user\n3. Log in for user\n4. Add agent\n0. Exit\n");

        printf("Enter your choice :");
        scanf("%d",&c);
        getchar();

        switch(c)
        {
        case 1: //something
            break;
        case 2: printf("Taking you to the User sign up page\n\n");
                ulist = createUser(ulist, total);
            break;
        case 3://somthing
            break;
        case 4://something
            break;
        case 0: printf("<----------Exiting, Thank you For using HUNGRY APP.---------->\n\n");
            break;
        default:printf("Please choose a valid option\n");
        }

    }


    return 0;
}
