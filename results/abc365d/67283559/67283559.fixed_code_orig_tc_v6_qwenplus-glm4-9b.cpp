#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<char> hand = {'R', 'P', 'S'};
    vector<char> next;
    int total = 0, total2 = 0;

    // First round
    for (int i = 0; i < N; ++i) {
        int score = 0;
        char use;
        bool used = false;

        for (char c : hand) {
            if (c == 'R' && S[i] == 'S') {
                score++;
                use = 'R';
                used = true;
                break;
            } else if (c == 'P' && S[i] == 'R') {
                score++;
                use = 'P';
                used = true;
                break;
            } else if (c == 'S' && S[i] == 'P') {
                score++;
                use = 'S';
                used = true;
                break;
            }
        }

        if (!used) {
            score = 1; // Use the same move as the opponent
            use = S[i];
        }

        total += score;

        // Update the next possible moves for the next round
        next.clear();
        for (auto d : hand) {
            if (d != use) next.push_back(d);
        }
    }

    // Second round
    next.clear();
    for (auto d : hand) {
        if (d != S[0]) next.push_back(d);
    }

    for (int i = 1; i < N; ++i) {
        int score = 0;
        char use;
        bool used = false;

        for (char c : next) {
            if (c == 'R' && S[i] == 'S') {
                score++;
                use = 'R';
                used = true;
                break;
            } else if (c == 'P' && S[i] == 'R') {
                score++;
                use = 'P';
                used = true;
                break;
            } else if (c == 'S' && S[i] == 'P') {
                score++;
                use = 'S';
                used = true;
                break;
            }
        }

        if (!used) {
            score = 1;
            use = S[i];
        }

        total2 += score;

        next.clear();
        for (auto d : hand) {
            if (d != use) next.push_back(d);
        }
    }

    cout << max(total, total2) << endl;
}