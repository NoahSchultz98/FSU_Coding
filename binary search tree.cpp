#include <iostream>

using namespace std;
/*
class node{
   public:
   int data;
   node* left;
   node* right;
   
   node(){data = 0, left = nullptr, right = nullptr}
   node(int i){data = i;, left = nullptr, right = nullptr}
   insert(node head, int i)
   {
   
   }

};
*/

struct node {
   int data;
   node* left;
   node* right;
};

void printNodes(node* root);
void insert(node* root, int data);
void find_min(node* root);
void find_max(node* root);

int main()
{
   node* root;
   node* temp;
   
   temp = new node;
   temp->data = 33;
   temp->left = nullptr;
   temp->right = nullptr; 
   
   root = temp;
   /*
   temp = new node;
   temp->data = 20;
   temp->left = nullptr;
   temp->right = nullptr; 
   
   root->left = temp;
   
   temp = new node;
   temp->data = 50;
   temp->left = nullptr;
   temp->right = nullptr; 
   
   root->right = temp;
   */
   insert(root, 20);
   insert(root, 25);
   insert(root, 50);
   
   printNodes(root);
   
   return 0;
}

void find_max(node* root)
{
   if(root->right != nullptr){
      find_min(root->right);
      return;
   }
   cout << root->data << endl;
}

void find_min(node* root)
{
   if(root->left != nullptr){
      find_min(root->left);
      return;
   }
   cout << root->data << endl;
}

void printNodes(node* root){

   if(root->right != nullptr)
      printNodes(root->right);
      
   if(root->left != nullptr)
      printNodes(root->left);
      
   cout << root->data << endl;
   return;
}

void insert(node* root, int i)
{

   if(root == nullptr){
      cout << "Made a new node with data " << i << endl;
      root = new node;
      root->data = i;
      root->left = nullptr;
      root->right = nullptr;
      return;
   }
   
   if(root->data > i){
      cout << "i < data... going left (i = "<<i <<", data = "<< root->data<<")" << endl;
      insert(root->left, i);
      return;
   }

   cout << "i > data... going right (i = "<<i <<", data = "<< root->data<<")" << endl;
   insert(root->right, i);
   
   return;
}

