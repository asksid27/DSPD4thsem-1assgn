#ifndef ORDERS_H_INCLUDED
#define ORDERS_H_INCLUDED

typedef struct ORDER{
    char name_of_user[50];
    int user_id;
    char address_of_user[100];
    char phone_no_of_user[13];
    Food_Item * food_ordered;
    Agent * agent;
    struct ORDER * next;
}ORDER;




#endif // ORDERS_H_INCLUDED
