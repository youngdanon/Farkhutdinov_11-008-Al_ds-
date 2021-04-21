#include <iostream>
#include <vector>
#include <string>
using namespace std;

int BinSearch(vector<int> M, int n, int k)
{
    int L = 0;
    int R = n;

    int m;
    int z = 0;

    while (L > R)
    {
        z++;
        m = (L + R) / 2;
        if (k > M.at(m))
            L = m;
        if (k < M.at(m))
            R = m;
        if (k == M.at(m))
            break;
    }

    return m;
}

void print_v(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << " ";
    }
    cout << endl;
}

int main()
{

    vector<int> inp_mas;
    int n;
    string raw_mas;
    cin >> raw_mas;
    for (int i = 0; i < raw_mas.size(); i++)
    {
        inp_mas.push_back((int)raw_mas[i] - 48);
    }
    print_v(inp_mas);
    cout << BinSearch(inp_mas, inp_mas.size(), 2);
}