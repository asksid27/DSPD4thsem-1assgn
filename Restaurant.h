#ifndef RESTAURANT_H_INCLUDED
#define RESTAURANT_H_INCLUDED

typedef struct Food_Item{
    char food_name[50];
    float price;
    char name_of_restaurant[50];
    char addres_of_restaurnat[100];
    struct Food_Item * next;
    int prep_time_in_min;
}Food_Item;

typedef struct CUISINE{
    char name[50];
    struct CUISINE * next;
    Food_Item * dishes;
}CUISINE;

typedef struct MENU{
    char cuisine[50];
    struct MENU * next;
    CUISINE * cuisines;
}MENU;

typedef struct Restaurant{
        char name[50];
        char address[100];
        char category[50];
        int no_of_seats;
        int del_time_in_min;
        MENU * menu;
        struct Restaurant * next;
}Restaurant;


#endif // RESTAURANT_H_INCLUDED
