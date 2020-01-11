// Convert a Binary Search Tree to a sorted Circular Doubly-Linked List in place.

// You can think of the left and right pointers as synonymous to the predecessor and successor pointers in a doubly-linked list. For a circular doubly linked list, the predecessor of the first element is the last element, and the successor of the last element is the first element.

// We want to do the transformation in place. After the transformation, the left pointer of the tree node should point to its predecessor, and the right pointer should point to its successor. You should return the pointer to the smallest element of the linked list.

 

// Example 1:



// Input: root = [4,2,5,1,3]


// Output: [1,2,3,4,5]

// Explanation: The figure below shows the transformed BST. The solid line indicates the successor relationship, while the dashed line means the predecessor relationship.


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (!root) return NULL;
        
        auto i = dfs(root);
        i[0]->left = i[1];
        i[1]->right = i[0];
        return i[0];
    }

private:
    vector<Node*> dfs(Node* node) {
        vector<Node*> nn, ll;
        Node *n;
        
        if (node->left) {
            nn = dfs(node->left);
            n = nn[1];
            n->right = node;
            node->left = n;
        }
        
        if (node->right) {
            ll = dfs(node->right);
            n = ll[0];
            node->right = n;
            n->left = node;
        }
        
        return {!nn.empty() ? nn[0] : node, !ll.empty() ? ll[1] : node};
    }
};