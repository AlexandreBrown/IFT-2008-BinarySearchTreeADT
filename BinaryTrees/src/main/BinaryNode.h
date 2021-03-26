#ifndef BINARYTREE_SRC_MAIN_BINARYNODE_H_
#define BINARYTREE_SRC_MAIN_BINARYNODE_H_

template<typename T>
struct BinaryNode {

	T element;
	BinaryNode* left;
	BinaryNode* right;

	BinaryNode(
		const T& theElement,
		BinaryNode* theLeft,
		BinaryNode* theRight
	) : element{theElement},
	    left{theLeft},
	    right{theRight} {}

	BinaryNode(
		const T&& theElement,
		BinaryNode* theLeft,
		BinaryNode* theRight
	) : element{std::move(theElement)},
	    left{theLeft},
	    right{theRight} {}
};

#endif
