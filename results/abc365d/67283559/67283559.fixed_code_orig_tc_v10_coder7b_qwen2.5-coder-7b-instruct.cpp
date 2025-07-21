#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    string S;
    cin >> S;

    const vector<char> hand = {'R', 'P', 'S'};
    auto get_score = [&](char c1, char c2) {
        if ((c1 == 'R' && c2 == 'S') || (c1 == 'P' && c2 == 'R') || (c1 == 'S' && c2 == 'P')) return 1;
        return 0;
    };

    int total = 0;
    for (int i = 0; i < N; ++i) {
        int best_score = 0;
        char best_char = S[i];
        for (auto h : hand) {
            int score = get_score(h, S[i]);
            if (score > best_score) {
                best_score = score;
                best_char = h;
            }
        }
        total += best_score;
    }

    cout << total << '\n';

    return 0;
}