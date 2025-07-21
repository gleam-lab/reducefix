#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    string S;
    cin >> N >> S;
    char past = 'N';
    int ans = 0;
    for (char c : S) {
        if (c == 'P' && past == 'R') {
            ans++;
        } else if (c == 'R' && past == 'S') {
            ans++;
        } else if (c == 'S' && past == 'P') {
            ans++;
        }
        past = c;
    }
    cout << ans << endl;
    return 0;
}