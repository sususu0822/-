#include<stdio.h>
#include<stdlib.h>
struct Node{
	int num;
	struct Node* left;
	struct Node* right;
};
typedef struct Node* nodeLink;
nodeLink head=NULL;
nodeLink newnode(int num){
	nodeLink add = (nodeLink)malloc(sizeof(struct Node));
	if(add!=NULL){
		add->num = num;  //指標結構需用->
        add->right = add;  //左右都指向自己
        add->left = add;
	}
	return add;
}
void Insert(){
	int n,flag=1;
	scanf("%d",&n);
	nodeLink ptr=head;
	nodeLink add=newnode(n);
	
	if(head==NULL){
		head=add;
	}else{
		/*ptr右邊指標等於head的左邊指標時跳出*/
		while(ptr->right!=head->left){
			if(ptr->right->num>add->num){
				add->right=ptr->right->left;
				ptr->right->left=add->right;
				ptr->right=add->left;
				add->left=ptr->right;
				flag=0;
				break;
			}else{
				ptr=ptr->right;
			}	
		}
		if(flag==1){
			ptr->right=add->left;
			add->left=ptr->right;
			add->right=head->left;
			head->left=add->right;
		}
	}
}
void Delete(){
	int n;
	nodeLink ptr=head;
	scanf("%d",&n);
	if(head==NULL){
		printf("this Link is Empty\n");
	}else{
		if(head->num==n){
			head->left->right = head->right;
			head->right->left = head->left;
			head = head->right;
		}
		while(ptr->right!=head->left){
			if(ptr->right->num==n){
				nodeLink del;
				del=ptr->right;
				ptr->right->right->left=del->left;
				ptr->right=del->right;
				break;
			}else{
				ptr=ptr->right;
			}
		}
	}
}
void Print(){/**/
	nodeLink ptr=head;
	if(head==NULL){
		printf("this Link is Empty\n");
	}else{
		printf("%d\t",ptr->num);
		ptr=ptr->right;
		while(ptr!=head->left){
			printf("%d\t",ptr->num);
			ptr=ptr->right;
		}
	}
}
int main()
{
    int menu;
    while(1)
    {
        printf("\n[1]Insert [2]Delete [3]Print [Else]End : ");
        scanf(" %d",&menu);
        switch(menu)
        {
            case 1:  
                Insert();
                break;
            case 2:  
                Delete();
                break;
            case 3: 
                Print();
                break;
            default:
                printf("Exit!\n");
                exit(1);
                break;
        }
    }
}
