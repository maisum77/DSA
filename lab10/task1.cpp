#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int id, h;
    Node *L, *R;
    Node(int v) { id = v; h = 1; L = R = NULL; }
};

class AVL {
    int getH(Node* n) { return n ? n->h : 0; }
    int getBal(Node* n) { return n ? getH(n->L) - getH(n->R) : 0; }

    Node* rotateR(Node* y) {
        Node* x = y->L; Node* T2 = x->R;
        x->R = y; y->L = T2;
        y->h = max(getH(y->L), getH(y->R)) + 1;
        x->h = max(getH(x->L), getH(x->R)) + 1;
        return x;
    }

    Node* rotateL(Node* x) {
        Node* y = x->R; Node* T2 = y->L;
        y->L = x; x->R = T2;
        x->h = max(getH(x->L), getH(x->R)) + 1;
        y->h = max(getH(y->L), getH(y->R)) + 1;
        return y;
    }

    Node* insert(Node* node, int id) {
        if (!node) return new Node(id);
        if (id < node->id) node->L = insert(node->L, id);
        else if (id > node->id) node->R = insert(node->R, id);
        else return node;

        node->h = 1 + max(getH(node->L), getH(node->R));
        int b = getBal(node);

        if (b > 1 && id < node->L->id) return rotateR(node);
        if (b < -1 && id > node->R->id) return rotateL(node);
        if (b > 1 && id > node->L->id) { node->L = rotateL(node->L); return rotateR(node); }
        if (b < -1 && id < node->R->id) { node->R = rotateR(node->R); return rotateL(node); }
        return node;
    }

public:
    Node* root = NULL;
    void add(int id) { root = insert(root, id); }
    void show(Node* r) { if(r) { show(r->L); cout << r->id << " "; show(r->R); } }
};
int main()
{
AVL stockTree;
    stockTree.add(50); 
    stockTree.add(30); 
    stockTree.add(70); 
    stockTree.add(20);
    cout << "In-order (Balanced): "; stockTree.show(stockTree.root); cout << "\n\n";
}