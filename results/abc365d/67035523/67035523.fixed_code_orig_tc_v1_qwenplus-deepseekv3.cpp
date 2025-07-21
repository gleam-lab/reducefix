#include <iostream>
#include <string>

using namespace std;

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X'; // Default case, though not needed if input is correct
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    char current = win(s[0]);
    int changes = 1;

    for (int i = 1; i < n; ++i) {
        char next = win(s[i]);
        if (next != current) {
            changes++;
            current = next;
        }
    }

    cout << changes << endl;
    return 0;
}