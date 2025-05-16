#include <iostream>

using namespace std;

// By Hosseini

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = (low - 1);      

    for (int j = low; j <= high - 1; j++) {

        if (array[j] <= pivot) {
            i++; 
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[high]);
    return (i + 1);
}

void quickSort(int array[], int low, int high) {
    if (low < high) {

        int pi = partition(array, low, high);

        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

int main(){
    int size;
    int array[100];
    
    cout << "Enter the size of the array" << endl;
    cin >> size;

    cout << "Enter the array" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }

    quickSort(array, 0, size);

    cout << "Here's the sorted Array:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    
 return 0;
}
