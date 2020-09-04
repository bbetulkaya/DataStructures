#include <iostream>
using namespace std;

struct node
{
    int value;
    node *left;
    node *right;
};

class Binary_Tree
{
private:
    node *root;
    void destroy_tree(node *leaf);
    void insert(int key, node *leaf);
    node *search(int key, node *leaf);
    void inorder_print(node *leaf);
    void postorder_print(node *leaf);
    void preorder_print(node *leaf);

public:
    Binary_Tree();
    ~Binary_Tree();

    void insert(int key);
    node *search(int key);
    void destroy_tree();
    void inorder_print();
    void postorder_print();
    void preorder_print();
};

Binary_Tree::Binary_Tree()
{
    root = NULL;
}
Binary_Tree::~Binary_Tree()
{
    destroy_tree();
}
// Ağacı silme
void Binary_Tree::destroy_tree(node *leaf)
{
    if (leaf != NULL)
    {
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete leaf;
    }
}
void Binary_Tree::destroy_tree()
{
    destroy_tree(root);
}
// Ağaca eleman ekleme
void Binary_Tree::insert(int key, node *leaf)
{
    if (key < leaf->value)
    {
        if (leaf->left != NULL)
        {
            insert(key, leaf->left);
        }
        else
        {
            leaf->left = new node;
            leaf->left->value = key;
            leaf->left->left = NULL;
            leaf->left->right = NULL;
        }
    }
    else if (key >= leaf->value)
    {
        if (leaf->right != NULL)
        {
            insert(key, leaf->right);
        }
        else
        {
            leaf->right = new node;
            leaf->right->value = key;
            leaf->right->right = NULL;
            leaf->right->left = NULL;
        }
    }
}
// Mainden ulaşılabilen ekleme fonksiyonu
void Binary_Tree::insert(int key)
{
    if (root != NULL)
    {
        insert(key, root);
    }
    else
    {
        root = new node;
        root->value = key;
        root->left = NULL;
        root->right = NULL;
    }
}
// Eleman arayan fonksiyon
node *Binary_Tree::search(int key, node *leaf)
{
    if (leaf != NULL)
    {
        if (key == leaf->value)
        {
            return leaf;
        }
        if (key < leaf->value)
        {
            return search(key, leaf->left);
        }
        else
        {
            return search(key, leaf->right);
        }
    }
    else
    {
        return NULL;
    }
}
node *Binary_Tree::search(int key)
{
    return search(key, root);
}

// INORDER EKRANA YAZMA
void Binary_Tree::inorder_print()
{
    inorder_print(root);
    cout << "\n";
}
void Binary_Tree::inorder_print(node *leaf)
{
    if (leaf != NULL)
    {
        inorder_print(leaf->left);
        cout << leaf->value << "-";
        inorder_print(leaf->right);
    }
}

// POSTORDER EKRANA YAZMA
void Binary_Tree::postorder_print()
{
    postorder_print(root);
    cout << "\n";
}
void Binary_Tree::postorder_print(node *leaf)
{
    if (leaf != NULL)
    {
        postorder_print(leaf->left);
        postorder_print(leaf->right);
        cout << leaf->value << "-";
    }
}
// PREORDER EKRANA YAZMA
void Binary_Tree::preorder_print()
{
    preorder_print(root);
    cout << "\n";
}
void Binary_Tree::preorder_print(node *leaf)
{
    if (leaf != NULL)
    {
        cout << leaf->value << "-";
        preorder_print(leaf->left);
        preorder_print(leaf->right);
    }
}

int main()
{
    Binary_Tree *btree = new Binary_Tree();

    btree->insert(12);
    btree->insert(2);
    btree->insert(5);
    btree->insert(32);
    btree->insert(20);

    btree->inorder_print();
    btree->postorder_print();
}