//Convert a BST to DLL
#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node *left=NULL;
	Node *right=NULL;
};


//creates the node for DLL
Node* create(int localData)
{
	try{
		Node *node=new Node;
		node->data=localData;
		node->left=NULL;
		node->right=NULL;
		return node;
	}
	catch(bad_alloc xa)
	{
		cout<<"Can't Allocate Memory\n";
		return NULL;
	}
}


//For Displaying the DLL
void Display(Node *head)        //For displaying the nodes in the doubly linked DoublyList
{
    Node *temp=head;
    cout<<"\n\nContents of the DoublyList:\n";
    while(temp!=NULL)
    {
        cout<<temp->data<<"  ";
        temp=temp->right;
    }
    cout<<endl;

}


//converts a BST to a DLL
/*Do inorder traverasl and during it convert it into a BST.
store the previous node and at each root step make the root->left=previous and previous->next=root
*/
Node* BSTtoDLL(Node *root,Node **pre,Node **headNode)
{

	if(root==NULL)
		return NULL;

   //go to the left subtree
	BSTtoDLL(root->left,pre,headNode);


   //this is to store the first node of inorder traversal and the condition is true only once during the traversal start
   if(*headNode==NULL)
      *headNode=root;
   //make the previous(left) pointer of DLL node point to previous node
   root->left=*pre;

   //make the next(right) pointer of DLL point to next  element
	if(*pre!=NULL)
        (*pre)->right=root;
    *pre=root;

   //go to the right subtree
	BSTtoDLL(root->right,pre,headNode);

	return *headNode;
}



int main()
{
	 /* Create following tree as 1st balanced BST
           100
          /  \
        50    300
       / \
      20  70
    */
    Node *root1  = create(100);
    root1->left  = create(50);
    root1->right = create(300);
    root1->left->left = create(20);
    root1->left->right = create(70);

     Node*pre=NULL;
     Node *headNode=NULL;
    //then merge the two BSTs
    Node *head=BSTtoDLL(root1,&pre,&headNode);
    Display(head);
    return 0;
}
