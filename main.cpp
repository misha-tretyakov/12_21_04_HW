#include <iostream>
using namespace std;

void InitArray(int*& arr, int size) {
    arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}


void PrintArray(int*& arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void DeleteArray(int*& arr, int& size) {
    delete[] arr;
    arr = nullptr;
    size = 0;
}


void Append(int*& arr, int& size, int value) {
    int* temp = new int[size + 1];

    for (int i = 0; i < size; i++) {
        temp[i] = arr[i];
    }
    temp[size] = value;


    delete[] arr;
    size++;
    arr = temp;
}


void Insert(int*& arr, int& size, int value, int index) {
    if (index < 0 || index > size) {
        cout << "index out of bounds" << endl;
        return;
    }

    int* temp = new int[size+1];

    for (int i = 0; i < index; i++) {
        temp[i] = arr[i];
    }

    temp[index] = value;

    for (int i = index; i < size; i++) {
        temp[i + 1] = arr[i];
    }

    delete[] arr;
    size++;
    arr = temp;
}

void Delete(int*& arr, int& size, int index) {
    if (index < 0 || index >= size) {
        cout << "index out of bounds" << endl;
        return;
    }

    int* temp = new int[size - 1];

    for (int i = 0; i < index; i++) {
        temp[i] = arr[i];
    }

    for (int i = index + 1; i < size; i++) {
        temp[i - 1] = arr[i];
    }


    delete[] arr;
    size--;
    arr = temp;
}

int main() {
    int size = 5;
    int* arr = nullptr;

    InitArray(arr, size);
    PrintArray(arr, size);

    Append(arr, size, 4);
    PrintArray(arr, size);

    Insert(arr, size, 3, 2);
    PrintArray(arr, size);

    Delete(arr, size, size-1);
    PrintArray(arr, size);

    DeleteArray(arr, size);
}
