#include <iostream>
#include <queue>
using namespace std;

// 二叉链表节点结构体
template <typename T>
struct BiTNode {
    T data;
    BiTNode<T> *lchild;
    BiTNode<T> *rchild;
    BiTNode(T x) : data(x), lchild(NULL), rchild(NULL) {}
};

// 二叉链表类
template <typename T>
class BiTree {
private:
    BiTNode<T> *root;

public:
    // 初始化二叉链表
    BiTree() { root = createBiTree(); }

    // 前序遍历二叉链表（递归实现）
    void preOrderTraverse() { preOrder(root); }

    // 中序遍历二叉链表（递归实现）
    void inOrderTraverse() { inOrder(root); }

    // 后序遍历二叉链表（递归实现）
    void postOrderTraverse() { postOrder(root); }

    // 层序遍历二叉链表
    void levelOrderTraverse() {
        if (root == NULL) return;
        queue<BiTNode<T> *> q;
        q.push(root);
        while (!q.empty()) {
            BiTNode<T> *node = q.front();
            q.pop();
            cout << node->data << " ";
            if (node->lchild!= NULL) q.push(node->lchild);
            if (node->rchild!= NULL) q.push(node->rchild);
        }
    }

    // 销毁二叉链表（递归实现）
    void destroyBiTree() { destroy(root); root = NULL; }

private:
    // 辅助函数，用于根据扩展二叉树的前序遍历序列创建二叉树
    BiTNode<T> *createBiTree() {
        T x;
        cin >> x;
        if (x == '#') return NULL;
        BiTNode<T> *node = new BiTNode<T>(x);
        node->lchild = createBiTree();
        node->rchild = createBiTree();
        return node;
    }

    // 前序遍历的递归辅助函数
    void preOrder(BiTNode<T> *node) {
        if (node == NULL) return;
        cout << node->data << " ";
        preOrder(node->lchild);
        preOrder(node->rchild);
    }

    // 中序遍历的递归辅助函数
    void inOrder(BiTNode<T> *node) {
        if (node == NULL) return;
        inOrder(node->lchild);
        cout << node->data << " ";
        inOrder(node->rchild);
    }

    // 后序遍历的递归辅助函数
    void postOrder(BiTNode<T> *node) {
        if (node == NULL) return;
        postOrder(node->lchild);
        postOrder(node->rchild);
        cout << node->data << " ";
    }

    // 销毁二叉树的递归辅助函数
    void destroy(BiTNode<T> *node) {
        if (node == NULL) return;
        destroy(node->lchild);
        destroy(node->rchild);
        delete node;
    }
};

int main() {
    // 创建一个二叉树实例
    BiTree<char> tree;

	 

    // 执行前序遍历并输出结果
    cout << "前序遍历结果: ";
    tree.preOrderTraverse();
    cout << endl;

    // 执行中序遍历并输出结果
    cout << "中序遍历结果: ";
    tree.inOrderTraverse();
    cout << endl;

    // 执行后序遍历并输出结果
    cout << "后序遍历结果: ";
    tree.postOrderTraverse();
    cout << endl;

    // 执行层序遍历并输出结果
    cout << "层序遍历结果: ";
    tree.levelOrderTraverse();
    cout << endl;

    // 销毁二叉树
    tree.destroyBiTree();
    cout << "销毁后" << endl;

    return 0;
}
