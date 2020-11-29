
#include <iostream>
#include <cstring>
#include <string>
#define TESTING

using namespace std;

string Change(string& str)
{
    if (str.length() < 2)
    {
        cout << "Введіть більше символів";
        return str;
    }

    while (str.find("aa") != -1)
    {
        str = str.replace(str.find("aa"), 3, "***");

    }
   
    while (str.find("bb") != -1)
    {
        str = str.replace(str.find("bb"), 3, "***");
    

    }
    
    while (str.find("cc") != -1)
    {
        str = str.replace(str.find("cc"), 3, "***");

    }
    return str;
}

#ifdef TESTING
int main()
{
    string str;
    cout << "Enter string:" << endl;
    getline(cin, str);
    cout << "Modified string (param) : " << str << endl;

    Change(str);

    cout << "Modified string (result): " << str << endl;
    return 0;
}
#endif
