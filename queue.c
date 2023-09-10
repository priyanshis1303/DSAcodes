#include<stdio.h>
#include <stdlib.h>
#define size 5
int queue[size];
int front,rear;

void init();
void enqueue(int);
void dequeue();
void display();


void init()
{
front=-1;
rear=-1;
}

void enqueue(int x)
{
if(rear==size-1){
printf("queue is full");
}else{
rear++;
queue[rear]=x;

}
}
void dequeue(){
if(rear<front){
printf("queue is empty");
}
else{
printf(" %d id deleted ",queue[front++]);
}

}
void display(){
if(rear<front){
printf("queue is empty");}
else {
for (int i=front;i<rear;i++){
printf("%d",queue[i]);
}

}

}

void main(){

int ch,x;
init();
 while(1){
printf("queue operation\n1.enqueue\n2.dequeue\n3.display\n4.exit");
  printf("enter your choice");
 
 scanf("%d",&ch);
 switch(ch){
 
 case 1:
 printf("enter the element to enqueue");
 scanf("%d",&x);
 enqueue(x);
 break;
 
 
 case 2: dequeue();
 break;
 
 case 3: display();
 break;
 case 4: exit(1);
 default : printf("wrong choice"); 
 
 
 
 }//switch
 }//do ends
}//main ends