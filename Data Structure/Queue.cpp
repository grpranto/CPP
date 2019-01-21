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
    struct Node *front;
    struct Node *rear;
}*head;

void Create_Head()
{
    head = (struct Head*) malloc(sizeof(struct Head));
    head->count = 0;
    head->front = NULL;
    head->rear = NULL;
}

void Create_Node()
{
    node = (struct Node*) malloc(sizeof(struct Node));
    scanf("%d", &node->data);
    node->next = NULL;
}

void Enque()
{
        Create_Node();
        if(head->count == 0)
        {
            head->front = node;
            head->rear = node;
        }
        else
        {
            head->rear->next = node;
            head->rear = node;
        }
        head->count++;
}
void display()
{
    temp = head->front;
    if(temp != NULL)
    {
        while(temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
    else
        printf("No data in Queue\n");
}

void Deque()
{
    if(head->count > 0)
    {
        temp = head->front;
        head->front = head->front->next;
        free(temp);
    }
    else
        printf("No data in queue\n");
}

void front_rear()
{
    printf("Front : %d\n", head->front->data);
    printf("Rear : %d\n", head->rear->data);
}

int main()
{
    int z;
    Create_Head();
    for(;;)
    {
        printf("-------------------------------------------------------------------------\n1-Enqueue || 2-Dequeue || 3-Front & Rear || 4-Showing all data || 5-Exit\n-------------------------------------------------------------------------\n");
        scanf("%d", &z);
        if(z == 1)
            Enque();
        else if(z == 2)
            Deque();
         else if(z == 3)
            front_rear();
        else if(z == 4)
        {
            printf("Displaying data : ");
            display();
            cout<<endl;
        }
        else if(z == 5)
            return 0;
        else
           printf("Wrong data inputted : ");
    }

}
