## CMake
### 基本结构：
```cmake
cmake_minimum_required(VERSION 3.10.2)

project(main)

add_executable(main exp1.cpp)
```

`cmake_minimum_required()`：指定CMake要求的最低版本，可在终端输入`cmake --version`查看电脑上CMake的版本。<br />`project()`：定义工程的名称。<br />`add_executable(<name> source1 [source2 ...])`：使用指定的源文件`source`添加一个可执行文件`<name>`到工程中。其中，`<name>`为可执行文件的名称，不需要和`project`里面写成一样；`source`为对应的源文件，可写一个或者多个。<br />在终端输入`cmake .`在当前路径下生成Makefile，`.`表示在当前路径生成。后续操作与Makefile的操作相同。<br />如果想使用一个CMakeLists.txt同时生成多个可执行文件，直接在后面多写几个`add_executable()`就可以。
```cmake
cmake_minimum_required(VERSION 3.10.2)

project(main)

add_executable(demo1 exp1.cpp)
add_executable(demo2 exp2.cpp)
add_executable(demo3 exp3.cpp)
```
### 工程下存在多个源文件
```cmake
./CMakeDemo2
  	|
  	+--- main.cpp
  	|
  	+--- function.cpp
  	|
  	+--- function.h
```
相应的CMakeLists.txt
```cmake
cmake_minimum_required(VERSION 3.10.2)

project(CMakeDemo2)

aux_source_directory(src DIR_SRC)

add_executable(CMakeDemo2 ${DIR_SRC})
```
`aux_source_directory(<dir> <variable>)`：在指定的路径`<dir>`找到所有的源文件，并将结果存储到变量`<variable>`中。
### 源文件存在于不同的路径
```cmake
./CMakeDemo2
  	|
  	+--- src/
  	|			|
  	|			+--- main.cpp
  	|			+--- function.cpp
  	|
  	+--- include/
  	|			|
					+--- function.h
```
```cmake
cmake_minimum_required(VERSION 3.10.2)


project(CMakeDemo3)


aux_source_directory(src DIR_SRCS)


include_directories(include)


add_executable(CMakeDemo3 ${DIR_SRCS})
```
`include_directories()`：添加头文件。
## Exercise
### Exercise 2
输出结果：
```cpp
a = 0x7ffe7b7307f0
p = 0x7ffe7b7307f4
y = 19

b = 0x7ffe7b730810
b + 4 = 0x7ffe7b730820
ptr = 0x7ffe7b730824
2, 5
```
> 参考：[https://blog.csdn.net/u011617742/article/details/67633323](https://blog.csdn.net/u011617742/article/details/67633323)

分析：<br />`p = &a[1]`表示指针`p`指向数组`a`的第2个元素；<br />for循环表示把数组`a`的第2、3、4个加到`y`上；<br />第16行，`&a`是对数组取地址，其类型为`int [5]`,所以 `&a + 1`，其实是相当于`a + 5`，相当于在地址上加`sizeof(int [5])`。
### Exercise 3
输出结果：
```cpp
*p++ = 15, *p = 17
to programming.
*pm = af67
```
`a`是一个一维数组，数组中每个元素都是一个长度为4的数组。因此`*p = *(a+1)`实际上偏移了4个元素，`p`指向的是9。然后，`p += 3`再让`p`偏移3个元素，指向`15`；`*p++`再偏移一个元素，指向17。<br />long类型有8个字节，因此指针`q`偏移一个元素实际上偏移了8个字节，指向字符串中的t。<br />int类型有4个字节，而short类型只有2个字节，因此将int类型转为short类型时高16位丢失，只保留低16位。
