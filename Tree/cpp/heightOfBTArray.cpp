#include "header.h"

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node *constructTreeFromArray(int a[], int n)
{
    struct Node *nodes[n];
    struct Node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        nodes[i] = newNode(i);
        if (a[i] == -1)
        {
            root = nodes[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] != -1)
        {
            if (nodes[a[i]]->left == NULL)
            {
                nodes[a[i]]->left = nodes[i];
            }
            else
            {
                nodes[a[i]]->right = nodes[i];
            }
        }
    }
    return root;
}
void inorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data;
    inorder(root->left);
    inorder(root->right);
}

int heightOfTree(struct Node *root)
{
    if (root == NULL)
        return 0;
    int left = heightOfTree(root->left);
    int right = heightOfTree(root->right);
    return 1 + max(left, right);
}


void depthUtil(int p[],int i,int *depth){
    if (depth[i]){
        return;
    }
    if(p[i]==-1){
        depth[i] = 1;
        return;
    }
    if(depth[p[i]]==0){
        depthUtil(p, p[i], depth);
    }
    depth[i] = depth[p[i]] + 1;
}

int height(int p[],int n){
    int depth[n];
    for (int i = 0; i < n;i++){
        depth[i] = 0;
    }
    for (int i = 0; i < n;i++){
        depthUtil(p, i, depth);
    }
    int m = depth[0];
    for (int i = 1; i < n; i++)
        if (m < depth[i])
            m = depth[i];
    return m;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    int p[n];
    REP(i, n)
    {
        cin >> p[i];
    }
    cout << height(p, n);
    return 0;
}