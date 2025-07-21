#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; ++i) cin >> h[i];

    long long t = 0;
    bool flag = true;

    while (flag) {
        flag = false;
        for (int i = 0; i < n; ++i) {
            if (h[i] > 0) {
                flag = true;
                ++t;
                if (t % 3 == 0) h[i] -= 3;
                else --h[i];
            }
        }
    }

    cout << t << '\n';
    return 0;
}