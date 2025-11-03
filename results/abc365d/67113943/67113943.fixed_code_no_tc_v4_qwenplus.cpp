#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N >> S;
    
    int wins = 0;
    char opponent_move, my_last_move = 'X'; // X represents no previous move
    
    for (int i = 0; i < N; i++) {
        opponent_move = S[i];
        char best_response;
        
        // Determine the move that beats the opponent's current move
        if (opponent_move == 'R') {
            best_response = 'P'; // Paper beats Rock
        } else if (opponent_move == 'P') {
            best_response = 'S'; // Scissors beat Paper
        } else { // opponent_move == 'S'
            best_response = 'R'; // Rock beats Scissors
        }
        
        // If our best response is different from our last move, we need to change and win
        // If it's the same as our last move, we can use it again and win
        // We only fail to win if we have to make the same move as opponent (but that never happens with optimal play)
        
        // The key insight: we win whenever we can make the winning move
        // We can make the winning move unless we're constrained by having to change moves
        // Actually, rereading the problem: we win a round if our move beats opponent's move
        // And we can choose any move in each round, but consecutive moves must be different
        
        if (my_last_move != best_response) {
            wins++;
            my_last_move = best_response;
        } else {
            // We would need to play the same move as last time, but we can't repeat
            // So we must play something else, which might not win
            // We need to pick a non-losing strategy here
            
            // Since we can't repeat, we have to choose between the other two moves
            // One of them loses, one of them draws
            // We should choose the draw rather than the loss
            
            char alternative_move;
            if (best_response == 'R') {
                // We can't play 'R', so choose between 'P' and 'S'
                // 'P' loses to 'R', 'S' draws with 'R'
                // Wait, no: if opponent plays R, then:
                // - P beats R (win)
                // - S loses to R (loss)
                // - R draws with R (draw)
                // But we're trying to respond to opponent's R, so best_response is P
                // Since we can't play P (because it was our last move), we must choose between R and S
                // R: draw, S: lose
                // So we choose R for draw
                alternative_move = 'R';
            } else if (best_response == 'P') {
                // Can't play P, choose between R and S
                // Opponent played P, so:
                // - R loses to P
                // - S beats P (but we can't play this - it's best_response)
                // - P draws with P
                // We can play R (lose) or S (win, but can't because it's best_response and we assume we can't repeat?)
                // Wait, no: best_response is what we wanted to play, but we can't repeat our last move
                // Our last move was P, so we can't play P again
                // To beat opponent's P, we need S
                // But if we can't play S (because it was our last move?), no - our last move was P
                // So we can play S to win
                // I think I'm confusing myself
                
                // Let me restart the logic:
                // In this round, opponent plays some move
                // We want to play the move that beats it
                // BUT we cannot play the same move we played in the previous round
                // So if the winning move is different from our last move, we play it and win
                // If the winning move is the same as our last move, we cannot play it, so we must play one of the other two
                // Between the other two, one will lose and one will draw
                // So we choose the one that draws (rather than loses)
                
                // So when best_response equals my_last_move, we cannot win, but we can avoid losing
                // Therefore, we don't increment wins in this case
                // We just update our move to the drawing move
                
                // For opponent's move requiring best_response 'P':
                // This means opponent played 'S' (since P beats S)
                // We can't play P (our last move), so we choose between R and S
                // If we play R: R vs S -> R loses (S beats R)
                // If we play S: S vs S -> draw
                // So we play S for draw
                alternative_move = 'S';
            } else { // best_response == 'S'
                // This means opponent played 'R' 
                // We can't play S (last move), so choose between R and P
                // R vs R: draw
                // P vs R: P wins (but we can't play P because it would be best_response? No - best_response is S)
                // Wait, no: if opponent played R, best_response is P
                // So this case shouldn't happen
                // I think I have a bug in my logic
                
                // Let me correct:
                // best_response is computed based on opponent's current move
                // if opponent plays R, best_response = P
                // if opponent plays P, best_response = S  
                // if opponent plays S, best_response = R
                
                // So when best_response is 'S', opponent played 'P'
                // We can't play S (because it was our last move), so we choose between R and P
                // R vs P: R loses (P beats R)
                // P vs P: draw
                // So we play P for draw
                alternative_move = 'P';
            }
            
            // Actually, simpler approach:
            // When we can't play the winning move, we play either of the other two
            // One of them results in a loss, one in a draw
            // We choose the draw
            // But since we're not winning, we don't increment the win counter
            // And we update our last move to this alternative (drawing) move
            
            my_last_move = alternative_move;
            // Don't increment wins
        }
    }   
    
    cout << wins;
    return 0;
}