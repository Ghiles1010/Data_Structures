#include<stdio.h>
#include<stdlib.h>
#include"../structs/structs.h"

int power(int x, int p){

    int res = 1;

    if(p == 0)
        return 1;

    for(int i=0; i<p; i++)
        res*=x;

    return res;
}


typedef struct node_queue{

    Node_BST *element;
    struct node_queue *next;

}node_queue;


void enqueue(node_queue **head, node_queue **tail, Node_BST *x){

    node_queue *node = (node_queue*)malloc(sizeof(node_queue));

    node->element = x;
    node->next = NULL;

    // queue empty
    if(*head == NULL){

        *head = node;
        *tail = node;

    } else {

        (*tail)->next = node;
        *tail = node;
    }
}

Node_BST* dequeue(node_queue **head, node_queue **tail){

    node_queue *node;
    Node_BST *x;

    if(*head != NULL){

        node = *head;
        *head = (*head)->next;

        x = node->element;
        free(node);


        if(*head == NULL){

            *tail = NULL;
        }

        return x;
    }
    else{

        printf("Intern error, queue is empty, returning NULL");
        return NULL;
    }
}



void print_BST(Binary_Search_Tree BST){

    node_queue *head = NULL, *tail = NULL;
    Node_BST *temp;
    int current_line_size = 1, cpt = 0, space_num,
    current_height = 1, max_line_size = power(2,BST.height);

    if(BST.root == NULL){

        printf("The tree is empty. \n");
        return;
    }


    enqueue(&head, &tail, BST.root);

    // while the head is not empty
    while(head != NULL){

        temp = dequeue(&head, &tail);
        cpt ++;

        if(cpt == current_line_size){

            printf("\n");

            space_num = (max_line_size - power(2, current_height)) / 2;

            for(int i = 0; i<space_num; i++){
                printf(" ");
            }

            space_num/=2;

            current_height +=1;
            current_line_size *=2 ;
        }

        printf("%d  ", temp->element);

        if(temp->Left_Child != NULL){

            enqueue(&head, &tail, temp->Left_Child);
        }

        if(temp->Right_Child != NULL){

            enqueue(&head, &tail, temp->Right_Child);
        }
    }
}








void initalize_BST(Binary_Search_Tree *BST){

    BST->root = NULL;
    BST->height = 0;
    BST->last_row_size = 0;
}


Node_BST* create_node(int x){

        Node_BST *node = (Node_BST*)malloc(sizeof(Node_BST));
        node->element = x;
        node->Left_Child = NULL;
        node->Right_Child = NULL;

        return node;

}

void insert(Node_BST *node, int x){

    if(x > node->element){

        if(node->Right_Child == NULL){

            node->Right_Child = create_node(x);
        }
        else{

            insert(node->Right_Child, x);
        }

    }
    else{

        if(node->Left_Child == NULL){

            node->Left_Child = create_node(x);
        }
        else{

            insert(node->Left_Child, x);
        }

    }
}



void insert_BST(Binary_Search_Tree *BST, int x){


    if(BST->root == NULL){

        Node_BST *node = (Node_BST*)malloc(sizeof(Node_BST));
        node->element = x;

        node->Left_Child = NULL;
        node->Right_Child = NULL;

        BST->root = node;
        BST->last_row_size = 1;

    }
    else{

        insert(BST->root, x);
    }

    /*** Updating information of the tree ***/

    if(BST->height == 0){

        BST->height = 1;
        BST->last_row_size = 1;

    } else {

        // if we filled a new row
        if( BST->last_row_size + 1 > power(2, BST->height-1) ){

            BST->height ++;
            BST->last_row_size = 1;

        }else{

            BST->last_row_size ++;
        }
    }
}


void infixe(Node_BST *node){

    if(node != NULL){

        infixe(node->Left_Child);
        printf("%d ", node->element);
        infixe(node->Right_Child);
    }

}

void print_infixe_BST(Binary_Search_Tree BST){

    infixe(BST.root);
    printf("\n");

}




