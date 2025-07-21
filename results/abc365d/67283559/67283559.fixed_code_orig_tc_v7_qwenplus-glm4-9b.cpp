#include <iostream>
#include <vector>
using namespace std;

bool canWin(char move1, char move2) {
    return (move1 == 'R' && move2 == 'S') ||
           (move1 == 'S' && move2 == 'P') ||
           (move1 == 'P' && move2 == 'R');
}

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    // Initial hand
    vector<char> hand = {'R', 'P', 'S'};
    int totalScore = 0;
    vector<char> nextMoves = hand; // for the first round
    
    // First round
    for (int i = 0; i < S[0] - 'R'; ++i) {
        if (nextMoves[0] == S[1 + i]) {
            totalScore++;
            nextMoves.erase(nextMoves.begin());
        }
    }
    
    // Remaining moves
    for (int i = 1; i < N; ++i) {
        vector<char> tempNextMoves;
        for (char nextMove : nextMoves) {
            if (canWin(nextMove, S[i])) {
                totalScore++;
                tempNextMoves.push_back(nextMove);
            }
        }
        nextMoves = tempNextMoves;
    }
    
    cout << totalScore << endl;
    return 0;
}