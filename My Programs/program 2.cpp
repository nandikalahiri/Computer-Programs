Q2. Write a program to show the effect of call by value and call by reference in functions.
  INPUT - 
  Call By Value - 
  #include <iostream>
using namespace std;

void swap(int x, int y)
{
    int temp = x;
    x = y;
    y = temp;

    cout << "After swap: a = " << x << " b = " << y << endl;
}

int main()
{
    int a = 40;
    int b = 50;

    cout << "Before swap: a = " << a << " b = " << b << endl;

    swap(a, b);

    return 0;
}
OUTPUT - 
  Before swap: a = 40 b = 50
  After swap : a = 50 b = 40
  Call By Reference - 
  #include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int x = 5;
    int y = 10;

    cout << "Before swap: x = " << x << ", y = " << y << endl;

    swap(&x, &y);

    cout << "After swap: x = " << x << ", y = " << y << endl;

    return 0;
}
OUTPUT - 
  Before swap : x = 5 y = 10
  After swap : x = 10 y = 5
