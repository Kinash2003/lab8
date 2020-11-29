#define _CRT_SECURE_NO_WARNINGS 
#include <iostream> 

using namespace std;

bool Count(char* s, char c) {
    if (s[0] == 0) return false;
    if (s[0] == c) return true;
    return Count(s + 1, s[0]);
}

void Change_r(char* s, char* newStr, char& state, int& strPos, int& Str) {
    if (s[strPos] == 0) {
        if (state == 'a') newStr[Str++] = 'a';
        if (state == 'b') newStr[Str++] = 'b';
        if (state == 'c') newStr[Str++] = 'c';
        newStr[Str++] = '\0';
        return;
    }

    switch (s[strPos]) {
    case 'a':
        if (state == 'a') {
            newStr[Str++] = '*';
            newStr[Str++] = '*';
            newStr[Str++] = '*';
            state = ' ';
        }
        else {
            if (state == 'b') newStr[Str++] = 'b';
            if (state == 'c') newStr[Str++] = 'c';
            state = 'a';
        }
        break;
    case 'b':
        if (state == 'b') {
            newStr[Str++] = '*';
            newStr[Str++] = '*';
            newStr[Str++] = '*';
            state = ' ';
        }
        else {
            if (state == 'a') newStr[Str++] = 'a';
            if (state == 'c') newStr[Str++] = 'c';
            state = 'b';
        }
        break;
    case 'c':
        if (state == 'c') {
            newStr[Str++] = '*';
            newStr[Str++] = '*';
            newStr[Str++] = '*';
            state = ' ';
        }
        else {
            if (state == 'a') newStr[Str++] = 'a';
            if (state == 'b') newStr[Str++] = 'b';
            state = 'c';
        }
        break;
    default:
        if (state == 'a') newStr[Str++] = 'a';
        if (state == 'b') newStr[Str++] = 'b';
        if (state == 'c') newStr[Str++] = 'c';
        newStr[Str++] = s[strPos];
        state = ' ';
        break;
    }
    strPos++;

    Change_r(s, newStr, state, strPos, Str);
    return;
}

int main() {
    char str[101];
    char newStr[151];

    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    bool changed = Count(str, ' ');

    char state = ' ';
    int strPos = 0;
    int newStrPos = 0;

    Change_r(str, newStr, state, strPos, newStrPos);

    cout << "String: " << str << endl << endl;
    if (changed) {
        cout << "String was modified." << endl;
        cout << "Modified string (result): " << newStr << endl;
    }
    else {
        cout << "String was not modified." << endl;
    }

    return 0;
}