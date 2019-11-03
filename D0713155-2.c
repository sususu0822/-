#include<stdio.h>
#include<stdlib.h>
#define MAX 10
void add(int*,int*,int);
void Delete(int*,int*);
void Print(void);
int isFull(int,int);
int front=0; 
int rear=0;
int queue[MAX]={0};
int main(){
		int i=1,j,n,input;
	while(i){
		printf("[1]新增 [2]刪除 [3]顯示 [0]結束 : ");
		scanf("%d",&n);
		switch(n){
			case 1:
				printf("Input: ");
				scanf("%d",&input);
				add(&front,&rear,input);
				break;
			case 2:
				Delete(&front,&rear);
				break;
			case 3:
				Print();
				break;
			case 0:
				i=0;
				break;
			default:
				printf("ERROR\n");
				break;				
		}
	}
}
int isFull(int front, int rear){
	int i;
	if(front==(rear+1)%MAX) return 1;
	else return 0;
}
int isEmpty(int top, int rare){
	if(top==rare){
		return 1;
	}else{
		return 0;		
	}
}
void add(int* front, int* rear, int item){
	if(isFull(*front,*rear)){
		printf("queue is full\n");
	}else{
		queue[*rear]=item;
		*rear=((*rear)+1)%MAX;
	}
}
void Delete(int* front,int* rear){
	int i,j;
	if(isEmpty(*front,*rear)){
		printf("queue is empty\n");
	}else{
		*front = ((*front)+1)%MAX;
	}
}
void Print(void){
	int i,j;
	printf("queue index: ");
	if(front>rear) rear += MAX;
	for(i=front;i<rear;i++){
		printf("%d ",queue[i]);
	}
	printf("\n");
}
