/**
 * @file demo.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-06-23
 *
 * @copyright Copyright (c) 2022
 *
 * c++ demo.cpp -o demo -std=c++20 -stdlib=libc++
 */

#include <fstream>
#include <string>
#include <codecvt>
#include <iostream>
#include <locale>

using namespace std;

int main(int argc, char *argv[])
{
    std::wstring str = L"123,abc:我是谁！\n";
    std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;

    std::string narrowStr = conv.to_bytes(str);
    cout << narrowStr;
    {
        std::ofstream ofs("test.txt"); //⽂件是utf8编码
        ofs << narrowStr;
    }

    string ch = "12中国34";

    cout << ch << ", length =" << ch.length() << endl;

    //locale lc("zh_CN.UTF-8");
    //locale::global(lc);
    wcout.imbue(locale("")); // zh_CN.UTF-8 is defulat, libstdc++ does not work but libc++ works fine.
    wcout << str << endl;

    // wcout.imbue(std::locale(std::locale(""), new std::codecvt_utf8<wchar_t>));
    wstring wch = conv.from_bytes(ch);
    cout << conv.to_bytes(wch) << ", length =" << wch.length() << endl;

    std::ifstream ifs("test.txt");

    while (!ifs.eof())
    {
        string line;
        getline(ifs, line);
        wstring wb = conv.from_bytes(line);

        wcout.imbue(locale("zh_CN.UTF-8")); //更改区域设置 只为控制台输出显⽰
        wcout << wb << endl;
    }
}
