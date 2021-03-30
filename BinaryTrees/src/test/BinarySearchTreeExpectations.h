#ifndef BINARYTREES_SRC_TEST_BINARYSEARCHTREEEXPECTATIONS_H_
#define BINARYTREES_SRC_TEST_BINARYSEARCHTREEEXPECTATIONS_H_

using std::to_string;

class BinarySearchTreeExpectations {

	public:

		template<typename T>
		static std::string getExpectedTreeOutputFormat(const std::initializer_list<T>& elements);
};

template<typename T>
std::string BinarySearchTreeExpectations::getExpectedTreeOutputFormat(const std::initializer_list<T>& elements) {

	std::string result;

	for (auto elementIterator = elements.begin(); elementIterator != elements.end() ; ++elementIterator) {
		result += to_string(*elementIterator) + ";";
	}

	return result;
}

#endif