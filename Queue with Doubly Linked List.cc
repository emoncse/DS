///*QUEUE USING DOUBLY LINKED LIST*///
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *front; //head//
struct node *rear;  //tail//

void init(){
    front = 0;
    rear = 0;
}
void enQueue(int x){
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data = x;
    newNode -> next = 0;
    newNode -> prev = rear;

    if(front ==0 && rear ==0) front = rear = newNode;
    else{
        rear->next = newNode;
        rear = newNode;
    }
}
void deQueue(){
    struct node *temp;
    temp = front;
    if(front == 0){
        printf("Queue is Empty!\n");
    }
    else{
        printf("DeQueued: %d\n",front->data);
        front = front-> next;
        free(temp);
    }
}
void printFront(){
    struct node *temp;
    temp = front;
    if(front == 0) printf("Queue is empty!");
    else printf("Front Element is:%d", front->data);
}
int length(){
    int count = 0;
    struct node *temp;
    temp=front;
    while(temp!=0){
        count++;
        temp=temp->next;
    }
    printf("Length of Queue is %d\n",count);
    return count;
}
void display(){
    struct node *temp;
    temp = front;
    if(front==0){
        printf("Queue is Empty!\n");
    }
    else{
        printf("Queue: ");
        while( temp != 0 ){
            printf("%d ",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
int main()
{
    init();
    int op;
    printf("1.Add element to Queue.\n2.DeQueue from Queue.\n3.Display Queue.\n4.Display Front Element\n5.Display length\n\n");

    while(1){
        scanf("%d",&op);
        if(op==1){
            int val;
            scanf("%d",&val);
            enQueue(val);
        }
        else if(op==2) deQueue();
        else if(op==3) display();
        else if(op==4) printFront();
        else if(op==5) length();
    }
    return 0;
}
