#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 1e5 + 5;
ll arr[MAXN], ans[MAXN];
vector<ll> vec;

void init() {
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
}

ll query(ll x) {
    auto it = lower_bound(vec.begin(), vec.end(), x);
    return it - vec.begin();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        cin >> arr[i];
        vec.push_back(arr[i]);
    }
    init();
    for(int i = 1; i <= m; ++i) {
        ll x, k; cin >> x >> k;
        ll pos = query(x);
        ans[pos] = k;
    }
    for(int i = 0; i < vec.size(); ++i) {
        if(ans[i]) {
            int cnt = ans[i] - 1;
            while(cnt--) {
                int l = lower_bound(vec.begin(), vec.end(), vec[i]) - vec.begin();
                if(l == vec.size()) --l;
                ans[l]--;
            }
        }
    }
    for(int i = 0; i < vec.size(); ++i) {
        if(ans[i]) {
            cout << vec[i] - ans[i] << '\n';
        } else {
            cout << vec[i] << '\n';
        }
    }
    return 0;
}