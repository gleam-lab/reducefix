#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<char> hand = {'R', 'P', 'S'};
    int total = 0, total2 = 0;
    int nextIndex = 0;

    for (int i = 0; i < N; i++) {
        int score = 0;
        char use = 0; // Use variable to store the best move to play
        for (int j = 0; j < hand.size(); j++) {
            char n = hand[j];
            if ((n == 'R' && S[i] == 'S') || (n == 'P' && S[i] == 'R') || (n == 'S' && S[i] == 'P')) {
                // Update score and set the use character
                use = n;
                score++;
                break;
            }
        }
        if (score == 0) use = S[i]; // If no valid move, use the actual move

        // Update the total score
        total += score;

        // Update the 'next' vector by removing the used character
        hand.erase(remove(hand.begin(), hand.end(), use), hand.end());

        // If the first move is known and not used, simulate the rest of the game
        if (i == 0 || use == S[i]) {
            nextIndex = j;
        }
    }

    // Simulate the rest of the game starting from the first move
    for (int i = 1; i < N; i++) {
        int score = 0;
        char use;
        for (int j = 0; j < hand.size(); j++) {
            char n = hand[j];
            if ((n == 'R' && S[i] == 'S') || (n == 'P' && S[i] == 'R') || (n == 'S' && S[i] == 'P')) {
                use = n;
                score++;
                break;
            }
        }
        if (score == 0) use = S[i];
        total2 += score;
        hand.erase(remove(hand.begin(), hand.end(), use), hand.end());
    }

    // Output the maximum of the two totals
    cout << max(total, total2) << endl;
}