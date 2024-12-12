#include <iostream>
using namespace std;
int n;
#define size 10
template <class T>

void selectionSort(T A[size])
{
    int i, j, min;
    T temp;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[min])
            {
                min = j;
            }
        }

        temp = A[i];
        A[i] = A[min];
        A[min] = temp;
    }
    cout << "Sorted Array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "  " << A[i];
    }
}
int main()
{
    int A[size];
    float B[size];
    int ch;

    cout << "1. Integer Array" << endl;
    cout << "2. Float Array" << endl;
    cout << "3. Exit" << endl;
    cout << endl;
    cout << "Enter the choice: " << endl;
    cin >> ch;

    switch (ch)
    {
    case 1:
        cout << "Enter the size of the array: " << endl;
        cin >> n;
        cout << "Enter the integer elements in the array: " << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        selectionSort(A);
        break;

    case 2:
        cout << "Enter the size of the array: " << endl;
        cin >> n;
        cout << "Enter the float elements in the array: " << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> B[i];
        }
        selectionSort(B);
        break;
    case 3:
        exit(0);
    }
    return 0;
}