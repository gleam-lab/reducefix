#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    string S;
    cin >> N >> S;
    
    // We want to minimize the number of changes so that no two adjacent characters are the same.
    // Instead of simulating a state machine, we can use greedy approach:
    // Traverse and whenever we see a repetition, change the current character to one that breaks the repetition.
    // But note: problem might be asking for minimum operations to make all adjacent different.
    
    // However, looking at the logic in original code: it seems to simulate a state machine
    // trying to track what the previous move was (in a Rock-Paper-Scissors like sequence? P,R,S)
    // But the logic is flawed.

    // Alternate interpretation: maybe we need to count minimum changes such that no two adjacent are same.
    // That's a classic greedy problem.

    if (N == 0) {
        cout << 0 << endl;
        return 0;
    }

    int ans = 0;
    char prev = S[0];
    
    for (int i = 1; i < N; i++) {
        if (S[i] == prev) {
            ans++;
            // Change S[i] to a character different from both prev and next (if exists)
            // We don't actually modify S, just simulate
            // Choose a temporary char that is not S[i] and not (i+1 < N ? S[i+1] : 0)
            char avoid = (i+1 < N) ? S[i+1] : 0;
            // The new "prev" will be a char != S[i] (which was equal to prev) and ideally not equal to next
            // But since we're only counting, we just set prev to something different
            // Let’s say we pick a char among 'P','R','S' that is not S[i] and not avoid
            for (char c : {'P', 'R', 'S'}) {
                if (c != S[i] && c != avoid) {
                    prev = c;
                    break;
                }
            }
            // If no such char (shouldn't happen with 3 chars), just pick any not S[i]
            if (prev == S[i]) {
                for (char c : {'P', 'R', 'S'}) {
                    if (c != S[i]) {
                        prev = c;
                        break;
                    }
                }
            }
        } else {
            prev = S[i];
        }
    }

    cout << ans;
    return 0;
}