#include <iostream>
#include <sstream>

using namespace std;

int reduce_number(int number)
{
    return number;
}

int main(int argc, char* argv[]) 
{
    if (argc <= 1)
    {
        cout << "Usage: ./reduce_number <integer>" << endl;
        return 0;
    }
    
    int number = atoi(argv[1]);
    int reduced_number = reduce_number(number);
    cout << reduced_number << endl;
    return 0;
}
