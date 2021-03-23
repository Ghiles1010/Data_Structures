#include<stdio.h>
#include<stdlib.h>
#include"structs/structs.h"
#include"algorithms/Linked_Lists.h"
#include"algorithms/Binary_Search_Tree.h"


int main(){

    Binary_Search_Tree BST;

    initalize_BST(&BST);



    for(int i = 0; i < 15; i++){

        insert_BST(&BST, rand()%10);
    }



    print_infixe_BST(BST);

    print_BST(BST);

    printf("\n Height : %d\n Last: %d", BST.height, BST.last_row_size);


	return 0;
}
