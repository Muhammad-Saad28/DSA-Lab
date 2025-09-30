#include <iostream>
using namespace std;

int SumIterative(int number) 
{
    int sum = 0;
    while (number > 0) {
        sum += number % 10;  
        number /= 10;        
    }
    return sum;
}

int SumRecursive(int number) 
{
    if (number == 0) 
        return 0;
    return (number % 10) + SumRecursive(number / 10);
}

int main() 
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    cout << "Sum of digits (Iterative): " << SumIterative(num) << endl;
    cout << "Sum of digits (Recursive): " << SumRecursive(num) << endl;

    return 0;
}
