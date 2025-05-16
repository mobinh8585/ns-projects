#include <iostream>

using namespace std;

// By Hosseini

struct Student{
    string name;
    int yearofbirth;
    double weight;
    int height;
};

void bubbleSort(Student arr[], int size){
    
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j].name > arr[j + 1].name)
            {
                Student temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
}

void averageHeightAndWeight(Student arr[], int size, double &averageHeight, double &averageWeight){
    
    int sumHeight = 0;
    int sumWeight = 0;
    for (int i = 0; i < size; i++)
    {
        sumHeight += arr[i].height;
        sumWeight += arr[i].weight;
    }
    
    averageHeight = sumHeight / size;
    averageWeight = sumWeight / size;
}


int main(){

    double averageHeight = 0;
    double averageWeight = 0;

    Student students[5] = {};
    
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter the name of student " << i + 1 << ": ";
        cin >> students[i].name;
        cout << "Enter the year of birth of student " << i + 1 << ": ";
        cin >> students[i].yearofbirth;
        cout << "Enter the weight of student " << i + 1 << ": ";
        cin >> students[i].weight;
        cout << "Enter the height of student " << i + 1 << ": ";
        cin >> students[i].height;
    }
    
    bubbleSort(students, 5);
    
    cout << "Here's the sorted array of students: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << ". " << "Name: " << students[i].name << ", Year of birth: " << students[i].yearofbirth << ", Weight: " << students[i].weight << ", Height: " << students[i].height << endl;
    }

    averageHeightAndWeight(students, 5, averageHeight, averageWeight);

    cout << "The average height of students is: " << averageHeight << endl;
    cout << "The average weight of students is: " << averageWeight << endl;

    
    return 0;
}
