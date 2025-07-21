#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<char> next = {'R', 'P', 'S'};
    int total = 0;

    for (int i = 0; i < N; ++i) {
        int score = 0;
        char use = S[i];

        for (char c : next) {
            if ((c == 'R' && S[i] == 'S') ||
                (c == 'P' && S[i] == 'R') ||
                (c == 'S' && S[i] == 'P')) {
                score++;
                use = c;
                break;
            }
        }

        next.clear();
        total += score;

        for (auto d : {'R', 'P', 'S'}) {
            if (d != use) next.push_back(d);
        }
    }

    next.clear();
    int total2 = 0;

    for (auto d : {'R', 'P', 'S'}) {
        if (d != S[0]) next.push_back(d);
    }

    for (int i = 1; i < N; ++i) {
        int score = 0;
        char use = S[i];

        for (char c : next) {
            if ((c == 'R' && S[i] == 'S') ||
                (c == 'P' && S[i] == 'R') ||
                (c == 'S' && S[i] == 'P')) {
                score++;
                use = c;
                break;
            }
        }

        next.clear();
        total2 += score;

        for (auto d : {'R', 'P', 'S'}) {
            if (d != use) next.push_back(d);
        }
    }

    cout << max(total, total2) << endl;

    return 0;
}