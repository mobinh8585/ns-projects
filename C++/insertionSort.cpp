#include <iostream>

using namespace std;

// By Hosseini

void insertionSort(int array[], int size){

    for (int i = 1; i < size; i++)
    {
        int K = array[i];
        int j = i -1;

        while (j >= 0 && array[j] > K)
        {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = K;
    
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

    insertionSort(array, size);

    cout << "Here's the sorted Array:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    
 return 0;
}
