#include <stdio.h> 
#include<time.h>
#include<stdlib.h>
   
//Represent a list of the doubly linked list  
  
struct list{  
    int data;  
    struct list *previous;  
    struct list *next;  
};      
   
//Represent the head and tail of the doubly linked list  
struct list *head, *tail = NULL;  
   
//addData() will add a data to the list  
struct list  addData(int data) {  
    //Create a new node  
    struct list *newlist = (struct list*)malloc(sizeof(struct list));  
    newlist->data = data;  
      
    //If list is empty  
    if(head == NULL) {  
        //Both head and tail will point to newNode  
        head = tail = newlist;  
        //head's previous will point to NULL  
        head->previous = NULL;  
        //tail's next will point to NULL, as it is the last node of the list  
        tail->next = NULL;  
    }  
    else {  
        //newNode will be added after tail such that tail's next will point to newNode  
        tail->next = newlist;  
        //newNode's previous will point to tail  
        newlist->previous = tail;  
        //newNode will become new tail  
        tail = newlist;  
        //As it is last node, tail's next will point to NULL  
        tail->next = NULL;  
    }  
}  
   
//removeDuplicatelist() will remove duplicate elements from the list  
void removeDuplicatelist() {  
    //Node current will point to head  
    struct list *current, *index, *temp;  
      
    //Checks whether list is empty  
    if(head == NULL) {  
        return;  
    }  
    else {  
        //Initially, current will point to head node  
        for(current = head; current != NULL; current = current->next) {  
            //index will point to node next to current  
            for(index = current->next; index != NULL; index = index->next) {  
                if(current->data == index->data) {  
                    //Store the duplicate node in temp  
                    temp = index;  
                    //index's previous node will point to node next to index thus, removes the duplicate node  
                    index->previous->next = index->next;  
                    if(index->next != NULL)  
                        index->next->previous = index->previous;  
                    //Delete duplicate node by making temp to NULL  
                    temp = NULL;  
                }  
            }  
        }  
    }  
}  
   
//display() will print out the data of the list  
void display() {  
    //Node current will point to head  
    struct list *current = head;  
    if(head == NULL) {  
        printf("List is empty\n");  
        return;  
    }  
    while(current != NULL) {  int k=0;
        //Prints each node by incrementing pointer.  
        printf("%d ", current->data);  
        current = current->next;  
        k++;
        if(k%5==0){
            printf("\n");
        }
    }  
    printf("\n");  
}  

//sortList() will sort the given list in ascending order  
void sortList() {  
    struct list *current = NULL, *index = NULL;  
    int temp;  
    //Check whether list is empty  
    if(head == NULL) {  
        return;  
    }  
    else {  
        //Current will point to head  
        for(current = head; current->next != NULL; current = current->next) {  
            //Index will point to node next to current  
            for(index = current->next; index != NULL; index = index->next) {  
                //If current's data is greater than index's data, swap the data of current and index  
                if(current->data > index->data) {  
                    temp = current->data;  
                    current->data = index->data;  
                    index->data = temp;  
                }  
            }  
        }  
    }  
}   
   
int main()  
{   struct list head;
    srand(time(NULL));

    for(int i=0;i<200;i++){ int i;
    int n= rand()%49+1;
    head=addData(n);
    i++;
    
    }

      
    printf("Originals list: \n");  
    display(head);
    sortList();
    printf("Sorted list: \n");  
    display(head);
      
    //Removes duplicate nodes  
    removeDuplicatelist(head);  
      
    printf("List after removing duplicates: \n");  
    display(head);  
   
    return 0;  
}  
