#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> h(n);
    for(int i = 0; i < n; ++i)
        cin >> h[i];

    long long ans = 0;
    for(int i = 0; i < n; ++i) {
        if(h[i] > 0) {
            if(h[i] % 3 == 0) {
                ans += h[i] / 3;
                h[i] = 0;
            } else {
                ans += h[i] / 3 + 1;
                h[i] -= (h[i] / 3 + 1) * 3;
            }
        }
    }

    cout << ans << endl;
    return 0;
}