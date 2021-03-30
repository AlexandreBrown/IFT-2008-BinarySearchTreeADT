#include "AvlTree.h"

template<typename Comparable>
void AvlTree<Comparable>::insert(const Comparable& x, AvlNode<Comparable>*& t) {

	BinarySearchTree<Comparable, AvlNode<Comparable>>::insert(x, t);

	balance(t);
}

template<typename Comparable>
void AvlTree<Comparable>::insert(Comparable&& x, AvlNode<Comparable>*& t) {

	BinarySearchTree<Comparable, AvlNode<Comparable>>::insert(std::move(x), t);

	balance(t);
}

template<typename Comparable>
void AvlTree<Comparable>::balance(AvlNode<Comparable>*& node) {

	if (node==nullptr) {
		return;
	}

	if (height(node->left) - height(node->right) > ALLOWED_IMBALANCE) {
		if (height(node->left->left) >= height(node->left->right)) {
			rotateWithLeftChild(node);
		} else {
			doubleRotateWithLeftChild(node);
		}
	} else if (height(node->right) - height(node->left) > ALLOWED_IMBALANCE) {
		if (height(node->right->right) >= height(node->right->left)) {
			rotateWithRightChild(node);
		} else {
			doubleRotateWithRightChild(node);
		}
	}

	node->height = std::max(height(node->left), height(node->right)) + 1;
}

template<typename Comparable>
int AvlTree<Comparable>::height(AvlNode<Comparable>* node) const {
	return node==nullptr ? -1 : node->height;
}

template<typename Comparable>
void AvlTree<Comparable>::remove(const Comparable& x, AvlNode<Comparable>*& t) {

	BinarySearchTree<Comparable, AvlNode<Comparable>>::remove(x, t);

	balance(t);
}

template<typename Comparable>
void AvlTree<Comparable>::rotateWithLeftChild(AvlNode<Comparable>*& k2) {
	AvlNode<Comparable>* k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;
	k2->height = std::max(height(k2->left), height(k2->right)) + 1;
	k1->height = std::max(height(k1->left), k2->height) + 1;
	k2 = k1;
}

template<typename Comparable>
void AvlTree<Comparable>::doubleRotateWithLeftChild(AvlNode<Comparable>*& k3) {
	rotateWithRightChild(k3->left);
	rotateWithLeftChild(k3);
}

template<typename Comparable>
void AvlTree<Comparable>::rotateWithRightChild(AvlNode<Comparable>*& k2) {
	AvlNode<Comparable>* k1 = k2->right;
	k2->right = k1->left;
	k1->left = k2;
	k2->height = std::max(height(k2->right), height(k2->left)) + 1;
	k1->height = std::max(height(k1->right), k2->height) + 1;
	k2 = k1;
}

template<typename Comparable>
void AvlTree<Comparable>::doubleRotateWithRightChild(AvlNode<Comparable>*& k3) {
	rotateWithLeftChild(k3->right);
	rotateWithRightChild(k3);
}
