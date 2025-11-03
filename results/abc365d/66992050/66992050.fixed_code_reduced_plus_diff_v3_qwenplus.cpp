#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    string S;
    cin >> N >> S;
    
    // We need to simulate the process of replacing consecutive occurrences
    // The key is to use a stack-like approach or iterative reduction
    // But simpler: simulate from left to right, keeping track of current state
    
    if (N == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    string result = "";
    for (char c : S) {
        if (result.empty()) {
            result += c;
        } else {
            char last = result.back();
            // Check if current character forms a reducible pair with last
            // PR -> R, RP -> P, PS -> S, SP -> P, RS -> R, SR -> S
            // But actually, we want to apply the transformation rules:
            // According to typical "Rock Paper Scissors" chain reduction:
            // When two adjacent different moves happen, one dominates.
            // However, based on expected outputs, this seems to be counting
            // the number of times a new "dominant" action starts
            
            // Actually, re-read: it looks like we're simulating a state machine
            // where each letter tries to dominate, and only when a weaker one follows
            // do we increment counter.
            
            // Alternate interpretation: greedy grouping. 
            // Let's try a different approach - use a stack
            bool reduced = false;
            if ((last == 'P' && c == 'R') || (last == 'R' && c == 'P')) {
                result.back() = 'P';
                reduced = true;
            } else if ((last == 'P' && c == 'S') || (last == 'S' && c == 'P')) {
                result.back() = 'S';
                reduced = true;
            } else if ((last == 'R' && c == 'S') || (last == 'S' && c == 'R')) {
                result.back() = 'R';
                reduced = true;
            }
            
            if (!reduced) {
                result += c;
            }
        }
    }
    
    // Now count how many transformations occurred = original length - final length
    // But wait, that doesn't match either.
    
    // Let's go back. Looking at sample: "PPR" -> expected 2
    // Step by step:
    // P -> state=P, count=1 (first occurrence)
    // P -> same as past ('P'), so no count, state stays P
    // R -> different from past ('P'), but rule says: if not past=='P', then add and set past='P'
    //       but past is 'P', so condition fails -> else branch: past='R'
    // So final count=1, but expected=2
    
    // Ah! The logic in conditions is inverted and incorrect.
    // Let's re-analyze:
    // It seems the intended logic is:
    // We are simulating a sequence of actions, and we want to count how many times
    // an action successfully "takes over" or initiates a new dominant phase.
    //
    // Correct approach: 
    // We traverse and maintain the current dominant action.
    // Whenever we see an action that beats the current dominant, we switch and increment count.
    //
    // Rules: Rock (R) beats Scissors (S), Scissors (S) beats Paper (P), Paper (P) beats Rock (R)
    //
    // So:
    // - If current is R, then only S can beat it
    // - If current is S, then only P can beat it  
    // - If current is P, then only R can beat it
    
    char current = S[0];
    int ans = 1; // first character always counts
    
    for (int i = 1; i < N; i++) {
        char c = S[i];
        if (c == current) {
            continue; // same as current, no change
        }
        
        // Check if c beats current
        if ((c == 'R' && current == 'S') ||
            (c == 'S' && current == 'P') ||
            (c == 'P' && current == 'R')) {
            current = c;
            ans++;
        }
        // If current beats c, then no change in dominance, don't increment
    }
    
    cout << ans;
    return 0;
}