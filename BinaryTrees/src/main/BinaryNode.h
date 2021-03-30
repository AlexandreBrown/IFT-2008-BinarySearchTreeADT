#ifndef BINARYTREE_SRC_MAIN_BINARYNODE_H_
#define BINARYTREE_SRC_MAIN_BINARYNODE_H_

template<typename T>
struct BinaryNode {

	T element;

	BinaryNode<T>* left;

	BinaryNode<T>* right;

	BinaryNode(
		const T& theElement
	) : element{theElement},
	    left{nullptr},
	    right{nullptr} {}

	BinaryNode(
		T&& theElement
	) : element{std::move(theElement)},
	left{nullptr},
	right{nullptr} {}

	BinaryNode(
		const T& theElement,
		BinaryNode<T>* theLeft,
		BinaryNode<T>* theRight
	) : element{theElement},
	    left{theLeft},
	    right{theRight} {}

	BinaryNode(
		T&& theElement,
		BinaryNode<T>* theLeft,
		BinaryNode<T>* theRight
	) : element{std::move(theElement)},
	    left{theLeft},
	    right{theRight} {}
};

#endif
