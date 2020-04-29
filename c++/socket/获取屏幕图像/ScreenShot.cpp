
// 通过 HDC句柄 获取屏幕 复制到剪切板

#include <iostream>
#include <windows.h>

using namespace std;

void screenshot(POINT a, POINT b)
{
    // 截取屏幕到位图
    // 该函数检索一指定窗口的客户区域或整个屏幕的显示设备上下文环境的句柄，以后可以在GDI函数中使用该句柄来在设备上下文环境中绘图。
    HDC screenImage = GetDC(NULL);
    // 该函数创建一个与指定设备兼容的内存设备上下文环境（DC）。通过GetDc()获取的HDC直接与相关设备沟通，而本函数创建的DC，则是与内存中的一个表面相关联。
    HDC hDC = CreateCompatibleDC(screenImage);
    // 该函数创建与指定的设备环境相关的设备兼容的位图
    HBITMAP hBitmap = CreateCompatibleBitmap(screenImage, abs(b.x - a.x), abs(b.y - a.y));
    // 该函数选择一对象到指定的设备上下文环境中，该新对象替换先前的相同类型的对象。
    HGDIOBJ old_obj = SelectObject(hDC, hBitmap);
    // BitBlt是一个计算机函数，该函数对指定的源设备环境区域中的像素进行位块（bit_block）转换，以传送到目标设备环境。
    BOOL bRet = BitBlt(hDC, 0, 0, abs(b.x - a.x), abs(b.y - a.y), screenImage, a.x, a.y, SRCCOPY);

    // 将位图保存到剪贴板
    // 打开剪切板
    OpenClipboard(NULL);
    // 清空剪切板
    EmptyClipboard();
    // 设置剪切板内容
    SetClipboardData(CF_BITMAP, hBitmap);
    
    // 关闭剪切板
    CloseClipboard();

    // 清理重置内存
    SelectObject(hDC, old_obj);
    // 该函数删除指定的设备上下文环境
    DeleteDC(hDC);
    // ReleaseDC函数释放设备上下文环境（DC）供其他应用程序使用
    ReleaseDC(NULL, screenImage);
    // 删除位图数据
    DeleteObject(hBitmap);
}

int main()
{
    POINT a, b;
    a.x = 0;
    a.y = 0;

    b.x = 1920;
    b.y = 1080;

    screenshot(a, b);
    
}