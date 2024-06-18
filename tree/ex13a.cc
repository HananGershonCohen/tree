#include <iostream>
using namespace std;

struct Tnode {
	int _val;
	Tnode* _lson, * _rson;
};
//===========================================================
void insertRec(Tnode*& root, int num)
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
		insertRec(root->_lson, num); // rec. call
	else
		insertRec(root->_rson, num); // rec. call
}
//===========================================================
Tnode* insert()
{
	Tnode* root = nullptr;
	int num;

	while (cin >> num)  // have to change condistion until "EOF"
		insertRec(root, num);

	return root;
}
//===========================================================
int count_nodes_with_equal_left_child(Tnode* root, int counter)
{
	// we use here with In-order;

	if (!root) // If there is no tree at all
		return counter;

	if (!root->_lson) // If we have reached the end of the tree
		return counter;

	if (root->_val == root->_lson->_val) // check condition
		counter++;

	counter = count_nodes_with_equal_left_child(root->_lson, counter);
	counter = count_nodes_with_equal_left_child(root->_rson, counter);

	return counter;
}
//===========================================================
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
//===========================================================
int main()
{
	Tnode* root = insert();
	cout << count_nodes_with_equal_left_child(root, 0); // check how much nodes equal to their left son ?
	free_tree(root);

	return 0;
}

