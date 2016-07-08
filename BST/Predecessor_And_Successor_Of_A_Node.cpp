//find the predecessor and successor of a given key node.
//If the key is not found then return the two values between which the key would have lied.
#include<iostream>
using namespace std;

//creates a node
struct Node
{
	int data;
	Node *left;
	Node *right;
};

//for returning two Node values in the the function
struct Pair
{
	Node *pre;
	Node *successor;
};

//creates a node
Node* createNode(int data)
{
	try
	{
		Node *node=new Node;
		node->data=data;
		node->left=NULL;
		node->right=NULL;

		return node;
	}
	catch(bad_alloc xa)
	{
		cout<<"Memory Full !\n";
		return NULL;
	}
}

//creates a BST
void insert(Node **root,int key)
{
	//when the BST is empty
	if(*root==NULL)
	{
		(*root)=createNode(key);
		return;
	}

	//when the key is already present
	if((*root)->data==key)
		return;

	//findPredecessorSuccessor for the appropriate position for the key
	//if the key is less than root ,go left
	//else go right
	if((*root)->data>key)
		insert(&((*root)->left),key);
	else
		insert(&((*root)->right),key);

}

//finds the maximum value of a tree
Node* maxVal(Node*root)
{
	if(root==NULL)
		return NULL;

	while(root->right)
	{
		root=root->right;
	}
	return root;
}


//finds the minimum value of a tree
Node* minVal(Node*root)
{
	if(root==NULL)
		return NULL;

	while(root->left)
	{
		root=root->left;
	}
	return root;
}

//returns the inorder successor and predecessor of a key.If key is not present return the two numbers between
//which the key lies.
/*Here successor and pre keeps track of the last left child and last right child required for finding the successor and predecessor for case 2*/
Pair findPredecessorSuccessor(Node *root,Pair pair,int key)
{
	 //when the tree is empty
	if(root==NULL )
		return pair;

	if(root->data==key)
	{
	    //inorder predecessor is the rightmost(maximum) node of the left subtree if left subtree exists
	    //else it is the last node whose right child is an ancestor of root
		if(root->left)
			pair.pre=maxVal(root->left);

		//inorder successor is the leftmost(minimum) node of the right subtree if the right subtree exists
		//else it is the last node whose left child is an ancestor of root
		if(root->right)
			pair.successor=minVal(root->right);

		return pair;
	}

	//go to left subtree when the key is smaller than the root data
	else if(root->data>key )
	{
		pair.successor=root;
		return findPredecessorSuccessor(root->left,pair,key);
	}

	//go to right subtree when the key is greater than the root data
	else if(root->data<key )
	{
		pair.pre=root;
		return findPredecessorSuccessor(root->right,pair,key);
	}

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

int main()
{
	/*
				5
           /   \
          3		 8
         / \   /  \
        2   4  6   9
	   /
	  1

	*/

	Node *root=createNode(5);
	insert(&root,3);
	insert(&root,8);
	insert(&root,2);
	insert(&root,4);
	insert(&root,1);
	insert(&root,6);
	insert(&root,9);

	cout<<"Inorder Traversal:\n";
    inOrder(root);
    cout<<endl;

    Pair pair;
    pair.pre=NULL;
    pair.successor=NULL;
    Pair result=findPredecessorSuccessor(root,pair,7);

	if(result.pre)
    cout<<"\n\nPredecessor:"<<(result.pre)->data;
	else
		cout<<"No predecessor\n";
	if(result.successor)
		cout<<" Successor:"<<(result.successor)->data<<endl;
	else
		cout<<"No predecessor\n";

	return 0;
}
