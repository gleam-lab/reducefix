#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<char> S(N);
    for (int i = 0; i < N; ++i) {
        cin >> S[i];
    }

    int ans = 0;
    for (int i = 1; i < N; ++i) {
        if (S[i] == S[i-1]) {
            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}