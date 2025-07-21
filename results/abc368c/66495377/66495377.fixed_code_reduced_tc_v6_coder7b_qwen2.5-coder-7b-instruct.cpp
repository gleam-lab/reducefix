#include <iostream>
#include <vector>

using namespace std;

long long solve(long long t, long long h) {
    if (h <= 0) return 0;
    
    if (t % 3 == 0) {
        t += h / 3;
        h %= 3;
    } else {
        t += h / 2;
        h %= 2;
    }
    
    return t + solve(t, h);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<long long> hs(n);
    for (auto& h : hs) cin >> h;

    long long ans = 0;
    for (auto& h : hs) ans = solve(ans, h);

    cout << ans << '\n';
}