#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10

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
void Push(char stack[],int* top, char *item){
	if(isFull(*top)){
		printf("stack is full\n");
	}else{
		stack[++(*top)]=*item;
	}
}
char Delete(char stack[], int* top){
	int i,j;
	if(isEmpty(*top)){
		printf("stack is empty\n");
	}else{
		return stack[(*top)--];
	}
}
int priority(char op) { 
    switch(op) { 
        case '+': case '-': return 12;
        case '*': case '/': case '%': return 13;
        default:            return 0;
    } 
} 
void InToPostfix(char infix[], char postfix[])
{ 
    char stack[MAX];
    int i, j, top=-1;
    //create(stack,&top);
    for(i=strlen(infix)-1, j=0; i>=0; i--) 
        switch(infix[i]) 
        { 
            case ')':  // �B��l���| 
            	Push(&stack[0],&top,&infix[i]);
                /*  1. push infix[i] �� stack �� */
                break; 
            case '+': case '-': case '*': case '/': 
                while(priority(stack[top]) >= priority(infix[i])) {  // ����u���v
                    postfix[j++] = Delete(&stack[0],&top);
					/*  2. �N stack ���� pop �X �s�J postfix[j++] ��*/
                } 
                Push(&stack[0],&top,&infix[i]);
                /*  2. push infix[i] �� stack �� */  //�N�ӹB��l�[�J���|
                break; 
            case '(': 
                while(stack[top] != ')') { // �J ) ��X�� ( 
                	postfix[j++] = Delete(&stack[0],&top);
                    /*  3. �N stack ���� pop �X �s�J postfix[j++] �� */
                } 
                Delete(&stack[0],&top);
                /* �N stack ���� pop �X */  // ����X ( 
                break; 
            default:  // �B�⤸������X 
                postfix[j++] = infix[i];
	    }
    while(top>-1)  //�N���|���Ҧ��B�⤸��X
    	postfix[j++] = Delete(&stack[0],&top);
        /*  5. �N stack ���� pop �X �s�J postfix[j++] �� */
} 


int main(){
	int i=1,j;
	char infix[MAX]={0},postfix[MAX]={0};
	while(i){
		printf("INPUT: ");
		scanf("%s",infix);
		InToPostfix(&infix[0],&postfix[0]);
		for(j=strlen(postfix)-1;j>=0;j--){
			printf("%c",postfix[j]);
		}
		printf("\n");
	}
	
}
