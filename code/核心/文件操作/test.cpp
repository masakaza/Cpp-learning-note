#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream ifs("test.txt",ios::in);

    int count = 0;
    string n;
    while (getline(ifs,n))
    {
        if (!n.empty())
        {
            count++;
        }
        
    }

    cout << count << endl;
    return 0;
}

