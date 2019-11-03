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
            case ')':  // 運算子堆疊 
            	Push(&stack[0],&top,&infix[i]);
                /*  1. push infix[i] 至 stack 中 */
                break; 
            case '+': case '-': case '*': case '/': 
                while(priority(stack[top]) >= priority(infix[i])) {  // 比較優先權
                    postfix[j++] = Delete(&stack[0],&top);
					/*  2. 將 stack 中值 pop 出 存入 postfix[j++] 中*/
                } 
                Push(&stack[0],&top,&infix[i]);
                /*  2. push infix[i] 至 stack 中 */  //將該運算子加入堆疊
                break; 
            case '(': 
                while(stack[top] != ')') { // 遇 ) 輸出至 ( 
                	postfix[j++] = Delete(&stack[0],&top);
                    /*  3. 將 stack 中值 pop 出 存入 postfix[j++] 中 */
                } 
                Delete(&stack[0],&top);
                /* 將 stack 中值 pop 出 */  // 不輸出 ( 
                break; 
            default:  // 運算元直接輸出 
                postfix[j++] = infix[i];
	    }
    while(top>-1)  //將堆疊內所有運算元輸出
    	postfix[j++] = Delete(&stack[0],&top);
        /*  5. 將 stack 中值 pop 出 存入 postfix[j++] 中 */
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
