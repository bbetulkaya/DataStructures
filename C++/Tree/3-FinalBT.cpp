#include <iostream>
using namespace std;

class AGAC
{
public:
    char data;
    AGAC *left;
    AGAC *right;

    AGAC();
    AGAC(char v);
};
AGAC::AGAC()
{
    data = ' ';
    left = NULL;
    right = NULL;
}
AGAC::AGAC(char v)
{
    data = v;
    left = NULL;
    right = NULL;
}

class agac_l
{
private:
    AGAC *root;
    void ekle(char key, AGAC *leaf);
    void in_yaz(AGAC *leaf);
    void post_yaz(AGAC *leaf);

public:
    agac_l();
    bool bosmu();
    void ekle(char key);
    void in_yaz();
    void post_yaz();
};
agac_l::agac_l()
{
    root = NULL;
}
bool agac_l::bosmu()
{
    return root == NULL;
}
// ELEMAN EKLEME
void agac_l::ekle(char key)
{
    if (!bosmu())
    {

        ekle(key, root);
    }
    else
    {

        root = new AGAC(key);
        root->left = NULL;
        root->right = NULL;
    }
}
void agac_l::ekle(char key, AGAC *leaf)
{
    if (key < leaf->data)
    {
        if (leaf->left != NULL)
        {
            ekle(key, leaf->left);
        }
        else
        {
            leaf->left = new AGAC;
            leaf->left->data = key;
            leaf->left->left = NULL;
            leaf->left->right = NULL;
        }
    }
    else if (key >= leaf->data)
    {
        if (leaf->right != NULL)
        {
            ekle(key, leaf->right);
        }
        else
        {
            leaf->right = new AGAC;
            leaf->right->data = key;
            leaf->right->right = NULL;
            leaf->right->left = NULL;
        }
    }
}
// IN ORDER YAZMA
void agac_l::in_yaz()
{
    cout << "IN ORDER" << endl;
    in_yaz(root);
    cout << "\n";
}
void agac_l::in_yaz(AGAC *leaf)
{
    if (leaf != NULL)
    {
        in_yaz(leaf->left);
        cout << leaf->data << "-";
        in_yaz(leaf->right);
    }
}
// POST ORDER YAZMA
void agac_l::post_yaz()
{
    cout << "POST ORDER" << endl;
    post_yaz(root);
    cout << "\n";
}
void agac_l::post_yaz(AGAC *leaf)
{
    if (leaf != NULL)
    {
        post_yaz(leaf->left);
        post_yaz(leaf->right);
        cout << leaf->data << "-";
    }
}

int main()
{
    agac_l *agac = new agac_l();

    for (char ch = 'A'; ch <= 'Z'; ch++)
    {
        agac->ekle(ch);
    }

    agac->in_yaz();
    agac->post_yaz();
}