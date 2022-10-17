 #include <iostream>
 
 using namespace std;

/*

Noah Schultz
Programming Languages
Test 1
9/29/2022

*/


// singly linked list 

// each node can have only ONE child 
// multiple parents CAN have the SAME child 

// it would be possible to make a dynamic array of ListNode* to hold a variable amount of children
// However... that would be a lot of work
 struct ListNode 
{
   char val;
   ListNode *next;
   ListNode() : val('a'), next(nullptr) {}
   ListNode(char x) : val(x), next(nullptr) {}
   ListNode(char x, ListNode *next) : val(x), next(next) {}
};

bool isPath(ListNode* pt1, ListNode* pt2);

int main (int argc, char *argv[])
{
   ListNode* c = new ListNode('c');
   ListNode* b = new ListNode('b', c);
   ListNode* a = new ListNode('a', b);
   // a points to b and b points to c


   if(isPath(a,b))
      cout << "a -> b is a path" << endl;
   else
      cout << "a -> b is NOT a path" << endl;
      
   if(isPath(a,c))
      cout << "a -> c is a path" << endl;
   else
      cout << "a -> c is NOT a path" << endl;
      
    if(isPath(b,a))
      cout << "b -> a is a path" << endl;
   else
      cout << "b -> a is NOT a path" << endl;
      
   if(isPath(c,a))
      cout << "c -> a is a path" << endl;
   else
      cout << "c -> a is NOT a path" << endl;
      
      
      return 0;
}

bool isPath(ListNode* pt1, ListNode* pt2)
{
   // recursive function
   // first we check to see if the child is the target node
   if(pt1->next == pt2)
      return true; // if the child node is the target then there is a path
   else if(pt1->next != nullptr) 
      isPath(pt1->next, pt2); // if the child is not the target and there is another child node, then call is path on the next node
   else // if we have exhausted these two options then their is not path to the target node
      return false;
}
