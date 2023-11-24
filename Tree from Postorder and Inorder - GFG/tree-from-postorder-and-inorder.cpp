//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
    int findPos(int in[], int num, int st, int ed){
        for(int i=st;i<=ed;i++)
            if(in[i]==num)
                return i;
        return -1;
    }
    
    Node* solve(int in[], int post[], int inSt, int inEd, int& index){
        
        if(index < 0 ||  inSt > inEd){
            return NULL;
        }
        
        Node* root = new Node(post[index]);
        int pos = findPos(in,post[index--],inSt,inEd);
        root->right = solve(in,post,pos+1,inEd,index);
        root->left = solve(in,post,inSt,pos-1,index);
        return root;
    }

Node *buildTree(int in[], int post[], int n) {
    int index =n-1;
    return solve(in, post,0,n-1,index);
}
