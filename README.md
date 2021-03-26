# BinarySearchTree ADT (Abstract Data Tye)  
See https://github.com/AlexandreBrown/GTestSetupUsingExternalProject/ to setup GTest using ExternalProject instead of downloading the repo manually
## Setup after cloning :
1. Inside the project folder (eg: `IFT-2008-BinarySearchTreeADT/BinaryTrees`), create a directory called "lib". 
  - `IFT-2008-BinarySearchTreeADT/BinaryTrees/lib`

2. Inside this newly created directory (lib), put the GTest repository https://github.com/google/googletest.
    - Simply clone the repo using `git clone https://github.com/google/googletest` or download the zip by visiting the repo page.  
    - Ex: from `IFT-2008-BinarySearchTreeADT/BinaryTrees/lib` run `git clone https://github.com/google/googletest`
    
3. Create build directory from the root of the `IFT-2008-BinarySearchTreeADT/BinaryTrees` folder (eg: IFT-2008-BinarySearchTreeADT/BinaryTrees/build).
  - `mkdir build`
  - `cd build`
4. Try to cmake and make to ensure your project is well setup
  - In a terminal at the project build location, do the following commands:
    - `cmake ..`
    - `make`
  - If no error occured then everything should be setup correctly.  
