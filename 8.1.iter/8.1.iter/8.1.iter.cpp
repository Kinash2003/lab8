#define _CRT_SECURE_NO_WARNINGS 
#include <iostream> 

using namespace std;

void Count(char* s, char* Str, bool& chang) {
    char state = ' ';
    int strPos = 0;
    int newStr = 0;
    chang = false;

    while (s[strPos] > 0) {
        switch (s[strPos]) {
        case 'a':
            if (state == 'a') {
                Str[newStr++] = '*';
                Str[newStr++] = '*';
                Str[newStr++] = '*';
                chang = true;
                state = ' ';
            }
            else {
                if (state == 'b') Str[newStr++] = 'b';
                if (state == 'c') Str[newStr++] = 'c';
                state = 'a';
            }
            break;
        case 'b':
            if (state == 'b') {
                Str[newStr++] = '*';
                Str[newStr++] = '*';
                Str[newStr++] = '*';
                chang = true;
                state = ' ';
            }
            else {
                if (state == 'a') Str[newStr++] = 'a';
                if (state == 'c') Str[newStr++] = 'c';
                state = 'b';
            }
            break;
        case 'c':
            if (state == 'c') {
                Str[newStr++] = '*';
                Str[newStr++] = '*';
                Str[newStr++] = '*';
                chang = true;
                state = ' ';
            }
            else {
                if (state == 'a') Str[newStr++] = 'a';
                if (state == 'b') Str[newStr++] = 'b';
                state = 'c';
            }
            break;
        default:
            if (state == 'a') Str[newStr++] = 'a';
            if (state == 'b') Str[newStr++] = 'b';
            if (state == 'c') Str[newStr++] = 'c';
            Str[newStr++] = s[strPos];
            state = ' ';
            break;
        }
        strPos++;
    }
    if (state == 'a') Str[newStr++] = 'a';
    if (state == 'b') Str[newStr++] = 'b';
    if (state == 'c') Str[newStr++] = 'c';
    Str[newStr++] = '\0';
    return;
}

int main() {
    char str[101];
    char newStr[151];
    bool chang;

    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    Count(str, newStr, chang);

    cout << "String: " << str << endl << endl;
    if (chang) {
        cout << "String was modified." << endl;
        cout << "Modified string (result): " << newStr << endl;
    }
    else {
        cout << "String was not modified." << endl;
    }

    return 0;
}
	
