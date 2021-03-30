#ifndef BINARYTREES_SRC_MAIN_AVLNODE_H_
#define BINARYTREES_SRC_MAIN_AVLNODE_H_

#include "BinaryNode.h"

template<typename T>
struct AvlNode {

	T element;

	AvlNode<T>* left;

	AvlNode<T>* right;

	int height;

	AvlNode(
		const T& theElement
	) : element{theElement},
	    left{nullptr},
	    right{nullptr},
	    height{0} {}

	AvlNode(
		T&& theElement
	) : element{std::move(theElement)},
	    left{nullptr},
	    right{nullptr},
	    height{0} {}

	AvlNode(
		const T& theElement,
		AvlNode<T>* theLeft,
		AvlNode<T>* theRight
	) : element{theElement},
	    left{theLeft},
	    right{theRight},
	    height{0} {}

	AvlNode(
		T&& theElement,
		AvlNode<T>* theLeft,
		AvlNode<T>* theRight
	) : element{std::move(theElement)},
	    left{theLeft},
	    right{theRight},
	    height{0} {}
};

#endif
