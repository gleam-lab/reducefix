#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using int64 = long long;

int n;
int64 H[200001]; // Use a larger size if necessary

bool can_kill(int mid) {
    int64 total_attacks = 0;
    rep(i, n) {
        int64 tries = mid / H[i];
        if (H[i] % 3 == 0) {
            total_attacks += tries;
        } else {
            total_attacks += tries + 1;
        }
    }
    return total_attacks <= mid;
}

int main() {
    cin >> n;
    rep(i, n) cin >> H[i];
    
    int64 l = 0, r = 1e18;
    while (r - l >= 2) {
        int64 mid = (l + r) / 2;
        if (can_kill(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r << endl;
}