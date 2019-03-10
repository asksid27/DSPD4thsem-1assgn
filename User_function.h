#ifndef USER_FUNCTION_H_INCLUDED
#define USER_FUNCTION_H_INCLUDED

#include <stdio.h>

USER * createUser(USER * ulist, COUNT total)
{
    char pass[10];
    int flag = 0;
    char * t;

    USER * temp = (USER*)malloc(sizeof(USER));
    printf("Enter User name: ");
    fgets(temp->name, 50, stdin);
    printf("Enter User address: ");
    fgets(temp->address, 100, stdin);
    printf("Enter User phone no: ");
    fgets(temp->phone_no, 13, stdin);
    printf("Enter User password(max 10 characters): ");
    fgets(temp->password, 10, stdin);
    printf("Confirm password: ");
    fgets(pass, 10, stdin);

    while(flag == 0)
    {


        if(strcmp(pass, temp->password) == 0)
        {
            temp->next = NULL;
            USER * temp1 = ulist;
            if(temp1 == NULL)
            {
                ulist = temp;
            }
            else
            {
                while(temp1->next != NULL)
                    temp1 = temp1->next;
                temp1->next = temp;
            }
            total.count_user++;
            printf("User successfully added");
            flag = 1;
        }
        else
        {
            printf("Password didn't match\n");
            printf("Enter User password(max 10 characters): ");
            scanf("%s",&temp->password);
            getchar();
            printf("Confirm password: ");
            scanf("%s",&pass);
            getchar();
        }
    }
    return ulist;
}


#endif // USER_FUNCTION_H_INCLUDED
