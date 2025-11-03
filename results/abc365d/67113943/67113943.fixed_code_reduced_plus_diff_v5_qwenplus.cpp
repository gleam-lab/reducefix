#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N >> S;

    int wins = 0;
    char last_played = 'X'; // No move played initially

    for (char c : S) {
        char winning_move;
        if (c == 'R') winning_move = 'P';
        else if (c == 'P') winning_move = 'S';
        else winning_move = 'R'; // c == 'S'

        if (winning_move != last_played) {
            wins++;
            last_played = winning_move;
        } else {
            // We cannot use the same winning move twice in a row.
            // So we must play something else. But note: we don't win this round,
            // and we want to set last_played to something that allows us to potentially
            // win the next round.
            // However, playing a losing move or draw is fine — we just need to pick one
            // that doesn't interfere with future wins.
            // The key is: we can play any move except the winning_move (since we already used it).
            // But to maximize future chances, we should play the move that *loses* to current c,
            // because then we are free to play the winning move again after one round.
            // For example: opponent plays 'R', we previously played 'P' (win), so now we can't play 'P'.
            // So we play 'R' (same as opponent) -> draw, or 'S' -> lose.
            // But which one to pick? Actually, it doesn't matter for scoring, but matters for what we can do next.
            // However, note: next opponent move is unknown. So we want to minimize constraint.
            // Important insight: after playing a non-winning move, we are free to play any move next round.
            // So we can simply update last_played to something different from winning_move.
            // Let's play the move that corresponds to the current opponent move.
            last_played = c; // This ensures we don't repeat the winning move, and it's safe.
        }
    }

    cout << wins << endl;
    return 0;
}