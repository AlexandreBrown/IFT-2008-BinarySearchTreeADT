#include <gtest/gtest.h>
#include "../main/BinarySearchTree.h"
#include "../main/BinaryNode.h"
#include "BinarySearchTreeExpectations.h"
#include "utils/RandomValues.h"

using std::logic_error;
using std::to_string;
using Random::RandomValues;

namespace {
	class BinarySearchTreeTest : public testing::Test {

		public:
			BinarySearchTree<size_t, BinaryNode<size_t>> tree;
	};
}

TEST_F(BinarySearchTreeTest, contains_return_true_when_node_is_present_in_tree) {

	auto expectedValue = RandomValues::getRandomNumber<size_t>();;
	tree.insert(expectedValue);

	auto contains = tree.contains(expectedValue);

	ASSERT_TRUE(contains);
}

TEST_F(BinarySearchTreeTest, contains_return_false_when_node_is_not_present_in_tree) {

	auto expectedValue = RandomValues::getRandomNumber<size_t>();
	tree.insert(expectedValue + 1);

	auto contains = tree.contains(expectedValue);

	ASSERT_FALSE(contains);
}

TEST_F(BinarySearchTreeTest, contains_return_true_when_node_is_present_in_complex_tree) {

	auto expectedValue = RandomValues::getRandomNumber<size_t>();
	tree.insert(expectedValue - 4);
	tree.insert(expectedValue - 3);
	tree.insert(expectedValue - 2);
	tree.insert(expectedValue - 1);
	tree.insert(expectedValue);
	tree.insert(expectedValue + 1);
	tree.insert(expectedValue + 2);
	tree.insert(expectedValue + 3);
	tree.insert(expectedValue + 4);

	auto contains = tree.contains(expectedValue);

	ASSERT_TRUE(contains);
}

TEST_F(BinarySearchTreeTest, findMin_throws_logic_error_when_tree_is_empty) {

	ASSERT_THROW(tree.findMin(), logic_error);
}

TEST_F(BinarySearchTreeTest, findMin_returns_minimum_value_when_value_is_present) {

	auto expectedMin = RandomValues::getRandomNumber<size_t>();
	tree.insert(expectedMin);

	auto min = tree.findMin();

	ASSERT_EQ(expectedMin, min);
}

TEST_F(BinarySearchTreeTest, findMin_returns_minimum_value_when_value_is_present_in_complex_tree) {

	auto randomValue = RandomValues::getRandomNumber<size_t>();
	auto expectedMin = randomValue - 2;
	tree.insert(randomValue - 1);
	tree.insert(randomValue + 2);
	tree.insert(expectedMin);
	tree.insert(randomValue);
	tree.insert(randomValue + 1);

	auto min = tree.findMin();

	ASSERT_EQ(expectedMin, min);
}

TEST_F(BinarySearchTreeTest, findMax_throws_logic_error_when_tree_is_empty) {

	ASSERT_THROW(tree.findMax(), logic_error);
}

TEST_F(BinarySearchTreeTest, findMax_returns_maximum_value_when_value_is_present) {

	auto expectedMax = RandomValues::getRandomNumber<size_t>();
	tree.insert(expectedMax);

	auto max = tree.findMax();

	ASSERT_EQ(expectedMax, max);
}

TEST_F(BinarySearchTreeTest, findMax_returns_maximum_value_when_value_is_present_in_complex_tree) {

	auto randomValue = RandomValues::getRandomNumber<size_t>();
	auto expectedMax = randomValue + 2;
	tree.insert(randomValue - 2);
	tree.insert(randomValue - 1);
	tree.insert(expectedMax);
	tree.insert(randomValue);
	tree.insert(randomValue + 1);

	auto max = tree.findMax();

	ASSERT_EQ(expectedMax, max);
}

TEST_F(BinarySearchTreeTest, trying_to_remove_element_of_empty_tree_does_not_crash) {

	ASSERT_NO_THROW(tree.remove(RandomValues::getRandomNumber<size_t>()));
}

TEST_F(BinarySearchTreeTest, removes_value_from_tree) {

	auto expectedValue = RandomValues::getRandomNumber<size_t>();
	tree.insert(expectedValue);

	tree.remove(expectedValue);

	ASSERT_FALSE(tree.contains(expectedValue));
}

TEST_F(BinarySearchTreeTest, removes_value_from_complex_tree_without_removing_other_values) {

	auto value1 = RandomValues::getRandomNumber<size_t>();
	auto value2 = RandomValues::getRandomNumber<size_t>();
	auto value3 = RandomValues::getRandomNumber<size_t>();
	auto value4 = RandomValues::getRandomNumber<size_t>();
	auto value5 = RandomValues::getRandomNumber<size_t>();
	tree.insert(value1);
	tree.insert(value3);
	tree.insert(value5);
	tree.insert(value2);
	tree.insert(value4);

	tree.remove(value2);

	ASSERT_FALSE(tree.contains(value2));
	ASSERT_TRUE(tree.contains(value1));
	ASSERT_TRUE(tree.contains(value3));
	ASSERT_TRUE(tree.contains(value4));
	ASSERT_TRUE(tree.contains(value5));
}

TEST_F(BinarySearchTreeTest, can_remove_value_when_value_is_not_the_smallest_value) {

	auto smallerValue = size_t{1};
	auto expectedValueToRemove = size_t{2};
	tree.insert(smallerValue);
	tree.insert(expectedValueToRemove);

	tree.remove(expectedValueToRemove);

	ASSERT_FALSE(tree.contains(expectedValueToRemove));
	ASSERT_TRUE(tree.contains(smallerValue));
}

TEST_F(BinarySearchTreeTest, can_remove_value_when_value_is_the_smallest_value) {

	auto biggerValue = size_t{2};
	auto expectedValueToRemove = size_t{1};
	tree.insert(biggerValue);
	tree.insert(expectedValueToRemove);

	tree.remove(expectedValueToRemove);

	ASSERT_FALSE(tree.contains(expectedValueToRemove));
	ASSERT_TRUE(tree.contains(biggerValue));
}

TEST_F(BinarySearchTreeTest, can_remove_value_when_value_has_two_children) {

	auto valueToRemove = size_t{2};
	auto leftChild = size_t{valueToRemove - 1};
	auto rightChild = size_t{valueToRemove + 1};
	tree.insert(valueToRemove);
	tree.insert(leftChild);
	tree.insert(rightChild);

	tree.remove(valueToRemove);

	ASSERT_FALSE(tree.contains(valueToRemove));
	ASSERT_TRUE(tree.contains(leftChild));
	ASSERT_TRUE(tree.contains(rightChild));
}

TEST_F(BinarySearchTreeTest, isEmpty_returns_true_when_tree_is_empty) {

	ASSERT_TRUE(tree.isEmpty());
}

TEST_F(BinarySearchTreeTest, isEmpty_returns_true_when_tree_is_empty_after_remove) {

	auto element = RandomValues::getRandomNumber<size_t>();
	tree.insert(element);

	tree.remove(element);

	ASSERT_TRUE(tree.isEmpty());
}

TEST_F(BinarySearchTreeTest, isEmpty_returns_false_when_tree_still_contains_elements) {

	auto element1 = RandomValues::getRandomNumber<size_t>();
	auto element2 = RandomValues::getRandomNumber<size_t>();
	tree.insert(element1);
	tree.insert(element2);

	tree.remove(element1);

	ASSERT_FALSE(tree.isEmpty());
}

TEST_F(BinarySearchTreeTest, makeEmpty_removes_all_elements) {

	auto element1 = RandomValues::getRandomNumber<size_t>();
	auto element2 = RandomValues::getRandomNumber<size_t>();
	tree.insert(element1);
	tree.insert(element2);

	tree.makeEmpty();

	ASSERT_TRUE(tree.isEmpty());
}

TEST_F(BinarySearchTreeTest, makeEmpty_has_no_effect_on_empty_tree) {

	tree.makeEmpty();

	ASSERT_TRUE(tree.isEmpty());
}

TEST_F(BinarySearchTreeTest, makeEmpty_is_idempotent) {

	tree.makeEmpty();
	tree.makeEmpty();

	ASSERT_TRUE(tree.isEmpty());
}

TEST_F(BinarySearchTreeTest, copy_constructor_copies_other_tree_content) {

	auto treeExpectedElements = {
		RandomValues::getRandomNumber<int>(),
		RandomValues::getRandomNumber<int>(),
		RandomValues::getRandomNumber<int>(),
		RandomValues::getRandomNumber<int>()
	};
	auto tree1 = BinarySearchTree<int, BinaryNode<int>>{};
	for (const auto& element : treeExpectedElements) {
		tree1.insert(element);
	}

	auto tree2 = tree1;

	for (const auto& expectedElement: treeExpectedElements) {
		ASSERT_TRUE(tree2.contains(expectedElement));
	}
}

TEST_F(BinarySearchTreeTest, assignment_operator_copies_other_tree_content) {

	auto treeExpectedElements = {
		RandomValues::getRandomNumber<int>(),
		RandomValues::getRandomNumber<int>(),
		RandomValues::getRandomNumber<int>(),
		RandomValues::getRandomNumber<int>()
	};
	auto tree1 = BinarySearchTree<size_t, BinaryNode<size_t>>{};
	for (const auto& element : treeExpectedElements) {
		tree1.insert(element);
	}

	tree = tree1;

	for (const auto& expectedElement: treeExpectedElements) {
		ASSERT_TRUE(tree.contains(expectedElement));
	}
}

TEST_F(BinarySearchTreeTest,
       assignment_operator_removes_previously_inserted_element_before_copying_content_of_other_tree) {

	auto expectedElement = RandomValues::getRandomNumber<size_t>();
	auto tree1 = BinarySearchTree<size_t, BinaryNode<size_t>>{};
	tree1.insert(expectedElement);
	auto unexpectedElement = RandomValues::getRandomNumber<size_t>();
	tree.insert(unexpectedElement);

	tree = tree1;

	ASSERT_FALSE(tree.contains(unexpectedElement));
}

TEST_F(BinarySearchTreeTest, prints_tree_in_symmetric_order) {

	auto expectedNode1 = size_t{7};
	auto expectedNode2 = size_t{2};
	auto expectedNode3 = size_t{8};
	auto expectedNode4 = size_t{1};
	auto expectedNode5 = size_t{4};
	auto expectedNode6 = size_t{3};
	auto expectedNode7 = size_t{5};
	tree.insert(expectedNode1);
	tree.insert(expectedNode2);
	tree.insert(expectedNode3);
	tree.insert(expectedNode4);
	tree.insert(expectedNode5);
	tree.insert(expectedNode6);
	tree.insert(expectedNode7);
	auto expectedTreeInSymmetricOrder = BinarySearchTreeExpectations::getExpectedTreeOutputFormat({
		                                                                                              expectedNode4,
		                                                                                              expectedNode2,
		                                                                                              expectedNode6,
		                                                                                              expectedNode5,
		                                                                                              expectedNode7,
		                                                                                              expectedNode1,
		                                                                                              expectedNode3
	                                                                                              });
	std::ostringstream output;

	tree.printTreeInSymmetricOrder(output);

	ASSERT_EQ(expectedTreeInSymmetricOrder, output.str());
}

TEST_F(BinarySearchTreeTest, prints_tree_in_pre_order) {

	auto expectedNode1 = size_t{7};
	auto expectedNode2 = size_t{2};
	auto expectedNode3 = size_t{8};
	auto expectedNode4 = size_t{1};
	auto expectedNode5 = size_t{4};
	auto expectedNode6 = size_t{3};
	auto expectedNode7 = size_t{5};
	tree.insert(expectedNode1);
	tree.insert(expectedNode2);
	tree.insert(expectedNode3);
	tree.insert(expectedNode4);
	tree.insert(expectedNode5);
	tree.insert(expectedNode6);
	tree.insert(expectedNode7);
	auto expectedTreeInPreOrder = BinarySearchTreeExpectations::getExpectedTreeOutputFormat({
		                                                                                              expectedNode1,
		                                                                                              expectedNode2,
		                                                                                              expectedNode4,
		                                                                                              expectedNode5,
		                                                                                              expectedNode6,
		                                                                                              expectedNode7,
		                                                                                              expectedNode3
	                                                                                              });
	std::ostringstream output;

	tree.printTreeInPreOrder(output);

	ASSERT_EQ(expectedTreeInPreOrder, output.str());
}

TEST_F(BinarySearchTreeTest, prints_tree_in_post_order) {

	auto expectedNode1 = size_t{7};
	auto expectedNode2 = size_t{2};
	auto expectedNode3 = size_t{8};
	auto expectedNode4 = size_t{1};
	auto expectedNode5 = size_t{4};
	auto expectedNode6 = size_t{3};
	auto expectedNode7 = size_t{5};
	tree.insert(expectedNode1);
	tree.insert(expectedNode2);
	tree.insert(expectedNode3);
	tree.insert(expectedNode4);
	tree.insert(expectedNode5);
	tree.insert(expectedNode6);
	tree.insert(expectedNode7);
	auto expectedTreeInPostOrder = BinarySearchTreeExpectations::getExpectedTreeOutputFormat({
		                                                                                        expectedNode4,
		                                                                                        expectedNode6,
		                                                                                        expectedNode7,
		                                                                                        expectedNode5,
		                                                                                        expectedNode2,
		                                                                                        expectedNode3,
		                                                                                        expectedNode1
	                                                                                        });
	std::ostringstream output;

	tree.printTreeInPostOrder(output);

	ASSERT_EQ(expectedTreeInPostOrder, output.str());
}

TEST_F(BinarySearchTreeTest, inserts_value_in_tree) {

	auto expectedValue = RandomValues::getRandomNumber<size_t>();

	tree.insert(expectedValue);

	ASSERT_TRUE(tree.contains(expectedValue));
}

TEST_F(BinarySearchTreeTest, trying_to_insert_a_value_that_already_exists_throws_logic_error) {

	auto expectedValue = RandomValues::getRandomNumber<size_t>();

	tree.insert(expectedValue);

	ASSERT_THROW(tree.insert(expectedValue), logic_error);
}

TEST_F(BinarySearchTreeTest, inserts_value_in_tree_using_std_move) {

	auto expectedValue = RandomValues::getRandomNumber<size_t>();

	tree.insert(std::move(expectedValue));

	ASSERT_TRUE(tree.contains(expectedValue));
}

TEST_F(BinarySearchTreeTest, trying_to_insert_a_value_using_std_move_that_already_exists_throws_logic_error) {

	auto expectedValue = RandomValues::getRandomNumber<size_t>();

	tree.insert(std::move(expectedValue));

	ASSERT_THROW(tree.insert(std::move(expectedValue)), logic_error);
}