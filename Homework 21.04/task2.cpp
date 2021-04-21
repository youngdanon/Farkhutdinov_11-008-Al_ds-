#include <iostream>
#include <vector>
#include <string>
using namespace std;

int binarySearch(vector<int> a, int fromIndex, int toIndex, int key, bool last)
{
    int low = fromIndex;
    int high = toIndex - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int midVal = a.at(mid);

        if (midVal < key || (last && midVal == key))
            low = mid + 1;
        else if (midVal > key || (!last && midVal == key))
            high = mid - 1;
    }
    return last ? high : low;
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
    int n, m;
    int x;

    cin >> n >> m;
    vector<int> inp;
    int num;
    for (int i = 0; i < n * m; i++)
    {
        cin >> num;
        inp.push_back(num);
    }

    cin >> x;

    int index = binarySearch(inp, 0, n * m, x, false);
    if (index > inp.size() - 1)
    {
        cout << "Number not found" << endl;
    }
    else
    {
        cout << "Number founded" << endl;
    }
}