#ifndef RES_FUNCTION_H_INCLUDED
#define RES_FUNCTION_H_INCLUDED

void createRestaurant()
{

    Restaurant * temp = malloc(sizeof(Restaurant));
    printf("Enter Restaurant name: ");
    fgets(temp->name, 50, stdin);
    strtok(temp->name, "\n");
    printf("Enter Restaurant address: ");
    fgets(temp->address, 100, stdin);
    strtok(temp->address, "\n");
    printf("Enter Restaurant category: ");
    fgets(temp->category, 50, stdin);
    strtok(temp->category, "\n");
    printf("Enter no. of seats present in the restaurant: ");
    scanf("%d",&temp->no_of_seats);
    printf("Enter delivery time in minutes: ");
    scanf("%d",&temp->del_time_in_min);
    getchar();

    printf("Enter all the cuisines provided by the restaurant: ");
    MENU * csn = malloc(sizeof(MENU));
    fgets(csn->cuisine, 50, stdin);
    strtok(csn->cuisine, "\n");
    csn->cuisines = NULL;
    csn->next = NULL;

    char ch = 'y';
    printf("Do you want to enter another cuisine: ");
    scanf("%c",&ch);
    getchar();

    MENU * newcuisine = csn;

    while(ch == 'y')
    {
        MENU * temp1 = malloc(sizeof(MENU));
        fgets(temp1->cuisine, 50 , stdin);
        strtok(temp1->cuisine, "\n");
        newcuisine->next = temp1;
        temp1->next = NULL;
        temp1->cuisines = NULL;
        newcuisine = newcuisine->next;
        printf("Do you want to enter another cuisine: ");
        scanf("%c",&ch);
        getchar();
    }

    temp->next = NULL;
    temp->menu = csn;

    if(rlist == NULL)
        rlist = temp;
    else
    {
        Restaurant * temp1 = rlist;
        while(temp1->next != NULL)
            temp1 = temp1->next;
        temp1->next = temp;
    }
}

void addFoodItem()
{

    Food_Item * fitem = malloc(sizeof(Food_Item));

    printf("Enter Food Item name: ");
    fgets(fitem->food_name, 50, stdin);
    strtok(fitem->food_name, "\n");
    printf("Enter price of the item: ");
    scanf("%f",&fitem->price);
    getchar();
    printf("Enter name of restaurant to add the food item to: ");
    fgets(fitem->name_of_restaurant, 50, stdin);
    strtok(fitem->name_of_restaurant, "\n");
    printf("Enter address of restaurant to add the food item to: ");
    fgets(fitem->address_of_restaurant, 100, stdin);
    strtok(fitem->address_of_restaurant, "\n");
    printf("Enter preparation time in minutes: ");
    scanf("%d",&fitem->prep_time_in_min);
    fitem->count_for_user = 0;
    getchar();
    fitem->next = NULL;

    Restaurant * temp = rlist;

    while(temp != NULL && (strcmp(temp->name, fitem->name_of_restaurant) != 0 && strcmp(temp->address, fitem->address_of_restaurant) != 0 ))
        temp = temp->next;

    if(temp == NULL)
        printf("No such restaurant exists.\n");
    else
    {
        char a[50];
        printf("Enter the cuisine to which the dish belongs to: ");
        fgets(a, 50, stdin);
        strtok(a, "\n");

        MENU * temp1 = temp->menu;

        while(temp1 != NULL && strcmp(a, temp1->cuisine) != 0)
            temp1 = temp1->next;

        if(temp1 != NULL)
        {
            Food_Item * newItem = temp1->cuisines;
            while(newItem->next != NULL)
                newItem = newItem->next;
            newItem->next = fitem;
            printf("Food item %s successfully added to the restaurant %s",fitem->food_name,fitem->name_of_restaurant);
        }
        else
            printf("This restaurant doesn't provide this cuisine\n");
    }
}

void addCuisine()
{


}

void listRestaurant()
{
    int c = 1;

    while(c > 0 && c < 4)
    {
        printf("1. List all restaurants\n2. List restaurants category wise\n3. List restaurants area wise\n4. List restaurants cuisine wise\n0.Go back to previous menu\n");
        printf("Enter your choice :");
        scanf("%d",&c);
        getchar();

        switch(c)
        {
        case 1: {
            Restaurant * temp = rlist;
            while(temp != NULL)
            {
                printf("%s",temp->name);
                temp = temp->next;
            }
        }
            break;
        case 2: {
            char a[50];
            printf("Enter the category of restaurant to list: ");
            fgets(a, 50, stdin);
            strtok(a, "\n");

            Restaurant * temp = rlist;
            while(temp != NULL)
            {
                if(strcmp(temp->category, a) == 0)
                    printf("%s",temp->name);
                temp = temp->next;
            }
        }
            break;
        case 3:{
            char a[100];
            printf("Enter the area of restaurant to list: ");
            fgets(a, 100, stdin);

            Restaurant * temp = rlist;
            while(temp != NULL)
            {
                if(strcmp(temp->address, a) == 0)
                    printf("%s",temp->name);
                temp = temp->next;
            }
        }
            break;
        case 4: {
            char a[50];
            printf("Enter the cuisine to list: ");
            fgets(a, 50, stdin);

            Restaurant * temp = rlist;
            while(temp != NULL)
            {
                MENU * temp1 = temp->menu;
                while(temp1 != NULL)
                {
                    if(strcmp(temp1->cuisine, a) == 0)
                        printf("%s",temp->name);
                    temp1 = temp1->next;
                }
                temp = temp->next;
            }
        }
            break;
        case 0: printf("<----------Thank You, Taking you back to the previous menu---------->\n\n");
            break;
        default:printf("Please choose a valid option\n");
        }


    }

}

void restaurantModifier()
{
    int c = -1;
    int flag = 0;

     while(flag == 0)
    {
        printf("1. Add a new Restaurant\n2. Add Food Item to a restaurant\n3. Modify a Restaurant\n4. Add Cuisine to restaurant\n5.List restaurants\n0. Go back to previous menu\n");

        printf("Enter your choice :");
        scanf("%d",&c);
        getchar();

        switch(c)
        {
        case 1: printf("Taking you to the restaurant add page\n\n");
                createRestaurant();
                flag = 1;
            break;
        case 2: printf("Taking you to the add Food Item page\n\n");
                addFoodItem();
                flag = 1;
            break;
        case 3://somthing
                flag = 1;
            break;
        case 4: /*printf("Taking you to the add Cuisine to a restaurant page\n\n");
                rlist = addCuisine(rlist);*/
                flag = 1;
            break;
        case 5: printf("Taking you to the list restaurants page\n\n");
                listRestaurant();
                flag = 1;
            break;
        case 0: printf("<----------Exiting, Thank you For using HUNGRY APP.---------->\n\n");
                flag = 1;
            break;
        default:printf("Please choose a valid option\n");
        }

    }

}



#endif // RES_FUNCTION_H_INCLUDED
