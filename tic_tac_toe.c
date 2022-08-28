#include<stdio.h>
#include<string.h> 
 #include<dos.h>

int insert(char[],char,int);
int turn(char[],int[]);
int check(char[]);
int exist(int,int[]);
int a_insert(int,int[]);

static char p1[100],p2[100];
static int t,ind=0,n1=0,n2=0,d=0;                           

int main()
{
     system("color 70");
//    settextbold();
    int choice;

    while(1)
    {
        int a[10];  
        ind=0;    
        char str1[]="   1\t|   2\t|   3\n________ ________ ________\n   4\t|   5\t|   6\n________ ________ ________\n   7\t|   8\t|   9";
        puts(str1);
        printf("\n");
        char str[]="   -\t|   -\t|   -\n________ ________ ________\n   -\t|   -\t|   -\n________ ________ ________\n   -\t|   -\t|   -";
        puts(str);
        printf("\n");
        
        printf("\nEnter player X name : ");
        fflush(stdin);
        gets(p1);
        printf("\nEnter player O name : ");
        gets(p2);

        label:
        printf("\nWho want to start game : \t1.%s X\t2.%s O\n\nYour choice : ",p1,p2);
        fflush(stdin);
        scanf("%d",&t);
        if(t!=1 && t!=2)
        {
            goto label;
        }

        turn(str,a);   

        start:
        printf("\n\nDo you want to play again ?\t1.YES\t2.NO\n");
        fflush(stdin);
        scanf("%d",&choice);

        if(choice==2)
        {
            printf("\n\nPlayer(X) wins %d times\nPlayer(O)) %d times\nnumber of draw matchs : %d",n1,n2,d);
            break;
        }

        else if(choice!=1 && choice!=2)
            goto start;
         
    }
    
}

int insert(char str[],char m,int pos)
{
    if(pos==1)
        str[3]=m;
    else if(pos==2)
        str[9]=m;
    else if(pos==3)
        str[15]=m;
    else if(pos==4)
        str[47]=m;
    else if(pos==5)
        str[53]=m;
    else if(pos==6)
        str[59]=m;
    else if(pos==7)
        str[91]=m;
    else if(pos==8)
        str[97]=m;
    else if(pos==9)
        str[103]=m;   
}

int turn(char str[],int a[])
{
    int che,res,flag=0,i;
    char pos;

    for(i=0;i<9;i++)
    {
        start:
        if(t==1)
        {

            printf("\nEnter position %s(X) : ",p1); 
            fflush(stdin);
            scanf("%d",&pos);

            res=exist(pos,a);

            if(res==1 || (pos<1 || pos>9))
            {
                printf("\n Error!!! retry\n");
                goto start;
            }
            else
            {
                a_insert(pos,a);

                insert(str,'X',pos);    
                puts(str);

                che=check(str);
                if(che==1)
                {
                    printf("\n\n%s win ",p1);
                    n1++;
                    flag=1;
                    break;
                }
                t=2;
            }
        }
        else if(t==2)
        {
            printf("\nEnter position %s(O) : ",p2);
            fflush(stdin);
            scanf("%d",&pos);

            res=exist(pos,a);

            if(res==1 || (pos<1 || pos>9))
            {
                printf("\nError!!! retry \n");
                goto start;
            }
            else
            {
                a_insert(pos,a);

                insert(str,'O',pos);
                puts(str);
                
                che=check(str);
                if(che==1)
                {
                    printf("\n\n%s win",p2);
                    n2++;
                    flag=1;
                    break;
                }
                t=1;
            }
        }
    }    
    if(flag==0)
    {
        d++;
        printf("\nMatch draw");
    }
}
int check(char str[])
{
    if((str[3]==str[9] && str[9]==str[15] && str[3]!='-') || (str[3]==str[47] && str[47]==str[91] && str[3]!='-') || (str[3]==str[53] && str[53]==str[103] && str[3]!='-') || (str[15]==str[53] && str[53]==str[91] && str[15]!='-'))
    {
        return 1;
    }

    else if((str[9]==str[53] && str[53]==str[97] && str[9]!='-') ||(str[15]==str[59] && str[59]==str[103] && str[15]!='-') ||(str[91]==str[97] && str[97]==str[103] && str[91]!='-'))
    {
        return 1;
    }

    else if((str[47]==str[53] && str[53]==str[59] && str[53]!='-'))
    {
        return 1;
    }


    else
    {
        return 0;
    }
    
}

int exist(int pos,int a[])
{
    int flag=0,i;
    if(pos==1)
        pos=3;
    else if(pos==2)
        pos=9;
    else if(pos==3)
        pos=15; 
    else if(pos==4)
        pos=47;
    else if(pos==5)
        pos=53;
    else if(pos==6)
        pos=59;
    else if(pos==7)
        pos=91;
    else if(pos==8)
        pos=97;
    else if(pos==9)
        pos=103;
    for(i=0;i<ind;i++)
    {
        if(a[i]==pos)
        {
            flag=1;
        }
    }
    
    return flag;
}

int a_insert(int pos,int a[])
{
    if(pos==1)
        a[ind++]=3;
    else if(pos==2)
        a[ind++]=9;
    else if(pos==3)
        a[ind++]=15; 
    else if(pos==4)
        a[ind++]=47;
    else if(pos==5)
        a[ind++]=53;
    else if(pos==6)
        a[ind++]=59;
    else if(pos==7)
        a[ind++]=91;
    else if(pos==8)
        a[ind++]=97;
    else if(pos==9)
        a[ind++]=103;
}