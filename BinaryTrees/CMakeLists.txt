cmake_minimum_required(VERSION 3.5)
project(BinaryTrees)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main/BinarySearchTree.tpp
        src/main/BinarySearchTree.h
        src/main/BinaryNode.h src/main/AvlNode.h src/main/AvlTree.h src/main/AvlTree.tpp)

add_executable(${PROJECT_NAME} src/main/main.cpp ${SOURCE_FILES})

# Testing flags
option(BUILD_TESTING "build unit tests" ON)

if (BUILD_TESTING)

    # GTest
    add_subdirectory(lib/googletest)
    include_directories(lib/googletest/googletest/include)
    include_directories(lib/googletest/googlemock/include)


    # Not mandatory but nice tool
    enable_testing() #Enables CTest which can run all our tests via command-line (use command : "make" in /build to apply changes made to code then run "make test")

    set(TEST_SOURCE_FILES src/test/BinarySearchTreeTest.cpp
            src/test/BinarySearchTreeTest.cpp
            src/test/AvlTreeTest.cpp
            src/test/BinarySearchTreeExpectations.h
            src/test/utils/RandomValues.h)
    set(TESTABLE_SOURCE_FILES src/main/BinarySearchTree.tpp
            src/main/BinarySearchTree.h
            src/main/BinaryNode.h
            src/main/AvlNode.h
            src/main/AvlTree.h
            src/main/AvlTree.tpp) # Note that we don't need to include main.cpp from production because we don't want to test our entry point

    add_executable(${PROJECT_NAME}_test ${TESTABLE_SOURCE_FILES} ${TEST_SOURCE_FILES})
    add_test(${PROJECT_NAME}_test ${PROJECT_NAME}_test) # If we don't add this, CTest will not find our tests when doing: make test

    # Executes our executable which contains our production source files and our test files using GTest main function
    # Not using gtest_main is possible but we would need to write the test main function ourselves, see https://gist.githubusercontent.com/mawenbao/9223908/raw/10fd68efe5565da7b7e79dcc5fd9ed314bcb3aed/main.cpp for an implementation
    target_link_libraries(${PROJECT_NAME}_test gtest gtest_main pthread)
endif ()

