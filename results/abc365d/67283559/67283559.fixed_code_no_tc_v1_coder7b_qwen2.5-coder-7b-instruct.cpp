#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<char> hand = {'R', 'P', 'S'};
    vector<int> scores(3, 0);

    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < 3; ++j) {
            if ((hand[j] == 'R' && S[i] == 'S') ||
                (hand[j] == 'P' && S[i] == 'R') ||
                (hand[j] == 'S' && S[i] == 'P')) {
                scores[j]++;
            }
        }
    }

    int max_score = *max_element(scores.begin(), scores.end());
    cout << max_score << endl;

    return 0;
}