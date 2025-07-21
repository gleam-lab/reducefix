#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    string S;
    cin >> N >> S;
    char past = 'N'; // Initialize with a neutral value
    int ans = 0;
    for (char c : S) {
        if (past == 'N') {
            past = c; // First move, just set the past
            continue;
        }
        // Check if current move beats the computer's previous move
        if ((c == 'P' && past == 'R') || 
            (c == 'R' && past == 'S') || 
            (c == 'S' && past == 'P')) {
            ans++;
        }
        past = c; // Update the past move for next iteration
    }
    cout << ans;
    return 0;
}