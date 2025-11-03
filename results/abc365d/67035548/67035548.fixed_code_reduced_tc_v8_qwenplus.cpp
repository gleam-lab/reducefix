#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <cmath>
#include <iomanip>
using namespace std;

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X';
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    // dp[i][last] = maximum rounds we can survive up to position i, ending with move 'last'
    // last: 0='R', 1='P', 2='S'
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));
    
    auto getIdx = [](char c) {
        if (c == 'R') return 0;
        if (c == 'P') return 1;
        if (c == 'S') return 2;
        return -1;
    };
    
    auto getChar = [](int idx) {
        if (idx == 0) return 'R';
        if (idx == 1) return 'P';
        if (idx == 2) return 'S';
        return 'X';
    };
    
    // Initialize base case
    for (int j = 0; j < 3; j++) {
        char myMove = getChar(j);
        if (myMove == win(s[0])) {
            dp[0][j] = 1; // We beat opponent's first move
        } else if (myMove != s[0]) {
            dp[0][j] = 1; // Draw or loss doesn't end game, but we survive round
        }
        // Actually, in rock-paper-scissors, any move plays the round.
        // The round is played regardless. We want to maximize consecutive rounds?
        // But problem seems to be about surviving as long as possible.
        // Re-read: It appears we are simulating a tournament where you must beat the current champion.
        // But based on expected output, let's reconsider.
    }

    // After re-analyzing the sample:
    // Input: 4, PPRP -> Output: 3
    // Let's simulate:
    // We need to choose moves such that we win as many rounds as possible consecutively?
    // But the logic isn't matching.

    // Alternate interpretation from known similar problems:
    // This looks like "Fight Monster" or "Rock Paper Scissors" tournament problem.
    // You start as challenger. To beat a champion, you must play their winning move.
    // Once you win, you become the champion (your move becomes the one just played).
    // If you lose or draw, you keep your current move and try again next round?

    // Actually, based on common problems: 
    // You go through each character in the string (champions).
    // You can choose any move initially.
    // To defeat a champion showing move X, you must use win(X).
    // After defeating, your current move becomes the one you just used.
    // If you fail to defeat, you can change your move freely for the next round.

    // But sample: "PPRP"
    // Round 1: Champion shows 'P'. To beat it, use 'S'. Use 'S' -> win. Current move = 'S'
    // Round 2: Champion shows 'P'. We have 'S', which beats 'P'. So we win without changing. Current move = 'S'
    // Round 3: Champion shows 'R'. We have 'S', which loses to 'R'. So we must switch to 'P' to beat 'R'. Win. Move = 'P'
    // Round 4: Champion shows 'P'. We have 'P' -> draw? Do we lose? Or do we need to beat?
    // Problem: do we need to *beat* or just *not lose*?

    // But we got output 2 vs expected 3.

    // Alternative known solution approach for "maximum wins" in RPS string:
    // Try all 3 starting moves and simulate greedily.

    int maxWins = 0;
    for (char start : {'R', 'P', 'S'}) {
        char current = start;
        int wins = 0;
        for (int i = 0; i < n; i++) {
            if (current == win(s[i])) {
                wins++;
                // After winning, our move becomes the winning move
                // But wait: when we win, we played 'win(s[i])', so that becomes our current move
                current = win(s[i]);
            } else {
                // We don't win, so we can choose to switch to the winning move for next time
                // But this round we don't win, so no increment
                // However, we can prepare: set current to win(s[i]) for next round?
                // But only if we want to win next round. But we are simulating fixed strategy.
                // Actually, even if we lose this round, we can change our move freely for the next round.
                // So we set our move to win(s[i]) so we can win this round? No, too late.
                // But for the next round, we can have optimal move.
                // However, we didn't win this round, so we don't update our move due to win.
                // But we are allowed to change our move at will between rounds?
                // Yes — the problem typically allows choosing any move each round.
                // But then why not win every round?
                // Ah! Key insight: after you win a round, your move becomes fixed to the move you used to win.
                // If you lose or draw, you can change your move arbitrarily next round.

                // So:
                // - If you win: your move becomes the move you played (which is win(opponent))
                // - If you lose/draw: you can pick any move for next round

                // Therefore, in losing state, we can plan optimally.

                // So in simulation:
                // If we can win this round (current == win(s[i])), we do and lock our move.
                // Otherwise, we don't win, but we can choose what move to use for next round.
                // To maximize future wins, we should set our move to win(s[i]) so we can win next round?
                // But no: we are not forced. We can pick any move. So we don't win this round,
                // but we can set up for future.

                // However, since we are simulating a fixed starting move, we must decide:
                // What move do we use this round if we aren't going to win?
                // Actually, it doesn't matter because we lose anyway, and we can change freely next round.
                // So we just don't win, and then for next round we can pick anything.

                // But crucially: we are allowed to pick any move each round unless we won the previous round.
                // Wait: correction from standard problem: 
                // "After winning, your weapon changes to the one you used to win, and you cannot change it until you win again."
                // No — usually it's: once you win, your move is locked to that move going forward?
                // Or: after winning, you adopt that move as your current move, and you keep it until you decide to change (but you can only change when not coming from a win?)

                // Actually, standard rule in these problems: 
                // - You start with any move.
                // - Each round, you must use your current move unless you lost/drew last round, in which case you can switch.
                // But here, there's no mention of last round status.

                // Let's look at simpler simulation.

                // Known accepted solution idea for same problem:
                // Try all three endings and reverse.

                // Another idea: 
                // f(s) = maximum number of wins achievable
                // We can use DP: state = (position, current_move)
                // Transition:
                //   Option 1: if current_move == win(s[i]), then we can win this round -> dp[i+1][win(s[i])] = max(dp[i+1][win(s[i])], dp[i][current_move] + 1)
                //   Option 2: we don't win, but we can switch to any move for next round -> for all m in {R,P,S}, dp[i+1][m] = max(dp[i+1][m], dp[i][current_move])
                // But note: if we don't win, we are free to change move, so we can jump to any state.

                // Base: at i=0, we can start with any move, so dp[0][m] = 0 for all m.

                // Then answer = max(dp[n][0..2])

                // Let's test with "PPRP"

                // i=0, s[0]='P', win('P')='S'
                // For m='S': we win -> dp[1]['S'] = 1
                // For m!='S': we don't win -> we can transition to any move at i=1, so dp[1][*] = max(dp[1][*], 0)

                // So after i=1: dp[1]['S']=1, others=0

                // i=1, s[1]='P', win='S'
                // From state 'S': we have move 'S' which wins against 'P' -> dp[2]['S'] = max(dp[2]['S'], 1+1)=2
                // From other states (0): we can do nothing new

                // i=2, s[2]='R', win='P'
                // From state 'S': 'S' vs 'R' -> 'S' loses, so we don't win. But we can switch to any move for next round.
                // So we propagate: dp[3][R]=max(dp[3][R],2), dp[3][P]=max(...,2), dp[3][S]=max(...,2)
                // So all states at i=3 have value 2

                // i=3, s[3]='P', win='S'
                // Now from any state at i=3:
                //   if move is 'S': win -> value 2+1=3
                //   otherwise: no win, but propagate 2
                // So dp[4]['S'] = 3

                // Answer = 3 -> matches expected.

                // So we implement DP.

                // We break out of the loop and redo with DP.
            }
        }
    }

    // Redo with proper DP
    vector<vector<int>> dp2(n + 1, vector<int>(3, 0));
    
    // At start, we can choose any move, so initial cost 0 for all
    // dp2[i][j] = max wins up to round i (after processing i-th opponent) ending with move j
    
    for (int j = 0; j < 3; j++) {
        dp2[0][j] = 0;
    }
    
    for (int i = 0; i < n; i++) {
        char opp = s[i];
        char beat = win(opp); // move needed to beat opponent
        int beat_idx = getIdx(beat);
        
        for (int j = 0; j < 3; j++) { // j: current move index
            if (dp2[i][j] == 0 && i > 0) continue; // unreachable state?
            // But we initialize all at i=0, so should be fine.
            
            char my_move = getChar(j);
            if (my_move == beat) {
                // We win this round
                // After winning, our move becomes the one we used: j (same)
                dp2[i+1][j] = max(dp2[i+1][j], dp2[i][j] + 1);
            } else {
                // We don't win, but we can switch to any move for next round
                for (int k = 0; k < 3; k++) {
                    dp2[i+1][k] = max(dp2[i+1][k], dp2[i][j]);
                }
            }
        }
    }
    
    int ans = 0;
    for (int j = 0; j < 3; j++) {
        ans = max(ans, dp2[n][j]);
    }
    
    cout << ans << endl;
    
    return 0;
}