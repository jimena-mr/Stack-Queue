#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Stack {
private:
    struct Node {
        TreeNode* data;
        Node* next;
        Node(TreeNode* value) : data(value), next(nullptr) {}
    };
    Node* top;
public:
    Stack() : top(nullptr) {}

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(TreeNode* value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    TreeNode* pop() {
        if (top == nullptr) {
            return nullptr;
        }
        TreeNode* poppedData = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return poppedData;
    }

    bool isEmpty() {
        return top == nullptr;
    }
    void printStack() const {
        Node* current = top;
        while (current != nullptr) {
            cout << current->data->val << " ";
            current = current->next;
        }
        cout << endl;
    }
};



int main() {

  // Stack
  Stack stack;
  TreeNode* node4 = new TreeNode(4);
  TreeNode* node5 = new TreeNode(5);
  TreeNode* node6 = new TreeNode(6);
  TreeNode* node7 = new TreeNode(7);
  TreeNode* node8 = new TreeNode(8);

  stack.push(node4);
  stack.push(node5);
  stack.push(node6);
  stack.push(node7);
  stack.push(node8);
  
  cout << "Stack elements:"; stack.printStack();
  
    return 0;
}
