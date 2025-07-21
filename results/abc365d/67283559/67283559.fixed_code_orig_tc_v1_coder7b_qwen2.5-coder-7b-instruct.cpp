#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<char> next = {'R', 'P', 'S'};
    int total = 0;

    for (int i = 0; i < N; ++i) {
        int score = 0;
        char use = S[i];
        for (char n : next) {
            if ((n == 'R' && S[i] == 'S') ||
                (n == 'P' && S[i] == 'R') ||
                (n == 'S' && S[i] == 'P')) {
                score++;
                use = n;
                break;
            }
        }
        next.erase(remove(next.begin(), next.end(), use), next.end());
        total += score;
    }

    cout << total << '\n';

    return 0;
}