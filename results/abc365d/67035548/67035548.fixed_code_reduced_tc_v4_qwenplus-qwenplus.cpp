#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Returns the move that beats the given move
char winning_move(char c) {
    if (c == 'R') return 'P';
    if (c == 'P') return 'S';
    if (c == 'S') return 'R';
    return c; // for completeness, though not used with 'X'
}

int solve(const string& s) {
    int n = s.size();
    int count = 0;
    char last = 'X'; // Initially no move
    
    for (int i = 0; i < n; ++i) {
        if (last != winning_move(s[i])) {
            count++;
            last = winning_move(s[i]);
        } else {
            last = s[i];
        }
    }
    
    return count;
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    // Forward solution
    int forward = solve(s);
    
    // Backward solution
    reverse(s.begin(), s.end());
    int backward = solve(s);
    
    // Return the maximum of both approaches
    cout << max(forward, backward) << endl;
    
    return 0;
}