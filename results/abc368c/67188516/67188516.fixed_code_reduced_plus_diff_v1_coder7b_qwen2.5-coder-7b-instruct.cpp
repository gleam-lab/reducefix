#include <iostream>
#include <vector>

using namespace std;

long long solve(long long h) {
    long long ans = 0;
    while (h > 0) {
        if (h % 3 == 0) {
            ans += h / 3 * 3;
            h -= h / 3 * 3;
        } else if (h % 3 == 1) {
            if (ans % 3 == 0) {
                ans += h / 3 * 3 + 1;
                h = 1;
            } else {
                ans += h / 3 * 3;
                h -= h / 3 * 3;
                h += 2;
            }
        } else { // h % 3 == 2
            ans += h / 3 * 3 + 2;
            h = 0;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<long long> hs(N);
    for (int i = 0; i < N; ++i) {
        cin >> hs[i];
    }

    long long total = 0;
    for (auto& h : hs) {
        total += solve(h);
    }

    cout << total << '\n';

    return 0;
}