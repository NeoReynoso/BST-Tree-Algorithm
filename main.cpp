//
//  main.cpp
//  BST Algorithm
//
//  Created by Ivan Reynoso on 1/30/23.
//

template<typename T>

void BTree<T>::BSTInsert(T value)

{

       Node<T>* newNode = new Node<T>(value, NULL, NULL);

       if (root == NULL)

             root = newNode;

       else

       {

             Node<T>* r = root;

             while (r != NULL)

             {

 

                    if (value < r->element)

                    {

                           if (r->left == NULL)

                           {

                                 r->left = newNode;

                                 r = NULL;

                           }

                           else

                                 r = r->left;

                    }

                    else

                    {

                           if (r->right == NULL)

                           {

                                 r->right = newNode;

                                 r = NULL;

                           }

                           else

                                 r = r->right;

                    }

             }

       }

}

 

template<typename T>

void BTree<T>::BSTRemove(T value)

{

 

       Node<T>* cur = BSTsearch(value);

       deleteNode(cur);

}

 

 

 

template<class T>

void BTree<T>::deleteNode(Node<T>* z)

{

       if (z->getLeft() == nullptr)

             transplant(z, z->getRight());

       else if (z->getRight() == nullptr)

             transplant(z, z->getLeft());

       else

       {

             Node<T>* y;

             // Find y as the minimum in z's right subtree

             y = z->getRight();

             while (y->getLeft() != nullptr)

             {

                    y = y->getLeft();

             }

             // Y's right subtree to Z's right subtree

             if (y->getParent() != z)

             {

                    transplant(y, y->getRight());

                    y->setRight(z->getRight());

                    y->getRight()->setParent(y);

             }

             // Swap y and z and y's left subtree to z's left subtree

             transplant(z, y);

             y->setLeft(z->getLeft());

             y->getLeft()->setParent(y);

       }

}

 

template<class T>

void BTree<T>::transplant(Node<T>* u, Node<T>* v)

{

       if (u->getParent() == nullptr)

             root = v;

       else if (u == u->getParent()->getLeft())

             u->getParent()->setLeft(v);

       else

             u->getParent()->setRight(v);

       if (v != nullptr)

             v->setParent(u->getParent());

}

 

int main() {

       BTree<int> bst;

       bst.BSTInsert(5);

       bst.BSTInsert(3);

       bst.BSTInsert(7);

       //     5

       //   3   7

 

       bst.BSTInsert(9);

       //     5

       //   3   7

       //         9

      

       bst.BSTInsert(10);

       //     5

       //   3   7

       //         9

       //           10

      

 

       bst.BSTInsert(1);

       //     5

       //   3   7

       // 1       9

       //           10

      

       bst.BSTInsert(8);

       //     5

       //   3   7

       // 1       9

       //        8  10

 

 

       bst.BSTInsert(6);

       //     5

       //   3   7

       // 1    6  9

       //        8  10

 

 

       bst.BSTInsert(4);

       //     5

       //   3    7

       // 1  4  6  9

       //        8  10

 

       bst.BSTInsert(2);

       //     5

       //   3    7

       // 1  4  6  9

       //  2      8  10

 

       bst.BSTPrint();

 

       cout << endl << "Number 10 has level of " << bst.BSTNodeLevel(10) << endl;

       return 0;

}


