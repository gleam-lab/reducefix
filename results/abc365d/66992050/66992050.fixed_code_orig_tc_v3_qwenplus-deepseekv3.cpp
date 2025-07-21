#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;
    
    if (N == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    char prev = S[0];
    int ans = 1;
    
    for (int i = 1; i < N; ++i) {
        char current = S[i];
        if (prev == 'R' && current == 'S') {
            ans++;
            prev = current;
        } else if (prev == 'S' && current == 'P') {
            ans++;
            prev = current;
        } else if (prev == 'P' && current == 'R') {
            ans++;
            prev = current;
        } else {
            prev = current;
        }
    }
    
    cout << ans << endl;
    return 0;
}