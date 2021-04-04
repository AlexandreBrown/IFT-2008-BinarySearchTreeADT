set(TEST_SOURCE_FILES BinarySearchTreeTest.cpp
        BinarySearchTreeTest.cpp
        AvlTreeTest.cpp
        BinarySearchTreeExpectations.h
        utils/RandomValues.h)
set(TESTABLE_SOURCE_FILES ../main/BinarySearchTree.tpp
        ../main/BinarySearchTree.h
        ../main/BinaryNode.h
        ../main/AvlNode.h
        ../main/AvlTree.h
        ../main/AvlTree.tpp) # Note that we don't need to include main.cpp from production because we don't want to test our entry point

add_executable(${PROJECT_NAME}_test ${TESTABLE_SOURCE_FILES} ${TEST_SOURCE_FILES})
add_test(${PROJECT_NAME}_test ${PROJECT_NAME}_test) # If we don't add this, CTest will not find our tests when doing: make test

# Executes our executable which contains our production source files and our test files using GTest main function
# Not using gtest_main is possible but we would need to write the test main function ourselves, see https://gist.githubusercontent.com/mawenbao/9223908/raw/10fd68efe5565da7b7e79dcc5fd9ed314bcb3aed/main.cpp for an implementation
target_link_libraries(${PROJECT_NAME}_test gtest gtest_main pthread)