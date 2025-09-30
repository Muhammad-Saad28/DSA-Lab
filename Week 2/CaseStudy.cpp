#include <iostream>
#include <string>
#include <cstdlib>  
using namespace std;

void insertEmployee(int ids[], string names[], string depts[], int &n, int id, string name, string dept) {
    ids[n] = id;
    names[n] = name;
    depts[n] = dept;
    cout << "Inserted: ID=" << id << ", Name=" << name << ", Dept=" << dept << endl;
    n++;
}

int searchByID(int ids[], string names[], string depts[], int n, int id) {
    for (int i = 0; i < n; i++) {
        if (ids[i] == id) {
            cout << "Employee Found: ID=" << ids[i] 
                 << ", Name=" << names[i] 
                 << ", Dept=" << depts[i] << endl;
            return i;
        }
    }
    cout << "Employee with ID=" << id << " not found!" << endl;
    return -1;
}

int searchByName(int ids[], string names[], string depts[], int n, string name) {
    for (int i = 0; i < n; i++) {
        if (names[i] == name) {
            cout << "Employee Found: ID=" << ids[i] 
                 << ", Name=" << names[i] 
                 << ", Dept=" << depts[i] << endl;
            return i;
        }
    }
    cout << "Employee with Name=" << name << " not found!" << endl;
    return -1;
}

void deleteEmployee(int ids[], string names[], string depts[], int &n, int id) {
    int index = searchByID(ids, names, depts, n, id);
    if (index == -1) return;

    for (int i = index; i < n - 1; i++) {
        ids[i] = ids[i + 1];
        names[i] = names[i + 1];
        depts[i] = depts[i + 1];
    }
    n--;
    cout << "Employee with ID=" << id << " deleted successfully." << endl;
}

void displayEmployees(int ids[], string names[], string depts[], int n) {
    if (n == 0) {
        cout << "No employees in the system." << endl;
        return;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ids[j] > ids[j + 1]) {
                swap(ids[j], ids[j + 1]);
                swap(names[j], names[j + 1]);
                swap(depts[j], depts[j + 1]);
            }
        }
    }

    cout << "Employees in the System:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "ID=" << ids[i] 
             << ", Name=" << names[i] 
             << ", Dept=" << depts[i] << endl;
    }
}

int main() {
    int ids[100];
    string names[100];
    string depts[100];
    int n = 0;
    int choice;

    do {
        cout << "\n=== Employee Management System ===\n";
        cout << "1. Insert Employee\n";
        cout << "2. Delete Employee by ID\n";
        cout << "3. Search Employee by ID\n";
        cout << "4. Search Employee by Name\n";
        cout << "5. Display Employees\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        system("cls");  

        if (choice == 1) {
            int id;
            string name, dept;
            cout << "--- Insertion ---\n";
            cout << "Enter Employee ID: ";
            cin >> id;
            cout << "Enter Employee Name: ";
            cin >> name;
            cout << "Enter Department: ";
            cin >> dept;
            insertEmployee(ids, names, depts, n, id, name, dept);
        }
        else if (choice == 2) {
            int id;
            cout << "--- Deletion ---\n";
            cout << "Enter Employee ID to delete: ";
            cin >> id;
            deleteEmployee(ids, names, depts, n, id);
        }
        else if (choice == 3) {
            int id;
            cout << "--- Search by ID ---\n";
            cout << "Enter Employee ID to search: ";
            cin >> id;
            searchByID(ids, names, depts, n, id);
        }
        else if (choice == 4) {
            string name;
            cout << "--- Search by Name ---\n";
            cout << "Enter Employee Name to search: ";
            cin >> name;
            searchByName(ids, names, depts, n, name);
        }
        else if (choice == 5) {
            cout << "--- Display Employees ---\n";
            displayEmployees(ids, names, depts, n);
        }
        else if (choice == 6) {
            cout << "Exiting Employee Management System..." << endl;
        }
        else {
            cout << "Invalid choice! Please try again." << endl;
        }

    } while (choice != 6);

    return 0;
}
