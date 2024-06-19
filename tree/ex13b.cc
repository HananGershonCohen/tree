#include <iostream>
using namespace std;
//******
//STRUCT
//******

struct Input
{
    int in_id;
    int in_x;
    int in_y;
};

struct Point {
    int x;
    int y;
};

struct Node {
    int _id;
    Point* _data;
    Node* _left;
    Node* _right;
};
//===================================================================
void insert_data(Node*& root, Input user)
{
    root->_id = user.in_id;
    root->_data = new Point(); // הקצאת זיכרון עבור ה-Point
    root->_data->x = user.in_x;
    root->_data->y = user.in_y;
    root->_left = root->_right = nullptr;
}
//===================================================================
void insertRec(Node*& root, Input user) {
    if (!root) {
        root = new Node();
        insert_data(root, user); // func. for insert data into tree.(not rec.)
        return;
    }

    if (user.in_id <= root->_id) {
        insertRec(root->_left, user);
    }
    else {
        insertRec(root->_right, user);
    }
}
//===================================================================
Node* insert() {
    Input user;
    Node* root = nullptr;

    // condition: while input 3 varible and not EOF.
    while (cin >> user.in_id >> user.in_x >> user.in_y) {  // Use EOF for input termination
        insertRec(root, user);
    }

    return root;
}
//===================================================================
void print_data(Node* root)
{
    cout << root->_id << ' ';
    cout << root->_data->x << ' ';
    cout << root->_data->y << ' ';
}
//===================================================================
void print_InOrder(Node* root) {
    if (root) {
        print_InOrder(root->_left);
        print_data(root); // func. for print the data.
        print_InOrder(root->_right);
    }
}
//===================================================================
int main()
{
    Node* root = insert();
    print_InOrder(root);

    return 0;
}
