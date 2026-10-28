#include <iostream>
using namespace std;

int main()
{
    int arr[9] = {4,2,8,0,5,7,1,3,9};
    for (int i = 0; i < (size(arr) - 1); i++)
    {
        for (int j = 0; j < (size(arr) - 1 - i); j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
            
        }
        
    }

    for (int i = 0; i < size(arr); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    system("pause");

    return 0;
}