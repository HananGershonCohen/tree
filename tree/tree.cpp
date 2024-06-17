#include <iostream>
using namespace std;

struct Tnode {
	int _val;
	Tnode* _lson, * _rson;
};

void insert_rec(Tnode*& root, int num)
{
	if (!root) // create new member and insert into tree
	{
		Tnode* newTnode = new Tnode(); 
		newTnode->_val = num;
		newTnode->_lson = newTnode->_rson = nullptr;
		root = newTnode;
		return;
	}

	if (num <= root->_val)  
		insert_rec(root->_lson, num); // rec. call
	else	
		insert_rec(root->_rson, num); // rec. call
}

void insert(Tnode* &root)
{
	int num;
	cout << "Enter number:\n";
	cin >> num;

	while (num)
	{
		insert_rec(root, num);
		cout << "Enter number:\n";
		cin >> num;
	}
}

void print_InOrder(Tnode* root)
{ 
	// print LTR
	if (root)
	{
		print_InOrder(root->_lson);
		cout << root->_val << ' ';
		print_InOrder(root->_rson);
	}
}

void print_InOrder_reverse(Tnode* root)
{
	// print RTL
	if (root)
	{
		print_InOrder_reverse(root->_rson);
		cout << root->_val << ' ';	
		print_InOrder_reverse(root->_lson);
	}
}

void free_tree(Tnode*& root)
{
	if (root)
	{
		free_tree(root->_lson);
		free_tree(root->_rson);
		delete root;
		root = nullptr;
	}
}

int main()
{
	Tnode* root = nullptr;
	insert(root);

	print_InOrder(root); 
	cout << endl;

	print_InOrder_reverse(root);
	cout << endl;

	free_tree(root);
	return 0;
}
