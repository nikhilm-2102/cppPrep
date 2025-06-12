#include <iostream>
#include <queue>

using namespace std;

struct Node
{
  int data;
  Node* left;
  Node* right;
  
  Node(int val)
  {
      data = val;
      left = right = nullptr;
  }
};

class BinaryTree
{
    int index;
    Node* rootNode;
    
    public:
    BinaryTree() : index(-1), rootNode(nullptr)
    {
    }
    
    Node* BuildTree(int* nodes, int size)
    {
        index++;
        if(nodes[index] == -1)
            return nullptr;
        
        Node* newNode = new Node(nodes[index]);
        newNode->left = BuildTree(nodes,size);
        newNode->right = BuildTree(nodes,size);
        rootNode = newNode;
        return newNode;
    }
    
    void InOrderTraversal(Node* node)
    {
        if(node == nullptr)
            return;
        
        InOrderTraversal(node->left);
        cout << node->data << " ";
        InOrderTraversal(node->right);
    }
    
    void PreOrderTraversal(Node* node)
    {
        if(node == nullptr)
            return;
            
        cout << node->data << " ";
        PreOrderTraversal(node->left);
        PreOrderTraversal(node->right);
    }
    
    void PostOrderTraversal(Node* node)
    {
        if(node == nullptr)
            return;
            
        PostOrderTraversal(node->left);
        PostOrderTraversal(node->right);
        cout << node->data << " ";
    }
    
    Node* GetRoot()
    {
        return rootNode;
    }
    
    void DeleteTree(Node* node)
    {
        if(node == nullptr)
            return;
        
        DeleteTree(node->left);
        DeleteTree(node->right);
        delete node;
    }
    
    void LevelOrderTraversal(Node* node)
    {
        if(node == nullptr)
            return;
        
        queue<Node*> NodesQueue;
        
        NodesQueue.push(node);
        NodesQueue.push(nullptr);
        while(!NodesQueue.empty())
        {
            Node* topNode = NodesQueue.front();
            if(topNode == nullptr)
            {
                cout << "\n";
                NodesQueue.pop();
                
                if(NodesQueue.empty())
                {
                    break;
                }
                else
                {
                    NodesQueue.push(nullptr);            
                }
            }
            else
            {
                cout << topNode->data << " ";
                NodesQueue.pop();
                if(topNode->left)
                    NodesQueue.push(topNode->left);
                if(topNode->right)
                    NodesQueue.push(topNode->right);
            }
        }
    }
    
    int GetNodesCount(Node* node)
    {
        if(node == nullptr)
            return 0;
            
        return GetNodesCount(node->left) + GetNodesCount(node->right) + 1; 
    }
    
    int GetHeight(Node* node)
    {
        int leftHeight = 0;
        int rightHeight = 0;
        if(node == nullptr)
            return 0;
            
        leftHeight = GetHeight(node->left);
        rightHeight = GetHeight(node->right);
        
        return max(leftHeight,rightHeight) + 1;
    }
    
    int sumOfNodes(Node* node)
    {
        if(node == nullptr)
            return 0;
        int leftSum = sumOfNodes(node->left);
        int rightSum = sumOfNodes(node->right);
        return  leftSum + rightSum + node->data;
    }
    
    ~BinaryTree()
    {
        DeleteTree(rootNode);
    }
};

int main() {
    int nodes[] = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1 };
    //      1
    //   2     3
    // 4   5     6
    BinaryTree tree;
    int size = sizeof(nodes) / sizeof(nodes[0]);
    Node* root = tree.BuildTree(nodes,size);
    cout << "In-order Traversal - ";
    tree.InOrderTraversal(root);
    cout << "\n";
    cout << "Pre-order Traversal - ";
    tree.PreOrderTraversal(root);
    cout << "\n";
    cout << "Post-order Traversal - ";
    tree.PostOrderTraversal(root);
    cout << "\n";
    cout << "Level-order Traversal - \n";
    tree.LevelOrderTraversal(root);
    
    cout << "height = " << tree.GetHeight(root) << endl;
    
    cout << "count = " << tree.GetNodesCount(root) << endl;
    
    cout << "Sum = " << tree.sumOfNodes(root) << endl;
    return 0;
}
