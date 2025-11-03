#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<char> hand = {'R','P','S'};
    int max_score = 0;

    // Try all possible starting choices
    for (char start : hand) {
        vector<char> available = hand;
        // Remove the starting choice from available (since we must choose different next time)
        auto it = find(available.begin(), available.end(), start);
        if (it != available.end()) {
            available.erase(it);
        }

        int score = 0;
        char prev_use = start;

        // Simulate each round
        for (int i = 0; i < N; i++) {
            char opponent = S[i];
            char use = prev_use; // We reuse the previous choice logic, but now we simulate correctly

            // Check if we can win this round with any available choice
            bool won = false;
            for (char c : available) {
                if ((c == 'R' && opponent == 'S') ||
                    (c == 'P' && opponent == 'R') ||
                    (c == 'S' && opponent == 'P')) {
                    score++;
                    use = c;
                    won = true;
                    break;
                }
            }

            // If we can't win, try to pick something (even if it's a loss or draw)
            if (!won) {
                // Pick the first available that isn't the same as previous if possible
                use = available[0]; // default
                for (char c : available) {
                    if (c != prev_use) {
                        use = c;
                        break;
                    }
                }
            }

            // Update available choices for next round: remove the one we just used
            vector<char> next_available;
            for (char c : hand) {
                if (c != use) {
                    next_available.push_back(c);
                }
            }
            available = next_available;
            prev_use = use;
        }

        max_score = max(max_score, score);
    }

    cout << max_score << endl;
    return 0;
}