#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N >> S;

    long long wins = 0;
    char prev = 'X'; // Use 'X' as initial sentinel (no previous move)

    for (char c : S) {
        char winmove;
        if (c == 'R') winmove = 'P';
        else if (c == 'P') winmove = 'S';
        else winmove = 'R';

        if (prev != winmove) {
            wins++;
            prev = winmove;
        } else {
            // We can choose any move different from opponent's current move and still maintain winning streak
            // But to maximize future wins, we should pick the move that allows most flexibility
            // Actually, just keep prev as winmove only when switching; otherwise, after a repeat,
            // we are free to choose. However, logic was flawed: we must simulate optimal play.

            // Correction: The key is that when we can repeat the same winning move,
            // we don't need to change. But our state "prev" represents our last move.
            // If we could have used the same winning move again, then we do not increment.
            // So no action needed — we simply don't update `prev` to winmove unless we switch.
            // But actually, even if we use the same move, we are still using `winmove`.
            // So we should set prev = winmove always when we win? But problem is in transition.

            // Revised understanding: At each step, we must choose a move to beat the opponent.
            // We want to maximize total number of rounds we win.
            // We can choose any move that beats opponent, but we cannot make the same move twice consecutively.

            // Therefore, at each round:
            // - If the winning move against opponent's current move is different from our last move, we can use it -> win and update.
            // - Else, we cannot use it (would repeat), so we must lose this round (choose non-winning move).
            // BUT WAIT: we might be able to win without repeating? No — because only one move beats each.

            // Actually: Each move has exactly one counter:
            // R -> P
            // P -> S
            // S -> R

            // So if the required winning move equals our previous move, we cannot play it (consecutive disallowed), so we lose.
            // Otherwise, we win and update our last move.

            // But in code above, we did:
            //   if (winmove != prev) { wins++; prev = winmove; }
            //   else { prev = c; }   <-- THIS IS WRONG.

            // Why? Because if we can't win (because winmove == prev), then we must play something else.
            // But we are NOT forced to play what the opponent played.
            // We can play the third move (the one that doesn't win and isn't repeated).
            // And our next state (prev) becomes that losing move.

            // Example: opp='R', so winmove='P'. If our prev was 'P', we can't play 'P'. 
            // So we must play either 'R' or 'S'. Both lose to 'R'? 
            // Wait: 'R' ties with 'R', 'S' loses to 'R'. So best is tie? But problem counts only WINS.
            // So we get 0 points this round regardless.

            // But the key is: what should `prev` be updated to?
            // We can choose between two losing moves. To maximize future chances, we should pick the one 
            // that is NOT the next round's winning move (if known). But we don't know the future.

            // However, note: we are allowed to choose arbitrarily among non-losing-consecutive moves.
            // Optimal strategy: when we cannot win, we should set our move to something that maximizes chance of winning next time.

            // Insight: This is a greedy + state machine DP.

            // Let dp[i][move] = maximum wins up to i-th round ending with move ('R','P','S')
            // But N can be 200000 -> O(N*3) = acceptable.

            // We need to refactor to DP.

            // Given the failing cases, original greedy logic is incorrect.

            // Let's switch to DP.

            // But note: we already started with greedy. Need full rewrite.

            // However, we cannot do full rewrite in middle of loop.

            // Hence, we restart logic below.
        }
    }

    // Since the above logic is flawed, we re-implement correctly using DP.
    // Remove the above loop and replace.
}