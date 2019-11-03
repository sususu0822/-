#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
int isFull(int top){
	if(top>=MAX-1) return 1;
	else return 0;
}
int isEmpty(int top){
	if(top == -1) return 1;
	else return 0;
}
void Push(int stack[], int* top, char* item){
	int n;
	n = (*item)-'0';
	if(isFull(*top)){
		printf("stack is full\n");	
	}
	else{
		stack[++(*top)] = n;
	}
}
char pop(int stack[], int* top){
	if(isEmpty(*top)) printf("stack is empty\n");
	else{
		return stack[(*top)--];
	}
} 
int priority(char op){
	switch(op){
		case '+': case '-': return 12;
		case '*': case '/': case'%': return 13;
		default : return 0;
	}
}
int main(){
	char input[MAX]={0};
	int ans,i,j,temp;
	int top=-1;
	int stack[MAX]={0};
	//
	printf("Input: ");
	scanf("%s",input);
	//printf("%s %d",input,strlen(input));
	//
	for(i=strlen(input)-1,j=0;i>=0;i--){
		switch(input[i]){
			case'+':{
				temp = pop(&stack[0],&top);
				stack[top] = temp + stack[top];
				break;
			}
			case'-':{
				temp = pop(&stack[0],&top);
				stack[top] = temp - stack[top];
				break;
			}
			case'*':{
				temp = pop(&stack[0],&top);
				stack[top] = temp * stack[top];
				break;
			}
			case'/':{
				temp = pop(&stack[0],&top);
				stack[top] = temp / stack[top];
				break;
			}
			case'%':{
				temp = pop(&stack[0],&top);
				stack[top] = temp % stack[top];
				break;
			}
			default:{
				Push(&stack[0],&top,&input[i]);
				break;
			}
		}
	}
	printf("Ans: %d\n",stack[0]);
} 
