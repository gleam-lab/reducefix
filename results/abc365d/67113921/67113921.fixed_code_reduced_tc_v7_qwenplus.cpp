#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N;
    cin >> S;
    int wins = 0;
    char prev = 'a'; // no move has been made yet

    for (char c : S){
        char winmove;
        if (c == 'R'){
            winmove = 'P';
        } else if (c == 'P'){
            winmove = 'S';
        } else { // c == 'S'
            winmove = 'R';
        }
        
        // We can choose the winning move unless it's same as previous
        // But note: we are allowed to choose any move, so we only need to avoid repeating our own previous move
        if (winmove != prev) {
            wins++;
            prev = winmove; // we play the winning move
        } else {
            // We cannot play winmove because it would repeat our own previous move
            // So we must play something else. But we still want to maximize wins in future.
            // Since we can't play the winning move now, we lose this round.
            // We should choose a non-winning, non-losing move? Actually, no: we just need to pick a move different from prev.
            // But to minimize impact on future rounds, we can pick one that might help next time.
            // However, the problem only asks for maximum number of wins — we don't need to simulate all strategies.
            // Important: we are free to choose any move as long as it's not equal to our previous move.
            // So when winmove == prev, we must pick a different move (which will not beat opponent's c), so we don't win.
            // But what should we set `prev` to?
            // We can choose either of the two remaining moves. One is losing, one is tying.
            // Doesn't matter for score, but affects next move.

            // Let's pick a move that is NOT winmove and NOT the same as opponent's current move? Not necessary.
            // Actually, best strategy: pick a move that may allow us to win next time.
            // But since we don't know future, safest is to pick arbitrarily among options ≠ prev.
            // However, we can simulate optimal choice: pick a move different from prev.

            // The two other options:
            // All moves: R, P, S
            for (char m : {'R', 'P', 'S'}) {
                if (m != prev) {
                    // We pick m, but only if it's not the winning one (we already know winmove == prev)
                    // So m is either tie or lose
                    // Doesn't give us a win
                    prev = m;
                    break;
                }
            }
        }
    }   
    cout << wins;
}