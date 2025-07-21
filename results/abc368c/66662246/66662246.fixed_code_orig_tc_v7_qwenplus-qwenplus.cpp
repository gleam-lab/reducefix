#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

// Function to simulate attacks on a single enemy and return the number of T steps needed
ll compute_steps(int h) {
    // Each cycle is: 3 attacks -> total damage = 1 + 1 + 3 = 5 per full cycle
    ll full_cycles = h / 5;
    ll steps = full_cycles * 3;
    int rem = h % 5;

    // Simulate remaining attacks
    for (int t = 1; rem > 0; ++t, --rem) {
        if (t % 3 == 0) rem -= 3;
        else rem -= 1;
        steps++;
    }
    return steps;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> H(n);
    for (int i = 0; i < n; ++i) cin >> H[i];

    ll ans = 0;
    for (int h : H) {
        ans += compute_steps(h);
    }

    cout << ans << endl;
    return 0;
}