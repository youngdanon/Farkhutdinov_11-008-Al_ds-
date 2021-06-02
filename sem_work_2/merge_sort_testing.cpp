#include <iostream>
#include <math.h>
#include "ctime"
#include <iomanip>
#include <string.h>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;


int iteration_counter = 0;

//Стандартный компаратор
template <typename T>
class standart_cmp
{
public:
    static bool less(const T &a, const T &b)
    {
        return a < b;
    }
};

//Функция слияния массива
//array - массив, который упорядочен (при помощи этого же компаратора) до middle, и после middle
//buffer - массив, размером не меньше чем array
template <typename T, typename cmp = standart_cmp<T>>
void merge(T *array, T *buffer, int left, int middle, int right)
{
    //Индесы считывания чисел из array
    int it_left = 0;
    int it_right = 0;

    //Как только какой-либо из "итераторов" выходит за границу, прекращаем цикл
    while (left + it_left < middle && middle + it_right < right)
    {
        if (cmp::less(array[left + it_left], array[middle + it_right]))
        {
            buffer[it_left + it_right] = array[left + it_left];
            it_left++;
        }
        else
        {
            buffer[it_left + it_right] = array[middle + it_right];
            it_right++;
        }
    }

    //Записываем оставшиеся части, невыписанные из array
    while (left + it_left < middle)
    {
        buffer[it_left + it_right] = array[left + it_left];
        it_left++;
    }

    while (middle + it_right < right)
    {
        buffer[it_left + it_right] = array[middle + it_right];
        it_right++;
    }

    //Выписываем buffer в array
    for (int i = 0; i < it_left + it_right; i++)
        array[left + i] = buffer[i];
}

//array - массив
//buffer - буфер для сортировки, размером не меньше, чем array
//left - нижняя граница, right - верхняя
template <typename T, typename cmp = standart_cmp<T>>
void merge_sort(T *array, T *buffer, int left, int right)
{
    iteration_counter++;
    //Массив единичного размера уже отсортированым считается
    if (right - left <= 1)
    {
        return;
    }

    //Индекс серединного элемента
    int middle = left + (right - left) / 2;

    //Сортируем половинки массива
    merge_sort(array, buffer, left, middle);
    merge_sort(array, buffer, middle, right);

    //Составляем из двух отсортированных половинок
    //Целый отсортированный массив
    merge<T, cmp>(array, buffer, left, middle, right);
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

        int *arr = new int[size];
        int *buff = new int[size];

        for (int i = 0; i < size; i++)
        {
            arr[i] = intValues.at(i);
        }

        iteration_counter = 0;
        double startTime = clock();
        // here is executing tests
       
        merge_sort(arr, buff, 0, size);

        double endTime = clock();
        counter++;
        // cout << result << to_string(endTime - startTime) + "\n"; // output elements count and test complition 
        cout << result << to_string(iteration_counter) + "\n";
    }
    file.close();
    return result;
}

int main()
{
    process_data();
    return 0;
}

// int main()
// {
//     int n;
//     std::cin >> n;

//     int *arr = new int[n];
//     int *buff = new int[n];

//     for (int i = 0; i < n; i++)
//     {
//         std::cin >> arr[i];
//     }

//     merge_sort(arr, buff, 0, n);

//     for (int i = 0; i < n; i++)
//     {
//         std::cout << arr[i] << " ";
//     }
//     std::cout << std::endl;
//     return 0;
// }