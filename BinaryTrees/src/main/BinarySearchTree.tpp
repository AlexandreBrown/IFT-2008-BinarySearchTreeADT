#include "BinarySearchTree.h"

template<typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree() : root{nullptr} {}

template<typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree(const BinarySearchTree& rhs) : root{nullptr} {
	root = clone(rhs.root);
}

template<typename Comparable>
BinaryNode<Comparable>* BinarySearchTree<Comparable>::clone(BinaryNode<Comparable>* t) const {
	if (t==nullptr) {
		return nullptr;
	}
	return new BinaryNode<Comparable>{
		.element = t->element,
		.left = clone(t->left),
		.right = clone(t->right)
	};
}

template<typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree(BinarySearchTree&& rhs): root{nullptr} {
	root = clone(rhs.root);
}

template<typename Comparable>
BinarySearchTree<Comparable>::~BinarySearchTree() {
	makeEmpty();
}

template<typename Comparable>
void BinarySearchTree<Comparable>::makeEmpty() {
	makeEmpty(root);
}

template<typename Comparable>
void BinarySearchTree<Comparable>::makeEmpty(BinaryNode<Comparable>*& t) {
	if (t!=nullptr) {
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
	}

	t = nullptr;
}

template<typename Comparable>
bool BinarySearchTree<Comparable>::contains(const Comparable& x) const {
	return contains(x, root);
}

template<typename Comparable>
bool BinarySearchTree<Comparable>::contains(const Comparable& x, BinaryNode<Comparable>* t) const {
	if (t==nullptr) {
		return false;
	}
	if (x < t->element) {
		return contains(x, t->left);
	}
	if (t->element < x) {
		return contains(x, t->right);
	}
	return true;
}

template<typename Comparable>
const Comparable& BinarySearchTree<Comparable>::findMin() const {
	if (root==nullptr) {
		throw std::logic_error{"Could not find min element of empty tree!"};
	}

	return findMin(root)->element;
}

template<typename Comparable>
BinaryNode<Comparable>* BinarySearchTree<Comparable>::findMin(BinaryNode<Comparable>* t) const {
	if (t->left==nullptr) {
		return t;
	}
	return findMin(t->left);
}

template<typename Comparable>
const Comparable& BinarySearchTree<Comparable>::findMax() const {
	if (root==nullptr) {
		throw std::logic_error{"Could not find max element of empty tree!"};
	}

	return findMax(root)->element;
}

template<typename Comparable>
BinaryNode<Comparable>* BinarySearchTree<Comparable>::findMax(BinaryNode<Comparable>* t) const {
	while (t->right!=nullptr) {
		t = t->right;
	}
	return t;
}

template<typename Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable& x) {
	insert(x, root);
}

template<typename Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable& x, BinaryNode<Comparable>*& t) {
	if (t==nullptr) {
		t = new BinaryNode<Comparable>{x, nullptr, nullptr};
	} else if (x < t->element) {
		insert(x, t->left);
	} else if (t->element < x) {
		insert(x, t->right);
	} else {
		throw std::logic_error{"Element is already present in the tree!"};
	}
}

template<typename Comparable>
void BinarySearchTree<Comparable>::insert(Comparable&& x) {
	insert(std::move(x), root);
}

template<typename Comparable>
void BinarySearchTree<Comparable>::insert(Comparable&& x, BinaryNode<Comparable>*& t) {
	if (t==nullptr) {
		t = new BinaryNode<Comparable>{std::move(x), nullptr, nullptr};
	} else if (x < t->element) {
		insert(std::move(x), t->left);
	} else if (t->element < x) {
		insert(std::move(x), t->right);
	} else {
		throw std::logic_error{"Element is already present in the tree!"};
	}
}

template<typename Comparable>
void BinarySearchTree<Comparable>::remove(const Comparable& x) {
	remove(x, root);
}

template<typename Comparable>
void BinarySearchTree<Comparable>::remove(const Comparable& x, BinaryNode<Comparable>*& t) {
	if (t==nullptr) {
		return;
	}

	if (x < t->element) {
		remove(x, t->left);
	} else if (t->element < x) {
		remove(x, t->right);
	} else if (has2Children(t)) {
		t->element = findMin(t->right)->element;
		remove(t->element, t->right);
	} else {
		BinaryNode<Comparable>* oldNode = t;
		t = (t->left!=nullptr) ? t->left : t->right;
		delete oldNode;
	}
}

template<typename Comparable>
bool BinarySearchTree<Comparable>::has2Children(BinaryNode<Comparable>* const& t) const {
	return t->left!=nullptr && t->right!=nullptr;
}

template<typename Comparable>
bool BinarySearchTree<Comparable>::isEmpty() const {
	return root==nullptr;
}

template<typename Comparable>
BinarySearchTree<Comparable>& BinarySearchTree<Comparable>::operator=(const BinarySearchTree& rhs) {

	if (this->root!=rhs.root) {
		makeEmpty();
		root = clone(rhs.root);
	}

	return *this;
}

template<typename Comparable>
BinarySearchTree<Comparable>& BinarySearchTree<Comparable>::operator=(BinarySearchTree&& rhs) {

	if (this->root!=rhs.root) {
		makeEmpty();
		root = clone(rhs.root);
	}

	return *this;
}

template<typename Comparable>
void BinarySearchTree<Comparable>::printTreeInSymmetricOrder(std::ostream& out) const {
	printTreeInSymmetricOrder(root, out);
}

template<typename Comparable>
void BinarySearchTree<Comparable>::printTreeInSymmetricOrder(BinaryNode<Comparable>* t, std::ostream& out) const {
	if(t ==nullptr) {
		return;
	}

	printTreeInSymmetricOrder(t->left, out);

	out << t->element << ";";

	printTreeInSymmetricOrder(t->right, out);
}

template <typename Comparable>
void BinarySearchTree<Comparable>::printTreeInPreOrder(std::ostream& out) const {
	printTreeInPreOrder(root, out);
}

template<typename Comparable>
void BinarySearchTree<Comparable>::printTreeInPreOrder(BinaryNode<Comparable>* t, std::ostream& out) const {
	if(t ==nullptr) {
		return;
	}

	out << t->element << ";";

	printTreeInPreOrder(t->left, out);

	printTreeInPreOrder(t->right, out);
}

template <typename Comparable>
void BinarySearchTree<Comparable>::printTreeInPostOrder(std::ostream& out) const {
	printTreeInPostOrder(root, out);
}

template<typename Comparable>
void BinarySearchTree<Comparable>::printTreeInPostOrder(BinaryNode<Comparable>* t, std::ostream& out) const {
	if(t ==nullptr) {
		return;
	}

	printTreeInPostOrder(t->left, out);

	printTreeInPostOrder(t->right, out);

	out << t->element << ";";
}