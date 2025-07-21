#include <iostream>
#include <string>
using namespace std;

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X'; // default case
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
            ++ans;
            prev = optimal;
        } else {
            // If the previous move is the same as the optimal move for the current,
            // check if changing to another move can win the next one as well
            if (i + 1 < n) {
                char next = s[i + 1];
                if (win(next) != optimal) {
                    prev = win(next);
                } else {
                    prev = current;
                }
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}