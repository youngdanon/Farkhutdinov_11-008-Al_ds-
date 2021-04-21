#include <iostream>

using namespace std;

int BinSearch(int *M, int n, int k)
{
    int L = 0;
    int R = n;

    int m;
    int z = 0;

    while (L < R)
    {
        z++;
        m = (L + R) / 2;
        if (k > M[m])
            L = m;
        if (k < M[m])
            R = m;
        if (k == M[m])
            break;
        if (R - L <= 1)
            break;
    }
    if ((k - M[L]) < (M[R] - k))
        return L;
    return R;
}

int main()
{
    int x;
    cin >> x;
    int size = x / 2 + 2;
    int quads[size];
    for (int i = 0; i < size; i++)
    {
        quads[i] = i * i;
    }

    int square_index = BinSearch(quads, size, x);
    cout << square_index << endl;

    return 0;
}