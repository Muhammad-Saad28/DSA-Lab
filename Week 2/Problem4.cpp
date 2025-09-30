#include <iostream>
#include <string>
using namespace std;

string compressString(const string& str) 
{
    string result = "";
    int n = str.length();

    for (int i = 0; i < n; i++) 
    {
        int count = 1;
        while (i + 1 < n && str[i] == str[i + 1]) 
        {
            count++;
            i++;
        }
        result += str[i];
        result += to_string(count);
    }

    return result;
}

int main() 
{
    string input;
    cout << "Enter a string: ";
    cin >> input;

    string compressed = compressString(input);
    cout << "Compressed string: " << compressed << endl;

    return 0;
}
