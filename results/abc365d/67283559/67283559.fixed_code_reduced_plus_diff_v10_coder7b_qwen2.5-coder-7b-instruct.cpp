#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<int> scores = {0, 0};
    vector<char> hands = {'R', 'P', 'S'};

    auto updateScores = [&](char choice) {
        scores[choice == 'R'] += 1;
        scores[choice == 'P'] += 1;
        scores[choice == 'S'] += 1;
    };

    auto getBestChoice = [&](const string& s) {
        int bestScore = -1;
        char bestChoice = '\0';

        for (char h : hands) {
            int score = count_if(s.begin(), s.end(), [h](char c) {
                return (c == 'R' && h == 'P') ||
                       (c == 'P' && h == 'S') ||
                       (c == 'S' && h == 'R');
            });
            if (score > bestScore) {
                bestScore = score;
                bestChoice = h;
            }
        }

        return bestChoice;
    };

    for (int i = 0; i < N; ++i) {
        char bestChoice = getBestChoice(S.substr(i));
        updateScores(bestChoice);
    }

    cout << *max_element(scores.begin(), scores.end()) << endl;

    return 0;
}