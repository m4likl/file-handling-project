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

struct node *Insert(int id,char name[],float mark){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->id=id;
    strcpy(temp->name,name);
    temp->mark=mark;
    temp->prev=NULL;
    temp->next=NULL;

}

void Insert(int id,char name,float mark){
    
}
int  main(){
    int n;
    int id;
    float mark;
    char name[100];
    //conditions loop
    while(1){
        scanf("%d",&n);
        switch(n){
            case 1:     //add new student 
                        scanf("%d %s %f",&id,name,&mark);
                        Insert(id,name,mark);
                        break;
        }
    }
}
