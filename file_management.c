#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//create a struct for the user 
struct node {
    int id;
    char name[100];
    float mark;
    struct node *next,*prev;
};

struct node *user[100];

struct node *Create(int id,char name[],float mark){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->id=id;
    strcpy(temp->name,name);
    temp->mark=mark;
    temp->prev=NULL;
    temp->next=NULL;
    return temp;
}

struct node *Insert(struct node *head,int id,char name[],float mark){
    struct node *new = Create(id,name,mark);
    if(head == NULL){
        return new;   // first student becomes head
    }
    struct node *temp=head;
    while(temp->next!=NULL){ //goes to the end node
        temp=temp->next;
    }
    temp->next=new;
    new->prev=temp;
    return head;
}

void display(struct node *head){
    struct node *temp=head;
    while(temp!=NULL){
        printf("%s - %d - %.2f\n",temp->name,temp->id,temp->mark);
        temp=temp->next;
    }

}
void search(struct node *head,int id){
    struct node *temp=head,*found=NULL;
    int signal=0;
    while(temp!=NULL){
        if(temp->id==id){
           signal=1;
           found=temp;
           break;
        } 
        temp=temp->next;  
    }

    if(signal==1){
         printf("%s of ID: %d is present",found->name,found->id);
    }
    else{
        printf("No student of ID:%d exists",id);
    }
}
int  main(){
    int n;
    int id;
    float mark;
    char name[100];
    struct node *head=NULL;
    //conditions loop
    while(1){
        scanf("%d",&n);
        switch(n){
            case 1:     //add new student 
                        scanf("%d %s %f",&id,name,&mark);
                        head=Insert(head,id,name,mark);
                        break;

            case 2:     //display
                        display(head);
                        break;

                        //search
            case 3:     scanf("%d",&id);
                        search(head,id);
                        break;
        }
    }
}
