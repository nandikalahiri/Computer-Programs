Q1. Write a program to check number palindrome and string palindrome.
INPUT - 
Palindrome - 
#include <iostream>
using namespace std;

int main()
{
    int n, r, temp, sum = 0;

    cout << "Enter the number = ";
    cin >> n;

    temp = n;

    while (n > 0)
    {
        r = n % 10;
        sum = (sum * 10) + r;
        n = n / 10;
    }

    if (temp == sum)
        cout << "The number is Palindrome";
    else
        cout << "The number is not Palindrome";

    return 0;
}
OUTPUT - 
Enter a string : 123
123 is not a Palindrome

String Palindrome - 
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char string1[20];
    int i, length;
    int flag = 0;

    cout << "Enter a string: ";
    cin >> string1;

    length = strlen(string1);

    for (i = 0; i < length; i++)
    {
        if (string1[i] != string1[length - i - 1])
        {
            flag = 1;
            break;
        }
    }

    if (flag)
    {
        cout << string1 << " is not a Palindrome" << endl;
    }
    else
    {
        cout << string1 << " is a Palindrome" << endl;
    }

    return 0;
}
OUTPUT - 
Enter a string : 123
123 is not a Palindrome
