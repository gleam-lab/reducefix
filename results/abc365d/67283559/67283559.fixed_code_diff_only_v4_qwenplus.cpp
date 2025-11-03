#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;
    
    vector<char> choices = {'R', 'P', 'S'};
    auto getWinner = [](char a, char b) -> int {
        if ((a == 'R' && b == 'S') || (a == 'P' && b == 'R') || (a == 'S' && b == 'P')) {
            return 1;
        }
        return 0;
    };
    
    int maxScore = 0;
    
    // Try all possible starting hand choices
    for (char firstMove : choices) {
        vector<char> available = choices;
        // Remove the chosen move
        available.erase(remove(available.begin(), available.end(), firstMove), available.end());
        
        int score = 0;
        char currentMove = firstMove;
        
        for (int i = 0; i < N; i++) {
            // Check if current move wins
            if (getWinner(currentMove, S[i])) {
                score++;
            }
            
            // Update available moves for next round
            if (i < N - 1) {
                // The move we just used is no longer available
                // So the next move must be chosen from remaining two
                // Find which one of the two available options we should use
                char nextMove = ' ';
                for (char c : available) {
                    if (c != currentMove) {
                        nextMove = c;
                        break;
                    }
                }
                currentMove = nextMove;
                
                // Update available set: remove the move we're about to use
                // and add back the one we used two turns ago (if applicable)
                if (i >= 1) {
                    // After using a move, it becomes unavailable
                    // But the move from two rounds ago becomes available again
                    char moveTwoBack = firstMove;
                    if (i >= 2) {
                        // For i >= 2, we need to calculate what was used two moves ago
                        // This gets complex, so let's rethink our approach
                    }
                }
            }
        }
        
        maxScore = max(maxScore, score);
    }
    
    // Correct approach: simulate properly with state tracking
    maxScore = 0;
    
    for (int startIdx = 0; startIdx < 3; startIdx++) {
        vector<char> avail = {'R', 'P', 'S'};
        char current = avail[startIdx];
        avail.erase(avail.begin() + startIdx);
        
        int score = 0;
        
        for (int i = 0; i < N; i++) {
            // Play current move against opponent's move
            if ((current == 'R' && S[i] == 'S') ||
                (current == 'P' && S[i] == 'R') ||
                (current == 'S' && S[i] == 'P')) {
                score++;
            }
            
            if (i < N - 1) {
                // Next move must be from the remaining two
                // Choose optimally
                char nextFromAvail = avail[0]; // Just pick one from available
                
                // Reset availability: next state will have all moves except the one we're about to use
                vector<char> newAvail;
                for (char c : {'R', 'P', 'S'}) {
                    if (c != nextFromAvail) {
                        newAvail.push_back(c);
                    }
                }
                avail = newAvail;
                current = nextFromAvail;
            }
        }
        
        maxScore = max(maxScore, score);
    }
    
    // Complete correct solution
    maxScore = 0;
    
    // There are only 3 possible initial states
    for (int init = 0; init < 3; init++) {
        vector<char> hand = {'R', 'P', 'S'};
        char current = hand[init];
        vector<char> available;
        for (int i = 0; i < 3; i++) {
            if (i != init) available.push_back(hand[i]);
        }
        
        int score = 0;
        for (int i = 0; i < N; i++) {
            // Play current move
            if ((current == 'R' && S[i] == 'S') ||
                (current == 'P' && S[i] == 'R') ||
                (current == 'S' && S[i] == 'P')) {
                score++;
            }
            
            if (i < N - 1) {
                // For next move, we can only use one of the two available
                // We want to maximize future gains, but since we don't know future,
                // we just need to simulate both possibilities? 
                // Actually, the problem is simpler: at each step we have exactly two choices
                // But our choice now affects availability for next step
                
                // Since we don't have lookahead, we can try both branches
                // But that would be exponential. Instead, notice:
                // At each step, we have two available moves, we pick one, 
                // then the next step has the other one plus the one we used two steps ago
                // However, in this problem, the rule seems to be: you can't repeat moves consecutively,
                // but there's no restriction beyond that based on the typical interpretation
                
                // Re-reading the problem: "you cannot use the same hand twice in a row"
                // That's the only constraint!
                
                // So actually: at each step, you can use any move except the one you used in the previous step
                // But my code above is overcomplicating it.
                
                // Let me restart with correct understanding:
                // You start with all three moves available
                // After using a move, it becomes unavailable for the next turn only
                // On subsequent turns, it becomes available again
                // So constraint: cannot use same move twice consecutively
                
                // Therefore, at each position i, your choice depends only on what you used at i-1
                // This is a simple DP problem.
            }
        }
    }
    
    // Final correct solution with DP
    if (N == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    // dp[i][last] = maximum score up to turn i, where last is the move used at turn i (0=R, 1=P, 2=S)
    vector<vector<int>> dp(N, vector<int>(3, 0));
    
    // Initialize first move
    for (int j = 0; j < 3; j++) {
        char move = "RPS"[j];
        if ((move == 'R' && S[0] == 'S') ||
            (move == 'P' && S[0] == 'R') ||
            (move == 'S' && S[0] == 'P')) {
            dp[0][j] = 1;
        } else {
            dp[0][j] = 0;
        }
    }
    
    // Fill DP table
    for (int i = 1; i < N; i++) {
        for (int curr = 0; curr < 3; curr++) {
            char currentMove = "RPS"[curr];
            int win = 0;
            if ((currentMove == 'R' && S[i] == 'S') ||
                (currentMove == 'P' && S[i] == 'R') ||
                (currentMove == 'S' && S[i] == 'P')) {
                win = 1;
            }
            
            // Can come from any previous state except same move
            for (int prev = 0; prev < 3; prev++) {
                if (prev != curr) {  // Cannot use same move twice in a row
                    dp[i][curr] = max(dp[i][curr], dp[i-1][prev] + win);
                }
            }
        }
    }
    
    // Answer is max of last row
    int result = 0;
    for (int j = 0; j < 3; j++) {
        result = max(result, dp[N-1][j]);
    }
    
    cout << result << endl;
    
    return 0;
}