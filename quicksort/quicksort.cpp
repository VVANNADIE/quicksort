#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Функция для обмена элементов массива
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Функция для разделения массива и возврата индекса опорного элемента
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Опорный элемент
    int i = low - 1;       // Индекс меньшего элемента

    for (int j = low; j <= high - 1; j++) {
        // Если текущий элемент меньше или равен опорному
        if (arr[j] <= pivot) {
            i++;  // Увеличиваем индекс меньшего элемента
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Функция быстрой сортировки
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Получаем индекс опорного элемента
        int pi = partition(arr, low, high);

        // Рекурсивно применяем быструю сортировку к левой и правой частям
        quickSort(arr, low, pi - 1);    // Сортировка левой части массива
        quickSort(arr, pi + 1, high);   // Сортировка правой части массива
    }
}

int main() {
    setlocale(LC_ALL, "Russian"); // Устанавливаем русскую локаль для корректного отображения русских символов
    // Массив с 10 элементами
    int arr1[10];
    cout << "Массив с 10 элементами: ";
    for (int i = 0; i < 10; i++) {
        arr1[i] = rand() % 100;  // Заполняем случайными числами от 0 до 99
        cout << arr1[i] << " ";
    }
    cout << endl ;

    clock_t start, end;
    double timeTaken;

    start = clock(); // Запускаем таймер

    quickSort(arr1, 0, 9); // Применяем быструю сортировку к массиву

    end = clock(); // Останавливаем таймер
    timeTaken = double(end - start) / CLOCKS_PER_SEC * 1000; // Вычисляем время выполнения в миллисекундах

    cout << "Отсортированный массив с 10 элементами: ";
    for (int i = 0; i < 10; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl ;
    cout << "Время выполнения для массива с 10 элементами: " << timeTaken << " мс" << endl << endl;

    // Массив с 100 элементами
    int arr2[100];
    cout << "Массив с 100 элементами: ";
    for (int i = 0; i < 100; i++) {
        arr2[i] = rand() % 100;  // Заполняем случайными числами от 0 до 99
        cout << arr2[i] << " ";
    }
    cout << endl << endl;

    start = clock(); // Запускаем таймер

    quickSort(arr2, 0, 99); // Применяем быструю сортировку к массиву

    end = clock(); // Останавливаем таймер
    timeTaken = double(end - start) / CLOCKS_PER_SEC * 1000; // Вычисляем время выполнения в миллисекундах

    cout << "Отсортированный массив с 100 элементами: ";
    for (int i = 0; i < 100; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl ;
    cout << "Время выполнения для массива с 100 элементами: " << timeTaken << " мс" << endl << endl;

    // Массив с 1000 элементами
    int arr3[1000];
    cout << "Массив с 1000 элементами: ";
    for (int i = 0; i < 1000; i++) {
        arr3[i] = rand() % 100;  // Заполняем случайными числами от 0 до 99
        cout << arr3[i] << " ";
    }
    cout << endl << endl;

    start = clock(); // Запускаем таймер

    quickSort(arr3, 0, 999); // Применяем быструю сортировку к массиву

    end = clock(); // Останавливаем таймер
    timeTaken = double(end - start) / CLOCKS_PER_SEC * 1000; // Вычисляем время выполнения в миллисекундах

    cout << "Отсортированный массив с 1000 элементами: ";
    for (int i = 0; i < 1000; i++) {
        cout << arr3[i] << " ";
    }
    cout << endl ;
    cout << "Время выполнения для массива с 1000 элементами: " << timeTaken << " мс" << endl;

    return 0;
}