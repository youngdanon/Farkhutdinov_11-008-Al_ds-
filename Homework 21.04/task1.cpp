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

    vector<int> inp_mas;
    int n;
    string raw_mas;
    cin >> raw_mas;
    cin >> n;
    for (int i = 0; i < raw_mas.size(); i++)
    {
        inp_mas.push_back((int)raw_mas[i] - 48);
    }
    // print_v(inp_mas);
    print_v(inp_mas);
    int first_ind = binarySearch(inp_mas, 0, inp_mas.size(), n, false);
    int last_ind = binarySearch(inp_mas, 0, inp_mas.size(), n, true);
    if (first_ind > inp_mas.size() - 1)
    {
        cout << "Number is not founded" << endl;
    }
    else
    {
        cout << "Fisrt founded: " << first_ind << endl;
        cout << "Last founded: " << last_ind << endl;
    }
}