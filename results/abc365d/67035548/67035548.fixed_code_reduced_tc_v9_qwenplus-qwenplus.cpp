#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Returns the winning move against c
char win(char c) {
    if (c == 'R') return 'P';
    if (c == 'P') return 'S';
    if (c == 'S') return 'R';
    return c; // Should never happen
}

int solve(const string& s) {
    int n = s.size();
    vector<char> best(n + 1); // best[i] = best choice at position i (after processing)
    best[n] = 'X'; // sentinel value
    
    int ans = 0;
    char curr = 'X'; // current choice
    
    for (int i = n - 1; i >= 0; --i) {
        char my_move = win(s[i]); // move that beats opponent
        
        // If we can continue our streak with current move
        if (curr != my_move) {
            ans++;
            curr = my_move;
        }
        
        best[i] = curr;
    }

    return ans;
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    // Two passes: one from left to right, one from right to left
    int forward = solve(s);
    
    reverse(s.begin(), s.end());
    int backward = solve(s);
    
    cout << max(forward, backward) << endl;
    
    return 0;
}