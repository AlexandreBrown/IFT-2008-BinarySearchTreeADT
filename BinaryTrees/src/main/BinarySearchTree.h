#ifndef BinaryTree_MYCLASS_H
#define BinaryTree_MYCLASS_H

#include <string>
#include <iostream>
#include "BinaryNode.h"

template<typename Comparable>
class BinarySearchTree {
	public:

		BinarySearchTree();

		BinarySearchTree(const BinarySearchTree& rhs);

		BinarySearchTree(BinarySearchTree&& rhs);

		~BinarySearchTree();

		const Comparable& findMin() const;

		const Comparable& findMax() const;

		bool contains(const Comparable& x) const;

		bool isEmpty() const;

		void printTreeInSymmetricOrder(std::ostream& out = std::cout) const;

		void printTreeInPreOrder(std::ostream& out = std::cout) const;

		void printTreeInPostOrder(std::ostream& out = std::cout) const;

		void makeEmpty();

		void insert(const Comparable& x);

		void insert(Comparable&& x);

		void remove(const Comparable& x);

		BinarySearchTree& operator=(const BinarySearchTree& rhs);

		BinarySearchTree& operator=(BinarySearchTree&& rhs);

	private:

		BinaryNode<Comparable>* root;

		void insert(const Comparable& x, BinaryNode<Comparable>*& t);

		void insert(Comparable&& x, BinaryNode<Comparable>*& t);

		void remove(const Comparable& x, BinaryNode<Comparable>*& t);

		BinaryNode<Comparable>* findMin(BinaryNode<Comparable>* t) const;

		BinaryNode<Comparable>* findMax(BinaryNode<Comparable>* t) const;

		bool contains(const Comparable& x, BinaryNode<Comparable>* t) const;

		void makeEmpty(BinaryNode<Comparable>*& t);

		BinaryNode<Comparable>* clone(BinaryNode<Comparable>* t) const;

		bool has2Children(BinaryNode<Comparable>* const& t) const;

		void printTreeInSymmetricOrder(BinaryNode<Comparable>* t, std::ostream& out) const;

		void printTreeInPreOrder(BinaryNode<Comparable>* t, std::ostream& out) const;

		void printTreeInPostOrder(BinaryNode<Comparable>* t, std::ostream& out) const;
};

#include "BinarySearchTree.tpp"

#endif
