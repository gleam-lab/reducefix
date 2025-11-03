#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    string S;
    cin >> N >> S;
    
    // We want to minimize the number of changes such that no two adjacent characters are the same
    // and the sequence follows R -> P -> S -> R cycle
    
    // Key idea: use DP where state is (position, last_move)
    // But note: we can also think greedily with state machine
    
    // Alternate approach: try all 3 possible starting moves and simulate
    int ans = N; // worst case: change every character
    
    // Try each possible initial gesture
    for (char start : {'R', 'P', 'S'}) {
        int changes = 0;
        char current = start;
        
        for (char c : S) {
            if (c == current) {
                // No change needed
            } else {
                changes++;
            }
            
            // Move to next in cycle: R->P->S->R
            if (current == 'R') current = 'P';
            else if (current == 'P') current = 'S';
            else current = 'R';
        }
        
        ans = min(ans, changes);
    }
    
    cout << ans;
    return 0;
}