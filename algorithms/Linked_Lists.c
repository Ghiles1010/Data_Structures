#include<stdio.h>
#include<stdlib.h>
#include"../structs/structs.h"

//////////////////////////////////////////////////////
void initialize_LL(Linked_List *LL){


    LL->head = NULL;
    LL->size = 0;

}

//////////////////////////////////////////////////////
void print_LL(Linked_List LL){


    Node_LL *head = LL.head;
    if(head == NULL){

        printf("The list is empty !");
    }
    else{

        while(head != NULL){

            printf("%d ", head->element);
            head = head->next;
        }
    }

    printf("\n");
}

//////////////////////////////////////////////////////
int exists(Node_LL *head, int x){


    if(head == NULL){


        return 0;
    }


    while(head != NULL){

        if(head->element == x){

            return 1;
        }
        head = head->next;
    }

    return 0;



}
//////////////////////////////////////////////////////
void insert_Position_LL(Linked_List *LL, int x, int position){

    Node_LL *p = LL->head, *q;
    int cpt = 0;


    // If it's empty
    if( (position < 0) || (position > LL->size) )  {

        printf("Error, position out of bounds\n");
        return;
    }

    // Initialize new node
    Node_LL *node = (Node_LL*) malloc(sizeof(Node_LL));
    node->element = x;

    if(position == 0){

            LL->head = node;
            node->next = p;
    }


    while(p != NULL && cpt != position){

        q = p;
        p = p->next;

        cpt++;
    }

    q->next = node;
    node->next = p;

    LL->size ++;

}

//////////////////////////////////////////////////////
void insert_Sorted_LL(Linked_List *LL, int x){

    Node_LL *p = LL->head, *q;

    // Initialize new node
    Node_LL *node = (Node_LL*) malloc(sizeof(Node_LL));
    node->element = x;

    // If it's empty
    if(LL->head == NULL){

        LL->head = node;
        node->next = NULL;
    }

    // not empty
    else{

        while(p != NULL && p->element < x){


            q = p;
            p = p->next;
        }

        if(p == LL->head){

            LL->head = node;
            node->next = p;
        }
        else{

            q->next = node;
            node->next = p;
        }

    }

    LL->size ++;
}







