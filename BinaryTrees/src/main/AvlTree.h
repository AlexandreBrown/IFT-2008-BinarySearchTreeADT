#ifndef BINARYTREES_SRC_MAIN_AVLTREE_H_
#define BINARYTREES_SRC_MAIN_AVLTREE_H_

#include "BinarySearchTree.h"
#include "AvlNode.h"

template<typename Comparable>
class AvlTree : public BinarySearchTree<Comparable, AvlNode<Comparable>> {

	protected:

		void insert(const Comparable& x, AvlNode<Comparable>*& t) override;

		void insert(Comparable&& x, AvlNode<Comparable>*& t) override;

		void remove(const Comparable& x, AvlNode<Comparable>*& t) override;

	private:

		const int ALLOWED_IMBALANCE = 1;

		int height(AvlNode<Comparable>* node) const;

		void balance(AvlNode<Comparable>*& node);

		void rotateWithLeftChild(AvlNode<Comparable>*& k2);

		void doubleRotateWithLeftChild(AvlNode<Comparable>*& k3);

		void rotateWithRightChild(AvlNode<Comparable>*& k2);

		void doubleRotateWithRightChild(AvlNode<Comparable>*& k3);
};

#include "AvlTree.tpp"

#endif
