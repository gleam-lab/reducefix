#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll MAX_COORD = 2 * 100000000 + 10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<ll> a(n + 1), b(q);
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    map<ll, int> freq;
    for(int i = 1; i <= n; ++i) {
        freq[a[i]]++;
    }

    vector<pair<ll, int>> sorted_a(freq.begin(), freq.end());

    for(int i = 0; i < q; ++i) {
        cin >> b[i];
    }

    for(int i = 0; i < q; ++i) {
        int k = b[i];
        int ans = 0;
        for(auto& [coord, count] : sorted_a) {
            if(k <= count) {
                ans = coord;
                break;
            } else {
                k -= count;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}