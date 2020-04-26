#include <vector>
#include <iostream>
/*
作业 2

本课程说明网址
https://www.zhihu.com/question/389457315/answer/1170354190

本课程视频页面
https://www.bilibili.com/video/BV1rt4y127ak/
*/

using namespace std;

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
// 本次作业用到了 string, 主要是...
// 0, 用下标引用字符串
// 2, 循环
// 3, 选择 (也就是 if)

// ======
//
// 定义我们用于测试的函数
// 上个作业已经解释过这个用法，故这里不重复介绍

void ensure(bool condition, const string &message)
{
    if (condition)
    {
        log("||| 测试成功");
    }
    else
    {
        log("*** 测试失败: ", message);
    }
}

// 作业 1
// 实现步骤
//     1. 通过遍历字符串 s1，取出循环的元素与 s2 判断，如果某次循环的元素与 s2 相等，就让 index 等于 i，并且结束循环。
//     2. 如果循环结束后都没有找到与 s2 相等的元素，就让 index 的值为 -1。
//     注意，如果 s2 在 s1 中出现了多次，只计算第一次出现的位置。

int find(const string &s1, char s2)
{
    // 返回 s2 在 s1 中的下标, 从 0 开始, 如果不存在则返回 -1
    size_t i = 0;
    int index = -1;
    while (i < s1.size())
    {
        if (s2 == s1[i])
        {
            index = i;
            break;
        }
        i = i + 1;
    }
    return index;
}

// 测试函数
void testFind()
{
    ensure(find("hello", 'a') == -1, "find 1");
    ensure(find("hello", 'e') == 1, "find 2");
    ensure(find("hello", 'l') == 2, "find 3");
}

// 下面给出一个例子作为后面作业的参考
// 返回字符串的小写形式的函数
// 注意, 这里假设了 s 字符串全是大写字母
string
lowercase(const string &s)
{
    // 这里是两个字符串, 包含了大写字母和小写字母
    // 用 const 修饰是因为它们并不会被修改
    const string lower = "abcdefghijklmnopqrstuvwxyz";
    const string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // 初始化一个空字符串
    string result = "";
    size_t i = 0;
    while (i < s.size())
    {
        // 注意, 这个 find 已经帮你实现了
        int index = find(upper, s[i]);
        // 字符串可以用加号拼接, 不明白可以 log 一下
        result += lower[index];
        i += 1;
    }
    return result;
}

// 测试函数
void testLowercase()
{
    ensure(lowercase("HELLO") == "hello", "lowercase 1");
    ensure(lowercase("GUA") == "gua", "lowercase 2");
}

// 作业 2
//
// 定义一个函数
// 参数是一个字符串 s
// 返回大写后的字符串
// 注意, 假设 s 字符串中全是小写字母
//
// 实现步骤
//     1. 遍历字符串 s，使用作业 1 的 find 函数找到 s 中的每一位元素在 lower 中的 index，
//     2. 得到 index 之后，就知道这个元素对应的大写字母是什么，大小写字母的 index 是相同的
//     3. 累加这些大写字符之后的结果就是 s 对应的大写后的字符串
string
uppercase(const string &s)
{
    const string lower = "abcdefghijklmnopqrstuvwxyz";
    const string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // 初始化一个空字符串
    string result = "";
    size_t i = 0;
    while (i < s.size())
    {
        // 注意, 这个 find 已经帮你实现了
        int index = find(lower, s[i]);
        // 字符串可以用加号拼接, 不明白可以 log 一下
        result += upper[index];
        i += 1;
    }
    return result;
}

void testUppercase()
{
    ensure(uppercase("hello") == "HELLO", "uppercase 1");
    ensure(uppercase("gua") == "GUA", "uppercase 2");
}

// 作业 3
//
// 实现 lowercase1
// 它能正确处理带 小写字母 的字符串
//
// 实现步骤
//     1. 遍历字符串 s，如果 s 中的元素是大写字母（即这个元素被 upper 字符串包含）
//     2. 如果 s 中的元素是小写字母，直接拼接即可

string
lowercase1(const string &s)
{
    // 这里是两个字符串, 包含了大写字母和小写字母
    // 用 const 修饰是因为它们并不会被修改
    const string lower = "abcdefghijklmnopqrstuvwxyz";
    const string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // 初始化一个空字符串
    string result = "";
    size_t i = 0;
    while (i < s.size())
    {
        int index = find(upper, s[i]);
        if (index != -1)
        {
            result += lower[index];
        }
        else{
            result +=s[i];
        }
        i += 1;
    }
    return result;
}

void testLowercase1()
{
    ensure(lowercase1("heLLo") == "hello", "lowercase1 1");
    ensure(lowercase1("gua") == "gua", "lowercase1 2");
    ensure(lowercase1("GW") == "gw", "lowercase1 3");
}

// 作业 4
//
// 实现 uppercase1
// 它能正确处理带 大写字母 的字符串
//
// 实现步骤
//     1. 参考作业 3
string
uppercase1(const string &s)
{
    // 这里是两个字符串, 包含了大写字母和小写字母
    // 用 const 修饰是因为它们并不会被修改
    const string lower = "abcdefghijklmnopqrstuvwxyz";
    const string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // 初始化一个空字符串
    string result = "";
    size_t i = 0;
    while (i < s.size())
    {
        int index = find(lower, s[i]);
        if (index != -1)
        {
            result += upper[index];
        }
        else
        {
            result += s[i];
        }
        i += 1;
    }
    return result;
}

void testUppercase1()
{
    ensure(uppercase1("helLo") == "HELLO", "uppercase1 1");
    ensure(uppercase1("gUA") == "GUA", "uppercase1 2");
}

// 作业 5
// 实现一个叫 凯撒加密 的加密算法, 描述如下
// 对于一个字符串, 整体移位, 就是加密
// 以右移 1 位为例
// 原始信息 'afz' 会被加密为 'bga'
// 实现 encode1 函数, 把明文加密成密码并返回
// 右移 1 位
//
// 注意:
//     s 是一个只包含小写字母的字符串
//
// 实现步骤
//     1. 遍历字符串 s，找出每一位元素在 lower 中的 index，然后找出 lower 中 index + 1 的元素，拼接在一起
//     2. 注意考虑边界情况，如果计算出来 index 25(也就是字符 'z')，则取出第一位元素（也就是 'a'）
string
encode1(const string &s)
{
    const string lower = "abcdefghijklmnopqrstuvwxyz";
    const string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // 初始化一个空字符串
    string result = "";
    size_t i = 0;
    while (i < s.size())
    {
        int index = find(lower, s[i]);
        if (index < lower.size() - 1)
        {
            result += lower[index + 1];
        }
        else
        {
            result += lower[0];
        }
        i += 1;
    }
    return result;
}

void testEncode1()
{
    ensure(encode1("afz") == "bga", "encode1 1");
    ensure(encode1("gw") == "hx", "encode1 2");
}

// 作业 6
// 实现 decode1 函数, 把作业 5 加密的密码解密为明文并返回
//
// 注意:
//     s 是一个只包含小写字母的字符串
//
// 实现步骤
//     1. 作业 5 是往右移一位来加密，解密的操作就是整体往左移动一位，比如 'bga' 会解密成 'afz'
//     2. 遍历字符串 s，找出每一位元素在 lower 中的 index，然后找出 lower 中 index - 1 的元素，拼接在一起
//     3. 注意考虑边界情况，如果计算出来的元素是 'a'，则取出 'z'
string
decode1(const string &s)
{
    const string lower = "abcdefghijklmnopqrstuvwxyz";
    const string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // 初始化一个空字符串
    string result = "";
    size_t i = 0;
    while (i < s.size())
    {
        int index = find(lower, s[i]);
        if (index > 0)
        {
            result += lower[index - 1];
        }
        else
        {
            result += lower[lower.size() - 1];
        }
        i += 1;
    }
    return result;
}

void testDecode1()
{
    ensure(decode1("bga") == "afz", "decode1 1");
    ensure(decode1("hx") == "gw", "decode1 2");
}

// 作业 7
// 实现 encode2
// 多了一个参数 shift 表示移的位数
//
// 注意:
//     s 是一个只包含小写字母的字符串
//
// 实现步骤
//     1. 和作业 5 类似，不一样的地方在于这里是计算出 index 之后，找出 lower 中 index + shift 的元素，然后拼接在一起
//     2. 注意考虑边界情况，即 index + shift 超出了边界的情况

string
encode2(const string &s, int shift)
{
    const string lower = "abcdefghijklmnopqrstuvwxyz";
    const string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // 初始化一个空字符串
    string result = "";
    size_t i = 0;
    while (i < s.size())
    {
        int index = find(lower, s[i]);
        if (index < lower.size() - shift)
        {
            result += lower[index + shift];
        }
        else
        {
            result += lower[index + shift - lower.size()];
        }
        i += 1;
    }
    return result;
}

void testEncode2()
{
    ensure(encode2("afz", 2) == "chb", "encode2 1");
    ensure(encode2("gw", 3) == "jz", "encode2 2");
}

// 作业 8
// 实现 decode2
// 多了一个参数 shift 表示移的位数
//
// 注意:
//     s 是一个只包含小写字母的字符串
//
// 实现步骤
//     1. 和作业 6 类似，不一样的地方在于这里是计算出 index 之后，找出 lower 中 index - shift 的元素，然后拼接在一起
//     2. 注意考虑边界情况

string
decode2(const string &s, int shift)
{
    const string lower = "abcdefghijklmnopqrstuvwxyz";
    const string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // 初始化一个空字符串
    string result = "";
    size_t i = 0;
    while (i < s.size())
    {
        int index = find(lower, s[i]);
        if (index < shift)
        {
            result += lower[index - shift + lower.size()];
        }
        else
        {
            result += lower[index - shift];
        }
        i += 1;
    }
    return result;
}

void testDecode2()
{
    ensure(decode2("chb", 2) == "afz", "decode2 1");
    ensure(decode2("jz", 3) == "gw", "decode2 2");
}

// 作业 9
// 实现 encode3
// 多了一个参数 shift 表示移的位数
// 如果 s 中包含了不是字母的字符, 比如空格或者其他符号, 则对这个字符不做处理保留原样
//
// 注意:
//     s 是一个只包含小写字母和不是字母的字符的字符串
//
// 实现步骤
//     1. 作业 9 和作业 7 的区别在于 s 不同。
//         作业 7 中的 s 只包含小写字母，作业 9 多了一些不需要处理的字符串，所以遍历的时候需要单独判断
//     2. 如果遍历出来的不是字母，则什么都不处理，直接拼接在字符串上
//     3. 如果遍历出来的是小写字母，就按照作业 7 中的方式处理
string
encode3(const string &s, int shift)
{
    const string lower = "abcdefghijklmnopqrstuvwxyz";
    const string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // 初始化一个空字符串
    string result = "";
    size_t i = 0;
    while (i < s.size())
    {
        int index = find(lower, s[i]);
        if (index == -1)
        {
            result += s[i];
        }
        else
        {
            if (index < lower.size() - shift)
            {
                result += lower[index + shift];
            }
            else
            {
                result += lower[index + shift - lower.size()];
            }
        }
        i += 1;
    }
    return result;
}

void testEncode3()
{
    ensure(encode3("a fz", 2) == "c hb", "encode3 1");
    ensure(encode3("g#w", 3) == "j#z", "encode3 2");
}

// 作业 10
// 实现 decode3
// 多了一个参数 shift 表示移的位数
// 如果 s 中包含了不是字母的字符, 比如空格或者其他符号, 则对这个字符不做处理保留原样
//
// 注意:
//     s 是一个只包含小写字母和不是字母的字符的字符串
//
// 实现步骤
//     1. 作业 10 和作业 8 类似，所以在遍历的时候考虑 s 是否为小写字母。如果是小写字母就按照作业 8 的方式处理
//     2. 否则直接拼接结果

string
decode3(const string &s, int shift)
{
    const string lower = "abcdefghijklmnopqrstuvwxyz";
    const string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // 初始化一个空字符串
    string result = "";
    size_t i = 0;
    while (i < s.size())
    {
        int index = find(lower, s[i]);
        if (index == -1)
        {
            result += s[i];
        }
        else
        {
            if (index < shift)
            {
                result += lower[index - shift + lower.size()];
            }
            else
            {
                result += lower[index - shift];
            }
        }

        i += 1;
    }
    return result;
}

void testDecode3()
{
    ensure(decode3("ch#b", 2) == "af#z", "decode3 1");
    ensure(decode3("j z", 3) == "g w", "decode3 2");
}

// 作业 11
// 知乎有一个求助题, 破译密码的
// 链接在此
// https://www.zhihu.com/question/28324597
// 这一看就是凯撒加密...
// 请帮助楼主解出原文
//
// 实现步骤
//     1. 作业 11 和作业 10 的区别在于，作业 11 的 shift 是不确定的，所以需要把 shift 都尝试一遍
//     2. 在尝试的时候要先把 code 转成小写（大写字母转成小写，空格和标点不要转）
//     3. shift 的可能取值为 1 - 25，把这些情况都尝试一遍，观察解密出来的结果
//
// 这里需要肉眼观察出正确的译文
// 在第五节课中，会教大家如何自动识别出正确的译文
// （这里的第五节课，是指《〖快编程〗的免费编程入门课》第五节）
void decode4()
{
    const string code = "VRPHWLPHV L ZDQW WR FKDW ZLWK BRX,EXW L KDYH QR UHDVRQ WR FKDW ZLWK BRX";
}

void test()
{
    testFind();
    testLowercase();
    testUppercase();
    testLowercase1();
    testUppercase1();
    testEncode1();
    testDecode1();
    testEncode2();
    testDecode2();
    testEncode3();
    testDecode3();
}

int main(int argc, const char *argv[])
{
    test();

    return 0;
}