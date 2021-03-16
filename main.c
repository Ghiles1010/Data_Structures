#include<stdio.h>
#include<stdlib.h>
#include"structs/structs.h"
#include"algorithms/Linked_Lists.h"
#include"algorithms/Binary_Search_Tree.h"


int main(){

    Binary_Search_Tree BST;

    initalize_BST(&BST);

    insert_BST(&BST, 5);
    insert_BST(&BST, 4);
    insert_BST(&BST, 10);
    insert_BST(&BST, 2);
    insert_BST(&BST, 2);

    print_infixe_BST(BST);


	return 0;
}
