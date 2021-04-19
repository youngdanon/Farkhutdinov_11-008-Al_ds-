#include <iostream>
#include <math.h>
#include "ctime"
#include <iomanip>
#include <string.h>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

vector<int> split(const string &s, char delimiter)
{
    vector<int> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter))
    {
        tokens.push_back(stoi(token));
    }
    return tokens;
}

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

string absolutePathToInputFile = "/home/youngdanon/Документы/repos/tests-generator/input.txt"; // absolute path to file
string process_data()
{
    ifstream file(absolutePathToInputFile);
    string result = "";
    string line;
    int counter = 0;
    while (getline(file, line))
    {
        auto fenvik = new FenvikTree;
        vector<int> intValues = split(line, ' ');   // splitting by delimiter and creating vector with int values
        result = to_string(intValues.size()) + ","; // amount of elements. "," - delimiter
        int size = intValues.size();
        for (int i = 0; i < size; i++)
        {
            fenvik->increase(i, intValues.at(i));
        }
        double startTime = clock();
        // here is executing tests
        for (int i = 0; i < size; i++)
        {
            fenvik->sum(size);
        }
        
        double endTime = clock();
        counter++;
        cout <<result<<to_string(endTime - startTime) + "\n"; // output elements count and test complition time

    }
    file.close();
    return result;
}

int main()
{
    process_data();
    return 0;
}
