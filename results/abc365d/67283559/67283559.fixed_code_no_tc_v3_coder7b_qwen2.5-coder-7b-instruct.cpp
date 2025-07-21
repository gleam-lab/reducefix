#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100005;
char S[MAX_N], hand[] = {'R', 'P', 'S'};

int main() {
    int N;
    cin >> N;
    cin >> (S + 1); // Start from index 1 to match problem constraints

    int total = 0;
    for (int i = 1; i <= N; ++i) {
        int score = 0;
        char use;
        for (int j = 0; j < 3; ++j) {
            char n = hand[j];
            if ((n == 'R' && S[i] == 'S') || (n == 'P' && S[i] == 'R') || (n == 'S' && S[i] == 'P')) {
                score++;
                use = n;
                break;
            }
        }
        if (score == 0) use = S[i];
        total += score;
    }

    int total2 = 0;
    for (int i = 1; i <= N; ++i) {
        int score = 0;
        char use;
        for (int j = 0; j < 3; ++j) {
            char n = hand[j];
            if ((n == 'R' && S[i] == 'S') || (n == 'P' && S[i] == 'R') || (n == 'S' && S[i] == 'P')) {
                score++;
                use = n;
                break;
            }
        }
        if (score == 0) use = S[i];
        total2 += score;
    }

    cout << max(total, total2) << endl;
    return 0;
}