#include <iostream>
#include <sstream>

using namespace std;

int reduce_number(int number)
{
    if (number < 10)
    {
        return number;
    }
        
    string s{to_string(number)};
    size_t i;
    for (i = 0; i < s.length() - 1; ++i)
    {
        if (s[i] > s[i + 1])
        {
            break;
        }
    }
    return stoi(s.substr(0, i) + s.substr(i + 1, s.length() - (i + 1)));
}

int reduce_number_brute(int number)
{
    string original_string = to_string(number);
    int min_number = number;

    for (int i = 0; i < original_string.length(); i++)
    {
        string test = original_string;
        test.erase(i, 1);
        if (atoi(test.c_str()) < min_number)
        {
            min_number = atoi(test.c_str());
        }
    }
    
    return min_number;
}

int main(int argc, char* argv[]) 
{
    // if (argc <= 1)
    // {
    //     cout << "Usage: ./reduce_number <integer>" << endl;
    //     return 0;
    // }
    
    {
    time_t now = time(nullptr);
    for (int i = 1000000; i < 10000000; i++)
    {
        reduce_number(i);
    }
    time_t end = time(nullptr);
    cout << "It took " << end - now << " seconds to run the loop\n";
    }
    
    {
    time_t now = time(nullptr);
    for (int i = 1000000; i < 10000000; i++)
    {
        reduce_number_brute(i);
    }
    time_t end = time(nullptr);
    cout << "It took " << end - now << " seconds to brute run the loop\n";
    }
    
    
    
    // int number = atoi(argv[1]);
    // int reduced_number = reduce_number(number);
    // cout << reduced_number << endl;
    return 0;
}
