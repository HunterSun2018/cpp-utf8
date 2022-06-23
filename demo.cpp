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

    wcout.imbue(locale("")); //更改区域设置 只为控制台输出显⽰
    wstring wch = conv.from_bytes(ch);
    cout << conv.to_bytes(wch) << ", length =" << wch.length() << endl;

    std::ifstream ifs("test.txt");

    while (!ifs.eof())
    {
        string line;
        getline(ifs, line);
        wstring wb = conv.from_bytes(line);

        wcout << wb << endl;
    }
}
