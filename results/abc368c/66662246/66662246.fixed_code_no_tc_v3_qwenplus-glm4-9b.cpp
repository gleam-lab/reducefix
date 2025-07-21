#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    long long total_attacks = 0;
    int attack = 1; // Initial attack value is 1 because if health is odd, it always decreases by 1

    for (int h : a) {
        while (h > 0) {
            if (attack % 3 == 0) {
                h -= 3;
            } else {
                h--;
            }
            total_attacks++;
            if (h % 3 == 0 && h != 0) {
                h -= 3;
            }
        }
        attack++;
    }

    cout << total_attacks << endl;
}