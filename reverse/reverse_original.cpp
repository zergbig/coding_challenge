#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char* argv[]) 
{
    if (argc <= 1)
    {
        cout << "Usage: ./reverse <some string>" << endl;
        return 0;
    }
    
    char* originalStr = argv[1];
    int reversedStrLen = strlen(originalStr) + 1;
    char * reversedStr = new char[reversedStrLen];
    memset(reversedStr, 0, reversedStrLen);
    
    for(int i = 0; i < reversedStrLen; i++)
    {
    	reversedStr[i] = originalStr[reversedStrLen - i];
    }
    
    cout << reversedStr << "\n";
}