#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N >> S;
    int wins = 0;
    for (int i = 0; i < N; ++i) {
        if (S[i] == 'R') {
            wins += (i == 0 || S[i-1] != 'R') || (i > 0 && S[i-1] == 'R' && (i == 1 || S[i-2] != 'P'));
        } else if (S[i] == 'P') {
            wins += (i == 0 || S[i-1] != 'P') || (i > 0 && S[i-1] == 'P' && (i == 1 || S[i-2] != 'S'));
        } else if (S[i] == 'S') {
            wins += (i == 0 || S[i-1] != 'S') || (i > 0 && S[i-1] == 'S' && (i == 1 || S[i-2] != 'R'));
        }
    }
    cout << wins << endl;
    return 0;
}