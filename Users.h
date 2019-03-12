#ifndef USERS_H_INCLUDED
#define USERS_H_INCLUDED

typedef struct USER{
    char name[50];
    int user_id;
    char address[100];
    char phone_no [13];
    char password[10];
    Food_Item * prev;
    struct USER * next;
}USER;






#endif // USERS_H_INCLUDED
