#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    string S;
    cin >> N >> S;
    
    if (N == 0) {
        cout << 0;
        return 0;
    }
    
    int ans = 0;
    char prev = S[0];
    
    for (int i = 1; i < N; i++) {
        char current = S[i];
        // Check if current move beats previous move
        if ((prev == 'R' && current == 'P') ||
            (prev == 'P' && current == 'S') ||
            (prev == 'S' && current == 'R')) {
            ans++;
            prev = current; // Only update when we win
        }
        // If same move, continue the streak
        else if (prev == current) {
            continue;
        }
        // If lost, reset the streak
        else {
            prev = current;
        }
    }
    
    cout << ans;
    return 0;
}