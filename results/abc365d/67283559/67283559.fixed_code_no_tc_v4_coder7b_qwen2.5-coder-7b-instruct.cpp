#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<char> hand = {'R', 'P', 'S'};
    vector<char> next(hand.begin(), hand.end());
    int total = 0;

    for (int i = 0; i < N; ++i) {
        int score = 0;
        char use = S[i];

        for (char n : next) {
            if ((n == 'R' && S[i] == 'S') || (n == 'P' && S[i] == 'R') || (n == 'S' && S[i] == 'P')) {
                score++;
                use = n;
                break;
            }
        }

        total += score;
        next.erase(remove(next.begin(), next.end(), use), next.end());
    }

    next.assign(hand.begin(), hand.end());

    int total2 = 0;
    for (int i = 1; i < N; ++i) {
        int score = 0;
        char use = S[i];

        for (char n : next) {
            if ((n == 'R' && S[i] == 'S') || (n == 'P' && S[i] == 'R') || (n == 'S' && S[i] == 'P')) {
                score++;
                use = n;
                break;
            }
        }

        total2 += score;
        next.erase(remove(next.begin(), next.end(), use), next.end());
    }

    cout << max(total, total2);
    return 0;
}