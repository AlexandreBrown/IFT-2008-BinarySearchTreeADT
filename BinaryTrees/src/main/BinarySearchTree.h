#ifndef BinaryTree_MYCLASS_H
#define BinaryTree_MYCLASS_H

#include <string>
#include <iostream>

template<typename Comparable, typename NodeType>
class BinarySearchTree {
	public:

		BinarySearchTree();

		BinarySearchTree(const BinarySearchTree& rhs);

		BinarySearchTree(BinarySearchTree&& rhs);

		virtual ~BinarySearchTree();

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

	protected:
		virtual void insert(const Comparable& x, NodeType*& t);

		virtual void insert(Comparable&& x, NodeType*& t);

		virtual void remove(const Comparable& x, NodeType*& t);

	private:

		NodeType* root;

		NodeType* findMin(NodeType* t) const;

		NodeType* findMax(NodeType* t) const;

		bool contains(const Comparable& x, NodeType* t) const;

		void makeEmpty(NodeType*& t);

		NodeType* clone(NodeType* t) const;

		bool has2Children(NodeType* const& t) const;

		void printTreeInSymmetricOrder(NodeType* t, std::ostream& out) const;

		void printTreeInPreOrder(NodeType* t, std::ostream& out) const;

		void printTreeInPostOrder(NodeType* t, std::ostream& out) const;
};

#include "BinarySearchTree.tpp"

#endif
