#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node * chain[10];

void init(){
    int i;
    for(i=0; i<10; i++){
        chain[i] = NULL;
    }
}

void insert(int item){
    
    struct node * newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = item;
    newnode->next = NULL;

    int key = item % 10;
    if(chain[key] == NULL){
        chain[key] = newnode;
    }else{ 
        struct node* temp = chain[key];

        while (temp->next)
        {
            temp=temp->next;
        }
        temp->next = newnode;       
    }
}

void print(){
    int i;
    for(i=0; i<10; i++){
        struct node* temp = chain[i];
        printf("chain[%d]->", i);
        while(temp){
            printf(" %d ->",temp->data);
            temp =temp->next;
        }
        printf("\n");
    }
}

int main(){
    init();
    int item;
    while(1){
        printf("Enter a number to insert: ");
        scanf("%d", &item);
        if(item == -1)
            break;
        insert(item);
    }
    printf("Hash Table: \n");
    print();

    return 0;
}