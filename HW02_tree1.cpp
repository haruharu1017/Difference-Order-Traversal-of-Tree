#include <iostream>
#include <queue>
using namespace std;

template <class Item>
class binaryTreeNode
{
    public:
    Item dataField;
    binaryTreeNode *leftField;
    binaryTreeNode *rightField;
    binaryTreeNode(const Item& item): dataField(item),leftField(nullptr),rightField(nullptr){}
};

template <class Item>
void insert(binaryTreeNode<Item> *& root, const Item& val)
{
    if(root==nullptr) {
        root=new binaryTreeNode<Item>(val);
        return;
    }
    
    queue<binaryTreeNode<Item>*> nodeQueue;
    nodeQueue.push(root);
    while(!nodeQueue.empty())
    {
        binaryTreeNode<Item>* current=nodeQueue.front();
        nodeQueue.pop();

        if(current->leftField==nullptr) {
            current->leftField=new binaryTreeNode<Item>(val);
            return;
        }else{
            nodeQueue.push(current->leftField);
        }

        if(current->rightField==nullptr) {
            current->rightField=new binaryTreeNode<Item>(val);
            return;
        }else{
            nodeQueue.push(current->rightField);
        }
    }
}

template <class Item>
void preOrderTraversal(binaryTreeNode<Item>* root)
{
    if (root==nullptr) return;
    cout<<root->dataField<<" ";
    preOrderTraversal(root->leftField);
    preOrderTraversal(root->rightField);
}

template <class Item>
void postOrderTraversal(binaryTreeNode<Item>* root)
{
    if(root==nullptr) return;
    postOrderTraversal(root->leftField);
    postOrderTraversal(root->rightField);
    cout<<root->dataField<<" ";
}

template <class Item>
void inOrderTraversal(binaryTreeNode<Item>* root)
{
    if(root==nullptr) return;
    inOrderTraversal(root->leftField);
    cout<<root->dataField<<" ";
    inOrderTraversal(root->rightField);
    
}

int main(){
    binaryTreeNode<char> *root=nullptr;
    insert(root, 'A');
    insert(root, 'L');
    insert(root, 'G');
    insert(root, 'O');
    insert(root, 'R');
    insert(root, 'I');
    insert(root, 'T');
    insert(root, 'H');
    insert(root, 'M');
    insert(root, 'S');
    postOrderTraversal(root);
    cout<<endl;
    preOrderTraversal(root);
    cout<<endl;
    inOrderTraversal(root);
}