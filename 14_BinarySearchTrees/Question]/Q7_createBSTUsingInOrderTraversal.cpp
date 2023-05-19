#include<iostream>
#include<queue>
using namespace std;
class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data) {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* buildTree() {
    int data;

    cin >> data;
    if (data == -1) {
        return NULL;
    }

    Node* root = new Node(data);
    cout << "\nEnter Data for the left part of " << data << " node: ";
    root->left = buildTree();

    cout << "\nEnter Data for the right part of " << data << " node: ";
    root->right = buildTree();

    return root;
}

Node*BSTUsingInOrder(int InOrder[] , int s ,int e){
    // base case 
    if(s>e){
        return NULL;
    }

    int mid  =(s+e)/2;
    int element = InOrder[mid];
    Node*root = new Node(element);

    root->left  = BSTUsingInOrder(InOrder ,s , mid-1);
    root->right  = BSTUsingInOrder(InOrder,mid+1 , e);
    
    return root;
}
void levelOrderTravaersalWithEndl(Node*root){
    queue<Node*>q;
    q.push(root);
        q.push(NULL);

    while(!q.empty()){
        //1
        Node*temp = q.front();
        //2
        q.pop();
        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
            
        }
        else{
        //3
        cout<<temp->data<<" ";
        //if  left node is present innclude it
        if(temp->left){
            q.push(temp->left);

        }
        //if right nodde is present include it
        if(temp->right){
            q.push(temp->right);
        }
        }
    }
}
int main(){
    int inOder[] = {10,20,30,40,50,60,70,80,90};
    // int inOder[] = {1,2,3,4,5,6,7,8};
    int s =0;
    int e = 8;
    Node*root = BSTUsingInOrder(inOder, s ,e);
    levelOrderTravaersalWithEndl(root);   
return 0;
}