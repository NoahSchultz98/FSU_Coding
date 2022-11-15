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

void find_child(node* root, int key);
void printNodes(node* root);
node* insert(node* root, int data);
//void insert(node* root, int i);
void find_min(node* root);
void find_max(node* root);
void post_order(node* root);
void pre_order(node* root);
void destroy_nodes(node* root);

int main()
{
   node* root;
   node* temp;
   
   /*
   *        THIS TREE IS AN EXAMPLE AND HAS NO SPECIAL QUALITIES
   *  IT IS NOT BALANCED, AND IS THE SAME AS THE TREE CONSTRUCTED IN PYTHON
   */
   
   temp = new node;
   temp->data = 33; // ROOT NODE
   temp->left = nullptr;
   temp->right = nullptr; 
   
   root = temp;

   insert(root, 20);
   insert(root, 25);
   insert(root, 50);
   insert(root, 10);
   insert(root, 21);
   insert(root, 42);
   insert(root, 32);
   insert(root, 13);
   insert(root, 53);
   insert(root, 52);
   insert(root, 19);
   
   cout << "ORDERED BST" << endl;
   
   printNodes(root); // <- PRINTS THE NODES IN ORDER FROM SMALLEST TO LARGEST
   
   cout << endl << "FIND A NODE WITH KEY 20" << endl;
   
   find_child(root, 20); // <- IF A NODE IN THE TREE HAS THIS KEY THEN THE FUNCTION RETURNS THAT THE NODE WAS FOUND
   
   cout << endl << "FIND A NODE WITH KEY 100" << endl;
   
   find_child(root, 100); // <- IF THERE IS NO NODE WITH THE KEY THEN THE FUNCTION RETURNS THAT NO NODE WITH THE KEY EXISTS
   
   cout << endl << endl << "POST ORDER BST" << endl;
   
   post_order(root); // PRINT THE DATA, THEN CALL THE FUNCTION RECURSIVLY TO TRAVERSE TO THE RIGHT, THEN LEFT
   
   cout << endl << endl << "PRE ORDER BST" << endl;
   
   pre_order(root); // TRAVERSE THE TREE RECURSIVLY TO THE RIGHT, THEN LEFT, LASTLY PRINT THE DATA
   
   destroy_nodes(root); // <- THIS FUNCTION WILL ENSURE WE DO NOT HAVE A MEMORY LEAK 
   
   /*
   *   THE NEXT TREE IS ONE THAT WILL PRINT IN ORDER WHEN USING THE PRE_ORDER FUNCTION
   */
   
   temp = new node;
   temp->data = 1; // ROOT NODE
   temp->left = nullptr;
   temp->right = nullptr; 
   
   root = temp;

   insert(root, 2);
   insert(root, 3);
   insert(root, 10);
   insert(root, 12);
   insert(root, 21);
   insert(root, 22);
   insert(root, 28);
   insert(root, 33);
   insert(root, 35);
   insert(root, 40);
   insert(root, 50);
   
   cout << endl << "PRE ORDER, ORDERED OUTPUT BST" << endl;
   
   pre_order(root); // TRAVERSE THE TREE RECURSIVLY TO THE RIGHT, THEN LEFT, LASTLY PRINT THE DATA
   
   destroy_nodes(root); // <- THIS FUNCTION WILL ENSURE WE DO NOT HAVE A MEMORY LEAK
   
   /*
   *  THIS TREE WILL PRINT IN ORDER WHEN USING THE POST_ORDER FUNCTION
   */
   
   temp = new node;
   temp->data = 100; // ROOT NODE
   temp->left = nullptr;
   temp->right = nullptr; 
   
   root = temp;

   insert(root, 90);
   insert(root, 88);
   insert(root, 80);
   insert(root, 79);
   insert(root, 66);
   insert(root, 64);
   insert(root, 55);
   insert(root, 52);
   insert(root, 50);
   insert(root, 33);
   insert(root, 20);
   
   cout << endl << "POST ORDER, ORDERED OUTPUT BST" << endl;
   
   post_order(root); // PRINT THE DATA, THEN CALL THE FUNCTION RECURSIVLY TO TRAVERSE TO THE RIGHT, THEN LEFT

   destroy_nodes(root); // <- THIS FUNCTION WILL ENSURE WE DO NOT HAVE A MEMORY LEAK
   
   return 0;
}

void destroy_nodes(node* root)
{
   if(root != nullptr){
      destroy_nodes(root->right);
      destroy_nodes(root->left);
      delete root;
   }
}

void post_order(node* root)
{
   if(root != nullptr){
      post_order(root->right);
      post_order(root->left);
      cout << root->data << endl;
   }
}

void pre_order(node* root)
{  
   if(root != nullptr){
      cout << root->data << endl;
      pre_order(root->right);
      pre_order(root->left);
   }
}

void find_child(node* root, int key)
{

   if( key == root->data ){
      cout << "A node with the key: "<< key << ", can be found in the tree" << endl;
      return;
   }else if( key > root->data && root->right != nullptr ){
      find_child(root->right, key);
      return;
   }else if( key < root->data && root->left != nullptr ){
      find_child(root->left, key); 
      return;
   }
      
   cout << "The node with key: " << key << ", could not be found" << endl;

}

void find_max(node* root)
{
   if(root->right != nullptr){
      find_min(root->right);
      return;
   }
   cout << root->data << endl;
   return;
}

void find_min(node* root)
{
   if(root->left != nullptr){
      find_min(root->left);
      return;
   }
   cout << root->data << endl;
   return;
}

void printNodes(node* root){ // prints node from smallest to largest

   if(root->left != nullptr)
      printNodes(root->left);
      
cout << root->data << endl;
      
   if(root->right != nullptr)
      printNodes(root->right);
      
   return;
}

//void insert(node* root, int i)
node* insert(node* root, int i)
{

   if(root == nullptr){
      node* temp = new node;
      temp->data = i;
      temp->left = nullptr;
      temp->right = nullptr;
      return temp;
   }
   
   if(root->data > i){
      root->left = insert(root->left, i);
   }else{
   root->right = insert(root->right, i);
   }
   return root;
}

