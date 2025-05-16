#include <iostream>

using namespace std;

// By Hosseini

int binarySearch(int array[], int size, int target) {
    int left = 0;
    int right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (array[mid] == target) {
            return mid;
        }
        
        else if (array[mid] < target) {
            left = mid + 1;
        }
        else if (array[mid] > target){
            right = mid - 1;
        }
    }
    
    return -1;
}

int main() {
    int size;
    int array[100];
    
    cout << "Enter the size of the array" << endl;
    cin >> size;

    cout << "Enter the SORTED array" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
    
    int target;
    cout << "Enter a number to find" << endl;
    cin >> target;
    
    int result = binarySearch(array, size, target);
    
    if (result != -1) {
        cout << "The number " << target << " on the index " << result << " has found" << endl;
    } else {
        cout << "The number " << target << " has not been found. The result: " << result << endl;
    }
    
    return 0;
}
