#include<stdio.h>
#include<malloc.h>
#include<string.h>

struct node
{
    int quantity;
    char name[20],size[5];
    struct node *add;
};
struct node *head=NULL,*c,*t,*l,*fd;

int a,odr=0,odrr=0,x,n,memb,ods=0;
char siz[1],nam[20],sizee[5];

food_list()
{
    printf("\nFood Menu\n\n");
    printf("1.Fried Rice.\n");
    printf("2.Murog Polau.\n");
    printf("3.Biriani [Beef].\n");
    printf("4.Katchi Biriani.\n");
    printf("5.Khichuri.\n");
    printf("6.Soup.\n");
    printf("7.Grill Chicken.\n");
    printf("8.Burger[chicken].\n");
    printf("9.Burger[Beef].\n");
    printf("10.Cheese Pizza.\n\n");
    while(1)
    {
        printf("Please enter your choice[1-10] :   ");
        scanf("%d",&n);

        if(n==1)
        {
            strcpy(nam,"Fried Rice");
            break;
        }
        else if(n==2)
        {
            strcpy(nam,"Murog Polau");
            break;
        }
        else if(n==3)
        {
            strcpy(nam,"Biriani [Beef]");
            break;
        }
        else if(n==4)
        {
            strcpy(nam,"Katchi Biriani");
            break;
        }
        else if(n==5)
        {
            strcpy(nam,"Khichuri");
            break;
        }
        else if(n==6)
        {
            strcpy(nam,"Soup");
            break;
        }
        else if(n==7)
        {
            strcpy(nam,"Grill Chicken");
            break;
        }
        else if(n==8)
        {
            strcpy(nam,"Burger[chicken]");
            break;
        }
        else if(n==9)
        {
            strcpy(nam,"Burger[Beef]");
            break;
        }
        else if(n==10)
        {
            strcpy(nam,"Cheese Pizza");
            break;
        }
        else
        {
            printf("\nYour given data is not valid.\n");
        }
    }
    printf("\n\n");
    while(1)
    {
        printf("Please enter the size of your food [S/M/L]\n");
        scanf("%s",&siz);

       if(strcmp(siz,"s")==0 || strcmp(siz,"S")==0 )
        {
            strcpy(sizee,"Small");
            break;
        }
        else if(strcmp(siz,"m")==0 || strcmp(siz,"M")==0)
        {
            strcpy(sizee,"Medium");
            break;
        }
        else if(strcmp(siz,"l")==0 || strcmp(siz,"L")==0)
        {
            strcpy(sizee,"Large");
            break;
        }
        else
        {
            printf("Your Given data is not valid.\n");
        }
    }
    printf("\n\n");
    printf("For how many members. Do you want this order.\n");
    scanf("%d",&memb);
}

order_receive()
{
    c=(struct node*)malloc(sizeof(struct node));
    if(odrr==0)
    {
        head=c;
        food_list();
        strcpy(c->name,nam);
        strcpy(c->size,sizee);
        c->quantity=memb;
        c->add=NULL;
        odr++;
        odrr++;
    }
    else
    {
        c=head;
        while(1)
        {
            if(c->add==NULL)
            {
                break;
            }
            else
            {
                c=c->add;
            }
        }
        l = (struct node*)malloc(sizeof(struct node));
        food_list();
        strcpy(l->name,nam);
        strcpy(l->size,sizee);
        l->quantity=memb;
        c->add=l;
        l->add=NULL;
        odr++;
        odrr++;
    }
}

order_serve()
{
    c=head;
    if(c==NULL)
    {
        printf("\nTheir are no order to serve.\n");
    }
    else
    {
        printf("\nOrder serving :\n",head->quantity);
        printf("\tFood name : %s.\n",c->name);
        printf("\tSize : %s.\n",c->size);
        printf("\tQuantity : %d.\n\n",c->quantity);
        fd=head->add;
        head=fd;
        odrr--;
        ods++;
        printf("There are %d orders left.\n ",odrr);
    }
}

Display()
{
    c=head;
    if(c==NULL)
    {
        printf("\nTheir are no order to serve.\n");
    }
    else
    {
        int i=1;
        printf("Foods have to serve \n\n");
        while(c!=NULL)
        {

            printf("Order number %d.\n",i);
            printf("\tFood name : %s.\n",c->name);
            printf("\tSize : %s.\n",c->size);
            printf("\tQuantity : %d.\n\n",c->quantity);
            c=c->add;
            i++;
        }
    }
}

int main()
{
    printf("\tWelcome to Free Restaurant\n");
    while(1)
    {
        printf("\nMain Menu\n\n");
        printf("\t1.Order Food.\n");
        printf("\t2.List of Serving food.\n");
        printf("\t3.Serve Food.\n");
        printf("\t4.Number food receive and order.\n");
        printf("\t5.Close restaurant.\n\n");
        printf("Please enter your choice : ");
        scanf("%d",&n);
        printf("\n\n");
        if(n==1)
        {
            order_receive();
        }
        else if(n==2)
        {
            Display();
        }
        else if(n==3)
        {
            order_serve();
        }
        else if(n==4)
        {
            printf("Total order receive : %d.\n",odr);
            printf("Total order serve : %d.\n",ods);
        }
        else if(n==5)
        {
            if(odr==ods)
            {
                printf("All orders are served .\n\tThank you.\n\n ");
                return 0;
            }
            else
            {
                printf("There are %d orders have to serve.\n",odrr);
                printf("If you want to close restaurant . \nPress 1.\n");
                scanf("%d",&n);
                if(n==1)
                {
                    printf("All orders are served .\n\tThank you.\n\n ");
                    return 0;
                }
            }
        }
        else
        {
            printf("Your given data is not valid.\n");
        }
    }
}


