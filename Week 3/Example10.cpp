#include <iostream>
using namespace std;

void inputApplicants(int id[], int marks[], int age[], int &n) 
{
    cout << "Enter number of applicants: ";
    cin >> n;

    cout << "Enter ApplicantID, Marks, Age for each applicant:\n";
    for (int i = 0; i < n; i++) 
    {
        cin >> id[i] >> marks[i] >> age[i];
    }
}

void sortApplicants(int id[], int marks[], int age[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (marks[j] < marks[j + 1] || (marks[j] == marks[j + 1] && age[j] > age[j + 1])) 
            {
                // Swap marks
                int temp = marks[j];
                marks[j] = marks[j + 1];
                marks[j + 1] = temp;

                // Swap age
                temp = age[j];
                age[j] = age[j + 1];
                age[j + 1] = temp;
                // Swap id
                temp = id[j];
                id[j] = id[j + 1];
                id[j + 1] = temp;
            }
        }
    }
}

int main() 
{
    int id[100], marks[100], age[100], n;

    inputApplicants(id, marks, age, n);
    sortApplicants(id, marks, age, n);
     cout << "\nFinal Admission List:\n";
    for (int i = 0; i < n; i++) 
    {
        cout << "ApplicantID: " << id[i]  << ", Marks: " << marks[i] << ", Age: " << age[i];
    }
}
