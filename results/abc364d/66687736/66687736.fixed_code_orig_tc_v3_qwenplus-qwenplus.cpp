#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define pii pair<ll,ll>
#define vpii vector<pii>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define fo(i, a, b) for (ll i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define sz(v) (ll)(v.size())
#define MOD 1000000007

template <typename T>
void print(T x) { cout << x << "\n"; }

template <typename T>
void printvec(vector<T> &v) {
    for (T x : v)
        cout << x << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, q;
    cin >> n >> q;

    vi a(n), res(q);
    map<ll, ll> cnt;
    for (auto &x : a) {
        cnt[x]++;
    }

    // Prepare prefix sums
    vector<pair<ll, ll>> sorted_freq;
    for (auto &p : cnt) {
        sorted_freq.push_back({p.first, p.second});
    }
    ll m = sz(sorted_freq);

    // Prefix sum array
    vi prefix(m + 1, 0);
    for (ll i = 0; i < m; ++i) {
        prefix[i + 1] = prefix[i] + sorted_freq[i].s;
    }

    auto get_kth = [&](ll b, ll k) -> ll {
        ll low = -1e9, high = 1e9;
        while (low < high) {
            ll mid = (low + high) / 2;
            ll left = b - mid;
            ll right = b + mid;

            // Binary search in sorted_freq
            auto it_left = lower_bound(sorted_freq.begin(), sorted_freq.end(), make_pair(left, 0LL));
            ll count_left = (it_left == sorted_freq.end()) ? prefix[m] : prefix[it_left - sorted_freq.begin()];
            if (it_left != sorted_freq.begin()) {
                count_left -= prefix[it_left - sorted_freq.begin()];
            }

            ll count = 0;
            auto it_right = upper_bound(sorted_freq.begin(), sorted_freq.end(), make_pair(right, 1e18));
            if (it_right != sorted_freq.begin()) {
                count = prefix[it_right - sorted_freq.begin()];
                if (it_left != sorted_freq.begin()) {
                    count -= prefix[it_left - sorted_freq.begin()];
                }
            }

            if (count >= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    };

    for (ll i = 0; i < q; ++i) {
        ll b, k;
        cin >> b >> k;
        res[i] = get_kth(b, k);
    }

    for (auto &x : res) {
        cout << x << "\n";
    }

    return 0;
}