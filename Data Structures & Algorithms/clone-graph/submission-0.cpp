/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
   public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) {
            return nullptr;
        }
        unordered_map<Node* , Node*>mpp;
        queue<Node*>q;
        Node*root= new Node(node->val);
        mpp[node]=  root;
        q.push(node);
        while(!q.empty())
        {
            Node*curr=  q.front();
            q.pop();
            for(Node*neigh  :curr-> neighbors)
            {
                if(!mpp.count(neigh)){
                    mpp[neigh]=  new Node(neigh ->val);
                    q.push(neigh);
                }

                mpp[curr]->neighbors.push_back(mpp[neigh]);
            }
        }
        return root;
    }
};
