
/**************************************************************************/
/************************** Linked Lists **********************************/
/**************************************************************************/


typedef struct Node_LL{

	int element;
	struct Node_LL *next;

}Node_LL;


typedef struct Linked_List{

    struct Node_LL *head;
    int size;

}Linked_List;


/**************************************************************************/
/*********************** Binary Search Tree *******************************/
/**************************************************************************/

typedef struct Node_BST{

    int element;
    struct Node_BST *Left_Child;
    struct Node_BST *Right_Child;

}Node_BST;

typedef struct Binary_Search_Tree{

    struct Node_BST *root;

}Binary_Search_Tree;









