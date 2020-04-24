/*
本课程说明网址
https://www.zhihu.com/question/389457315/answer/1170354190

本课程视频页面
https://www.bilibili.com/video/BV1rt4y127ak/

由于大作业的要求，我们这些程序都会使用 C++ 11 的标准来编写


前两个作业，我们使用在线编译器来完成，省却配置环境的时间
按照以下步骤使用在线编译器
1，打开网站 https://www.tutorialspoint.com/compile_cpp11_online.php
2，左侧是代码输入框，删除所有内容
3，把本文件完整地复制到左侧代码输入框中
4，点击页面左上角的 Execute 按钮即可运行程序并在右侧显示结果


在 C++ 中，程序的入口是强制的 int main() 函数
它在本文件的末尾


C++ 中需要包含头文件来使用一些库
vector 是数组功能
iostream 是输入输出功能
*/
#include <vector>
#include <iostream>

/*
你或许会在许多地方看到反对 using namespace std; 的声音
要求显式地使用 using std::out; 这样的语句
但实际上两派都有各自的理由，这里只陈述，不解释不站队
总的来说，在 .cpp 文件中用 using namespace std; 是大多数书上会教的方法
因此这里就这样用

对于不了解 C++ 的同学，这里稍作解释
C++ 的标准库的全程大概如下
std::cout
std::endl
std::string
...
这样写就太长了，于是用下面的名字来省略 std:: 这个前缀名字
using namespace std;
*/

using namespace std;

/*
_print 和 log 这两个函数
现在不需要看懂写法
暂时只需当作工具使用便是
原本在 C++ 中需要使用 cout 来输出，如下
cout << "hello" << " " << "world" << endl;

但是这样实在不是很方便，且你以后会写很多门其他语言
每门语言都有各自不同的输出方式
故而我们统一封装一个 log 函数来输出，用法如下
log("hello", " ", "world");

这也是在《〖快编程〗的免费编程入门课》中教的方式
https://www.bilibili.com/video/av82386417

这份作业要求你有一门语言的编程基础
如果没有，建议观看上面的《〖快编程〗的免费编程入门课》来完成这个基础
它一共有 5 节
*/
template <class T>
void _print(T arg)
{
    cout << arg << " ";
}

template <class... Args>
void log(Args... args)
{
    int arr[] = {(_print(args), 0)...};
    cout << endl;
}

// 作业正式开始
//
// 例子 1
// 求数组的和
/*
在 C++ 中，函数必须标注返回值类型，变量、参数必须标注类型
sum 函数是一个返回 float 类型的函数
它的参数名是 array，类型是 vector<float> &
其中 vector<float> 表示类型是 “存储 float 元素的数组”
& 符号表示参数 array 是一个 “引用”

“引用” 是一个 C++ 中的新概念，它实际上是一个 C 语言中指针的语法糖
我们暂时不用关心这个，在后续的作业中会学到它
现在记住所有 vector 类型都使用 & 来修饰变量即可
 */
float sum(vector<float> &array)
{
    // 先设置一个变量 s 用来存数组的和
    float s = 0;
    // .size() 函数的返回值是 size_t
    // 所以这里的变量 i 也是 size_t（你可以当作 int）
    size_t i = 0;
    // array.size() 求得 vector 的大小
    while (i < array.size())
    {
        float n = array[i];
        s = s + n;
        i = i + 1;
    }
    return s;
}

/*
按照《〖快编程〗的免费编程入门课》的标准
我们这里提供一个简易的测试方案（功能更强的测试方案在后续的作业中会给出）

ensure 函数第一个参数
如果为 true 则会输出 “测试成功”
如果为 false 则会输出 message
这样我们就可以知道是否测试成功，以及具体哪个测试失败了

对每一个函数，都应编写一个 test 函数，这样可以提高开发效率
*/
void ensure(bool condition, const string &message)
{
    if (condition)
    {
        log("测试成功");
    }
    else
    {
        log(message);
    }
}

bool floatEqual(float a, float b)
{
    // 这里的 delta 变量的类型我们用了 auto
    // 这是一个 C++ 11 的新特性
    // 它的作用是根据变量的值自动推导变量的类型
    // delta 的值是 0.00001 所以它会是 float 类型
    // 仅作介绍
    auto delta = 0.00001;
    // 如《〖快编程〗的免费编程入门课》 所述
    // 计算机对浮点数的比较要用这样的方式
    return a - b < delta && b - a < delta;
}

void testSum(void)
{
    vector<float> v1 = {1, 2, 3, 4};
    float s1 = sum(v1);
    ensure(floatEqual(s1, 10), "sum test error 1");
    //
    vector<float> v2 = {1, 2, 3, 4, 5, 6};
    float s2 = sum(v2);
    ensure(floatEqual(s2,21), "sum test error 2");
}

// 作业 1
// 参数是一个只包含数字的 array
// 求 array 的乘积
// 函数定义如下

// 提示：
//     通过遍历数组，然后累乘的方式计算数组的乘积，参考例子 1
//
// 分步提示：
//     1. 先设置一个变量 s 用来存数组的乘积，初始值为 1
//     2. 遍历数组，用变量 n 保存元素的值
//     3. 累乘每次的变量 n 到变量 s
//     4. 循环结束后，变量 s 里面存的是数组中所有元素的乘积
//     5. 返回变量 s（很重要，一定要 return s）

float product(vector<float> &array)
{
    float s = 1;
    for (int n = 0; n < array.size(); n++)
    {
        s *= array[n];
    }
    return s;
}

void testProduct(void)
{
    vector<float> v1 = {1, 2, 3, 4};
    float s1 = product(v1);
    ensure(floatEqual(s1,24), "product test error 1");

    vector<float> v2 = {1, 2, 3, 4, 5, 6};
    float s2 = product(v2);
    ensure(floatEqual(s2, 720), "product test error 2");
}

// 作业 2
// 返回一个数字的绝对值
// 函数定义如下
//
// 参考入门课求绝对值的代码来实现
// 1. 如果 n < 0，就把 n 的值赋值成 -n
// 2. 返回 n 的值（很重要，一定要 return n）
float abs1(float n)
{
    if (n < 0)
    {
        n = -n;
    }
    return n;
}

void testAbs(void)
{
    float v1 = 10;
    float s1 = abs1(v1);
    ensure(floatEqual(s1,10), "abs test error 1");

    float v2 = -12;
    float s2 = abs1(v2);
    ensure(floatEqual(s2, 12), "abs test error 2");
}

// 作业 3
// 参数是一个只包含数字的数组
// 求 数组 中所有数字的平均数
//
// 函数定义如下
// 求数组的平均数就是先求出数组中元素的总和，然后除以数组的长度（即元素的个数）
// 1. 使用例子 1 中的 sum 函数来计算数组中所有元素的总和
// 2. 使用 size 函数计算出数组中元素的个数
// 3. 使用数组中元素的总和除以数组中元素的个数，得到平均数
// 4. 返回平均数
float average(vector<float> &array)
{
    float average = 0;
    for (int n = 0; n < array.size(); n++)
    {
        average += array[n];
    }
    average /= array.size();
    return average;
}

void testAverage(void)
{
    vector<float> v1 = {1, 2, 3, 4};
    float s1 = average(v1);
    ensure(floatEqual(s1, 2.5), "average test error 1");

    vector<float> v2 = {1, 2, 3, 4, 5};
    float s2 = average(v2);
    ensure(floatEqual(s2, 3), "average test error 2");
}

// 作业 4
// 参数是一个只包含数字的 数组
// 求 数组 中最小的数字
//
// 先选数组中的第一个元素作为 s 的初始值
// 然后遍历数组，将每一个元素都与初始值比较
// 如果元素的值比初始值小，就把那个元素设置为 s 的值
// 最后返回 s 的值
// 1. 将数组中第一个元素的值赋值给 s 作为初始值
// 2. 遍历数组，用变量 n 保存元素的值
// 3. 比较 n 与 s 的值，如果 n < s，就把 n 的值赋值给 s
// 4. 循环结束后，变量 s 里面存的是数组中最小的数字
// 5. 返回变量 s（很重要，一定要 return s）
float min(vector<float> &array)
{
    int s = array[0];
    for (int n = 1; n < array.size(); n++)
    {
        if (s >= array[n])
        {
            s = array[n];
        }
    }
    return s;
}

void testMin(void)
{
    vector<float> v1 = {11, 20, 3, 45};
    float s1 = min(v1);
    ensure(floatEqual(s1, 3), "min test error 1");

    vector<float> v2 = {11, 2, 1, 41, 3};
    float s2 = min(v2);
    ensure(floatEqual(s2, 1), "min test error 2");
}

// 作业 5
// 参数是一个数字 n
// 返回以下序列的结果
// 1 - 2 + 3 - 4 + 5 ... n

// 首先可以把序列看成是一个数组，这样就可以循环 n 次。
// 观察序列可以发现一个规律：奇数的时候是加，偶数的时候是减
//
// 1. 先设置一个变量 s 用来存序列的和，初始值为 0
// 2. 循环 n 次，从 1 开始，到 n + 1 结束，即包括 n 但是不包括 n + 1
// 3. 判断每次循环的值。如果是奇数，累加这个数到 s 上，如果是偶数，累减这个数到 s 上
// 4. 循环结束后，变量 s 里面存的是序列的和
// 5. 返回变量 s（很重要，一定要 return s）
int sum1(int n)
{
    int s = 0;
    for (int i = 1; i < n + 1; i++)
    {
        if (i % 2 == 0)
        {
            s -= i;
        }
        else
        {
            s += i;
        }
    }
    return s;
}

void testSum1(void)
{
    int v1 = 5;
    int s1 = sum1(v1);
    ensure(s1 == 3, "sum1 test error 1");
    int v2 = 8;
    int s2 = sum1(v2);
    ensure(s2 == -4, "sum1 test error 2");
}
// 作业 6
// 参数是一个数字 n
// 返回以下序列的结果
// 1 + 2 - 3 + 4 - ... n
// 还是把序列看成是一个数组，不过从第二个元素（也就是 2 开始遍历）这样就可以循环 n - 1 次
//
// 1. 先设置一个变量 s 用来存序列的和，初始值为 1，这样就可以从 2 开始计算循环了
// 2. 循环 n - 1 次，从 2 开始，到 n 结束（包括 n）
// 3. 判断每次循环的值。
//    如果是第一个数字（这里是从 2 开始的），观察式子的规律，从 2 开始之后，当一个数字是奇数时，就是减去这个数（比如说 3 5 7 9...）。
//    当一个数字是偶数时，就是加上这个数（比如 2 4 6 8...）。
// 4. 循环结束后，变量 s 里面存的是序列的和
// 5. 返回变量 s（很重要，一定要 return s）
int sum2(int n)
{
    int s = 1;
    for (int i = 2; i < n + 1; i++)
    {
        if (i % 2 == 0)
        {
            s += i;
        }
        else
        {
            s -= i;
        }
    }
    return s;
}

void testSum2(void)
{
    int v1 = 5;
    int s1 = sum2(v1);
    ensure(s1 == -1, "sum2 test error 1");
    int v2 = 8;
    int s2 = sum2(v2);
    ensure(s2 == 6, "sum2 test error 2");
}
// 作业 7
//
// 实现 fac 函数
// 接受一个参数 n
// 返回 n 的阶乘, 1 * 2 * 3 * ... * n
// 计算从 1 到 n 的阶乘，重复了 n 次，所以可以用循环来处理
//
// 1. 先设置一个变量 s 用来存阶乘，初始值为 1
// 2. 用循环把 1 到 n 的数字相乘保存到 s 中
// 3. 循环结束后，变量 s 里面存的是从 1 到 n 的阶乘, 返回变量 s（很重要，一定要 return s）
int fac(int n)
{
    int s = 1;
    for (int i = 1; i < n + 1; i++)
    {
        s *= i;
    }
    return s;
}

void testFac(void)
{
    int v1 = 5;
    int s1 = fac(v1);
    ensure(s1 == 120, "fac test error 1");
    int v2 = 8;
    int s2 = fac(v2);
    ensure(s2 == 40320, "fac test error 2");
}
//
void test()
{
    testSum();
    testProduct();
    testAbs();
    testAverage();
    testMin();
    testSum1();
    testSum2();
    testFac();
}

// main 函数的参数是规定，复制粘贴即可
int main(int argc, const char *argv[])
{
    test();
    return 0;
}