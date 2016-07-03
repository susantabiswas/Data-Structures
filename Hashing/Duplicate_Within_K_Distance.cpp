//Find whether there is a duplicate within 'k' distance in an array elements.'k' is less than the array size
/*traverse the array
for each element ,insert it in the hash table and check for the next 'k' elements if any of them lies in the
hash table or not*/

#include<iostream>
#include<cmath>
using namespace std;

struct Node
{
	Node *next;
	int data;
};

class Hash
{
private:
	//Hash table
	Node *h[10];
public:
	Hash()
	{
		for (int i = 0; i < 10; ++i)
			h[i]=NULL;
	}
	//for inserting the hash keys
	void insertHashVal(int data);
	//for searching the keys in the hash table
	bool search(int data);
	//for mapping the index for a dataing value ,required in hash table
	int hashFunction(int);
	//for inserting the keys in front of the linked list
	void push(int,int);
	//checks whether there exists any duplicates wihtin 'k' distance or not
	bool checkduplicate(int arr[],int n,int k);

};

void Hash::push(int in,int data)
{
	try{
		Node *node=new Node;
		node->data=data;
		node->next=NULL;

		if(h[in]==NULL)
		{
			h[in]=node;
		}
		else
		{
			node->next=h[in];
			h[in]=node;
		}

	}
	catch(bad_alloc xa)
	{
		cout<<"Out of memory!!";
		return;
	}

}

//hash function
int Hash::hashFunction(int data)
{
	return ((int)abs(data))%7;
}

//for insertion of keys
void Hash::insertHashVal(int data)
{
	int in=hashFunction(data);
	push(in,data);
}

bool Hash::search(int data)
{
	int in=hashFunction(data);
	Node *temp=h[in];
	//search for the key in the linked list
	while(temp!=NULL)
	{
		if(temp->data==data)
			{
				return true;
			}
		temp=temp->next;
	}
	return false;
}

//checks whether there exists any duplicates within 'k' distance or not
bool checkDuplicate(int arr[],int n,int k)
{
	Hash ob;
	//insert the hash keys
	for (int i = 0; i < n; ++i)
	{
		ob.insertHashVal(arr[i]);
		for (int j = 1; j <= k && i+j<n; ++j)
		{
			if(ob.search(arr[i+j]))
				return true;
		}

	}
	return false;
}

int main()
{
	int arr[] = {1, 2, 3, 4, 4};
	int k = 3;

	int n=sizeof(arr)/sizeof(int);

	if(checkDuplicate(arr,n,k))
		cout<<"Duplicate found !!\n ";
	else
		cout<<"Duplicate not found !\n";

	return 0;
}
