#include <iostream>
#include <string>
using namespace std;

char winning_move(char c) {
    if (c == 'R') return 'P';
    if (c == 'P') return 'S';
    if (c == 'S') return 'R';
    return ' ';
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    int count = 1;
    char current = winning_move(s[0]);
    
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i-1]) {
            char next = winning_move(s[i]);
            if (next != current) {
                count++;
                current = next;
            }
        }
    }
    
    cout << count << endl;
    return 0;
}