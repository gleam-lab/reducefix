#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;
    int ans = 0;
    for (int i = 0; i < N - 1;) {
        char current = S[i];
        char next = S[i + 1];
        if ((current == 'P' && next == 'S') || 
            (current == 'S' && next == 'R') || 
            (current == 'R' && next == 'P')) {
            ans++;
            i += 2;
        } else {
            i++;
        }
    }
    cout << ans << endl;
    return 0;
}