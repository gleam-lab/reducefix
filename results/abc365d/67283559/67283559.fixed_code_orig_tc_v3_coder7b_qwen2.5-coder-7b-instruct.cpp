#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<char> hand = {'R', 'P', 'S'};

    auto canWin = [](char c1, char c2) -> bool {
        return (c1 == 'R' && c2 == 'S') || (c1 == 'P' && c2 == 'R') || (c1 == 'S' && c2 == 'P');
    };

    auto getNextMove = [&](char lastMove, const string& s) -> char {
        for (char move : hand) {
            if (move != lastMove && canWin(move, s.back())) {
                return move;
            }
        }
        return lastMove;
    };

    int firstMaxScore = 0;
    char lastFirstMove = S.front();
    for (size_t i = 0; i < N; ++i) {
        if (canWin(lastFirstMove, S[i])) {
            firstMaxScore += 1;
            lastFirstMove = getNextMove(lastFirstMove, S.substr(0, i + 1));
        } else {
            lastFirstMove = S[i];
        }
    }

    int secondMaxScore = 0;
    char lastSecondMove = S.back();
    for (int i = N - 1; i >= 0; --i) {
        if (canWin(lastSecondMove, S[i])) {
            secondMaxScore += 1;
            lastSecondMove = getNextMove(lastSecondMove, S.substr(i));
        } else {
            lastSecondMove = S[i];
        }
    }

    cout << max(firstMaxScore, secondMaxScore);

    return 0;
}