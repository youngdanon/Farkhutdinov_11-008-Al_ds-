#include <bits/stdc++.h>

using namespace std;

int n;
int a[100000]; //массив
int f[100000]; //дерево Фенвика

//сумма элементов от 0 до x
int sum(int x)
{
    int result = 0;

    for (; x >= 0; x = (x & (x + 1)) - 1)
    {
        result += f[x];
    }

    return result;
}

//сумма элементов от l до r
int sum_interval(int l, int r)
{
    if (l)
    {
        return sum(r) - sum(l - 1);
    }
    else
    {
        return sum(r);
    }
}

//увеличение a[idx] на delta
void increase(int idx, int delta)
{
    a[idx] += delta;

    for (; idx < n; idx |= idx + 1)
    {
        f[idx] += delta;
    }
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    { //ввод массива и заполнение дерева Фенвика
        int t;
        cin >> t;
        increase(i, t);
        // cout<< "Iter" << endl;
    }

    cout << sum_interval(1, n);
    //Можем обрабатывать запросы
}
