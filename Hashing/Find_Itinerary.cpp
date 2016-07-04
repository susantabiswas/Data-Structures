//Find Itinerary(recorded route) from a given list of tickets
/*Given a list of tickets, find itinerary in order using the given list.

Example:

Input:
"Chambal" -> "Banglore"
"Kolkata" -> "Delhi"
"Gwalior" -> "Chambal"
"Delhi"  -> "Gwalior"

Output:
Kolkata->Delhi, Delhi->Gwalior, Gwalior->Chambal, Chambal->Banglore,*/
/////////////////////////////////////////////////////////////////////////
/*-Add all the routes in a hash table
-Find the starting point of journey:
	starting point is that key which doesn't exist as a value in any key-value pair.
	create a reverse hash table in which each key value is the reverese of the key value pair given in the
	input
-then just start from that and using its value as the next key,keep on going till we dont't
get any more key from value
*/

#include<iostream>
using namespace std;

struct Node
{
	Node *next;
	string key,value;
};

class Hash
{
private:
	//Hash table
	Node *h[10];
	//Reverse Hash Table
	Node *rh[10];
public:
	Hash()
	{
		for (int i = 0; i < 10; ++i)
			h[i]=NULL;
		for (int i = 0; i < 10; ++i)
			rh[i]=NULL;
	}
	//for inserting the hash keys
	void insertHashVal(string,string);
	//for searching the keys in the hash table by their value
	bool search(string,Node**);
	//for mapping the index for a key value ,required in hash table
	int hashFunction(string);
	//for inserting the keys in front of the linked list
	void push(string,string,Node**);
	//finds the Itinerary from the key value pairs
	void findRoute();
	//returns the value using its corresponding key
	string value(string key);

};

void Hash::push(string key,string value,Node **head)
{
	try{
		Node *node=new Node;
		node->key=key;
		node->value=value;
		node->next=NULL;

		if(*head==NULL)
		{
			*head=node;
		}
		else
		{
			node->next=*head;
			*head=node;
		}

	}
	catch(bad_alloc xa)
	{
		cout<<"Out of memory!!";
		return;
	}

}

//hash function
int Hash::hashFunction(string key)
{
	return key.length()%7;
}

//for insertion of keys
void Hash::insertHashVal(string key,string value)
{
	int in=hashFunction(key);
	push(key,value,&h[in]);

	in=hashFunction(value);
	push(value,key,&rh[in]);
}

//searches the key value pair
bool Hash::search(string key,Node **head)
{
	Node *temp=*head;
	//search for the key in the linked list
	while(temp!=NULL)
	{
		if(temp->key==key)
			{
				return true;
			}
		temp=temp->next;
	}
	return false;
}

//returns the value of a key from the hash table
string Hash::value(string key)
{
	int in=hashFunction(key);
	Node *temp=h[in];
	while(temp!=NULL)
	{
		if(temp->key==key)
			return temp->value;
		temp=temp->next;
	}
	return " ";
}

//finds the Itinerary from the key value pairs
void Hash::findRoute()
{
	Node *temp=NULL;
	string start;
	int in,f=0;
	//first find the starting point of journey
	//starting point is that key which doesn't exist as a value in any key-value pair
	/*So the starting point is that key which doesn't exist in the reverse hash table 'rh' as a key*/
	for (int i = 0; i < 10; ++i)
	{
		if(h[i]!=NULL)
		{
			temp=h[i];
			while(temp!=NULL)
			{
				in=hashFunction(temp->key);
				if(!search(temp->key,&rh[in]))
					{
						start=temp->key;
						f=1;
						break;
					}
				temp=temp->next;
			}
			if(f==1)
				break;
		}
	}

//now print the travel route
	while(1)
	{
		cout<<start<<"->"<<value(start)<<"\n";
		start=value(start);
		if(value(start)==" ")
			return;
	}

}


int main()
{
	Hash ob;
	//create the hash table
	ob.insertHashVal("Chambal","Banglore");
	ob.insertHashVal("Kolkata","Delhi");
	ob.insertHashVal("Gwalior","Chambal");
	ob.insertHashVal("Delhi","Gwalior");

	ob.findRoute();
	return 0;
}

