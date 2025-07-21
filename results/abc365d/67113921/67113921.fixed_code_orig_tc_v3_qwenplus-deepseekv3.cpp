#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N >> S;

    int R = 0, P = 0, S = 0;
    for (char c : S) {
        if (c == 'R') R++;
        else if (c == 'P') P++;
        else if (c == 'S') S++;
    }

    cout << max({R, P, S}) + max({R, P, S}) - min({R, P, S}) << endl;

    return 0;
}