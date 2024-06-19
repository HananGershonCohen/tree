#include <iostream>
using namespace std;

struct Node {
    int _data;
    Node* _left;
    Node* _right;
};
//===================================================================
void insert(Node*& root, int num) {
    if (!root) {
        root = new Node();
        root->_data = num;
        root->_left = root->_right = nullptr;
        return;
    }

    if (num <= root->_data) {
        insert(root->_left, num);
    }
    else {
        insert(root->_right, num);
    }
}
//===================================================================
Node* insert() {
    Node* root = nullptr;
    int num;

    while (cin >> num && num != EOF) {  // Use EOF for input termination
        insert(root, num);
    }

    return root;
}
//===================================================================
void printInOrder(Node* root) {
    if (root) {
        printInOrder(root->_left);
        cout << root->_data << " ";
        printInOrder(root->_right);
    }
}
//===================================================================
void check_evevOrOdd(Node* root, int &even_count, int &odd_count)
{
    if (root->_data % 2 == 0)
        even_count++;
    else
        odd_count++;
}
//===================================================================
void even_values_​greater_odd_values(Node* root, Node*& under_root,int size_under_root)
{
    Node* max_Node_temp = nullptr;
    int  size_max_Node_temp = 0;

    if (!root) // if there is no tree
        return ;

    even_values_​greater_odd_values(root->_left, under_root, size_under_root);
    even_values_​greater_odd_values(root->_right, under_root, size_under_root);

    int even_count = 0, odd_count = 0; // local variables
    check_evevOrOdd(root,even_count,odd_count);
    if (root->_left)
        check_evevOrOdd(root->_left, even_count, odd_count);
    if (root->_right)
        check_evevOrOdd(root->_right, even_count, odd_count);

    if (even_count > odd_count) // if this local node is right, update value.
    {
        max_Node_temp = root;
        size_max_Node_temp = even_count;
    }

    if (even_count != odd_count)
    if (size_max_Node_temp > size_under_root) // if this max Node, update value.
    {
        under_root = max_Node_temp;
        size_under_root = size_max_Node_temp;
    }
}
//===================================================================
void free_tree(Node*& root)
{
    if (root)
    {
        free_tree(root->_left);
        free_tree(root->_right);
        delete root;
    }
}
//===================================================================
void print_result(Node* under_root)
{
    if (!under_root)
        cout << "NOT FOUND";
    else
        cout << under_root->_data;
}
//===================================================================
int main() 
{
    Node* root = insert();
    printInOrder(root);
    cout << endl;

    Node* under_root = nullptr;
    even_values_​greater_odd_values(root, under_root, 0);
    print_result(under_root);

   free_tree(root);

    return 0;
}
