//Merge  two balanced BSTs into one BST with Tc:O(m+n),where m,n are sizes of the two balanced BSTs respectively.

/*Make the two BSTs into DLLs
  Then merge the two DLLs
  Make BST from the merged DLL
*/

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

//converts the DLL into BST
//n:Size of DLL
Node* convertToBST(Node *root,int n)
{
    //base case:When the root is NULL .'n' ==0 when we pass a leaf node that is why the size is 0.
	if(root==NULL || n<=0)
		return NULL;

	//find the mid element of the DLL
	else
	{
		int mid =n/2;
		Node *temp=root;

		//traverse till the middle element
		for (int i = 0; i < mid; ++i)
		{
			root=root->right;
		}
        //make the prev as left pointer and next as right pointer
        root->left=convertToBST(temp,mid);
        root->right=convertToBST(root->right,n-mid-1);

		return root;
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

//inorder traversal of BST
void inOrder(Node *root)
{
    if(root==NULL)
        return;

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

//converts a BST to a DLL
//n:stores the size of DLL
/*Do inorder traverasl and during it convert it into a BST.
store the previous node and at each root step make the root->left=previous and previous->next=root
*/
Node* BSTtoDLL(Node *root,int &n,Node **pre,Node **headNode)
{

	if(root==NULL)
		return NULL;

   //go to the left subtree
	BSTtoDLL(root->left,n,pre,headNode);

   ++n;
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
	BSTtoDLL(root->right,n,pre,headNode);

	return *headNode;
}

//Merges the two DLLs
//temp1 is for list 1
//temp2 is for list 2
Node* mergeDLL(Node **temp1,Node **temp2)								//Merge two Linked List
{
	if(*temp1==NULL)		//When list 1 is empty
		return *temp2;
	if(*temp2==NULL)		//When list 2 is empty
		return *temp1;
	if(*temp1==NULL && *temp2==NULL)	//When both the lists are empty
		return NULL;

	Node *result=NULL,*prevnode=NULL;

	//Head case:to decide the node to which the head pointer will point
	if((*temp1)->data>=(*temp2)->data)
	{
		result=*temp2;
		prevnode=*temp2;
		(*temp2)=(*temp2)->right;

	}
	else
	{
		result=*temp1;
		prevnode=*temp1;
		*temp1=(*temp1)->right;
	}

	//traverse the rest of the two lists
	while(*temp1!=NULL && *temp2!=NULL)
	{
		if((*temp1)->data>=(*temp2)->data)
		{
			prevnode->right=*temp2;
			(*temp2)->left=prevnode;
			prevnode=*temp2;
			*temp2=(*temp2)->right;
		}
		else
		{
			prevnode->right=*temp1;
			(*temp1)->left=prevnode;
			prevnode=*temp1;
			*temp1=(*temp1)->right;
		}
	}

	//if either of the two lists become empty

		//when list 1 is empty
		if(*temp1==NULL && *temp2!=NULL)
		{
			prevnode->right=*temp2;
			(*temp2)->left=prevnode;
			return result;
		}
		//when list 2 is empty
		if(*temp2==NULL && *temp1!=NULL)
		{
			prevnode->right=*temp1;
			(*temp1)->left=prevnode;
			return result;
		}
}

//Merges the two BST
Node* mergeBST(Node *root1,Node *root2)
{
   //for getting the size of two DLLs
   int n1=0;
   int n2=0;

   //pre:stores the last inorder node
	static Node *pre=NULL;

	//headNode:stores the first node of inOrder traversal,it is returned in the end as it is the head of DLL
   static  Node *headNode=NULL;

	//convert the first BST into a DLL
	Node *h1=BSTtoDLL(root1,n1,&pre,&headNode);

	pre=NULL;
	headNode=NULL;

	//convert the second BST into a DLL
	Node *h2=BSTtoDLL(root2,n2,&pre,&headNode);

   //merge the two DLLs
   Node *head=mergeDLL(&h1,&h2);

   //now convert this Merged DLL to BST
   return convertToBST(head,n1+n2);
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

    /* Create following tree as 2nd balanced BST
            80
           /  \
         40   120
    */
    Node *root2  = create(80);
    root2->left  = create(40);
    root2->right = create(120);

    //then merge the two BSTs
    Node *root=mergeBST(root1,root2);

    //inorder traversal of the merged BST
    inOrder(root);



	return 0;
}
