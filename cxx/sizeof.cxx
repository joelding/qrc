#include <iostream>
using namespace std; 

int main(int argc, char *argv[]) 
{ 
    cout << "\nTYPE\tSIZEOF(bytes)"; 
    cout << "\nsizeof(int)\t" << sizeof(int); 
    cout << "\nsizeof(long)\t" << sizeof(long); 
    cout << "\nsizeof(float)\t" << sizeof(float); 
    cout << "\nsizeof(double)\t" << sizeof(double); 
    cout << "\nsizeof(char)\t" << sizeof(char);
    cout << "\n";

    cout << "sizeof(bool)\t" << sizeof(bool) << "\n";
    cout << "sizeof(true)\t" << sizeof(true) << "\n";
    cout << "sizeof(false)\t" << sizeof(false) << "\n";

    cout << "true\t" << static_cast<int>(true) << "\n";
    cout << "false\t" << static_cast<int>(false) << "\n";
 
    return 0; 
} 

