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
void check_evenOrOdd(Node* root, int &even_count, int &odd_count)
{
    if (root->_data % 2 == 0)
        even_count++;
    else
        odd_count++;
}
//===================================================================
void node_corrent_rec2(Node* root, int& even_count, int& odd_count)
{
    if (!root)
        return;

    node_corrent_rec2(root->_left, even_count, odd_count);
    node_corrent_rec2(root->_right, even_count, odd_count);

    check_evenOrOdd(root, even_count, odd_count);

}
//===================================================================
void even_values_​greater_odd_values_rec1(Node* root, Node*& under_root,int size_under_root)
{
    if (!root) // if there is no tree
        return ;

    even_values_​greater_odd_values_rec1(root->_left, under_root, size_under_root);
    even_values_​greater_odd_values_rec1(root->_right, under_root, size_under_root);

    int even_count = 0, odd_count = 0; // local variables
    node_corrent_rec2(root, even_count, odd_count);
    // if this local node is right, update value. AND  if this max Node, update value.
    if (even_count > odd_count && even_count > size_under_root)
    {
        under_root = root;
        size_under_root = even_count;
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
 
    Node* under_root = nullptr;
    even_values_​greater_odd_values_rec1(root, under_root, 0);
    print_result(under_root);

   free_tree(root);

    return 0;
}
