#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int stack[MAX]={0};
void Push(int*,int);
void Delete(int*);
void Print(void);
int isFull(int);
int top=-1; 
int main(){
	int i=1,j,n,input;
	while(i){
		printf("[1]新增 [2]刪除 [3]顯示 [0]結束 : ");
		scanf("%d",&n);
		switch(n){
			case 1:
				printf("Input: ");
				scanf("%d",&input);
				Push(&top,input);
				break;
			case 2:
				Delete(&top);
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
int isFull(int top){
	int i;
	if(top>=MAX-1) return 1;
	else return 0;
}
int isEmpty(int top){
	if(top==-1){
		return 1;
	}else{
		return 0;		
	}
}
void Push(int* top, int item){
	if(isFull(*top)){
		printf("stack is full\n");
	}else{
		stack[++(*top)]=item;
	}
}
void Delete(int* top){
	int i,j;
	if(isEmpty(*top)){
		printf("stack is empty\n");
	}else{
		stack[(*top)--];
	}
}
void Print(void){
	int i,j;
	printf("stack index: ");
	for(i=top;i>=0;i--){
		printf("%d ",stack[i]);
	}
	printf("\n");
}
