#include<stdio.h>
#include<stdlib.h>
#include"../structs/structs.h"

void initalize_BST(Binary_Search_Tree *BST){

    BST->root = NULL;
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

    }
    else{

        insert(BST->root, x);
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




