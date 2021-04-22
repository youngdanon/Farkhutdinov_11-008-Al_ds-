#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int govno_low(int *mas, int size, int key)
{
    int counter = 0;
    for (int i = 0; i < size; i++)
        if (mas[i] < key)
            counter++;
    return counter;
}

int govno_high(int *mas, int size, int key)
{
    int counter = 0;
    for (int i = 0; i < size; i++)
        if (mas[i] > key)
            counter++;
    return counter;
}

int BinSearch(int *M, int n)
{
    int L = 0;
    int R = INT_MAX;

    int m;

    while (L < R)
    {
        m = (L + R) / 2;
        if (govno_low(M, n, m) < govno_high(M, n, m))
            L = m;
        if (govno_low(M, n, m) > govno_high(M, n, m))
            R = m;
        if (govno_low(M, n, m) == govno_high(M, n, m))
            break;
    }

    return m;
}

int main()
{

    int n, m;
    cin >> n >> m;
    int inp_mas[n * m];
    for (int i = 0; i < n * m; i++)
        cin >> inp_mas[i];

    cout << BinSearch(inp_mas, n * m) << endl;
}