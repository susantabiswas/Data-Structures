//Convert a DLL to BST using in place conversion
/*Find the mid element of the DLL ,then recursively go to its previous nodes and next nodes doing
the same and make the previous as left and next as right pointers
*/
#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node *prev=NULL;
	Node *next=NULL;
};

class DoublyList
{
	public:
		//data member
		Node *head;

		//member methods
		DoublyList(){ head=NULL; }
		Node* create(int);
		void InsertBegin(int);
		void Display();
		void InsertEnd(int);
		void InsertAnyPosition(int,int);
		Node* convertToBST(Node*,int);
        void inOrder(Node*);
};

//creates the node for DLL
Node* DoublyList::create(int localData)
{
	try{
		Node *node=new Node;
		node->data=localData;
		node->prev=NULL;
		node->next=NULL;
		return node;
	}
	catch(bad_alloc xa)
	{
		cout<<"Can't Allocate Memory\n";
		return NULL;
	}
}

//For inserting the nodes in the end of DLL
void DoublyList:: InsertEnd(int dataItem)
{
	Node *node=create(dataItem);
	if(node!=NULL)
	{
		if(head==NULL)
		{
			head=node;
		}
		else
		{
			Node *temp=head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=node;
			node->prev=temp;

		}
	}
}

//converts the DLL into BST
//n:Size of DLL
Node* DoublyList::convertToBST(Node *root,int n)
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
			root=root->next;
		}
        //make the prev as left pointer and next as right pointer
        root->prev=convertToBST(temp,mid);
        root->next=convertToBST(root->next,n-mid-1);

		return root;
	}
}

//For Displaying the DLL
void DoublyList::Display()        //For displaying the nodes in the doubly linked DoublyList
{
    Node *temp=head;
    cout<<"\n\nContents of the DoublyList:\n";
    while(temp!=NULL)
    {
        cout<<temp->data<<"  ";
        temp=temp->next;
    }
    cout<<endl;

}

//inorder traversal of BST
void DoublyList::inOrder(Node *root)
{
    if(root==NULL)
        return;

    inOrder(root->prev);
    cout<<root->data<<" ";
    inOrder(root->next);
}
int main()
{
	DoublyList dll;
	//DLL creation
	for (int i = 1; i < 8; ++i)
		dll.InsertEnd(i);

	dll.Display();

	Node *root=dll.convertToBST(dll.head,7);
	//inorder traversal of BST
	dll.inOrder(root);
	return 0;
}
