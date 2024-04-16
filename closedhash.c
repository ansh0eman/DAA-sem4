#include <stdio.h>
#include <stdlib.h>

int h[10] ={NULL};

void insert(){
    int key, i, item, hkey;
    printf("Enter an element: ");
    scanf("%d", &item);
    key = item % 10;
    for(i=0; i<10; i++){
        hkey = (key + i) % 10 ;
        if(h[hkey] == NULL){
            h[key] = item;
            break;
        }
    }
    if (i==10)
        printf("cannot be inserted\n");
}

void search(){
    int i, key, index;
    printf("Enter seach element: ");
    scanf("%d", &key);
    int hkey = key % 10;
    for(i =0; i<10; i++){
        index = (hkey + i) % 10;
        if(h[index] == key){
            printf("Element found at index %d\n", index);
            break;
        }
    }
    if(i == 10){
        printf("value not found\n");
    }
}

void print(){
    int i;
    printf("elements in hash table: ");
    for(i = 0 ; i < 10 ; i++)
        printf("\nat index %d  value =  %d",i,h[i]);
}

int main(){
    int ch;
    while(1){
        printf("1.Insert\n2.Search\n3.Print\n4.Exit\n");
        scanf("%d", &ch);

        switch(ch){
            case 1: 
                insert();
                break;
            case 2:
                search();
                break;

            case 3:
                print();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    }
}