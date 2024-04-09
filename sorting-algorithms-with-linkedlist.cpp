#include <iostream>
#include <string> 
using namespace std;

struct Kucuk {
    char firstName[30];
    char lastName[30];
    int age;
    string gender;
    int income;
    Kucuk* next;
};

Kucuk* start_ptr = nullptr;

void add() {
    Kucuk* temp = new Kucuk;
    cout << "Please enter the First Name of the student: ";
    cin >> temp->firstName;
    cout << "Please enter the Last Name of the student: ";
    cin >> temp->lastName;
    cout << "Please enter the Age of the student: ";
    cin >> temp->age;
    cout << "Please enter the Gender of the student: ";
    cin.ignore(); //loop
    getline(cin, temp->gender);
    cout << "Please enter the Monthly income of the student: ";
    cin >> temp->income;
    cout << endl;
    temp->next = nullptr;

    if (start_ptr == nullptr) {
        start_ptr = temp;
    }
    else {
        Kucuk* temp2 = start_ptr;
        while (temp2->next != nullptr) {
            temp2 = temp2->next;
        }
        temp2->next = temp;
    }
}

void print_node() {
    Kucuk* temp = start_ptr;
    cout << "Student First Name | Student Last Name | Student Age | Student Gender | Monthly Income" << endl;
    if (temp == nullptr) {
        cout << "Empty list." << endl;
    }
    while (temp != nullptr) {
        cout << temp->firstName << "\t" << temp->lastName << "\t" << temp->age << "\t" << temp->gender << "\t" << temp->income << endl;
        temp = temp->next;
    }
}

void bubbleSort() {
    if (!start_ptr) return;

    bool swapped;
    Kucuk* ptr1;
    Kucuk* lptr = nullptr;

    do {
        swapped = false;
        ptr1 = start_ptr;

        while (ptr1->next != lptr) {
            if (ptr1->age > ptr1->next->age) {
                // Swap data
                swap(ptr1->firstName, ptr1->next->firstName);
                swap(ptr1->lastName, ptr1->next->lastName);
                swap(ptr1->age, ptr1->next->age);
                swap(ptr1->gender, ptr1->next->gender);
                swap(ptr1->income, ptr1->next->income);
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void insertionSort() {
    if (!start_ptr) return;

    Kucuk* sortedList = nullptr; 

    while (start_ptr != nullptr) {
        Kucuk* current = start_ptr;
        start_ptr = start_ptr->next;

        if (sortedList == nullptr || current->age <= sortedList->age) {
            current->next = sortedList;
            sortedList = current;
        } else {
            Kucuk* temp = sortedList;
            while (temp->next != nullptr && temp->next->age < current->age) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
    }

    start_ptr = sortedList; 
}

void selectionSort() {
    if (!start_ptr) return;

    Kucuk* current = start_ptr;

    while (current != nullptr) {
        Kucuk* min = current;
        Kucuk* temp = current->next;
        while (temp != nullptr) {
            if (temp->age < min->age) {
                min = temp;
            }
            temp = temp->next;
        }
        if (min != current) {
            swap(current->firstName, min->firstName);
            swap(current->lastName, min->lastName);
            swap(current->age, min->age);
            swap(current->gender, min->gender);
            swap(current->income, min->income);
        }
        current = current->next;
    }
}

int main() {
    int choice;

    while (true) {
        cout << "Select an option:" << endl;
        cout << "1. Add a student" << endl;
        cout << "2. Sort students by age using Bubble Sort" << endl;
        cout << "3. Sort students by age using Insertion Sort" << endl;
        cout << "4. Sort students by age using Selection Sort" << endl;
        cout << "5. Print student list" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                add();
                break;
            case 2:
                bubbleSort();
                cout << "Student list sorted by age using Bubble Sort." << endl;
                break;
            case 3:
                insertionSort();
                cout << "Student list sorted by age using Insertion Sort." << endl;
                break;
            case 4:
                selectionSort();
                cout << "Student list sorted by age using Selection Sort." << endl;
                break;
            case 5:
                print_node();
                break;
            case 6:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
