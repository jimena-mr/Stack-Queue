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


class Queue {
private:
    struct Node {
        TreeNode* data;
        Node* next;
        Node(TreeNode* value) : data(value), next(nullptr) {}
    };
    Node* front;
    Node* rear;
public:
    Queue() : front(nullptr), rear(nullptr) {}

    ~Queue() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(TreeNode* value) {
        Node* newNode = new Node(value);
        if (front == nullptr) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    TreeNode* pop() {
        if (front == nullptr) {
            return nullptr;
        }
        TreeNode* poppedData = front->data;
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        return poppedData;
    }

    bool isEmpty() {
        return front == nullptr;
    }
    void printQueue() const {
        Node* current = front;
        while (current != nullptr) {
            cout << current->data->val << " ";
            current = current->next;
        }
        cout << endl;
    }
};


int main() {
  // using Queue
  Queue queue;
  TreeNode* node1 = new TreeNode(1);
  TreeNode* node2 = new TreeNode(2);
  TreeNode* node3 = new TreeNode(3);
  TreeNode* node4 = new TreeNode(4);
  TreeNode* node5 = new TreeNode(5);

  queue.push(node1);
  queue.push(node2);
  queue.push(node3);
  queue.push(node4);
  queue.push(node5);

  cout << "Queue elements: "; queue.printQueue();
}