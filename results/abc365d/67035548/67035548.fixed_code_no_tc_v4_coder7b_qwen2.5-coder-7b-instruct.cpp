#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 7;

int n;
string s;
int siz[MAXN];
char rsp[MAXN];

bool can_win(char a, char b) {
    if(a == 'R' && b == 'S') return true;
    if(a == 'S' && b == 'P') return true;
    if(a == 'P' && b == 'R') return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> s;

    int ans = 0;
    for(int i = 0; i < n; ++i) {
        if(i == 0 || !can_win(rsp[i - 1], s[i])) {
            ++ans;
            rsp[i] = (s[i] == 'R' ? 'P' : (s[i] == 'P' ? 'S' : 'R'));
        } else {
            rsp[i] = s[i];
        }
    }

    cout << ans << '\n';

    return 0;
}