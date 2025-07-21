#include <bits/stdc++.h>
using namespace std;

int playGame(const string& S, const vector<char>& hand, int N, bool firstTurnRandom) {
    vector<char> next = hand;
    if (firstTurnRandom) {
        // For the second scenario, we assume the first move was any of the possible options
        // So we pick the one that gives maximum advantage in the long run
        // To simplify, we'll simulate all 3 possibilities and return the best score
        int maxScore = 0;
        for (char firstMove : hand) {
            vector<char> remaining;
            for (char c : hand) if (c != firstMove) remaining.push_back(c);
            int score = 0;
            if (firstMove == 'R' && S[0] == 'S') score++;
            if (firstMove == 'P' && S[0] == 'R') score++;
            if (firstMove == 'S' && S[0] == 'P') score++;

            vector<char> currentNext = remaining;
            for (int i = 1; i < N; i++) {
                bool won = false;
                for (char n : currentNext) {
                    if ((n == 'R' && S[i] == 'S') || 
                        (n == 'P' && S[i] == 'R') || 
                        (n == 'S' && S[i] == 'P')) {
                        score++;
                        char use = n;
                        currentNext.clear();
                        for (char c : hand) if (c != use) currentNext.push_back(c);
                        break;
                    }
                }
                if (!won) {
                    char use = S[i]; // opponent's move
                    currentNext.clear();
                    for (char c : hand) if (c != use) currentNext.push_back(c);
                }
            }
            maxScore = max(maxScore, score);
        }
        return maxScore;
    }

    // First simulation: choose optimal moves from the start
    int total = 0;
    for (int i = 0; i < N; i++) {
        bool won = false;
        for (char n : next) {
            if ((n == 'R' && S[i] == 'S') || 
                (n == 'P' && S[i] == 'R') || 
                (n == 'S' && S[i] == 'P')) {
                total++;
                char use = n;
                vector<char> newNext;
                for (char c : hand) if (c != use) newNext.push_back(c);
                next = newNext;
                won = true;
                break;
            }
        }
        if (!won) {
            char use = S[i]; // opponent's move
            vector<char> newNext;
            for (char c : hand) if (c != use) newNext.push_back(c);
            next = newNext;
        }
    }
    return total;
}

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<char> hand = {'R', 'P', 'S'};

    // First scenario: normal game from the beginning
    int total1 = playGame(S, hand, N, false);

    // Second scenario: we get to choose the first move optimally
    int total2 = playGame(S, hand, N, true);

    cout << max(total1, total2) << endl;
}