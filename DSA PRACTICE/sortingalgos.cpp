#include <iostream>
using namespace std;

void bubblesort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void insertion_sort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {

            arr[j + 1] = arr[j];

            j = j - 1;
        }
        arr[j + 1] = key;
    }
};
void display(int arr[])
{
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[5] = {4, 2, 6, 5, 3};
    // bubblesort(arr, 5);
    insertion_sort(arr, 5);
    display(arr);
}