#include "gtest/gtest.h"
#include "../main/AvlTree.h"
#include "BinarySearchTreeExpectations.h"
#include "utils/RandomValues.h"

using std::to_string;
using Random::RandomValues;

namespace {
	class AvlTreeTest : public testing::Test {
		public:

			BinarySearchTree<int, AvlNode<int>>* tree;

		protected:
			void SetUp() override {
				Test::SetUp();
				tree = new AvlTree<int>{};
			}

			void TearDown() override {
				Test::TearDown();
				delete tree;
			}
	};
}

TEST_F(AvlTreeTest, inserts_element_when_insertion_does_not_make_tree_imbalance) {

	auto expectedElement = RandomValues::getRandomNumber<int>();

	tree->insert(expectedElement);

	ASSERT_TRUE(tree->contains(expectedElement));
}

TEST_F(AvlTreeTest, inserts_element_when_insertion_using_std_move_does_not_make_tree_imbalance) {

	auto expectedElement = RandomValues::getRandomNumber<int>();

	tree->insert(std::move(expectedElement));

	ASSERT_TRUE(tree->contains(expectedElement));
}

TEST_F(AvlTreeTest, handles_zig_zig_left_single_rotation_after_insertion) {

	auto element1 = 10;
	tree->insert(element1);
	auto element2 = 5;
	tree->insert(element2);
	auto element3 = 20;
	tree->insert(element3);
	auto element4 = 4;
	tree->insert(element4);
	auto element5 = 3;
	std::ostringstream balancedTree;
	auto expectedBalancedTreeInPreOrder = BinarySearchTreeExpectations::getExpectedTreeOutputFormat({
		                                                                                                element1,
		                                                                                                element4,
		                                                                                                element5,
		                                                                                                element2,
		                                                                                                element3
	                                                                                                });

	tree->insert(element5);

	tree->printTreeInPreOrder(balancedTree);
	ASSERT_EQ(expectedBalancedTreeInPreOrder, balancedTree.str());
}

TEST_F(AvlTreeTest, handles_zig_zag_left_double_rotations_after_insertion) {

	auto element1 = 10;
	tree->insert(element1);
	auto element2 = 5;
	tree->insert(element2);
	auto element3 = 15;
	tree->insert(element3);
	auto element4 = 2;
	tree->insert(element4);
	auto element5 = 7;
	tree->insert(element5);
	auto element6 = 9;
	std::ostringstream balancedTree;
	auto expectedBalancedTreeInPreOrder = BinarySearchTreeExpectations::getExpectedTreeOutputFormat({
		                                                                                                element5,
		                                                                                                element2,
		                                                                                                element4,
		                                                                                                element1,
		                                                                                                element6,
		                                                                                                element3
	                                                                                                });

	tree->insert(element6);

	tree->printTreeInPreOrder(balancedTree);
	ASSERT_EQ(expectedBalancedTreeInPreOrder, balancedTree.str());
}

TEST_F(AvlTreeTest, handles_zig_zig_right_single_rotation_after_insertion) {

	auto element1 = 10;
	tree->insert(element1);
	auto element2 = 5;
	tree->insert(element2);
	auto element3 = 15;
	tree->insert(element3);
	auto element4 = 12;
	tree->insert(element4);
	auto element5 = 20;
	tree->insert(element5);
	auto element6 = 30;
	std::ostringstream balancedTree;
	auto expectedBalancedTreeInPreOrder = BinarySearchTreeExpectations::getExpectedTreeOutputFormat({
		                                                                                                element3,
		                                                                                                element1,
		                                                                                                element2,
		                                                                                                element4,
		                                                                                                element5,
		                                                                                                element6
	                                                                                                });

	tree->insert(element6);

	tree->printTreeInPreOrder(balancedTree);
	ASSERT_EQ(expectedBalancedTreeInPreOrder, balancedTree.str());
}

TEST_F(AvlTreeTest, handles_zig_zag_right_double_rotations_after_insertion) {

	auto element1 = 10;
	tree->insert(element1);
	auto element2 = 5;
	tree->insert(element2);
	auto element3 = 20;
	tree->insert(element3);
	auto element4 = 15;
	tree->insert(element4);
	auto element5 = 30;
	tree->insert(element5);
	auto element6 = 12;
	std::ostringstream balancedTree;
	auto expectedBalancedTreeInPreOrder = BinarySearchTreeExpectations::getExpectedTreeOutputFormat({
		                                                                                                element4,
		                                                                                                element1,
		                                                                                                element2,
		                                                                                                element6,
		                                                                                                element3,
		                                                                                                element5
	                                                                                                });

	tree->insert(element6);

	tree->printTreeInPreOrder(balancedTree);
	ASSERT_EQ(expectedBalancedTreeInPreOrder, balancedTree.str());
}

TEST_F(AvlTreeTest, handles_zig_zig_right_single_rotation_after_removal) {

	auto element1 = 15;
	tree->insert(element1);
	auto element2 = 10;
	tree->insert(element2);
	auto element4 = 20;
	tree->insert(element4);
	auto element3 = 7;
	tree->insert(element3);
	auto element5 = 30;
	tree->insert(element5);
	auto element6 = 40;
	tree->insert(element6);
	std::ostringstream balancedTree;
	auto expectedBalancedTreeInPreOrder = BinarySearchTreeExpectations::getExpectedTreeOutputFormat({
		                                                                                                element1,
		                                                                                                element2,
		                                                                                                element5,
		                                                                                                element4,
		                                                                                                element6
	                                                                                                });

	tree->remove(element3);

	tree->printTreeInPreOrder(balancedTree);
	ASSERT_EQ(expectedBalancedTreeInPreOrder, balancedTree.str());
}

TEST_F(AvlTreeTest, handles_zig_zig_left_single_rotation_after_removal) {

	auto element1 = 15;
	tree->insert(element1);
	auto element2 = 10;
	tree->insert(element2);
	auto element3 = 20;
	tree->insert(element3);
	auto element4 = 7;
	tree->insert(element4);
	auto element5 = 30;
	tree->insert(element5);
	auto element6 = 3;
	tree->insert(element6);
	std::ostringstream balancedTree;
	auto expectedBalancedTreeInPreOrder = BinarySearchTreeExpectations::getExpectedTreeOutputFormat({
		                                                                                                element1,
		                                                                                                element4,
		                                                                                                element6,
		                                                                                                element2,
		                                                                                                element3
	                                                                                                });

	tree->remove(element5);

	tree->printTreeInPreOrder(balancedTree);
	ASSERT_EQ(expectedBalancedTreeInPreOrder, balancedTree.str());
}

TEST_F(AvlTreeTest, handles_zig_zag_right_double_rotations_after_removal) {

	auto element1 = 15;
	tree->insert(element1);
	auto element2 = 10;
	tree->insert(element2);
	auto element3 = 20;
	tree->insert(element3);
	auto element4 = 18;
	tree->insert(element4);
	std::ostringstream balancedTree;
	auto expectedBalancedTreeInPreOrder = BinarySearchTreeExpectations::getExpectedTreeOutputFormat({
		                                                                                                element4,
		                                                                                                element1,
		                                                                                                element3
	                                                                                                });

	tree->remove(element2);

	tree->printTreeInPreOrder(balancedTree);
	ASSERT_EQ(expectedBalancedTreeInPreOrder, balancedTree.str());
}

TEST_F(AvlTreeTest, handles_zig_zag_left_double_rotations_after_removal) {

	auto element1 = 15;
	tree->insert(element1);
	auto element2 = 10;
	tree->insert(element2);
	auto element3 = 17;
	tree->insert(element3);
	auto element4 = 12;
	tree->insert(element4);
	std::ostringstream balancedTree;
	auto expectedBalancedTreeInPreOrder = BinarySearchTreeExpectations::getExpectedTreeOutputFormat({
		                                                                                                element4,
		                                                                                                element2,
		                                                                                                element1,
	                                                                                                });

	tree->remove(element3);

	tree->printTreeInPreOrder(balancedTree);
	ASSERT_EQ(expectedBalancedTreeInPreOrder, balancedTree.str());
}