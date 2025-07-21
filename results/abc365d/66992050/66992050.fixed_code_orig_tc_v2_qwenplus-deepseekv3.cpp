#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    string S;
    cin >> N >> S;
    
    int ans = 0;
    char last = ' '; // Initialize to an invalid character
    
    for (char c : S) {
        char current;
        if (c == 'R') {
            current = 'P'; // Paper beats Rock
        } else if (c == 'P') {
            current = 'S'; // Scissors beat Paper
        } else { // 'S'
            current = 'R'; // Rock beats Scissors
        }
        
        if (current != last) {
            ans++;
            last = current;
        } else {
            // Need to choose a different move that doesn't lose
            // But since it's the same as last, it's a draw, so no increment
            last = current; // or perhaps choose another move, but it's irrelevant for counting wins
        }
    }
    
    cout << ans << endl;
    return 0;
}