#include <iostream>
#include <string>
using namespace std;

int cmp(char x, char y) {
    if (x == 'X') return -100;
    if (y == 'X') return 100;
    if (x == y) return 0;
    if ((x == 'P' && y == 'R') || (x == 'R' && y == 'S') || (x == 'S' && y == 'P')) return 1;
    return -1;
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    int transitions = 0;
    char prev = 'A';
    for (int i = 0; i < n; ++i) {
        int result = cmp(s[i], prev);
        if (result == 1 || result == 100) { // next character is winning
            ++transitions;
        }
        prev = s[i];
    }
    cout << transitions;
    return 0;
}