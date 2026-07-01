class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {

            Node* rightNode = nullptr;

            int sz = q.size();

            while (sz--) {

                Node* cur = q.front();
                q.pop();

                cur->next = rightNode;
                rightNode = cur;

                if (cur->right) {
                    q.push(cur->right);
                    q.push(cur->left);
                }
            }
        }

        return root;
    }
};