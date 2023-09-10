#include<stdio.h>
#include <stdlib.h>

//global declaration
int stack[50],top,maxsize;

void createstack( int n){
maxsize=n;
top=-1;

}

void push(int e){
top++;
stack[top]=e;
}

int pop(){
int temp;
top--;
temp=stack[top];
return temp;
}

int isempty(){
if(top==-1){
return 1;
}else {
return 0;
}

}
int isfull(){
if(top==maxsize-1){
return 1;
}
else{
return 0;
}
}
int peak (){
return stack[top];
}

void printstack(){
for(int i=top;i>=0;i--){
printf("%d",stack[i]);
}
}

int main(){

int choice,size,element;
printf("Enter the size of stack:");
scanf("%d",&size);
createstack(size);

do{
printf("\n1.push\n2.pop\n3.peak\n4.printstack\n0.exit");
scanf("%d",&choice);
switch(choice){

case 1:
//push
if(isfull()!=1){
printf("enter element:");
scanf("%d",&element);
push(element);
break;

}else{
printf("stack is full");
}
case 2:
//pop
if(isempty()!=1){
printf("the element popped is :%d",pop());

}else{
printf("stack is empty");
}
break;
 case 3:
 //peak
 if(isempty()!=1){
 printf("the element at peak is :%d",peak());
 }else{
 printf("stack is empty");
 }
break;
case 4:
//printstack
if(isempty()!=1){
printstack();
}else {
printf("stack is empty");
}
break;
case 0:
printf("Exit");
break;
default : printf("error");
break;

}//switch ends
}while(choice!=0);//do while ends
return 0;
}
