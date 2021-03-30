#include "BinarySearchTree.h"

template<typename Comparable, typename NodeType>
BinarySearchTree<Comparable, NodeType>::BinarySearchTree() : root{nullptr} {}

template<typename Comparable, typename NodeType>
BinarySearchTree<Comparable, NodeType>::BinarySearchTree(const BinarySearchTree& rhs) : root{nullptr} {
	root = clone(rhs.root);
}

template<typename Comparable, typename NodeType>
NodeType* BinarySearchTree<Comparable, NodeType>::clone(NodeType* t) const {
	if (t==nullptr) {
		return nullptr;
	}
	return new NodeType(
		t->element,
		clone(t->left),
		clone(t->right)
	);
}

template<typename Comparable, typename NodeType>
BinarySearchTree<Comparable, NodeType>::BinarySearchTree(BinarySearchTree<Comparable, NodeType>&& rhs): root{nullptr} {
	root = clone(rhs.root);
}

template<typename Comparable, typename NodeType>
BinarySearchTree<Comparable, NodeType>::~BinarySearchTree() {
	makeEmpty();
}

template<typename Comparable, typename NodeType>
void BinarySearchTree<Comparable, NodeType>::makeEmpty() {
	makeEmpty(root);
}

template<typename Comparable, typename NodeType>
void BinarySearchTree<Comparable, NodeType>::makeEmpty(NodeType*& t) {
	if (t!=nullptr) {
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
	}

	t = nullptr;
}

template<typename Comparable, typename NodeType>
bool BinarySearchTree<Comparable, NodeType>::contains(const Comparable& x) const {
	return contains(x, root);
}

template<typename Comparable, typename NodeType>
bool BinarySearchTree<Comparable, NodeType>::contains(const Comparable& x, NodeType* t) const {
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

template<typename Comparable, typename NodeType>
const Comparable& BinarySearchTree<Comparable, NodeType>::findMin() const {
	if (root==nullptr) {
		throw std::logic_error{"Could not find min element of empty tree!"};
	}

	return findMin(root)->element;
}

template<typename Comparable, typename NodeType>
NodeType* BinarySearchTree<Comparable, NodeType>::findMin(NodeType* t) const {
	if (t->left==nullptr) {
		return t;
	}
	return findMin(t->left);
}

template<typename Comparable, typename NodeType>
const Comparable& BinarySearchTree<Comparable, NodeType>::findMax() const {
	if (root==nullptr) {
		throw std::logic_error{"Could not find max element of empty tree!"};
	}

	return findMax(root)->element;
}

template<typename Comparable, typename NodeType>
NodeType* BinarySearchTree<Comparable, NodeType>::findMax(NodeType* t) const {
	while (t->right!=nullptr) {
		t = t->right;
	}
	return t;
}

template<typename Comparable, typename NodeType>
void BinarySearchTree<Comparable, NodeType>::insert(const Comparable& x) {
	insert(x, root);
}

template<typename Comparable, typename NodeType>
void BinarySearchTree<Comparable, NodeType>::insert(const Comparable& x, NodeType*& t) {
	if (t==nullptr) {
		t = new NodeType(x);
	} else if (x < t->element) {
		insert(x, t->left);
	} else if (t->element < x) {
		insert(x, t->right);
	} else {
		throw std::logic_error{"Element is already present in the tree!"};
	}
}

template<typename Comparable, typename NodeType>
void BinarySearchTree<Comparable, NodeType>::insert(Comparable&& x) {
	insert(std::move(x), root);
}

template<typename Comparable, typename NodeType>
void BinarySearchTree<Comparable, NodeType>::insert(Comparable&& x, NodeType*& t) {
	if (t==nullptr) {
		t = new NodeType(std::move(x));
	} else if (x < t->element) {
		insert(std::move(x), t->left);
	} else if (t->element < x) {
		insert(std::move(x), t->right);
	} else {
		throw std::logic_error{"Element is already present in the tree!"};
	}
}

template<typename Comparable, typename NodeType>
void BinarySearchTree<Comparable, NodeType>::remove(const Comparable& x) {
	remove(x, root);
}

template<typename Comparable, typename NodeType>
void BinarySearchTree<Comparable, NodeType>::remove(const Comparable& x, NodeType*& t) {
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
		NodeType* oldNode = t;
		t = (t->left!=nullptr) ? t->left : t->right;
		delete oldNode;
	}
}

template<typename Comparable, typename NodeType>
bool BinarySearchTree<Comparable, NodeType>::has2Children(NodeType* const& t) const {
	return t->left!=nullptr && t->right!=nullptr;
}

template<typename Comparable, typename NodeType>
bool BinarySearchTree<Comparable, NodeType>::isEmpty() const {
	return root==nullptr;
}

template<typename Comparable, typename NodeType>
BinarySearchTree<Comparable, NodeType>& BinarySearchTree<Comparable, NodeType>::operator=(const BinarySearchTree& rhs) {

	if (this->root!=rhs.root) {
		makeEmpty();
		root = clone(rhs.root);
	}

	return *this;
}

template<typename Comparable, typename NodeType>
BinarySearchTree<Comparable, NodeType>& BinarySearchTree<Comparable, NodeType>::operator=(BinarySearchTree&& rhs) {

	if (this->root!=rhs.root) {
		makeEmpty();
		root = clone(rhs.root);
	}

	return *this;
}

template<typename Comparable, typename NodeType>
void BinarySearchTree<Comparable, NodeType>::printTreeInSymmetricOrder(std::ostream& out) const {
	printTreeInSymmetricOrder(root, out);
}

template<typename Comparable, typename NodeType>
void BinarySearchTree<Comparable, NodeType>::printTreeInSymmetricOrder(NodeType* t, std::ostream& out) const {
	if (t==nullptr) {
		return;
	}

	printTreeInSymmetricOrder(t->left, out);

	out << t->element << ";";

	printTreeInSymmetricOrder(t->right, out);
}

template<typename Comparable, typename NodeType>
void BinarySearchTree<Comparable, NodeType>::printTreeInPreOrder(std::ostream& out) const {
	printTreeInPreOrder(root, out);
}

template<typename Comparable, typename NodeType>
void BinarySearchTree<Comparable, NodeType>::printTreeInPreOrder(NodeType* t, std::ostream& out) const {
	if (t==nullptr) {
		return;
	}

	out << t->element << ";";

	printTreeInPreOrder(t->left, out);

	printTreeInPreOrder(t->right, out);
}

template<typename Comparable, typename NodeType>
void BinarySearchTree<Comparable, NodeType>::printTreeInPostOrder(std::ostream& out) const {
	printTreeInPostOrder(root, out);
}

template<typename Comparable, typename NodeType>
void BinarySearchTree<Comparable, NodeType>::printTreeInPostOrder(NodeType* t, std::ostream& out) const {
	if (t==nullptr) {
		return;
	}

	printTreeInPostOrder(t->left, out);

	printTreeInPostOrder(t->right, out);

	out << t->element << ";";
}