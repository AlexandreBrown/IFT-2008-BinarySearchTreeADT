# GTestSetup  
See https://github.com/AlexandreBrown/GTestSetupUsingExternalProject/ to setup GTest using ExternalProject instead of downloading the repo manually
## Setup after cloning :
1. Inside the project folder (eg: `GTestSetup/GTestSetup`), create a directory called "lib". 
  - `GTestSetup/GTestSetup/lib`

2. Inside this newly created directory (lib), put the GTest repository https://github.com/google/googletest.
    - Simply clone the repo using `git clone https://github.com/google/googletest` or download the zip by visiting the repo page.  
    - Ex: from `GTestSetup/GTestSetup/lib` run `git clone https://github.com/google/googletest`
    
3. Create build directory from the root of the nested GTestSetup folder (eg: GTestSetup/GTestSetup/build).
  - `mkdir build`
  - `cd build`
4. Try to cmake and make to ensure your project is well setup
  - In a terminal at the project build location, do the following commands:
    - `cmake ..`
    - `make`
  - If no error occured then everything should be setup correctly.  

## Main setup that was done to achieve this project (from scratch) :  

1. Inside the project folder, create a directory called "lib".

2. Inside this newly created directory (lib), put the googletest content form the official repository https://github.com/google/googletest.
    - Simply clone the repo using `git clone https://github.com/google/googletest` or download the zip by visiting the repo page.

3. Inside the `CMakeLists.Txt` -  that is located insise your Clion project -
you have to put:
```
add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)
include_directories(lib/googletest/googlemock/include)
target_link_libraries(GTestSetup_test gtest gtest_main pthread)
```  
4. Reload your CMakeLists (IDE should propose you to reload it)

5. Create build directory from the root of the nested GTestSetup folder (eg: `GTestSetup/GTestSetup/build`).
  - `mkdir build`
  - `cd build`

6. Try to cmake and make to ensure your project is well setup
  - In a terminal at the project build location, do the following commands:
    - `cmake ..`
    - `make`
  - If no error occured then everything should be setup correctly.

7. Start writing unit tests using GTest and make sure to add the test files to the test executable in your `CMakeLists.txt`
  - See `MyClassTest.cpp` for a test class sample  
  - See the `CMakeLists` for more details on how to define your test executable

Note: Some other config is needed like setting executable for your app etc, take a look at the CMakeLists for more details.
    
## Running the tests  
### Using CLion IDE
- To run the all the tests inside `MyClassTest` you can use the run button at the test fixture or test name  
  - You can also right click a folder with tests and run all the tests or you can run individual tests using the green run button  
  - You can also run tests from the bottom pane that opens up after runnign tests initially  
   -  ![Run Tests using IDE](https://camo.githubusercontent.com/f909220c3da451214c25555afed0b12dcf538f667ec6aba16661e0164ffe6046/68747470733a2f2f692e6962622e636f2f384d386d46434e2f53637265656e73686f742d66726f6d2d323032312d30312d32352d32332d33342d30362e706e67)
   -  ![Run Tests using IDE](https://i.ibb.co/X2TLqRw/Screenshot-from-2021-01-26-01-15-28.png)
  - Using the IDE to run tests might provide better feedback than other alternatives (subjective)  
      
### Using CTest  
- go into `/build` and run `make && make test`, this will recompile your poject and run all the tests using CTest and give you a command-line print of the result.
  -  ![Run Tests using IDE](https://i.ibb.co/XjWWgxY/Screenshot-from-2021-01-26-01-17-25.png)
  
## Known issues and workaround  
### Global fixes to try :
- Delete `/build` folder and recreate/populate it using `mkdir build` + `cmake ..` + `make`  
- CLion : File->Invalidate cache & restart
#### Cannot run tests using play button :
- Try to right click your test class from the file explorer (inside CLion) and click "Run all in YourClassTest.cpp"  
- If it doesn't work try deleting the `/build` folder and recreating it and repopulating it using steps describe in _Global fixes to try_  
- If it doesn't work try running your tests using `make test` from `/build` folder
#### Cannot find <gtest/gtest.h> / Don't have play button to run test inside my test class  :
- Try deleting `/build` and recreating/populating it using steps describe in _Global fixes to try_  
#### Code change is not reflected (test should fail but passes etc) : 
- Try re-running the test, maybe it was ran with outdated code or try `make && make test` from `/build`  
#### Could not build /cmake-build-debug does not exist :  
- Try File->Invalidate cache & restart
