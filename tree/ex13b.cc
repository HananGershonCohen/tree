#include <iostream>
using namespace std;

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


int main()
{
    Node* root = insert();

    return 0;
}
