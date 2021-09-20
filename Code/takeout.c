#include <stdio.h>
#include<ctype.h>
#include<windows.h>
#include<conio.h>
int order();
int invioce();
char item[5][15]= {"Burger","Pizza","Fried Rice","Chicken Fry","French Fry"};
int price[5]= {250,300,175,90,75};
int choice,a,quantity,quantity1,quantity2,quantity3,quantity4;
int orderQty[5];
float bill[5];
int main ()
{
    int getorder;
    int home;

    printf("\n\t-->Welcome to Take Out<--");

    printf(" \n\n1. Menu");
    printf(" \n2. Order");
    printf("\n Enter Your Choice:: ");
    scanf("%d",&getorder);
    system("cls");
    if(getorder==1)
    {
        FILE *myFile;
        myFile=fopen("test.txt","r");
        char t[100];
        while(fgets(t,100,myFile)!=NULL)
            puts(t);
        fclose(myFile);
        printf("\n\nEnter 1 to return home::");
        scanf("%d",&home);
        system("cls");
        if(home==1)
        {
            main();
        }
        else
        {
            printf("Wrong Input");
        }
    }
    else if (getorder==2)
    {
        order();

    }
    else
    {
        printf("Wrong Input");
        main();
    }

}
int order()
{

    int m_order;

    printf("\n\t-->Welcome to Take Out<--");
    printf("\n\n\t++Make your order now++");

    printf("\n Press 0 for:: Burger         ");
    printf("\n Press 1 for:: Pizza          ");
    printf("\n Press 2 for:: Fried Rice     ");
    printf("\n Press 3 for:: Chicken Fry    ");
    printf("\n Press 4 for:: French Fry     ");

    printf("\n Enter your Choice::");
    scanf("%d",& choice);
    if(choice==0)
    {
        printf("\n Enter Quantity of Burger:: ");
        //scanf("%d",&quantity);
        scanf("%d",&orderQty[0]);
        printf("Your Order has been placed successfully");
        bill[0] = orderQty[0]*price[0];
        system("cls");

    }


    else if(choice==1)
    {
        printf("\n Enter Quantity of Pizza:: ");
        scanf("%d",&orderQty[1]);
        printf("Your Order has been placed successfully");
        bill[1] = orderQty[1]*price[1];
        system("cls");
    }
    else  if(choice==2)
    {
        printf("\n Enter Quantity of Fried Rice:: ");
        scanf("%d",&orderQty[2]);
        printf("Your Order has been placed successfully");
        bill[2] = orderQty[2]*price[2];
        system("cls");
    }
    else if(choice==3)
    {
        printf("\n Enter Quantity of Chicken Fry:: ");
        scanf("%d",&orderQty[3]);
        printf("Your Order has been placed successfully");
        bill[3] = orderQty[3]*price[3];
        system("cls");
    }
    else if(choice==4)
    {
        printf("\n Enter Quantity of French Fry:: ");
        scanf("%d",&orderQty[4]);
        printf("Your Order has been placed successfully");
        bill[4] = orderQty[4]*price[4];
        system("cls");
    }
    else
    {
        printf("\nWrong key & press 1 to go home: ");
        scanf("%d",& a);
        if(a==1)
        {
            main();
            system("cls");
        }
        else
        {
            printf("\nWrong input please restart the application");
            system("cls");
        }

    }

    printf("\n\nDo you want to order more \n\t 1=yes \n\t 2=bill");
    printf("\nEnter Your Choice::");
    scanf("%d",&m_order);

    if(m_order==1)
    {
        system("cls");
        order();
    }
    else if(m_order=2)
    {
        system("cls");
        invioce();
    }
    else
    {

        system("cls");
        main();
    }


}

int invioce()
{
    printf("\n\t-->Welcome to Take Out<--");
    printf("\n\n\t++Here Is your Bill++");
    float total_price=0,return_amount;
    int i;
    int given_amount;
    for(i=0; i<5; i++)
    {
        if(orderQty[i]>0)
        {
            total_price=total_price+bill[i];
        }
    }


    int z=0;
    for(z=0; z<5; z++)
    {
        if(orderQty[z]>0)
        {
            printf("\n\n\t %s                 %d                      %d                    %.2f",item[z],orderQty[z],price[z],bill[z]);
        }
    }
    printf("\n\n \t\t\t\t                   Your Total Cost is :               %.2f",total_price);
    printf("\n\n \t\t\t                        Enter given amount:                 ");
    scanf("%d",&given_amount);
    return_amount=(given_amount)-(total_price);
    printf("\n \t\t \t                        The return amount is:               %.2f",return_amount);
    printf("\n\n\t\t\t*****Thanks for coming. Please come again*****\n\n\n\n\n\n\n");

    FILE *myFile2;
    myFile2 = fopen("invoice.txt", "w");
    fprintf(myFile2,"%s","\n\t-->Welcome to Take Out<--");
    fprintf(myFile2,"%s","\n\n\t++Here Is your Bill++");

    for(z=0; z<5; z++)
    {
        if(orderQty[z]>0)
        {
            fprintf(myFile2,"\n\n\t %s                 %d                      %d                    %.2f",item[z],orderQty[z],price[z],bill[z]);
        }

    }
    fprintf(myFile2,"%s %.2f","\n\t\t\t\t\t\t\t\t Total Price: ", total_price);
    fprintf(myFile2,"%s %d","\n\t\t\t\t\t\t\t\t Given Amount:  ", given_amount);
    fprintf(myFile2,"%s %.2f \n","\n\t\t\t\t\t\t\t\t Return Amount: ",(given_amount)-(total_price) );
    fprintf(myFile2,"%s","\n\n\t\t\t*****Thanks for coming. Please come again*****\n\n\n\n\n\n\n");
    fclose(myFile2);

    printf("\n The Text File Is On That Location: invoice.txt");
}
