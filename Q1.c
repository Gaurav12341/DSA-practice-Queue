#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
    

};


void Create(struct Queue *q,int size){
    q->size=size;
    q->front=q->rear=-1;
    q->Q=(int*)malloc(q->size*sizeof(int));
}
void enqueue(struct Queue*q,int x){
    if (q->rear==q->size-1)
        printf("\nQueue is full");
    else
    {
        q->rear++;
        q->Q[q->rear]=x;
    }
    }
int dequeue(struct Queue*q){
    int x=-1;
    if(q->front==q->rear)
        printf("\nQueue is Empty");
    else{
        q->front++;
        x=q->Q[q->front];

    }
    return x;
}
void Display(struct Queue q){
    for (int i = q.front+1; i <= q.rear; i++) 
    {
        printf("%d ",q.Q[i]);
    }
    
}

void CircularCreate(struct Queue*q,int size){
    q->size=size;
    q->front=q->rear=0;
    q->Q=(int*)malloc(q->size*sizeof(int));

}
void CircularEnqueue(struct Queue*q,int x){
    if((q->rear+1)%q->size==q->front)
        printf("QUeue is full");
    else{
        q->rear=(q->rear+1)*q->size;
        q->Q[q->rear]=x;
    }
}
int CircularDeque(struct Queue *q){
    int x=-1;
    if(q->front==q->rear)
        printf("Queue is empty\n");
    else{
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}
void CircularDisplay(struct Queue q){
    int i=q.front+1;
    do{
        printf("%d ",q.Q[i]);
        i=(i+1)%q.size;
      }while(i!=(q.rear+1)%q.size);
      printf("\n");
}
int main()
{
    struct Queue q;
    Create(&q,5);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    Display(q); 
    printf("\n%d\n",dequeue(&q));  //deleted element
    Display(q); 


    return 0;
}



