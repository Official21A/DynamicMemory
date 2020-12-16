# AVL Tree

AVL tree is a self-balancing Binary Search Tree (BST) where the difference between heights of left and right subtrees cannot be more than one for all nodes.<br />
Example of an AVL tree:<br />
<img src="https://media.geeksforgeeks.org/wp-content/cdn-uploads/AVL-Tree1.jpg" width="500" />

Most of the BST operations (e.g., search, max, min, insert, delete.. etc) take O(h) time where h is the height of the BST.<br />
The cost of these operations may become O(n) for a skewed Binary tree. If we make sure that height of the tree remains O(Logn) after every insertion and deletion,
then we can guarantee an upper bound of O(Logn) for all these operations.<br />
The height of an AVL tree is always O(Logn) where n is the number of nodes in the tree
