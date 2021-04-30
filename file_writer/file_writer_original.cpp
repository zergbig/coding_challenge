#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class FileWriter
{
public:
    FileWriter(const string& fileName): m_fh(nullptr), m_fileName(fileName)
    {
        // Only open existing files for reading and writing.
        // This is done by passing r+
        m_fh = fopen(fileName.c_str(), "r+");
    }
    
    virtual ~FileWriter()
    {
        fclose(m_fh);
    }
    
    size_t writeData(const char* data, size_t dataLen)
    {
        if (nullptr == data || 0 == dataLen)
        {
            return 0;
        }
        
        int rc = fseek(m_fh, 0, SEEK_END);
        if (rc != 0)
        {
            // Error seeking to the end of the file
            return 0;
        }
        
        return fwrite(data, sizeof(char), dataLen, m_fh);
    }
    
private:
    FILE* m_fh;
    string m_fileName;
};

int main(int argc, const char* argv[])
{
    if (argc < 2)
    {
        cout << "Please pass in a file name on the command line" << endl;
        return 0;
    }

    FileWriter fw(argv[1]);
    const char* data = "All work and no play makes Jack a dull boy.\n";
    size_t writeCount = fw.writeData(data, strlen(data));
    cout << "Wrote " << writeCount << " bytes to " << argv[1] << endl;
	return writeCount == 0;
}
