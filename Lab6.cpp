#include <iostream>
#include <string>
using namespace std;
int main()
{
    bool fc, fn;
    int count, start, r;
    string a;
    getline(cin, a);
    for (int i = 0; i < a.length(); i++) // Цикл, удаляющий слова
    {
        if (a[i-1] == ' ')
        {
            if (fc == 0 || fn == 0)
            {
                a.erase(start, count);
                i -= count;
            }
            count = 0;
            fc = 0;
            fn = 0;
            start = i;
        }
        else
        {
            if (a[i] != 32)
            {
                if (a[i] > 47 && a[i] < 58)
                {
                    fn = 1;
                }
                else
                {
                    if (a[i] > 64 && a[i] < 123)
                    {
                        fc = 1;
                    }
                }
            }
        count++;
        }
    }
    if (fc == 0 || fn == 0) // Удаление последнего слова
    {
        a.erase(start, count+1);
    }
    
    for (int i = 0; i < a.length(); i++) // Цикл, удаляющий лишние пробелы
    {
        if (a[0] == 32)
        {
            a.erase(0, 1);
        }
        if (a[a.length()] == 32)
        {
            a.erase(a.length()-1, 1);
        }
        if (a[i] == 32 && a[i+1] == 32)
        {
            a.erase(i, 1);
            i = 0;
        }
    }
    cout << a;
    return 0;
}

