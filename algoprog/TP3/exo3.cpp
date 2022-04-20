#include "mainwindow.h"
#include "tp3.h"
#include <QApplication>
#include <time.h>
#include <stack>
#include <queue>

MainWindow* w = nullptr;
using std::size_t;

struct BinarySearchTree : public BinaryTree
{
    Node* left;
    Node* right;
    int value;

    void initNode(int value)
    {
        left=nullptr;
        right=nullptr;
        this->value = value;
        // init initial node without children
    }

	void insertNumber(int value) {
        // create a new node and insert it in right or left child
        if (value>this->value){
            if (this->right==nullptr){
                this->right= new BinarySearchTree(value);
            }
            else{
                this->right->insertNumber(value);
            }
        }
        else {
            if (this->left==nullptr){
                this->left= new BinarySearchTree(value);
            }
            else{
                this->left->insertNumber(value);
            }
        }
    }



	uint height() const	{
        // should return the maximum height between left child and
        // right child +1 for itself. If there is no child, return
        // just 1

        uint hleft = 0;
        uint hright = 0;
        if (this->left != nullptr){
            hleft = this->left->height();
        }
        if (this->right != nullptr){
            hright = this->right->height();
        }
        return(std::max(hleft, hright)+1);
}


	uint nodesCount() const {
        // should return the sum of nodes within left child and
        // right child +1 for itself. If there is no child, return
        // just 1

        uint nleft = 0;
        uint nright = 0;
        if (this->left != nullptr){
            nleft = this->left->nodesCount();
        }
        if (this->right != nullptr){
            nright = this->right->nodesCount();
        }
        return(nleft+nright+1);
}

	bool isLeaf() const {
        // return True if the node is a leaf (it has no children)
        if (this->left == nullptr){
            if (this->right == nullptr){
                return true;
            }
            else {
                return  false;
            }
        }
        else{
        return false;
            }
	}

	void allLeaves(Node* leaves[], uint& leavesCount) {
        // fill leaves array with all leaves of this tree
         if (isLeaf()){
            leaves[leavesCount] = this;
        }
        if (this->left != nullptr)
            this->left->allLeaves(leaves, leavesCount);
        if (this->right != nullptr)
            this->right->allLeaves(leaves, leavesCount);
    }

	void inorderTravel(Node* nodes[], uint& nodesCount) {
        // fill nodes array with all nodes with inorder travel
        if (this->left != nullptr)
            this->left->inorderTravel(nodes, nodesCount);
        nodes[nodesCount++] = this;
        if (this->right != nullptr)
            this->right->inorderTravel(nodes, nodesCount);
	}

	void preorderTravel(Node* nodes[], uint& nodesCount) {
        // fill nodes array with all nodes with preorder travel
        nodes[nodesCount++] = this;
        if (this->left != nullptr)
            this->left->preorderTravel(nodes, nodesCount);
        if (this->right != nullptr)
            this->right->preorderTravel(nodes, nodesCount);
	}

	void postorderTravel(Node* nodes[], uint& nodesCount) {
        // fill nodes array with all nodes with postorder travel
        if (this->left != nullptr)
            this->left->inorderTravel(nodes, nodesCount);
        if (this->right != nullptr)
            this->right->inorderTravel(nodes, nodesCount);
        nodes[nodesCount++] = this;
	}

	Node* find(int value) {
        // find the node containing value
        if (this->value == value)
            return this;
        if (this->left != nullptr)
            return this->left->find(value);
        if (this->right != nullptr)
            return this->right->find(value);
        return createNode(-1);
    }

    void reset()
    {
        if (left != NULL)
            delete left;
        if (right != NULL)
            delete right;
        left = right = NULL;
    }

    BinarySearchTree(int value) : BinaryTree(value) {initNode(value);}
    ~BinarySearchTree() {}
    int get_value() const {return value;}
    Node* get_left_child() const {return left;}
    Node* get_right_child() const {return right;}
};

Node* createNode(int value) {
    return new BinarySearchTree(value);
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 200;
    w = new BinarySearchTreeWindow<BinarySearchTree>();
	w->show();

	return a.exec();
}
