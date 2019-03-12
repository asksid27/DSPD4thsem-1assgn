#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Restaurant.h"
#include "Users.h"
#include "Agent.h"
#include "Orders.h"
typedef struct COUNT{
    int count_restaurant;
    int count_user;
    int count_agent;
}COUNT;
COUNT total;
ORDER * olist;
Restaurant * rlist;
USER * ulist;
Agent * alist;

#include "initialize.h"
#include "User_function.h"
#include "Res_function.h"

void delivery_food()
{
    printf("Please Enter your name agent: ");
    char a[50];
    fgets(a, 50, stdin);
    strtok(a, "\n");
    ORDER * otemp = olist;
    ORDER * otempprev = otemp;

    int f = 0;

    while(otemp != NULL && f == 0)
    {
        if(strcmpi(otemp->agent->name, a) == 0)
            f = 1;
        else
        {
            otempprev = otemp;
            otemp = otemp->next;
        }
    }

    if(otemp != NULL && f == 1)
    {
        Agent * atemp = alist;
        while(strcmp(atemp->name, a) == 0)
            atemp = atemp->next;
        atemp->commission += (otemp->food_ordered->price * 0.1);
        otempprev = otemp->next;
        otemp->next = NULL;

        USER * utemp = ulist;

        printf("%s",otemp->name_of_user);

        while(strcmp(utemp->name, otemp->name_of_user) != 0)
            utemp = utemp->next;

        if(utemp->prev == NULL)
        {
            utemp->prev = malloc(sizeof(Food_Item));
            strcpy(utemp->prev->address_of_restaurant, otemp->food_ordered->address_of_restaurant);
            utemp->prev->count_for_user++;
            strcpy(utemp->prev->food_name, otemp->food_ordered->food_name);
            strcpy(utemp->prev->name_of_restaurant, otemp->food_ordered->name_of_restaurant);
            utemp->prev->next = NULL;
            utemp->prev->prep_time_in_min = otemp->food_ordered->prep_time_in_min;
            utemp->prev->price = otemp->food_ordered->price;
        }
        else
        {
            int flag = 0;
            while(utemp->prev->next != NULL && flag == 0)
            {
                if(strcmpi(utemp->prev->food_name, otemp->food_ordered->food_name) == 0 && strcmpi(utemp->prev->name_of_restaurant, otemp->food_ordered->name_of_restaurant) == 0)
                    flag =1;
                else
                    utemp = utemp->next;
            }

            if(flag == 0 || (strcmpi(utemp->prev->food_name, otemp->food_ordered->food_name) != 0 && strcmpi(utemp->prev->name_of_restaurant, otemp->food_ordered->name_of_restaurant) == 0))
            {
                Food_Item * newItem = malloc(sizeof(Food_Item));

                strcpy(newItem->address_of_restaurant, otemp->food_ordered->address_of_restaurant);
                newItem->count_for_user++;
                strcpy(newItem->food_name, otemp->food_ordered->food_name);
                strcpy(newItem->name_of_restaurant, otemp->food_ordered->name_of_restaurant);
                newItem->next = NULL;
                newItem->prep_time_in_min = otemp->food_ordered->prep_time_in_min;
                newItem->price = otemp->food_ordered->price;

                utemp->prev = newItem;
            }
            else
            {
                utemp->prev->count_for_user++;
            }
        }

        if(olist == otemp)
            olist = NULL;

        free(otemp);

        printf("Order successfully delivered %s\n", utemp->name);

    }
    else
    {
        printf("You are not assigned for any delivery\n");
    }
}


int main()
{
    initializeR();
    initializeU();
    initializeO();
    initializeA();

    int c = -1;

    while(c != 0)
    {
        printf("<----------WELCOME TO HUNGRY APP---------->\n        Choose from the following options: ");
        printf("\n\n");
        printf("1. Add OR Modify Restaurant and its details\n2. Sign up for user\n3. Log in for user\n4. Food Delivered option for Agent\n0. Exit\n");

        printf("Enter your choice :");
        scanf("%d",&c);
        getchar();

        switch(c)
        {
        case 1: printf("Taking you to the Restaurant page\n\n");
                restaurantModifier();
            break;
        case 2: printf("Taking you to the User sign up page\n\n");
                createUser();
            break;
        case 3: {
                    printf("Taking you to the User log in page\n\n");
                    logInUser();
                }
            break;
        case 4: printf("Taking you to the Agent page\n\n");
                delivery_food();
            break;
        case 0: printf("<----------Exiting, Thank you For using HUNGRY APP.---------->\n\n");
            break;
        default:printf("Please choose a valid option\n");
        }

    }

    if(olist != NULL)
        printf("%s %s %s %s",olist->name_of_user, olist->food_ordered->food_name, olist->food_ordered->name_of_restaurant, olist->agent->name);


    return 0;
}

