
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*node,*temp;

struct Head
{
    int count;
    struct Node *top;
}*head;

void CreateStack()
{
    head = (struct Head*) malloc(sizeof(struct Head));
    head->count = 0;
    head->top = NULL;
}

void CreateNode()
{
    node = (struct Node*) malloc(sizeof(struct Node));
    scanf("%d", &node->data);
    node->next = NULL;
}

void push()
{
    CreateNode();
    node->next = head->top;
    head->top = node;
    head->count++;
}

void pop()
{
    if(head->count != 0)
    {
        temp = head->top;
        head->top = head->top->next;
        free(temp);
        head->count--;
    }
    else
        printf("No data in stack for pop\n");
}

void StackTop()
{
    if(head->count != 0)
    {
        printf("Stack top : %d\n",head->top->data);
    }
    else
        printf("No data in stack\n");
}

void display()
{
    temp = head->top;
    if(head->top == NULL)
        printf("No data in stack\n");
    else
    {
        printf("Displaying data : ");
        while(temp != NULL)
        {
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}

int main()
{
    int x;
    CreateStack();
    for(;;)
    {
        printf("**************************************************************\n1 (Push) || 2 (Pop) || 3 (Display) || 4 (Show top)|| 5 (Exit)\n**************************************************************\n");
        scanf("%d", &x);
        if(x == 1)
        {
            printf("Push data : ");
            push();
            printf("\n");
        }
        else if(x == 2)
        {
            pop();
            printf("\n");
        }
        else if(x == 3)
        {
            display();
            printf("\n");
        }
        else if(x == 4)
        {
            StackTop();
            printf("\n");
        }
        else if(x == 5)
            return 0;
        else
            printf("Wrong input given\n\n");
    }


}
