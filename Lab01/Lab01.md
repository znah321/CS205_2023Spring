### cout格式化输出
> 参考：[http://c.biancheng.net/view/7578.html](http://c.biancheng.net/view/7578.html)

C++中，cout的输出格式可以通过ostream类中的成员方法来更改，常用的为：

| `flags(fmtfl)` | 将目前的格式状态**全部替换**为`fmtfl`（`fmtfl`可以表示一种格式，也可以表示多种格式） |
| --- | --- |
| `precision(n)` | 设置输出浮点数的精度为`n` |
| `setf(fmtfl, mask)` | 在当前格式的基础上，**追加**`fmtfl`格式，并删除`mask`格式。其中，`mask`参数可以省略 |
| `unsetf(mask)` | 在当前格式的基础上，删除`mask`格式 |

对于`flags`函数的参数`fmtfl`，有以下可选的值：

| `ios::boolapha` | 把 true 和 false 输出为字符串 |
| --- | --- |
| `ios::left` | 输出数据在本域宽范围内向左对齐 |
| `ios::right` | 输出数据在本域宽范围内向右对齐 |
| `ios::internal` | 数值的符号位在域宽内左对齐，数值右对齐，中间由填充字符填充 |
| `ios::dec` | 设置整数的基数为 10 |
| `ios::oct` | 设置整数的基数为 8 |
| `ios::hex` | 设置整数的基数为 16 |
| `ios::showbase` | 强制输出整数的基数（八进制数以 0 开头，十六进制数以 0x 打头） |
| `ios::showpoint` | 强制输出浮点数的小点和尾数 0 |
| `ios::uppercase` | 在以科学记数法格式 E 和以十六进制输出字母时以大写表示 |
| `ios::showpos` | 对正数显示“+”号 |
| `ios::scientific` | 浮点数以科学记数法格式输出 |
| `ios::fixed` | 浮点数以定点格式（小数形式）输出 |
| `ios::unitbuf` | 每次输出之后刷新所有的流 |

本次实验要求输出结果保留小数点后两位数字，需要用到`ios::fixed`参数。

1. 首先指定`cout`的输出格式，使用`flags()`或`setf()`均可（以`setf()`为例）；
2. 然后使用`precision()`指定输出浮点数的精度为2位。
```cpp
#include <iostream>

using namespace std;

int main()
{	
    float a = 0.1f;
    float b = 0.2f;
    float c = 0.3f;
    
    cout.setf(ios::fixed);
    cou.precision(2);
    cout << "Formatting output with cout:" << endl;
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;

    return 0;
}
```
对于`precision(n)`函数需要注意的是，在使用非`fixed`且非`scientific`方式输出的情况下，`n`即为有效数字最多的位数，如果有效数字位数超过`n`，则小数部分四舍五人，或自动变为科学计数法输出并保留一共`n`位有效数字；在使用 fixed 方式和 scientific 方式输出的情况下，n 是小数点后面应保留的位数。
