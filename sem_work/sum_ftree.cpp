#include <bits/stdc++.h>

using namespace std;

struct FenvikTree
{
    int n;
    int a[1000000]; //массив
    int f[1000000]; //дерево Фенвика
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
};

//сумма элементов от 0 до x

int main()
{
    auto tree = new FenvikTree();
    cout << "Введите кол-во игр за сезон (от 5 игр по условию лиги)" << endl;
    cin >> tree->n;
    cout << "Введите очки за каждую игру, каждое значение с новой строчки" << endl;
    for (int i = 0; i < tree->n; i++)
    { //ввод массива и заполнение дерева Фенвика
        int t;
        cin >> t;
        tree->increase(i, t);
    }
    //Можем обрабатывать запросы
    cout << "Результативность за сезон: " << tree->sum(tree->n) << endl;
    cout << "Результативность со 2 по " << tree->n - 2 << " игру: " << tree->sum_interval(2, tree->n - 2) << endl;
}
