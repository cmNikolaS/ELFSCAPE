#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{

    int B = 18;
    srand(time(0));

    for(int i = 0; i < 100; i++)
    {
        cout << rand()%(B-1)+1 << " ";
    }




    return 0;
}