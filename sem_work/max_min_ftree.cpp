#include <bits/stdc++.h>

using namespace std;

int n;
int a[100000];  //массив
int f[100000];  //дерево Фенвика

//минимум среди элементов от 0 до x
int get_min(int x) {
    int result = INT_MAX;

    for (; x >= 0; x = (x & (x + 1)) - 1) {
        result = min(result, f[x]);
    }

    return result;
}

//присваивание a[idx] = val (val <= a[idx])
void assign(int idx, int val) {
    a[idx] = val;

    for (; idx < n; idx |= idx + 1) {
        f[idx] = min(f[idx], val);
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {       //Изначально принимаем все значения в дереве
        f[i] = INT_MAX;                 //равными бесконечности, так как далее их можно
    }                                   //только уменьшать.

    for (int i = 0; i < n; i++) {    //ввод массива и заполнение дерева Фенвика
        int t;
        cin >> t;
        assign(i, t);
    }

    //Можем обрабатывать запросы.
}
