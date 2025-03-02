/*
 * This is a programme to compare the efficiency of different sorting algorithms.
 * The sorting algorithms include:
 * 1. Insert Sort
 * 2. Shell Sort
 * 3. Bubble Sort
 * 4. Quick Sort
 * 5. Selection Sort
 * 6. STL Sort
 */


#include <vector>
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

std::vector<int> randomArray(int n)
{
    std::vector<int> arr(n);
    std::iota(arr.begin(), arr.end(), 1);
    for (int i = 0; i < n; i++)
        std::swap(arr[i], arr[std::rand() % n]);
    return arr;
}

void insertSort(int arr[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            temp = arr[i];
            for (j = i - 1; j >= 0 && arr[j] > temp; j--)
            {
                arr[j + 1] = arr[j];
            }
            arr[j + 1] = temp;
        }
    }
}

void shellSort(int arr[], int n)
{
    int d, i, j;
    for (d = n / 2; d >= 1; d /= 2)
    {
        for (i = d + 1; i <= n; i++)
        {
            if (arr[i] < arr[i - 1])
            {
                arr[0] = arr[i];
                for (j = i - d; j > 0 && arr[0] < arr[j]; j -= d)
                {
                    arr[j + d] = arr[j];
                }
                arr[j + d] = arr[0];
            }
        }
    }
}

void bubbleSort(int arr[], int n)
{
    bool flag = true;
    for (int i = 0; i < n && flag; i++)
    {
        flag = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            int temp;
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = true;
            }
        }
    }
}

void quickSort(int arr[], int left, int right)
{
    if (left >= right)
        return;

    int pivotIndex = [&](int arr[], int left, int right) -> int
    {
        int pivot = arr[left];
        while (left < right)
        {
            while (left < right && arr[right] >= pivot)
                right--;
            arr[left] = arr[right];
            while (left < right && arr[left] <= pivot)
                left++;
            arr[right] = arr[left];
        }
        arr[left] = pivot;
        return left;
    }(arr, left, right);

    quickSort(arr, left, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, right);
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

int countTime(int arr[], int n, void (*sort)(int[], int))
{
    auto start = std::chrono::high_resolution_clock::now();
    sort(arr, n);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    return duration / 1000;
}

int countTime(int arr[], int n, void (*sort)(int[], int, int))
{
    auto start = std::chrono::high_resolution_clock::now();
    sort(arr, 0, n - 1);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    return duration / 1000;
}

int main()
{
    int n = 50000;
    std::vector<int> array = randomArray(n);
    int arr[n] = {0};

    for (int i = 0; i < n; i++)
        arr[i] = array[i];
    std::cout << "Insert Sort: " << countTime(arr, n, insertSort) << " ms" << std::endl;

    for (int i = 0; i < n; i++)
        arr[i] = array[i];
    std::cout << "Shell Sort: " << countTime(arr, n, shellSort) << " ms" << std::endl;

    for (int i = 0; i < n; i++)
        arr[i] = array[i];
    std::cout << "Bubble Sort: " << countTime(arr, n, bubbleSort) << " ms" << std::endl;

    for (int i = 0; i < n; i++)
        arr[i] = array[i];
    std::cout << "Quick Sort: " << countTime(arr, n, quickSort) << " ms" << std::endl;

    for (int i = 0; i < n; i++)
        arr[i] = array[i];
    std::cout << "Selection Sort: " << countTime(arr, n, selectionSort) << " ms" << std::endl;

    auto start = std::chrono::high_resolution_clock::now();
    std::sort(array.begin(), array.end());
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    std::cout << "STL Sort: " << duration / 1000 << " ms" << std::endl;

    return 0;
}