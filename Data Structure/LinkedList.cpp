
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*temp,*node,*t;

struct Head
{
    int count;
    struct Node *p;
}*head;

void Create_Head()
{
    head = (struct Head*) malloc(sizeof(struct Head));
    head->count = 0;
    head->p = NULL;
}

void Create_Node()
{
    node = (struct Node*) malloc(sizeof(struct Node));
    scanf("%d", &node->data);
    node->next = NULL;
}

void Insert_First()
{
    Create_Node();
    node->next = head->p;
    head->p = node;
    head->count++;
}
void Insert_Last()
{
    temp = head->p;
    if(head->count != 0)
    {
        while(temp->next != NULL)
            temp = temp->next;
        Create_Node();
        temp->next = node;
        head->count++;
    }
    else
        printf("No data in linked list\n");
}

void display()
{
    temp = head->p;
    if(temp != NULL)
    {
        while(temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
    else
        printf("No data in linked list\n");
}

int num;
void Insert_Anywhere()
{
    if(head->count >0)
    {
        printf("Enter the data which is in Linked-List : ");
        scanf("%d", &num);
        temp = head->p;
        while(temp != NULL)
        {
            if(temp->data == num)
                break;
            temp = temp->next;
        }
        if(temp != NULL)
        {
            Create_Node();
            node->next = temp->next;
            temp->next = node;
            display();
            head->count++;
        }
        else if(temp == NULL)
            printf("Data not found!!\n");

    }
    else
        printf("No data in Linked-List\n");

}

void Del_First()
{
    if(head->count > 0)
    {
        temp = head->p;
        head->p = temp->next;
        head->count--;
        free(temp);
    }
    else
        printf("No data in Linked-List\n");
}

void Del_Last()
{
    int c=1;
    temp = head->p;
    while(c <= head->count-2)
    {
        temp = temp->next;
        c++;
    }
    free(temp->next->next);
    temp->next = NULL;
    head->count--;

}

void Del_Anywhere()
{
    temp = head->p;
    if(head->count != 0)
    {

        printf("Enter a data which you want to delete : ");
        int m;
        scanf("%d", &m);
        if(temp->data == m)
        {
            head->p = temp->next;
            free(temp);
            head->count--;
        }
        else
        {
            while(temp != NULL)
            {
                if(temp->data == m)
                    break;
                t = temp;
                temp = temp->next;
            }
            if(temp != NULL)
            {
                t->next = temp->next;
                free(temp);
                head->count--;
                printf("After deleting data : ");
            }
        }
    }
    else
        printf("No data in linked list\n");
}

int main()
{
    int z;
    Create_Head();
    for(;;)
    {
        printf("\n1-Insert First || 2-Insert Last || 3-Insert Anywhere || 4-Delete First || 5-Delete Last || 6-Delete Anywhere || 7-Display || 8-exit\n\n");
        scanf("%d", &z);
        if(z == 1)
        {
            printf("Enter the data for inserting at 1st: ");
            Insert_First();
        }

        if(z == 2)
        {
            printf("Enter the data for inserting at last: ");
            Insert_Last();
        }
        else if(z == 3)
            Insert_Anywhere();
        else if(z == 4)
            Del_First();
        else if(z == 5)
            Del_Last();
        else if(z == 6)
            Del_Anywhere();
        else if(z == 7)
        {
            printf("Displaying data : ");
            display();
            cout<<endl;
        }
        else if(z == 8)
            return 0;
    }

}
