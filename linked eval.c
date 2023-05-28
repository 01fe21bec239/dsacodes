#include<stdio.h>
#include<stdlib.h>


struct node
{
    int data;
    struct node *link;
};
typedef struct node *NODE;

NODE create_node();
NODE insert_end(NODE head);
void display_list(NODE head);
NODE insert_front(NODE head);
NODE delete_end(NODE head);
NODE delete_front(NODE head);
NODE insert_spc(NODE head);
NODE delete_spc(NODE head);


int main()
{
    NODE head=NULL;
    int count;
    int ch;
    while(1)
    {
        printf("\nSingly linked list menu\n");
        printf("1:Insert_end 2:Insert_front 3:Delete_end 4:Delete_front  5:Display  6:Insert specific  7:Delete specific 8:Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:head=insert_end(head);
            break;
            case 2:head=insert_front(head);
            break;
            case 3:head=delete_end(head);
            break;
            case 4:head=delete_front(head);
            break;
            case 5:display_list(head);
            break;
            case 6:head=insert_spc(head);
            break;
            case 7:head=delete_spc(head);
            break;
            case 8:exit(0);
            default:printf("Invalid selection\n");
            break;
        }
    }
    return 0;
}

NODE create_node()
{
    NODE newnode;
    newnode=(NODE)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Memory not allocated\n");
        exit(0);
    }
    printf("Enter data\n");
    scanf("%d",&newnode->data);
    newnode->link=NULL;
    return newnode;
}

NODE insert_end(NODE head)
{
    NODE cur,newnode;
    newnode=create_node();
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        cur=head;
        while(cur->link!=NULL)
        {
            cur=cur->link;
        }
        cur->link=newnode;
    }
    return head;
}

void display_list(NODE head)
{
    NODE cur=head;
    if(head==NULL)
    {
        printf("Singly linked list is empty\n");
    }
    else
    {
        while(cur!=NULL)
        {
            printf("%d->",cur->data);
            cur=cur->link;
        }
    }
}

NODE insert_front(NODE head)
{
    NODE newnode;
    newnode=create_node();
    if(head==NULL)
    {
        head = newnode;
    }
    else
    {
        newnode->link = head;
        head=newnode;
    }
    return head;
}

NODE delete_end(NODE head)
{
    NODE prev , cur;
    if(head==NULL)
    {

        printf("Singly linked list is empty\n");
    }
    else if(head->link==NULL)
    {
        printf("Deleted %d\n",head->data);
        free(head);
        head=NULL;
    }
    else
    {
        prev=NULL;
        cur=head;
        while(cur->link!=NULL)
        {
            prev=cur;
            cur=cur->link;
        }
        prev->link=NULL;
        printf("Deleted %d\n",cur->data);
        free(cur);
    }
    return head;
}

NODE delete_front(NODE head)
{
    NODE cur;
    if(head==NULL)
    {
        printf("Singly linked list is empty\n");
    }
    else if(head->link==NULL)
    {
        printf("Deleted %d\n",head->data);
        free(head);
        head=NULL;
    }
    else
    {
        cur=head;
        head=head->link;
        printf("Deleted %d\n",cur->data);
        cur->link=NULL;
        free(cur);
    }
    return head;
}
int count_nodes(NODE head)
{
    int count=0;
    NODE cur;
    if(head==NULL)
    {
        return count;
    }
    else
    {
        cur=head;
        while(cur!=NULL)
        {
            count++;
            cur=cur->link;
        }
    }
    return count;
}
NODE insert_spc(NODE head)
{
    NODE newnode,prev,cur;
    int c,p,i;
    newnode=create_node(head);
    c=count_nodes(head);
    printf("Enter position\n");
    scanf("%d",&p);
    if(p>1 && p<c)
    {
        prev=NULL;
        cur=head;
        for(i=0;i<p-1;i++)
        {
            prev=cur;
            cur=cur->link;
        }
        prev->link=newnode;
        newnode->link=cur;
    }
    return head;
}
NODE delete_spc(NODE head)
{
    NODE prev,cur;
    int c,p,i;
    c=count_nodes(head);
    printf("Enter position\n");
    scanf("%d",&p);
    if(p>1 && p<c)
    {
        prev=NULL;
        cur=head;
        for(i=0;i<p-1;i++)
        {
            prev=cur;
            cur=cur->link;
        }
        prev->link=cur->link;
        printf("Deleted %d",cur->data);
        free(cur);
   }
    return head;
}


