#include <iostream>
#include <queue>
using namespace std;

// ��������ڵ�ṹ��
template <typename T>
struct BiTNode {
    T data;
    BiTNode<T> *lchild;
    BiTNode<T> *rchild;
    BiTNode(T x) : data(x), lchild(NULL), rchild(NULL) {}
};

// ����������
template <typename T>
class BiTree {
private:
    BiTNode<T> *root;

public:
    // ��ʼ����������
    BiTree() { root = createBiTree(); }

    // ǰ��������������ݹ�ʵ�֣�
    void preOrderTraverse() { preOrder(root); }

    // ����������������ݹ�ʵ�֣�
    void inOrderTraverse() { inOrder(root); }

    // ����������������ݹ�ʵ�֣�
    void postOrderTraverse() { postOrder(root); }

    // ���������������
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

    // ���ٶ��������ݹ�ʵ�֣�
    void destroyBiTree() { destroy(root); root = NULL; }

private:
    // �������������ڸ�����չ��������ǰ��������д���������
    BiTNode<T> *createBiTree() {
        T x;
        cin >> x;
        if (x == '#') return NULL;
        BiTNode<T> *node = new BiTNode<T>(x);
        node->lchild = createBiTree();
        node->rchild = createBiTree();
        return node;
    }

    // ǰ������ĵݹ鸨������
    void preOrder(BiTNode<T> *node) {
        if (node == NULL) return;
        cout << node->data << " ";
        preOrder(node->lchild);
        preOrder(node->rchild);
    }

    // ��������ĵݹ鸨������
    void inOrder(BiTNode<T> *node) {
        if (node == NULL) return;
        inOrder(node->lchild);
        cout << node->data << " ";
        inOrder(node->rchild);
    }

    // ��������ĵݹ鸨������
    void postOrder(BiTNode<T> *node) {
        if (node == NULL) return;
        postOrder(node->lchild);
        postOrder(node->rchild);
        cout << node->data << " ";
    }

    // ���ٶ������ĵݹ鸨������
    void destroy(BiTNode<T> *node) {
        if (node == NULL) return;
        destroy(node->lchild);
        destroy(node->rchild);
        delete node;
    }
};

int main() {
    // ����һ��������ʵ��
    BiTree<char> tree;

	 

    // ִ��ǰ�������������
    cout << "ǰ��������: ";
    tree.preOrderTraverse();
    cout << endl;

    // ִ�����������������
    cout << "����������: ";
    tree.inOrderTraverse();
    cout << endl;

    // ִ�к��������������
    cout << "����������: ";
    tree.postOrderTraverse();
    cout << endl;

    // ִ�в��������������
    cout << "����������: ";
    tree.levelOrderTraverse();
    cout << endl;

    // ���ٶ�����
    tree.destroyBiTree();
    cout << "���ٺ�" << endl;

    return 0;
}
