#include <iostream>
#include <fstream>
#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include <windows.h>

using namespace std;
int main()
{
    setlocale(LC_ALL, "");
    wcout << L"Введите название файла:\n";
    string s;
    cin >> s;
    FILE* file;
    fopen_s(&file, s.data(), "r, ccs=UTF-8");
    wchar_t wc;
    wstring ws = L"";
    if (file != NULL) {
        wc = fgetwc(file);
        while (wc != WEOF) {
            wchar_t wchar[2] = { wc, '\0' };
            ws.append(wchar);
            ws.append(L" ");
            wc = fgetwc(file);
        }
        ws.pop_back();
        fclose(file);
        fwprintf(stdout, ws.data());
    }
    return 0;
}
