#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string str;
    cout << "Enter a string: ";
    cin >> str;  

    int left = 0, right = str.length() - 1;
    bool isPalindrome = true;

    while (left < right) {
        if (str[left] != str[right]) {
            isPalindrome = false;
            break;
        }
        left++;
        right--;
    }

    if (isPalindrome)
        cout << "Palindrome" << endl;
    else
        cout << "Not Palindrome" << endl;

    return 0;
}
