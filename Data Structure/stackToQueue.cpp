/****************************************STACK TO QUEUE**************************************/


#include <bits/stdc++.h>
using namespace std;
/*******************Stack*******************/
struct Node1
{
    int data;
    struct Node1 *next;
}*temp1,*node1;

struct Head1
{
    int count;
    struct Node1 *top;
}*head1;

Create_Head_Stack()
{
    head1 = (struct Head1*) malloc(sizeof(struct Head1));
    head1->count = 0;
    head1->top = NULL;
}

Create_Node_Stack()
{
    node1 = (struct Node1*) malloc(sizeof(struct Node1));
    scanf("%d", &node1->data);
    node1->next = NULL;
}

void push()
{
    Create_Node_Stack();
    node1->next = head1->top;
    head1->top = node1;
    head1->count++;
}

void pop()
{
    if(head1->count != 0){
    temp1 = head1->top;
    head1->top = temp1->next;
    free(temp1);
    head1->count--;
    }
    else printf("No data in stack for pop\n");

}

display1()
{
    temp1 = head1->top;
    while(temp1 != NULL)
    {
        printf("%d ", temp1->data);
        temp1 = temp1->next;
    }
    putchar('\n');
}

/*************************Queue****************************/

struct Node2
{
    int data;
    struct Node2 *next;
}*temp2,*node2;

struct Head2
{
    int count;
    struct Node2 *front;
    struct Node2 *rear;
}*head2;

Create_Head_Queue()
{
    head2 = (struct Head2*) malloc(sizeof(struct Head2));
    head2->count = 0;
    head2->front = NULL;
    head2->rear = NULL;
}

Create_Node_Queue(int m)
{
    node2 = (struct Node2*) malloc(sizeof(struct Node2));
    //scanf("%d", &node2->data);
    node2->data = m;
    node2->next = NULL;
}

void Enqueue(int n)
{
    Create_Node_Queue(n);
    if(head2->count == 0)
    {
        head2->front = node2;
        head2->rear = node2;
        head2->count++;
    }
    else
    {
        head2->rear->next = node2;
        head2->rear = node2;
        head2->count++;
    }
}

display2()
{
    temp2 = head2->front;
    while(temp2 != NULL)
    {
        printf("%d ", temp2->data);
        temp2 = temp2->next;
    }
    putchar('\n');
}

/************************Stack TO Queue*****************/
void StackToQueue()
{
    temp1 = head1->top;
    while(temp1 != NULL)
    {
        int x = temp1->data;
        pop();
        Enqueue(x);
        temp1 = temp1->next;
    }
}

int main()
{
    Create_Head_Stack();
    Create_Head_Queue();
    for(;;){
    printf("1-Push  2-Stack TO Queue  3-display(stack)  4-display(queue)\n");
    int num; scanf("%d", &num);
    if(num == 1) push();
    else if(num == 2) StackToQueue();
    else if(num == 3) display1();
    else if(num == 4) display2();
    }
    return 0;
}
