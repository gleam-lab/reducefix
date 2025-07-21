#include <iostream>
#include <string>

using namespace std;

char winning_move(char x) {
    if (x == 'R') return 'P';
    if (x == 'P') return 'S';
    if (x == 'S') return 'R';
    return 'X'; // should not happen
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    int changes = 0;
    char current_win = winning_move(s[0]);
    
    for (int i = 1; i < n; ++i) {
        char next_win = winning_move(s[i]);
        if (next_win != current_win) {
            changes++;
            current_win = next_win;
        }
    }
    
    // The initial move counts as the first strategy, so changes+1 is the total strategies used
    // But the problem asks for the number of changes, so changes is correct if we start with the first move's winning strategy.
    cout << changes + 1 << endl;
    
    return 0;
}