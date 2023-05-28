#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define size 20
struct stack
{
    int data[size];
    int top;
};

void push(struct stack *sptr,int element)
{
    if(sptr->top==size-1)
    {
        printf("STACK OVERFLOW\n");
    }
    else
    {
        sptr->top++;
        sptr->data[sptr->top]=element;
    }
}

int pop(struct stack *sptr)
{
    if(sptr->top==-1)
    {
        return -1;
    }
    else
    {
       int element=sptr->data[sptr->top];
        sptr->top--;
        return element;
    }
}
void display(struct stack *sptr)
{ int i;
FILE *fp1;
fp1=fopen("push.txt","w");
    if(sptr->top==-1)
    {
        printf("Stack empty");
    }
    else{
        for(i=sptr->top;i>-1;i--)
        {
            fprintf(fp1,"Element is %d\n",sptr->data[i]);
        }
    }
    fclose(fp1);
}
int main()
{
    struct stack s,*sptr;
    sptr=&s;
    FILE *fp;
    fp=fopen("stack.txt","w");
    int element;
    sptr->top=-1;
    int ch;
    for(int i=0;i<10;i++)
    {
        fscanf(fp,"%d",&element);
        push(sptr,element);
    }
    display(sptr);
    /*while(1)
    {
       printf("stack menu\n");
        printf("1:push 2:pop 3:Display 4:Exit\n");
        fprintf(fp,"Enter ur choice\n");
        //scanf("%d",&ch);
         //printf("%d",ch);
         /*switch(ch)
        {
            case 1:fprintf(fp,"Enter element");
                   fscanf(fp,"%d",&element);
                   push(sptr,element);
            break;
            case 2:element=pop(sptr);
            break;
            case 3:display(sptr);
            break;
            case 4:exit(0);
            break;
            default:printf("Invalid choice\n");
            break;
        }
    }*/

    fclose(fp);
return 0;


}
