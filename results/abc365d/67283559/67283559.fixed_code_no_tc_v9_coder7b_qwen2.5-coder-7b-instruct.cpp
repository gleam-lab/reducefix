#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<char> hand = {'R', 'P', 'S'};
    int total = 0;

    // First round logic
    for (char s : S) {
        bool found = false;
        for (char h : hand) {
            if ((h == 'R' && s == 'S') || (h == 'P' && s == 'R') || (h == 'S' && s == 'P')) {
                total++;
                found = true;
                break;
            }
        }
        if (!found) total++;
    }

    // Second round logic
    int second_total = 0;
    for (int i = 1; i < N; ++i) {
        char prev = S[i - 1];
        bool found = false;
        for (char h : hand) {
            if ((h == 'R' && S[i] == 'S') || (h == 'P' && S[i] == 'R') || (h == 'S' && S[i] == 'P')) {
                second_total++;
                found = true;
                break;
            }
        }
        if (!found) second_total++;
    }

    cout << max(total, second_total) << endl;
    return 0;
}