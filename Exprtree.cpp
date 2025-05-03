#include<iostream>
#include<string>
#include<stack>
#include<cctype>
using namespace std;

class Node {
public:
    string data;
    Node *left, *right;

    Node(char x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Tree {
    stack<Node*> s;
    Node* root = NULL;

public:
    void exprTree(string prefix_expr) {
        for (int i = prefix_expr.size() - 1; i >= 0; i--) {
            if (isalpha(prefix_expr[i])) {
                s.push(new Node(prefix_expr[i]));
            } else {
                Node* top = new Node(prefix_expr[i]);
                top->left = s.top(); s.pop();
                top->right = s.top(); s.pop();
                s.push(top);
            }
        }
        root = s.top();
        cout << "Expression tree built" << endl;
    }

    void postorder() {
        if (!root) return;
        stack<Node*> s1, s2;
        s1.push(root);
        while (!s1.empty()) {
            Node* node = s1.top(); s1.pop();
            s2.push(node);
            if (node->left) s1.push(node->left);
            if (node->right) s1.push(node->right);
        }
        cout << "Postorder traversal:" << endl;
        while (!s2.empty()) {
            cout << s2.top()->data << "   ";
            s2.pop();
        }
        cout << endl;
    }

    void preorder() {
        preorder_traversal(root);
    }

    void preorder_traversal(Node* node) {
        if (node == NULL)
            return;
        cout << node->data << "   ";
        preorder_traversal(node->left);
        preorder_traversal(node->right);
    }
};

int main() {
    Tree t;
    t.exprTree("+--a*bc/def");
    cout << "Preorder traversal :" << endl;
    t.preorder();
    cout << endl;
    t.postorder();
    return 0;
}
