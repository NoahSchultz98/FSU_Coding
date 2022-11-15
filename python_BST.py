# Python program to demonstrate insert operation in binary search tree 
 
# A utility class that represents an individual node in a BST 
class Node: 
    def __init__(self,key): 
        self.left = None
        self.right = None
        self.val = key 
 
# A utility function to insert a new node with the given key 
def insert(root,key): 
    if root is None: 
        return Node(key) 
    else:
        if root.val == key:
            return root
        elif root.val < key: 
            root.right = insert(root.right, key) 
        else:
            root.left = insert(root.left, key)
    return root
 
# A utility function to do inorder tree traversal 
def inorder(root): 
    if root: 
        inorder(root.left) 
        print(root.val) 
        inorder(root.right)

def find_max(root):
    if root.right is not None:
        find_max(root.right)
    else:
        print("The max is = ", root.val)
    return

def find_min(root):
    if root.left is not None:
        find_min(root.left)
    else:
        print("The min is = ", root.val)
    return
 
 
 
# Driver program to test the above functions 
# Let us create the following BST 
#   enter numbers and make an image of BST.
# let first number be 70, second 40, etc.
 
r = Node(33) 
insert(r, 20)
insert(r, 25)
insert(r, 50)
insert(r, 10)
insert(r, 21)
insert(r, 42)
insert(r, 32)
insert(r, 13)
insert(r, 53)
insert(r, 52)
insert(r, 19)
 
# Print inoder traversal of the BST 
inorder(r)

# Print the maximum key, right most child
find_max(r)
find_min(r)
