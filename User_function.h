#ifndef USER_FUNCTION_H_INCLUDED
#define USER_FUNCTION_H_INCLUDED

void createUser()
{
    char pass[10];
    int flag = 0;

    USER * temp = (USER*)malloc(sizeof(USER));
    printf("Enter User name: ");
    fgets(temp->name, 50, stdin);
    strtok(temp->name, "\n");
    printf("Enter User address: ");
    fgets(temp->address, 100, stdin);
    strtok(temp->address, "\n");
    printf("Enter User phone no: ");
    fgets(temp->phone_no, 13, stdin);
    strtok(temp->phone_no, "\n");
    printf("Enter User password(max 10 characters): ");
    fgets(temp->password, 10, stdin);
    strtok(temp->password, "\n");
    printf("Confirm password: ");
    fgets(pass, 10, stdin);
    strtok(pass, "\n");

    while(flag == 0)
    {


        if(strcmp(pass, temp->password) == 0)
        {
            temp->user_id = total.count_user+(temp->name[0]%10)*1000;
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
            fgets(temp->password, 10, stdin);
            strtok(temp->password, "\n");
            printf("Confirm password: ");
            fgets(pass, 10, stdin);
            strtok(pass, "\n");
        }
    }

}

void searchRestaurant(USER * user_temp)
{
    char n[50];
    fgets(n, 50, stdin);
    strtok(n, "\n");
    Food_Item * newItem = malloc(sizeof(Food_Item));

    Restaurant * temp = rlist;

    while(temp != NULL && (strcmp(temp->name, n) != 0))
        temp = temp->next;

    if(temp != NULL)
    {
        printf("Food Items provided by this restaurant are: \n");
        MENU * temp1 = temp->menu;

        while(temp1 != NULL)
        {
            Food_Item * temp2 = temp1->cuisines;
            while(temp2 != NULL)
            {
                printf("%s: %f\n",temp2->food_name, temp2->price);
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }

        printf("Please enter the name of the food item you want: ");
        fgets(n, 50, stdin);
        strtok(n, "\n");

        temp1 = temp->menu;
        int flag = 0;

        while(temp1 != NULL && flag == 0)
        {
            Food_Item * temp2 = temp1->cuisines;

            while(temp2 != NULL && flag == 0)
            {
                if(strcmp(n, temp2->food_name) == 0)
                {
                    flag = 1;
                    if(olist == NULL)
                    {
                        Agent * atemp = alist;
                        while(atemp != NULL && atemp->occupied != 0)
                            atemp = atemp->next;
                        if(atemp != NULL)
                        {
                            olist = malloc(sizeof(ORDER));
                            strcpy(olist->name_of_user, user_temp->name);
                            strcpy(olist->address_of_user, user_temp->address);
                            strcpy(olist->phone_no_of_user, user_temp->phone_no);
                            olist->user_id = user_temp->user_id;
                            olist->food_ordered = temp2;
                            olist->agent = atemp;
                            olist->next = NULL;
                            strcpy(olist->agent->address_to_deliver, user_temp->address);
                            printf("Order is placed and will be delivered by %s in %d minutes\n",olist->agent->name,temp->del_time_in_min+olist->food_ordered->prep_time_in_min);
                        }
                        else
                        {
                            printf("No agent is available for delivery right now\n");
                        }
                    }
                    else
                    {

                    }
                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }

    }
    else
        printf("No such restaurant exists, Please Search again\n");

}

void cancelOrder(USER * user_temp)
{
    ORDER * otemp = olist;
    ORDER * otempprev = otemp;
    int flag = 0;

    while(otemp != NULL && flag == 0)
    {
        if(strcmp(otemp->name_of_user, user_temp->name) == 0)
            flag = 1;
        else
        {
            otempprev = otemp;
            otemp = otemp->next;
        }
    }

    if(flag == 1)
    {
        otempprev->next = otemp->next;
        otemp->next = NULL;
        otemp->agent->occupied = 0;
        if(olist == otemp)
            olist =NULL;
        free(otemp);
        printf("Order is successfully canceled\n");
    }
    else
    {
        printf("Your don't have any existing order\n");
    }
}

void prevOrder(USER * user_temp)
{
    Food_Item * prev = user_temp->prev;
    if(prev == NULL)
        printf("You haven't ordered anything till now\n");
    while(prev != NULL)
    {
        printf("%s\n",prev->food_name);
        prev = prev->next;
    }
}

void favOrder(USER * user_temp)
{
    Food_Item * fav = user_temp->prev;
    if(fav == NULL)
        printf("You haven't ordered yet\n");
    else
    {
        int c = fav->count_for_user;
        Food_Item * temp = fav->next;
        while(temp != NULL)
        {
            if(c < temp->count_for_user)
                fav = temp;
            temp = temp->next;
        }

    }
}


void logInUser()
{
    USER * temp = ulist;
    char n[50];
    char p[10];

    printf("Enter Your name: ");
    fgets(n, 50, stdin);
    strtok(n, "\n");

    printf("Enter your password: ");
    fgets(p, 10, stdin);
    strtok(p, "\n");

    while(temp != NULL && (strcmp(temp->name, n) != 0 && strcmp(temp->password, p) != 0 ))
    {
        temp = temp->next;
    }

    if(temp != NULL && strcmp(temp->name, n) == 0 && strcmp(temp->password, p) == 0 )
    {
        int c = 1;


        while(c > 0 && c < 4)
        {
            printf("1. Search food restaurant wise\n2. Cancel Order\n3. My previous Orders\n4. My favorite Order\n0. Go back to previous menu\n");

            printf("Enter your choice :");
            scanf("%d",&c);
            getchar();

            switch(c)
            {
            case 1: {
                        printf("Taking you to the restaurant search page\n\n");
                        searchRestaurant(temp);
                    }
                break;
            case 2: printf("Taking you to the Cancel Order page\n\n");
                    cancelOrder(temp);
                break;
            case 3: printf("Taking you to the previous order page" \n);
                    prevOrder(temp);
                break;
            case 4: printf("You favorite Order is : \n");
                    favOrder(temp);
                break;
            case 0: printf("<----------Exiting, Thank you For using HUNGRY APP.---------->\n\n");
                break;
            default:printf("Please choose a valid option\n");
            }


        }
    }
    else if(temp != NULL)
    {
        printf("Name and password didn't match, Please log in again\n");
    }
    else
        printf("User doesn't exist, Please log in First\n");


}




#endif // USER_FUNCTION_H_INCLUDED
