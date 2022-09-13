// Game-2303-Week2-Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include<stdio.h>
using namespace std;

int main()
{  
    int start, end;
    double sum = 0;
    cout << "Enter number 0 ";
    cin >> start;
    cout << "Enter number 1000 ";
    cin >> end;

    if (start > end)
    {
        cout << "1000 number must be greater than 0 number \nTry again";
    }
    else
    {
        for (start; start < end; start++)
        {
            if (start % 3 == 0 || start % 5 == 0)
            {
                sum = sum + start;
            }
        }
        cout << "Sum of all divisible numbers between " << start << " to " << " is " << sum;
    }

    /* Idk
    cout << "Numbers for 0 to 1000 ";

    int counter1 = 0;
    int counter2 = 0;
    for (int i = 0; i <= 1000; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (i % j == 0)
                counter1++;
        }
        if(counter1 == 1)
        {
            cout << " ," << i;
            counter2++;
        }
        counter1 = 0;
    }
    cout << endl;
    cout << "Total number number from 0 to 100 is " << counter2 + 1;
    */

    /*
    char str[100], ch[100];
    int a = 0, i;
    cout << "Enter the string: ";
    gets_s(str);
    for (i = 0; str[i] != 0; i++)
    {
        a++;
    }
    for (i = 0; str[i] != 0; i++)
    {
        ch[i] = str[a - 1 - i];
    }
    ch[i] ='\0';
    cout << "Reversed string: " << ch;
    return 0;
    */

    /*
    string myString = "The cake is a lie!";

    cout << myString << endl;

    for (int i = 0; i < myString.length(); i++)
    {
        cout << myString[i] << endl;
    }
    */
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
