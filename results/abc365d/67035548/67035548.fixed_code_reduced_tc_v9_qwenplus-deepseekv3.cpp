#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X'; // default case, though not needed if input is correct
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    int ans = 0;
    char prev = 'X'; // Initialize to an invalid move

    for (int i = 0; i < n; ++i) {
        char current = s[i];
        char optimal = win(current);
        if (optimal != prev) {
            ans++;
            prev = optimal;
        } else {
            // If the optimal move is the same as the previous, it doesn't count as a new win
            // So we keep the previous move for the next comparison
        }
    }

    cout << ans << endl;
    return 0;
}