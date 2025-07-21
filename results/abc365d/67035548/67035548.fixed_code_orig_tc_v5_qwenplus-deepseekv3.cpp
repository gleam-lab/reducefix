#include <iostream>
#include <string>
using namespace std;

char getWin(char c) {
    if (c == 'R') return 'P';
    if (c == 'P') return 'S';
    if (c == 'S') return 'R';
    return ' ';
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    char prev = ' ';
    int count = 0;
    
    for (char c : s) {
        char win = getWin(c);
        if (win != prev) {
            count++;
            prev = win;
        }
    }
    
    cout << count << endl;
    return 0;
}