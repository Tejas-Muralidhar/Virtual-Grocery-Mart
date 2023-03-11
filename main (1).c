//Created by Tejas: 1RN21CS171 and Tejas V: 1RN21CS172
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>

struct shopping_list{
    char item_name[20];
    struct quantity{
        char quantity[10];
        unsigned int number; 
    }item_quantity;
    float item_cost;
    struct shopping_list * link;
};
typedef struct shopping_list SL;// structure to store the shopping list.

struct customer_details{
    char name[20];
    char phone[11];
    float final_bill;
    SL * final_receipt;
};
typedef struct customer_details CD;// structure to store customer details along with their shopping list. Used to store in a file.

void print_logo(int x){
    switch(x){
        case 0:
        printf("\n\n");
        printf(R"EOF( __     __  ___   ____    _____   _   _      _      _          ____   ____     ___     ____   _____   ____   __   __    __  __      _      ____    _____ 
 \ \   / / |_ _| |  _ \  |_   _| | | | |    / \    | |        / ___| |  _ \   / _ \   / ___| | ____| |  _ \  \ \ / /   |  \/  |    / \    |  _ \  |_   _|
  \ \ / /   | |  | |_) |   | |   | | | |   / _ \   | |       | |  _  | |_) | | | | | | |     |  _|   | |_) |  \ V /    | |\/| |   / _ \   | |_) |   | |  
   \ V /    | |  |  _ <    | |   | |_| |  / ___ \  | |___    | |_| | |  _ <  | |_| | | |___  | |___  |  _ <    | |     | |  | |  / ___ \  |  _ <    | |  
    \_/    |___| |_| \_\   |_|    \___/  /_/   \_\ |_____|    \____| |_| \_\  \___/   \____| |_____| |_| \_\   |_|     |_|  |_| /_/   \_\ |_| \_\   |_|  
                                                                                                                                                         )EOF");
        break;
        case 1:
        printf("\n\n");
        printf(R"EOF(   ____           _             ____            _   _             
  / ___|_ __ __ _(_)_ __  ___  / ___|  ___  ___| |_(_) ___  _ __  
 | |  _| '__/ _` | | '_ \/ __| \___ \ / _ \/ __| __| |/ _ \| '_ \ 
 | |_| | | | (_| | | | | \__ \  ___) |  __/ (__| |_| | (_) | | | |
  \____|_|  \__,_|_|_| |_|___/ |____/ \___|\___|\__|_|\___/|_| |_|
                                                                  )EOF");
        break;
        case 2:
        printf("\n\n");
        printf(R"EOF(  __  __            _     ____            _   _             
 |  \/  | ___  __ _| |_  / ___|  ___  ___| |_(_) ___  _ __  
 | |\/| |/ _ \/ _` | __| \___ \ / _ \/ __| __| |/ _ \| '_ \ 
 | |  | |  __/ (_| | |_   ___) |  __/ (__| |_| | (_) | | | |
 |_|  |_|\___|\__,_|\__| |____/ \___|\___|\__|_|\___/|_| |_|
                                                            )EOF");
        break;
        case 3:
        printf("\n\n");
        printf(R"EOF( __     __              _        _     _        ____            _   _             
 \ \   / /__  __ _  ___| |_ __ _| |__ | | ___  / ___|  ___  ___| |_(_) ___  _ __  
  \ \ / / _ \/ _` |/ _ \ __/ _` | '_ \| |/ _ \ \___ \ / _ \/ __| __| |/ _ \| '_ \ 
   \ V /  __/ (_| |  __/ || (_| | |_) | |  __/  ___) |  __/ (__| |_| | (_) | | | |
    \_/ \___|\__, |\___|\__\__,_|_.__/|_|\___| |____/ \___|\___|\__|_|\___/|_| |_|
             |___/                                                                )EOF");
        break;
        case 4:
        printf("\n\n");
        printf(R"EOF(  _____           _ _         ____            _   _             
 |  ___| __ _   _(_) |_ ___  / ___|  ___  ___| |_(_) ___  _ __  
 | |_ | '__| | | | | __/ __| \___ \ / _ \/ __| __| |/ _ \| '_ \ 
 |  _|| |  | |_| | | |_\__ \  ___) |  __/ (__| |_| | (_) | | | |
 |_|  |_|   \__,_|_|\__|___/ |____/ \___|\___|\__|_|\___/|_| |_|
                                                                )EOF");
        break;
        case 5:
        printf("\n\n");
        printf(R"EOF(  ____        _              ____            _   _             
 |  _ \  __ _(_)_ __ _   _  / ___|  ___  ___| |_(_) ___  _ __  
 | | | |/ _` | | '__| | | | \___ \ / _ \/ __| __| |/ _ \| '_ \ 
 | |_| | (_| | | |  | |_| |  ___) |  __/ (__| |_| | (_) | | | |
 |____/ \__,_|_|_|   \__, | |____/ \___|\___|\__|_|\___/|_| |_|
                     |___/                                     )EOF");
        break;
        case 6:
        printf("\n\n");
        printf(R"EOF(  ____             _____               _   ____            _   _             
 / ___|  ___  __ _|  ___|__   ___   __| | / ___|  ___  ___| |_(_) ___  _ __  
 \___ \ / _ \/ _` | |_ / _ \ / _ \ / _` | \___ \ / _ \/ __| __| |/ _ \| '_ \ 
  ___) |  __/ (_| |  _| (_) | (_) | (_| |  ___) |  __/ (__| |_| | (_) | | | |
 |____/ \___|\__,_|_|  \___/ \___/ \__,_| |____/ \___|\___|\__|_|\___/|_| |_|
                                                                             )EOF");
        break;
    }
}

SL* add_item(SL *list,const char *name, const char *quantity,float cost){
    //to add new items to the list and return the updated SLL   
    /*to check if an item added is already present in the SLL. If yes,then don't make a new node, but 
    change the quantity and cost of the already existing node. */
    SL *p =NULL;
    int already_present = 0;
    for(p=list;p!=NULL;p=p->link){
        if(strcmp(name,p->item_name)==0&&strcmp(quantity,(p->item_quantity).quantity)==0){
            already_present = 1;
            ((p->item_quantity).number)++;
            p->item_cost += cost; 
        }
    }
    if(!already_present){
        SL* t=(SL*)malloc(sizeof(SL));
        strcpy(t->item_name,name);
        strcpy((t->item_quantity).quantity,quantity);
        (t->item_quantity).number = 1;
        t->item_cost = cost;
        t->link=NULL;
        if(list == NULL)
            list = t;
        else if(list->link==NULL){
            list->link=t;
            return list;
        }
        else{
            SL* l=NULL;
            for(l=list;l->link!=NULL;l=l->link);
            l->link=t;
        }
    }
    return list;
}

SL* delete_item(SL * list,char * item){
    //to delete items from the list and return the updated SLL 
    int pos = 1;
    SL *t = list;
    for(;t!=NULL;t=t->link){
        if(strcmp(t->item_name,item)!=0)
            pos++;
        else{
            if((t->item_quantity).number>1){
                ((t->item_quantity).number)--;
                return list;
            }
            break;
        }
    }
    int cnt=0;
    SL * temp,last;
    for(temp=list;temp!=NULL;cnt++,temp=temp->link);
    if(pos<1 || pos>cnt){
       printf("The item does not exist in your shopping list!\n");
       return list;
    }
    else if(pos==1){
        if(list==NULL)
            return list;
        SL* temp1=list->link;
        free(list);
        return temp1;
    }
    else if(pos==cnt){
        if(list==NULL)
            return list;
        if(list->link==NULL)
        {
            free(list);
            return NULL;
        }
        SL *p=list;
        SL *q=list->link;
        while(q->link!=0)
        {
            p=p->link;
            q=q->link;
        }
        free(q);
        p->link=NULL;
        return list;
    }
    else
    {
        SL* prev=list;
        SL* next=list->link;
        pos=pos-2;
        while(pos--)
        {
            prev=prev->link;
            next=next->link;
        }
        temp=next;
        next = next->link;
        free(temp);
        prev->link=next;
    }
    return list;
}

SL * enter_aisle(int aisle, SL * list){
    print_logo(aisle);
    printf("\n");
    int item,quantity,aisle_done = 0;;
    switch(aisle){ 
        /*Inside each case display mini list and ask them to select items to add. call add_item().
        Ask if they have anything to delete. If yes, take input and call delete_item().*/
        case 1: //grains
        printf("This is the Grains Section!\nHere is a list of all items available:\n");
        aisle_done = 0;
        while(!aisle_done){
            printf("1.White Rice\n2.Brown Rice\n3.Wheat\n4.Millets\n5.Ragi\n6.Barley\nType any other number to leave the aisle\n");
            printf("Choose your item: ");
            scanf("%d",&item);
            switch(item)
            {
                case 1://quantity
                printf("The quantity of White Rice available is given below:\n");
                printf("1.1Kg\n2.2Kg\n3.5Kg\n");
                printf("Enter the quantity\n");
                scanf("%d",&quantity);
                switch(quantity)
                {
                    //prototype of add_item is: SL * add_item(SL * list,const char *name,const char *quantity,float cost){
                    case 1: list = add_item(list, "White Rice","1Kg",80.00);break;
                    case 2: list = add_item(list, "White Rice","2Kg",150.00);break;
                    case 3: list = add_item(list, "White Rice","5Kg",380.00);break;
                    default: printf("No such quantity available!\n");
                }
                break;
                case 2://quantity
                printf("The quantity of Brown Rice available is given below:\n");
                printf("1.1Kg\n2.2Kg\n3.5Kg\n");
                printf("Enter the quantity\n");
                scanf("%d",&quantity);
                switch(quantity)
                {
                    case 1: list = add_item(list, "Brown Rice","1Kg",100.00);break;
                    case 2: list = add_item(list, "Brown Rice","2Kg",190.00);break;
                    case 3: list = add_item(list, "Brown Rice","5Kg",450.00);break;
                    default: printf("No such quantity available!\n");
                }
                break;
                case 3://quantity
                printf("The quantity of Wheat available is given below:\n");
                printf("1.1Kg\n2.5Kg\n3.10Kg\n");
                printf("Enter the quantity\n");
                scanf("%d",&quantity);
                switch(quantity)
                {
                    case 1: list = add_item(list, "Wheat","1Kg",50.00);break;
                    case 2: list = add_item(list, "Wheat","5Kg",200.00);break;
                    case 3: list = add_item(list, "Wheat","10Kg",400.00);break;
                    default: printf("No such quantity available!\n");
                }
                break;
                case 4://quantity
                printf("The quantity of Millets available is given below:\n");
                printf("1.1Kg\n2.5Kg\n");
                printf("Enter the quantity\n");
                scanf("%d",&quantity);
                switch(quantity)
                {
                    case 1: list = add_item(list, "Millets","1Kg",60.00);break;
                    case 2: list = add_item(list, "Millets","5Kg",270.00);break;
                    default: printf("No such quantity available!\n");   
                }
                break;
                case 5://quantity
                printf("The quantity of Ragi available is given below:\n");
                printf("1.1Kg\n2.5Kg\n3.10Kg\n");
                printf("Enter the quantity\n");
                scanf("%d",&quantity);
                switch(quantity)
                {
                    case 1: list = add_item(list, "Ragi","1Kg",80.00);break;
                    case 2: list = add_item(list, "Ragi","5Kg",350.00);break;
                    case 3: list = add_item(list, "Ragi","10Kg",750.00);break;
                    default: printf("No such quantity available!\n");
                }
                break;
                case 6://quantity
                printf("The quantity of Barley available is given below:\n");
                printf("1.1Kg\n2.2Kg\n3.5Kg\n");
                printf("Enter the quantity\n");
                scanf("%d",&quantity);
                switch(quantity)
                {
                    case 1: list = add_item(list, "Barley","1Kg",45.00);break;
                    case 2: list = add_item(list, "Barley","2Kg",80.00);break;
                    case 3: list = add_item(list, "Barley","5Kg",220.00);break;
                    default: printf("No such quantity available!\n");
                }
                break;
                default:printf("Sorry Wrong Choice\n");
            }
            printf("Are you done with this aisle?(y/n)");
            char ch[1];
            scanf("%s",ch);
            if(ch[0]=='y')
                aisle_done =1;
        }
        break;
        case 2://meat
        printf("This is the Meat Section!\nHere is a list of all items available:\n");
        aisle_done = 0;
        while(!aisle_done){
            printf("1.Beef\n2.Pork\n3.Lamb\n4.Chicken\nType any other number to leave the aisle\n");
            printf("Choose your item: ");
            scanf("%d",&item);
            switch(item)
            {
                case 1://quantity
                printf("The quantity of Beef available is given below:\n");
                printf("1.250g\n2.500g\n3.1Kg\n");
                printf("Enter the quantity\n");
                scanf("%d",&quantity);
                switch(quantity)
                {
                    case 1: list = add_item(list, "Beef","250g",50.00);break;
                    case 2: list = add_item(list, "Beef","500g",100.00);break;
                    case 3: list = add_item(list, "Beef","1Kg",200.00);break;
                    default: printf("No such quantity available!\n");
                }
                break;
                case 2://quantity
                printf("The quantity of Pork available is given below:\n");
                printf("1.250g\n2.500g\n3.1Kg\n");
                printf("Enter the quantity\n");
                scanf("%d",&quantity);
                switch(quantity)
                {
                    case 1: list = add_item(list, "Pork","250g",85.00);break;
                    case 2: list = add_item(list, "Pork","500g",175.00);break;
                    case 3: list = add_item(list, "Pork","1Kg",350.00);break;
                    default: printf("No such quantity available!\n");
                }
                break;
                case 3://quantity
                printf("The quantity of Lamb available is given below:\n");
                printf("1.250g\n2.500g\n3.1Kg\n");
                printf("Enter the quantity\n");
                scanf("%d",&quantity);
                switch(quantity)
                {
                    case 1: list = add_item(list, "Lamb","250g",225.00);break;
                    case 2: list = add_item(list, "Lamb","500g",450.00);break;
                    case 3: list = add_item(list, "Lamb","1Kg",900.00);break;
                    default: printf("No such quantity available!\n");
                }
                break;
                case 4://quantity
                printf("The quantity of Chicken available is given below:\n");
                printf("1.250g\n2.500g\n3.1Kg\n");
                printf("Enter the quantity\n");
                scanf("%d",&quantity);
                switch(quantity)
                {
                    case 1: list = add_item(list, "Chicken","250g",60.00);break;
                    case 2: list = add_item(list, "Chicken","500g",110.00);break;
                    case 3: list = add_item(list, "Chicken","1Kg",225.00);break;
                    default: printf("No such quantity available!\n");
                }
                break;
                default:
                printf("Sorry Wrong Choice\n");
            }
            printf("Are you done with this aisle?(y/n)");
            char ch[1];
            scanf("%s",ch);
            if(ch[0]=='y')
                aisle_done =1;
        }
        break;
        case 3://vegetables
        printf("This is the Vegetable Section!\nHere is a list of all items available:\n");
        aisle_done = 0;
        while(!aisle_done){
            printf("1.Tomatoes\n2.Potatoes\n3.Carrot\n4.Capsicum\n5.Onions\n6.Eggplant\n7.Peas\nType any other number to leave the aisle\n");
            printf("Choose your item: ");
            scanf("%d",&item);
            switch(item)
            {
                case 1://quantity
                printf("The quantity of Tomatoes available is given below:\n");
                printf("1.500g\n2.1Kg\n");
                printf("Enter the quantity\n");
                scanf("%d",&quantity);
                switch(quantity)
                {
                    case 1: list = add_item(list, "Tomatoes","500g",10.00);break;
                    case 2: list = add_item(list, "Tomatoes","1Kg",20.00);break;
                    default: printf("No such quantity available!\n");
                }
                break;
                case 2://quantity
                printf("The quantity of Potatoes available is given below:\n");
                printf("1.500g\n2.1Kg\n");
                printf("Enter the quantity\n");
                scanf("%d",&quantity);
                switch(quantity)
                {
                    case 1: list = add_item(list, "Potatoes","500g",15.00);break;
                    case 2: list = add_item(list, "Potatoes","1Kg",30.00);break;
                    default: printf("No such quantity available!\n");
                }
                break;
                case 3://quantity
                printf("The quantity of Carrot available is given below:\n");
                printf("1.250g\n2.500g\n3.1Kg\n");
                printf("Enter the quantity\n");
                scanf("%d",&quantity);
                switch(quantity)
                {
                    case 1: list = add_item(list, "Carrot","250g",15.00);break;
                    case 2: list = add_item(list, "Carrot","500g",30.00);break;
                    case 3: list = add_item(list, "Carrot","1Kg",60.00);break;
                    default: printf("No such quantity available!\n");
                }
                break;
                case 4://quantity
                printf("The quantity of Capsicum available is given below:\n");
                printf("1.500g\n2.1Kg\n");
                printf("Enter the quantity\n");
                scanf("%d",&quantity);
                switch(quantity)
                {
                    case 1: list = add_item(list, "Capsicum","500g",20.00);break;
                    case 2: list = add_item(list, "Capsicum","1Kg",40.00);break;
                    default: printf("No such quantity available!\n");
                }
                break;
                case 5://quantity
                printf("The quantity of Onion available is given below:\n");
                printf("1.500g\n2.1Kg\n");
                printf("Enter the quantity\n");
                scanf("%d",&quantity);
                switch(quantity)
                {
                    case 1: list = add_item(list, "Onion","500g",15.00);break;
                    case 2: list = add_item(list, "Onion","1Kg",30.00);break;
                    default: printf("No such quantity available!\n");
                }
                break;
                case 6://quantity
                printf("The quantity of Eggplant available is given below:\n");
                printf("1.250g\n2.500g\n3.1Kg\n");
                printf("Enter the quantity\n");
                scanf("%d",&quantity);
                switch(quantity)
                {
                    case 1: list = add_item(list, "Eggplant","250g",10.00);break;
                    case 2: list = add_item(list, "Eggplant","500g",20.00);break;
                    case 3: list = add_item(list, "Eggplant","1Kg",40.00);break;
                    default: printf("No such quantity available!\n");
                }
                break;
                case 7://quantity
                printf("The quantity of Peas available is given below:\n");
                printf("1.250g\n2.500g\n3.1Kg\n");
                printf("Enter the quantity\n");
                scanf("%d",&quantity);
                switch(quantity)
                {
                    case 1: list = add_item(list, "Peas","250g",20.00);break;
                    case 2: list = add_item(list, "Peas","500g",40.00);break;
                    case 3: list = add_item(list, "Peas","1Kg",80.00);break;
                    default: printf("No such quantity available!\n");
                }
                break;
                default:printf("Sorry Wrong Choice\n");
            }
            printf("Are you done with this aisle?(y/n)");
            char ch[1];
            scanf("%s",ch);
            if(ch[0]=='y')
                aisle_done =1;
        }
        break;
        case 4://fruits
        printf("This is the Fruits Section!\nHere is a list of all items available:\n");
        aisle_done = 0;
        while(!aisle_done){
            printf("1.Apples\n2.Bananas\n3.Oranges\n4.Mangoes\n5.Strawberries\n6.Watermelons\n7.Pears\nType any other number to leave the aisle\n");
             printf("Choose your item: ");
            scanf("%d",&item);
            switch(item)
            {
                case 1://quantity
                printf("The quantity of Apples available is given below:\n");
                printf("1.250g\n2.500g\n3.1Kg\n");
                printf("Enter the quantity\n");
                scanf("%d",&quantity);
                switch(quantity)
                {
                    case 1: list = add_item(list, "Apples","250g",60.00);break;
                    case 2: list = add_item(list, "Apples","500g",125.00);break;
                    case 3: list = add_item(list, "Apples","1Kg",250.00);break;
                    default: printf("No such quantity available!\n");
                }
                break;
                case 2://quantity
                printf("The quantity of Bananas available is given below:\n");
                printf("1.500g\n2.1Kg\n");
                printf("Enter the quantity\n");
                scanf("%d",&quantity);
                switch(quantity)
                {
                    case 1: list = add_item(list, "Bananas","500g",20.00);break;
                    case 2: list = add_item(list, "Bananas","1Kg",40.00);break;
                    default: printf("No such quantity available!\n");
                }
                break;
                case 3://quantity
                printf("The quantity of Oranges available is given below:\n");
                printf("1.250g\n2.500g\n3.1Kg\n");
                printf("Enter the quantity\n");
                scanf("%d",&quantity);
                switch(quantity)
                {
                    
                    case 1: list = add_item(list, "Oranges","250g",20.00);break;
                    case 2: list = add_item(list, "Oranges","500g",40.00);break;
                    case 3: list = add_item(list, "Oranges","1Kg",80.00);break;
                    default: printf("No such quantity available!\n");
                }
                break;
                case 4://quantity
                printf("The quantity of Mangoes available is given below:\n");
                printf("1.250g\n2.500g\n3.1Kg\n");
                printf("Enter the quantity\n");
                scanf("%d",&quantity);
                switch(quantity)
                {
                    case 1: list = add_item(list, "Mangoes","250g",35.00);break;
                    case 2: list = add_item(list, "Mangoes","500g",75.00);break;
                    case 3: list = add_item(list, "Mangoes","1Kg",150.00);break;
                    default: printf("No such quantity available!\n");
                }
                break;
                case 5://quantity
                printf("The quantity of Strawberries available is given below:\n");
                printf("1.250g\n2.500g\n3.1Kg\n");
                printf("Enter the quantity\n");
                scanf("%d",&quantity);
                switch(quantity)
                {
                    case 1: list = add_item(list, "Strawberries","250g",60.00);break;
                    case 2: list = add_item(list, "Strawberries","500g",125.00);break;
                    case 3: list = add_item(list, "Strawberries","1Kg",250.00);break;
                    default: printf("No such quantity available!\n");
                }
                break;
                case 6://quantity
                printf("The quantity of Watermelon available is given below:\n");
                printf("1.1Kg\n2.2Kg\n3.5Kg\n");
                printf("Enter the quantity\n");
                scanf("%d",&quantity);
                switch(quantity)
                {
                    case 1: list = add_item(list, "Watermelon","1Kg",15.00);break;
                    case 2: list = add_item(list, "Watermelon","2Kg",30.00);break;
                    case 3: list = add_item(list, "Watermelon","5Kg",75.00);break;
                    default: printf("No such quantity available!\n");
                }
                break;
                case 7://quantity
                printf("The quantity of Pears available is given below:\n");
                printf("1.250g\n2.500g\n3.1Kg\n");
                printf("Enter the quantity\n");
                scanf("%d",&quantity);
                switch(quantity)
                {
                    case 1: list = add_item(list, "Pears","250g",75.00);break;
                    case 2: list = add_item(list, "Pears","500g",150.00);break;
                    case 3: list = add_item(list, "Pears","1Kg",300.00);break;
                    default: printf("No such quantity available!\n");
                }
                break;
                default:printf("Sorry Wrong Choice\n");
            }
            printf("Are you done with this aisle?(y/n)");
            char ch[1];
            scanf("%s",ch);
            if(ch[0]=='y')
                aisle_done =1;        
        }
        break;
        case 5://dairy
        printf("This is the Diary Section!\nHere is a list of all items available:\n");
        aisle_done = 0;
        while(!aisle_done){
            printf("1.Cream\n2.Milk\n3.Curd\n4.Yogurt\n5.Cheese\n6.Paneer\n7.Butter\nType any other number to leave the aisle\n");
            printf("Choose your item: ");
            scanf("%d",&item);
            switch(item)
            {
                case 1://quantity
                printf("The quantity of Cream available is given below:\n");
                printf("1.250ml\n2.500ml\n3.1L\n");
                printf("Enter the quantity\n");
                scanf("%d",&quantity);
                switch(quantity)
                {
                    case 1: list = add_item(list, "Cream","250ml",50.00);break;
                    case 2: list = add_item(list, "Cream","500ml",100.00);break;
                    case 3: list = add_item(list, "Cream","1L",200.00);break;
                    default: printf("No such quantity available!\n");
                }
                break;
                case 2://quantity
                printf("The quantity of Milk available is given below:\n");
                printf("1.500ml\n2.1L\n");
                printf("Enter the quantity\n");
                scanf("%d",&quantity);
                switch(quantity)
                {
                    case 1: list = add_item(list, "Milk","500ml",20.00);break;
                    case 2: list = add_item(list, "Milk","1L",40.00);break;
                    default: printf("No such quantity available!\n");
                }
                break;
                case 3://quantity
                printf("The quantity of Curd available is given below:\n");
                printf("1.500ml\n2.1L\n");
                printf("Enter the quantity\n");
                scanf("%d",&quantity);
                switch(quantity)
                {
                    case 1: list = add_item(list, "Curd","500ml",25.00);break;
                    case 2: list = add_item(list, "Curd","1L",50.00);break;
                    default: printf("No such quantity available!\n");
                }
                break;
                case 4://quantity
                printf("The quantity of Yoghurt available is given below:\n");
                printf("1.500g\n2.1Kg\n");
                printf("Enter the quantity\n");
                scanf("%d",&quantity);
                switch(quantity)
                {
                    case 1: list = add_item(list, "Yoghurt","500g",45.00);break;
                    case 2: list = add_item(list, "Yoghurt","1Kg",90.00);break;
                    default: printf("No such quantity available!\n");
                }
                break;
                case 5://quantity
                printf("The quantity of Cheese available is given below:\n");
                printf("1.250g\n2.500g\n3.1Kg\n");
                printf("Enter the quantity\n");
                scanf("%d",&quantity);
                switch(quantity)
                {
                    case 1: list = add_item(list, "Cheese","250g",135.00);break;
                    case 2: list = add_item(list, "Cheese","500g",275.00);break;
                    case 3: list = add_item(list, "Cheese","1Kg",525.00);break;
                    default: printf("No such quantity available!\n");
                }
                break;
                case 6://quantity
                printf("The quantity of Paneer available is given below:\n");
                printf("1.100g\n2.200g\n");
                printf("Enter the quantity\n");
                scanf("%d",&quantity);
                switch(quantity)
                {
                    case 1: list = add_item(list, "Paneer","100g",60.00);break;
                    case 2: list = add_item(list, "Paneer","200g",100.00);break;
                    default: printf("No such quantity available!\n");
                }
                break;
                case 7://quantity
                printf("The quantity of Butter available is given below:\n");
                printf("1.100g\n2.250g\n3.500g\n");
                printf("Enter the quantity\n");
                scanf("%d",&quantity);
                switch(quantity)
                {
                    case 1: list = add_item(list, "Butter","100g",50.00);break;
                    case 2: list = add_item(list, "Butter","250g",125.00);break;
                    case 3: list = add_item(list, "Butter","500g",275.00);break;
                    default: printf("No such quantity available!\n");
                }
                break;
                default:printf("Sorry Wrong Choice\n");
            }
            printf("Are you done with this aisle?(y/n)");
            char ch[1];
            scanf("%s",ch);
            if(ch[0]=='y')
                aisle_done =1;        
        }
        break;
        case 6://seafood
        printf("This is the Seafood Section!\nHere is a list of all items available:\n");
        aisle_done = 0;
        while(!aisle_done){
            printf("1.Prawns\n2.Basa\n3.Tuna\n4.Salmon\n5.Silver Fish\n6.Anjal\n7.Sardines\n8.Rohu\nType any other number to leave the aisle\n");
            printf("Choose your item: ");
            scanf("%d",&item);
            switch(item)
            {
                case 1://quantity
                printf("The quantity of Prawns available is given below:\n");
                printf("1.250g\n2.500g\n3.1Kg\n");
                printf("Enter the quantity\n");
                scanf("%d",&quantity);
                switch(quantity)
                {
                    case 1: list = add_item(list, "Prawns","250g",150.00);break;
                    case 2: list = add_item(list, "Prawns","500g",300.00);break;
                    case 3: list = add_item(list, "Prawns","1Kg",600.00);break;
                    default: printf("No such quantity available!\n");
                }
                break;
                case 2://quantity
                printf("The quantity of Basa available is given below:\n");
                printf("1.250g\n2.500g\n3.1Kg\n");
                printf("Enter the quantity\n");
                scanf("%d",&quantity);
                switch(quantity)
                {
                    case 1: list = add_item(list, "Basa","250g",65.00);break;
                    case 2: list = add_item(list, "Basa","500g",125.00);break;
                    case 3: list = add_item(list, "Basa","1Kg",250.00);break;
                    default: printf("No such quantity available!\n");
                }
                break;
                case 3://quantity
                printf("The quantity of Tuna available is given below:\n");
                printf("1.250g\n2.500g\n3.1Kg\n");
                printf("Enter the quantity\n");
                scanf("%d",&quantity);
                switch(quantity)
                {
                    case 1: list = add_item(list, "Tuna","250g",75.00);break;
                    case 2: list = add_item(list, "Tuna","500g",150.00);break;
                    case 3: list = add_item(list, "Tuna","1Kg",300.00);break;
                    default: printf("No such quantity available!\n");
                }
                break;
                case 4://quantity
                printf("The quantity of Salmon available is given below:\n");
                printf("1.250g\n2.500g\n3.1Kg\n");
                printf("Enter the quantity\n");
                scanf("%d",&quantity);
                switch(quantity)
                {
                    case 1: list = add_item(list, "Salmon","250g",110.00);break;
                    case 2: list = add_item(list, "Salmon","500g",220.00);break;
                    case 3: list = add_item(list, "Salmon","1Kg",450.00);break;
                    default: printf("No such quantity available!\n");
                }
                break;
                case 5://quantity
                printf("The quantity of Silver Fish available is given below:\n");
                printf("1.250g\n2.500g\n3.1Kg\n");
                printf("Enter the quantity\n");
                scanf("%d",&quantity);
                switch(quantity)
                {
                    case 1: list = add_item(list, "Silver Fish","250g",90.00);break;
                    case 2: list = add_item(list, "Silver Fish","500g",175.00);break;
                    case 3: list = add_item(list, "Silver Fish","1Kg",350.00);break;
                    default: printf("No such quantity available!\n");
                }
                break;
                case 6://quantity
                printf("The quantity of Anjal available is given below:\n");
                printf("1.250g\n2.500g\n3.1Kg\n");
                printf("Enter the quantity\n");
                scanf("%d",&quantity);
                switch(quantity)
                {
                    case 1: list = add_item(list, "Anjal","250g",175.00);break;
                    case 2: list = add_item(list, "Anjal","500g",350.00);break;
                    case 3: list = add_item(list, "Anjal","1Kg",700.00);break;
                    default: printf("No such quantity available!\n");
                }
                break;
                case 7://quantity
                printf("The quantity of Sardines available is given below:\n");
                printf("1.250g\n2.500g\n3.1Kg\n");
                printf("Enter the quantity\n");
                scanf("%d",&quantity);
                switch(quantity)
                {
                    case 1: list = add_item(list, "Sardines","250g",65.00);break;
                    case 2: list = add_item(list, "Sardines","500g",125.00);break;
                    case 3: list = add_item(list, "Sardines","1Kg",250.00);break;
                    default: printf("No such quantity available!\n");
                }
                break;
                case 8://quantity
                printf("he quantity of Rohu available is given below:\n");
                printf("1.500g\n2.1Kg\n");
                printf("Enter the quantity\n");
                scanf("%d",&quantity);
                switch(quantity)
                {
                    case 1: list = add_item(list, "Rohu","500g",95.00);break;
                    case 2: list = add_item(list, "Rohu","1Kg",190.00);break;
                    default: printf("No such quantity available!\n");
                }
                break;
                default:printf("Sorry Wrong Choice\n");
            }
            printf("Are you done with this aisle?(y/n)");
            char ch[1];
            scanf("%s",ch);
            if(ch[0]=='y')
                aisle_done =1;
        }
        break;
        default: printf("No such aisle!\n");
    }
    return list;
}

void display_shopping_list(SL * list){
    //to display all the items, their quatity and their cost present in the list at any point in time
     if(list==NULL)
    {
        printf("\nYou currently have no items in your shopping list!\n");
        return;
    }
    printf("Your current shopping list is: \n");
    printf("+-------------------------------------+\n");
    printf("|    Item Name   |      Quantity      |\n");
    printf("+-------------------------------------+\n");
    while(list!=NULL)
    {
        printf("|%-15s | %-13s x %-2d |\n",list->item_name,(list->item_quantity).quantity, (list->item_quantity).number);
        list=list->link;
    }
    printf("+-------------------------------------+\n");
}

void display_final_bill(SL* list,float* bill_amount,CD c){
    //displays final reciept and calculates taxable amount
    float tax_amount = (*bill_amount) * 0.12;
    if(list==NULL)
    {
        printf("\nBill generation error! You have not bought any items!\n");
        return;
    }
    printf("Customer Name: %s\nCustomer Contact: %s\n",c.name,c.phone);
    printf("+------------------------------------------------------+\n");
    printf("|    Item Name   |      Quantity      |      Cost      |\n");
    printf("+------------------------------------------------------+\n");
    while(list!=NULL)
    {
        printf("|%-15s | %-13s x %-2d | Rs.%11.2f |\n",list->item_name,(list->item_quantity).quantity, (list->item_quantity).number,list->item_cost);
        list=list->link;
    }
    printf("+------------------------------------------------------+\n");
    printf("Total:                                  Rs.%11.2f\n",(*bill_amount));
    printf("GST (12%):                              Rs.%11.2f\n",tax_amount);
    (*bill_amount)+=tax_amount;
    printf("--------------------------------------------------------\n");
    printf("--------------------------------------------------------\n");
    printf("Payable Amount:                         Rs.%11.2f\n",(*bill_amount));
}

float calculate_bill(SL * list){
    //to add the item_cost of every node and return the bill amount (float)
    float bill =0;
    SL* t=NULL;
    for(t=list;t!=NULL;t=t->link){
        bill += t->item_cost;
    }
    return bill;
}

FILE * accept_record(CD *c, FILE *fp,float bill_amount,SL * list)
{
    //takes name and phone number as input and pushes all related information about customer into a specified file from CLA.
    printf("\nEnter your details: \n");
	printf("Name: ");
	scanf(" %[^\n]s",c->name);
	printf("Phone Number: ");
	scanf(" %s",c->phone);
	c->final_bill = bill_amount;
	c->final_receipt = list;
	fwrite(c,sizeof(CD),1,fp);
	return fp;
}

int main(int argc,char *argv[])
{
    system("clear");
    CD c;
    FILE *fp;
    int aisle,done_shopping = 0;
    float bill_amount;
    char ans[1],item[30];
    if(argc==1){
        printf("Too few Command Line Arguments!\nExiting...");
        return 0;
    }
    print_logo(0);
    SL* list=NULL;//like the first node, it points to first item node
    printf("\nWelcome to the Virtual Grocery Mart! Here's our layout:");
//find a way to make everything below this comment run on a while loop, where the loop is based on 'continue_shopping' variable.
    while(!done_shopping){
        printf("\n1.Grains Section\n2.Meat Section\n3.Vegetables Section\n4.Fruits Section\n5.Dairy Section\n6.Seafood Section\n");
        printf("Which aisle would you like to shop in?(Enter the Aisle number): ");
        scanf("%d",&aisle);
        system("clear");
        list = enter_aisle(aisle,list);
        display_shopping_list(list);
        printf("Are you done adding items to your shopping list?(y/n): ");
        scanf("%s",ans);
        if(ans[0] == 'y'){
            system("clear");
            done_shopping = 1;
        }
    }
    display_shopping_list(list);
    printf("Would you like to delete anything from your shopping list?(y/n): ");
    scanf("%s",ans);
    if(ans[0] == 'y'){
        done_shopping = 0;
        while(!done_shopping){
            display_shopping_list(list);
            printf("Enter the name of the item you would like to remove from your list(Case Sensitive): ");
            scanf(" %[^\n]s",item);
            list = delete_item(list,item);
            display_shopping_list(list);
            printf("Do you wish to delete anything else?(y/n): ");
            scanf("%s",ans);
            if(ans[0]=='n'){
                done_shopping =1;
            }
        }
    }
//Outside the proposed while loop, after all item selection is done, call calculate_bill() function.
    bill_amount = calculate_bill(list);
    fp = fopen(argv[1],"a");
    printf("\nGenerating your Receipt...");
    fp = accept_record(&c,fp,bill_amount,list);
    system("clear");
    printf("Your receipt: \n");
    display_final_bill(list,&bill_amount,c);
    printf("\nYour final bill comes up to Rs.%-7.2f",bill_amount);
    printf("\n\nThank you for shopping at the Virtual Grocery Mart!\n");
//Now that the items and bill is finalized, deduct the items purchased from inventory and add bill_amount to cash register.    
//Take customer details like name, bill_amount and list and store it in a new structre variable of type CD. 
//Store in a file meant for customer details.
    return 0;
}














