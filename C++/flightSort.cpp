#include <iostream>

using namespace std;

// By Hosseini

struct FlightTime{
    int hour;
    int minute;
};

struct Flight{
    int number;
    string destination;
    string origin;
    FlightTime time;
};



void mainMenu(Flight flights[], int size);
void sortByTime(Flight flights[], int size);
void searchByDestinationAndOrigin(Flight flights[], int size);
void searchByTime(Flight flights[], int size);
void showAllFlights(Flight flights[], int size);
void swap(Flight &a, Flight &b);

int main(){
    cout << "Welcome to the Flight Management System! completely made by Hosseini" << endl;

    int size;
    cout << "Enter the number of flights: ";
    cin >> size;
    Flight flights[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the number of flight " << i + 1 << ": ";
        cin >> flights[i].number;
        cout << "Enter the destination of flight " << i + 1 << ": ";
        cin >> flights[i].destination;
        cout << "Enter the origin of flight " << i + 1 << ": ";
        cin >> flights[i].origin;
        cout << "Enter the time of flight " << i + 1 << " (hour minute): ";
        cin >> flights[i].time.hour >> flights[i].time.minute;
    }
    
    mainMenu(flights, size);
    
}

void mainMenu(Flight flights[], int size){
    cout << "What do you want to do?" << endl;
    cout << "1. Sort flights by time" << endl;
    cout << "2. Search flights by destination and origin" << endl;
    cout << "3. Search flights by time" << endl;
    cout << "4. Show all flights" << endl;
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        sortByTime(flights, size);
        break;
    case 2:
        searchByDestinationAndOrigin(flights, size);
        break;
    case 3:
        searchByTime(flights, size);
        break;
    case 4:
        showAllFlights(flights, size);
        break;
    default:
        cout << "Invalid choice, please try again" << endl;
        mainMenu(flights, size);
    }
    
}

void swap(Flight &a, Flight &b){
    Flight temp = a;
    a = b;
    b = temp;
}

void sortByTime(Flight flights[], int size){

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (flights[j].time.hour > flights[j + 1].time.hour || (flights[j].time.hour == flights[j + 1].time.hour && flights[j].time.minute > flights[j + 1].time.minute))
            {
                swap(flights[j], flights[j + 1]);
            }
        }
    }
    cout << "Here's the sorted array of flights by time: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Flight " << i + 1 << ": " << flights[i].number << ", destination: " << flights[i].destination << ", origin: " << flights[i].origin << ", time: " << flights[i].time.hour << ":" << flights[i].time.minute << endl;
    }
    mainMenu(flights, size);
    
}

void searchByDestinationAndOrigin(Flight flights[], int size){

    string destination;
    string origin;
    cout << "Enter the destination of the flight to search: ";
    cin >> destination;
    cout << "Enter the origin of the flight to search: ";
    cin >> origin;

    cout << "Here's the array of flights with destination " << destination << " and origin " << origin << ": " << endl;
    
    int count = 1;
    for (int i = 0; i < size; i++)
    {
        if (flights[i].destination == destination && flights[i].origin == origin)
        {
            cout << "Flight " << count << ": " << flights[i].number << ", destination: " << flights[i].destination << ", origin: " << flights[i].origin << ", time: " << flights[i].time.hour << ":" << flights[i].time.minute << endl;
            count++;
        }
    }
    if (count == 1)
    {
        cout << "No flights found with destination " << destination << " and origin " << origin << endl;
    }
    mainMenu(flights, size);
    
}

void searchByTime(Flight flights[], int size){
    int hour;
    int minute;
    cout << "Enter the hour and minute of the flight to search from: ";
    cin >> hour >> minute;
    int hour2;
    int minute2;
    cout << "Enter the hour and minute of the flight to search to: ";
    cin >> hour2 >> minute2;

    int startTime = hour * 60 + minute;
    int endTime = hour2 * 60 + minute2;
    
    cout << "Here's the array of flights with time from " << hour << ":" << minute << " to " << hour2 << ":" << minute2 << ": " << endl;
    
    int count = 1;
    for (int i = 0; i < size; i++)
    {
        int flightTime = flights[i].time.hour * 60 + flights[i].time.minute;
        
        if (startTime <= flightTime && flightTime <= endTime)
        {
            cout << "Flight " << count << ": " << flights[i].number << ", destination: " << flights[i].destination << ", origin: " << flights[i].origin << ", time: " << flights[i].time.hour << ":" << flights[i].time.minute << endl;
            count++;
        }
    }
    if (count == 1)
    {
        cout << "No flights found with time from " << hour << ":" << minute << " to " << hour2 << ":" << minute2 << endl;
    }
    mainMenu(flights, size);
}

void showAllFlights(Flight flights[], int size){
    cout << "Here's the array of all flights: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Flight " << i + 1 << ": " << flights[i].number << ", destination: " << flights[i].destination << ", origin: " << flights[i].origin << ", time: " << flights[i].time.hour << ":" << flights[i].time.minute << endl;
    }
    mainMenu(flights, size);
}   



