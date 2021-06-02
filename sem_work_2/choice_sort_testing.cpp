#include <iostream>
#include <math.h>
#include "ctime"
#include <iomanip>
#include <string.h>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

long long iter_counter = 0;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            iter_counter++;
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

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

string absolutePathToInputFile = "/home/youngdanon/Документы/repos/tests-generator/input.txt"; // absolute path to file
string process_data()
{
    ifstream file(absolutePathToInputFile);
    string result = "";
    string line;
    int counter = 0;
    while (getline(file, line))
    {
        vector<int> intValues = split(line, ' ');   // splitting by delimiter and creating vector with int values
        result = to_string(intValues.size()) + ","; // amount of elements. "," - delimiter
        int size = intValues.size();
        // cout << result << endl;

        int arr[size];

        for (int i = 0; i < size; i++)
        {
            arr[i] = intValues.at(i);
        }

        iter_counter = 0;
        double startTime = clock();
        // here is executing tests

        selectionSort(arr, size);

        double endTime = clock();
        counter++;
        // cout << result << to_string(endTime - startTime) + "\n"; // output elements count and test complition
        cout << result << to_string(iter_counter)+','<< to_string(endTime - startTime) + "\n";

    }
    file.close();
    return result;
}

int main()
{
    process_data();
    return 0;
}
