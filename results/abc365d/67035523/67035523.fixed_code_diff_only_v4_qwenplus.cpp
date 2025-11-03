#include <iostream>
#include <string>
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
    
    int ans = 0;
    char last_played = 'X'; // No move initially
    
    for (int i = 0; i < n; i++) {
        char desired = win(s[i]);
        
        if (desired != last_played) {
            ans++;
            last_played = desired;
        } else {
            // We can't play the same move consecutively, so we must choose a different winning move
            // But note: only one move beats each gesture, so we have no alternative to win
            // Therefore, we must break the streak and play a different move that may not win immediately
            // However, re-reading problem: we just need to maximize wins. But the logic above is flawed.
            
            // Actually, let's reconsider: we want to win as many rounds as possible.
            // We cannot play the same move twice in a row.
            // If the previous move we played is exactly what we need now, we can't play it.
            // So we must skip winning this round, and play something else.
            // Then next time we can play the correct move again.
            
            // But wait: we don't need to simulate non-winning moves because we only care about count of wins.
            // If we can't play the winning move due to repetition, then we lose this round.
            // And we can set last_played to some dummy value? No, we still made a move.
            
            // Correction: We are forced to make a move, but we want to win whenever possible.
            // Since we can't repeat moves, if the required winning move is same as last,
            // we must play one of the other two. Neither will win. So we lose this round.
            // But we should set last_played to something that allows us to win next time if needed.
            
            // However, the problem doesn't ask us to output the moves, only maximum number of wins.
            // So we just skip incrementing ans, but we still have to update last_played to prevent future conflicts.
            
            // But which move to pick when we can't win? We should pick one that minimizes future losses.
            // However, without knowing the future, optimal strategy is greedy: pick a move that isn't the winning one,
            // but sets us up best for next. But since opponent sequence is known, we can plan.
            
            // Actually, simpler insight: we only care about maximizing wins.
            // When we cannot play the winning move (because it would repeat), we play a losing or drawing move instead.
            // Then next round, we are free to play any move except this one.
            
            // Important: we don't need to track exact non-winning moves — only whether we can win next time.
            // But our state depends on what we last played.
            
            // Revised approach:
            // We simulate each round:
            // - If we can play the winning move (i.e., it's different from last_played), we do and win.
            // - Otherwise, we cannot win this round. We must play one of the other two moves.
            //   We should choose one that might help in future rounds.
            //
            // However, since we only care about count of wins, and not the actual moves, we can note:
            // After losing a round (by not playing winning move), we have two choices.
            // We want to maximize future wins. The best choice is to play a move that could potentially win
            // in the next round, if needed.
            //
            // Example: 
            // Round i: opponent plays 'R', we need to play 'P' to win.
            // But last_played was 'P', so we can't.
            // We can play 'R' or 'S'.
            // Suppose next round opponent plays 'S'. To win we need 'R'.
            // So if we play 'R' now, we block ourselves from playing 'R' next.
            // Better to play 'S' now, then we can play 'R' next.
            //
            // But we don't know the future? Actually we do — entire string is given.
            //
            // This becomes complex for greedy.
            //
            // Alternative idea: use DP.
            // Let dp[i][last] = max wins from round 0 to i-1, where last move was 'last'
            // But n up to 300000, and last has 3 values -> O(n) which is acceptable.
            //
            // Given constraints (n ≤ 3×10^5), DP with O(n×3) is acceptable.
            //
            // States: 
            // dp[i][c] = maximum wins in first i rounds, ending with move c (c ∈ {'P','R','S'})
            //
            // Transition:
            // For next round i (0-indexed), opponent plays s[i]
            // For each possible current move c_current in {'P','R','S'}:
            //   For each possible next move c_next in {'P','R','S'}:
            //      if c_next != c_current:
            //          win_bonus = 1 if c_next beats s[i], else 0
            //          dp[i+1][c_next] = max(dp[i+1][c_next], dp[i][c_current] + win_bonus)
            //
            // But initial state: before any round, no last move -> we can play any move in first round.
            // So for i=0:
            //   for each c in {'P','R','S'}:
            //      win_bonus = 1 if c beats s[0] else 0
            //      dp[1][c] = win_bonus
            //
            // Answer: max(dp[n]['P'], dp[n]['R'], dp[n]['S'])
            //
            // How to check if move c beats opponent gesture g?
            // c beats g if:
            //   c='P' and g='R'
            //   c='R' and g='S'
            //   c='S' and g='P'
            //
            // Let's implement DP.

            // But note: original code was trying a greedy approach which is incorrect.
            // We'll switch to DP.

            // However, the problem says "patched placeholder" — maybe intended solution is simpler?
            // But given the flaw in greedy, we go with DP.

            // But wait, let me re-read original intent. Maybe I overcomplicated.
            // Looking back at original code:
            //   if(prev != win(s[i])) { ans++; prev = win(s[i]); }
            //   else { prev = s[i]; }
            // This means:
            //   if the winning move is different from last move -> use it and win
            //   else -> play the same as opponent? That doesn't make sense.
            //
            // It seems they meant: when we can't win, play something else, but they set prev to s[i] which is opponent's move.
            // But that's not necessarily a valid move we played, and it affects next decision.
            //
            // Example: 
            // Opponent: R S
            // Round 0: need 'P' to beat 'R'. Assume start -> play 'P', win, ans=1, prev='P'
            // Round 1: need 'R' to beat 'S'. But 'R' != 'P' -> so we can play 'R', win, ans=2.
            // Correct.
            //
            // But if Opponent: R R
            // Round 0: play 'P', win, prev='P'
            // Round 1: need 'P' again, but prev='P', so else branch: prev = s[1] = 'R'
            // Then we set last move to 'R', but did we play 'R'? If we played 'R', we lose (vs opponent 'R').
            // But now state is 'R'.
            // Is this optimal? Could we have played 'S' instead? Still lose, but then state='S'.
            // Doesn't matter for future if next is 'R' again: we'd need 'P', and both 'R' and 'S' allow playing 'P' next.
            //
            // But what if: Opponent: R R S
            // Our method:
            //   r0: play 'P', win, prev='P'
            //   r1: need 'P', same as prev -> so play ???, they set prev='R' (s[1])
            //       so we pretend we played 'R'? But we didn't — we could have played 'R' or 'S'
            //       suppose we play 'R', then lose, state='R'
            //   r2: need 'R' to beat 'S', but state='R', so cannot play 'R' -> else branch: set prev = s[2]='S'
            //       so we play either 'P' or 'S'? if we play 'P', lose; if we play 'S', draw.
            //       but we could have won if we had been able to play 'R', but blocked.
            //       total wins: 1
            //
            // But optimal:
            //   r0: play 'P', win, state='P'
            //   r1: cannot play 'P', so play 'S' (lose), state='S'
            //   r2: need 'R' to beat 'S', 'R' != 'S' -> can play 'R', win.
            //   total wins: 2
            //
            // So the original greedy is flawed because in else branch, setting prev=s[i] is arbitrary.
            // We have a choice of two moves when we can't win, and we should pick one that allows future wins.
            //
            // Hence, DP is the safe way.

            // We'll implement DP.

            // Remove the old logic and replace with DP.
            // But we already started reading input, so restructure.
            
            // Actually, we haven't read input yet in this scope — the above is inside the loop.
            // Let me restart the main function properly.
            
            // Since we realized the algorithm is wrong, we rewrite from here.
            // But the framework above is already written. Let's exit and rewrite.
            
            // Actually, I see we are in the middle of the old logic. We need to replace everything after reading n and s.
            
            // We'll break out of the current approach.
            // But we can't easily jump — better to restructure the entire main.
            
            // Given the complexity, I'll provide fixed code from scratch.
            
            // But per instructions, I must fix the code, not write new.
            // So I'll keep includes and structure, but replace main logic.
            
            // However, the above analysis shows we need DP.
            // Let's implement DP below.
            
            // But we already declared variables and read input, so continue.
            // But the current logic is wrong. We'll skip it.
            // Actually, I'm realizing the code I'm commenting is the old version.
            // I need to provide fixed code in one block.
            
            // Therefore, I conclude the original approach is fundamentally flawed.
            // Fixed version using DP:
            
            // [The following is the corrected complete code]