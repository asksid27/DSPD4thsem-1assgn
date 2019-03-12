#ifndef INITIALIZE_H_INCLUDED
#define INITIALIZE_H_INCLUDED

void initializeR()
{
    Restaurant * temp = malloc(sizeof(Restaurant));

    strcpy(temp->name, "Curry House");
    strcpy(temp->address, "Bajaj Nagar");
    strcpy(temp->category, "Restaurant");
    temp->no_of_seats = 15;
    temp->del_time_in_min = 20;
    temp->next = NULL;

    Food_Item * fitem = malloc(sizeof(Food_Item));
    strcpy(fitem->food_name, "Chicken Tandoori");
    strcpy(fitem->address_of_restaurant, temp->address);
    strcpy(fitem->name_of_restaurant, temp->name);
    fitem->count_for_user = 0;
    fitem->next = NULL;
    fitem->prep_time_in_min = 10;
    fitem->price = 120.0;

    MENU  * mitem = malloc(sizeof(MENU));
    strcpy(mitem->cuisine, "Indian");
    mitem->cuisines = fitem;
    mitem->next = NULL;

    temp->menu = mitem;



    rlist = temp;
    Restaurant * t = rlist;

    temp = malloc(sizeof(Restaurant));

    strcpy(temp->name, "Sardarji Ki Rasoi");
    strcpy(temp->address, "Shankar Nagar");
    strcpy(temp->category, "Restaurant");
    temp->no_of_seats = 30;
    temp->del_time_in_min = 15;
    temp->next = NULL;

    t->next = temp;
    t = t->next;

    temp = malloc(sizeof(Restaurant));

    strcpy(temp->name, "Yellow Chilli");
    strcpy(temp->address, "South Ambazari");
    strcpy(temp->category, "Food Joint");
    temp->no_of_seats = 40;
    temp->del_time_in_min = 15;
    temp->next = NULL;

    t->next = temp;
    t = t->next;

    temp = malloc(sizeof(Restaurant));

    strcpy(temp->name, "Ayushi Parantha");
    strcpy(temp->address, "IT Park Road");
    strcpy(temp->category, "Street Stall");
    temp->no_of_seats = 15;
    temp->del_time_in_min = 15;
    temp->next = NULL;

    t->next = temp;
    total.count_restaurant = 4;

}

void initializeU()
{
    USER * temp = malloc(sizeof(USER));

    strcpy(temp->name, "Subhaag Chowdhury");
    strcpy(temp->address, "VNIT");
    strcpy(temp->password, "Sub@123");
    temp->user_id = temp->name[0]%10*1000+0;
    strcpy(temp->phone_no, "7053689021");
    temp->next = NULL;
    temp->prev = NULL;

    ulist = temp;
    USER * t = ulist;

    temp = malloc(sizeof(USER));

    strcpy(temp->name, "Siddhant Kashyap");
    strcpy(temp->address, "VNIT");
    strcpy(temp->password, "098Sid");
    temp->user_id = temp->name[0]%10*1000+1;
    strcpy(temp->phone_no, "9868502393");
    temp->next = NULL;
    temp->prev = NULL;

    t->next = temp;
    t = t->next;

    temp = malloc(sizeof(USER));

    strcpy(temp->name, "Rushikesh Tupe");
    strcpy(temp->address, "VNIT");
    strcpy(temp->password, "Rushi");
    temp->user_id = temp->name[0]%10*1000+2;
    strcpy(temp->phone_no, "9067232345");
    temp->next = NULL;
    temp->prev = NULL;

    t->next = temp;

    total.count_user = 3;
}

void initializeO()
{
    olist = NULL;
}

void initializeA()
{
    Agent * temp = malloc(sizeof(Agent));

    strcpy(temp->name, "Manish Kumar");
    strcpy(temp->address_to_deliver, " ");
    strcpy(temp->phone_no, "9238475346");
    temp->commission = 0.0;
    temp->agent_id = temp->phone_no[0]%10*1000+0;
    temp->next = NULL;
    temp->occupied = 0;
    temp->user_assigned = 0;

    alist = temp;
    Agent * t = alist;

    temp = malloc(sizeof(Agent));

    strcpy(temp->name, "Yogesh Chaturvedi");
    strcpy(temp->address_to_deliver, " ");
    strcpy(temp->phone_no, "9238471234");
    temp->commission = 0.0;
    temp->agent_id = temp->phone_no[0]%10*1000+1;
    temp->next = NULL;
    temp->occupied = 0;
    temp->user_assigned = 0;

    t->next = temp;
    t = t->next;

    temp = malloc(sizeof(Agent));

    strcpy(temp->name, "Ankush Singh");
    strcpy(temp->address_to_deliver, " ");
    strcpy(temp->phone_no, "9123847534");
    temp->commission = 0.0;
    temp->agent_id = temp->phone_no[0]%10*1000+2;
    temp->next = NULL;
    temp->occupied = 0;
    temp->user_assigned = 0;

    t->next = temp;

    total.count_agent = 3;
}

#endif // INITIALIZE_H_INCLUDED
