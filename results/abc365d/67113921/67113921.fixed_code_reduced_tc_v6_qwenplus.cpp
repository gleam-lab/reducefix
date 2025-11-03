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
    char prev = 'a'; // previous move we made

    for (char c : S){
        char winmove;
        if (c == 'R'){
            winmove = 'P';
        } else if (c == 'P'){
            winmove = 'S';
        } else { // c == 'S'
            winmove = 'R';
        }
        
        // If our winning move is different from the previous move we played, we can use it and win
        if (winmove != prev) {
            wins++;
            prev = winmove;
        } 
        // Otherwise, we are forced to play something else (either tie or lose), so we play the same as opponent to minimize impact?
        // But note: we don't get a win. We just update state to avoid conflict in next round.
        else {
            // We cannot play the same winning move twice, so we have to play something else.
            // Since we can't win (because we can't repeat moves), we choose any other move.
            // Important: we must pick a move that is not winmove (which equals prev).
            // But we still need to set prev to *something*.
            // However, to maximize future chances, we should pick a non-winning move? 
            // Actually, no restriction on what we play when we don't win — only that we can't repeat consecutive moves.
            // So we can play either of the other two, but we want to set up for next round.
            // Best choice: play the losing move? Or the tying move?
            // Example: opponent plays R, we would like to play P, but P was just played -> can't repeat.
            // So we must play either R or S.
            // If we play R -> tie.
            // If we play S -> lose.
            // Doesn't matter for score, but affects next allowed move.
            // To maximize chance of winning next, we should pick one that might be different from next winmove.
            // But we don't know next. So safest: pick the opponent's current move (c).
            // That way, we are playing c now, and if next required winmove is not c, we can win.
            prev = c;
        }
    }   
    cout << wins;
}