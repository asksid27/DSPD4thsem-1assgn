#ifndef INITIALIZE_H_INCLUDED
#define INITIALIZE_H_INCLUDED

#include <stdio.h>
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

#include "User_function.h"

Restaurant * initializeR(Restaurant * rlist)
{
    Restaurant * temp = malloc(sizeof(Restaurant));

    strcpy(temp->name, "Curry House");
    strcpy(temp->address, "Bajaj Nagar");
    strcpy(temp->category, "Restaurant");
    temp->no_of_seats = 15;
    temp->del_time_in_min = 20;
    temp->next = NULL;

    rlist = temp;

    temp = malloc(sizeof(Restaurant));

    strcpy(temp->name, "Sardarji Ki Rasoi");
    strcpy(temp->address, "Shankar Nagar");
    strcpy(temp->category, "Restaurant");
    temp->no_of_seats = 30;
    temp->del_time_in_min = 15;
    temp->next = NULL;

    rlist->next = temp;

    return rlist;
}

USER * initializeU(USER * ulist)
{

    return ulist;
}

ORDER * initializeO(ORDER * olist)
{

    return olist;
}

Agent * initializeA(Agent * alist)
{

    return alist;
}

#endif // INITIALIZE_H_INCLUDED
