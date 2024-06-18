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

void print_preOrder(Tnode* root)
{
	if (root)
	{
		cout << root->_val << ' ';
		print_preOrder(root->_lson);
		print_preOrder(root->_rson);
	}
}

void print_postOrderpr(Tnode* root)
{
	if (root)
	{
		print_postOrderpr(root->_lson);
		print_postOrderpr(root->_rson);
		cout << root->_val << ' ';
	}
}

int sum_tree(Tnode* root)
{
	if (!root)
		return 0;

	return sum_tree(root->_lson) + root->_val + sum_tree(root->_rson);
}

void free_tree(Tnode*& root)
{
	if (root)
	{
		free_tree(root->_lson);
		free_tree(root->_rson);
		delete root;
	}
}

int main()
{
	Tnode* root = nullptr;
	insert(root);

	cout << "print_InOrder" << endl;
	print_InOrder(root); 
	cout << endl;

	cout << "print_InOrder_reverse" << endl;
	print_InOrder_reverse(root);
	cout << endl;

	cout << "print_preOrder" << endl;
	print_preOrder(root);
	cout << endl;

	cout << "print_postOrder" << endl;
	print_postOrderpr(root);
	cout << endl;

	cout << "sum_tree" << endl;
	cout << sum_tree(root);
	cout << endl;

	free_tree(root);
	return 0;
}
