//Deletes a key from BST
/* there can be three cases:
	1.when the key is a leaf node then it can be simply deleted
	2.when the key has a left or right child only.Then give the left/right child the position occupied by the key
	3.when both left and right nodes are present,then we replace the key with its inorder successor.the inorder successor
	 is the key with the lowest value in the right child of the key.
*/

#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
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

	//search for the appropriate position for the key
	//if the key is less than root ,go left
	//else go right
	if((*root)->data>key)
		insert(&((*root)->left),key);
	else
		insert(&((*root)->right),key);

}

//returns the lowest node of right child
Node* nextInorderNode(Node *root)
{
	if(root==NULL)
		return NULL;
	while(root->left!=NULL)
	{
		root=root->left;
	}
	return root;
}

//deletes a key from the BST
Node* deleteKey(Node *root,int key)
{
	if(root==NULL)
		return root;

	if(root->data==key)
	{
		//if no child
		if(root->right==NULL && root->left==NULL)
		{
		    delete root;
			return NULL;
		}
		//when there is only the right child
		else if(root->right && root->left==NULL)
		{
			Node *temp=root->right;
			delete root;
			return temp;
		}
		//when there is only the left child
		else if(root->left && root->right==NULL)
		{
			Node *temp=root->left;
			delete root;
			return temp;
		}
		//when there is both left and right child
		//inorder successor is to be found,which is the lowest node of right child
		else
		{
			//nextInorderNode returns the lowest node of right child
			Node *temp=nextInorderNode(root->right);
			//swap the value of nodes
			int swap=temp->data;
			temp->data=root->data;
			root->data=swap;

			root->right=deleteKey(root->right,temp->data);
		}
	}
	else if(root->data>key)
		root->left=deleteKey(root->left,key);
	else
		root->right=deleteKey(root->right,key);

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
          3		8
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

    if(deleteKey(root,8))
    	cout<<"Key Deleted !\n";
    else
    	cout<<"Key not Found and Deleted !\n";

	cout<<"Inorder Traversal:\n";
    inOrder(root);
	return 0;
}
