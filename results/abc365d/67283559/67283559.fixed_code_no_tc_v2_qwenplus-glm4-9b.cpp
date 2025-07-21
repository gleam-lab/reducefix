#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    // Mapping from hand to its winning moves
    vector<vector<char>> winMoves = {
        {'P'},   // R beats S
        {'R'},   // P beats R
        {'S'}    // S beats P
    };

    int totalScore = 0;

    // Calculate scores with strategy using next hand
    for (int i = 0; i < N; i++) {
        int score = 0;
        char use;
        for (char n : winMoves) {
            if (n == 'R' && S[i] == 'S') {
                score++;
                use = 'R';
                break;
            }
            if (n == 'P' && S[i] == 'R') {
                score++;
                use = 'P';
                break;
            }
            if (n == 'S' && S[i] == 'P') {
                score++;
                use = 'S';
                break;
            }
        }
        totalScore += score;
    }

    // Calculate scores with strategy using hand hand
    int totalScoreHand = 0;
    for (int i = 1; i < N; i++) { // Start from 1 to avoid double counting first character
        int score = 0;
        char use;
        for (char n : winMoves) {
            if (n == 'R' && S[i] == 'S') {
                score++;
                use = 'R';
                break;
            }
            if (n == 'P' && S[i] == 'R') {
                score++;
                use = 'P';
                break;
            }
            if (n == 'S' && S[i] == 'P') {
                score++;
                use = 'S';
                break;
            }
        }
        totalScoreHand += score;
    }

    // Compare both strategies to find the maximum score
    cout << max(totalScore, totalScoreHand);
    return 0;
}