#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef long long ll;
const int N = 1e9 + 7;

struct HashPair {
    template <class T1, class T2>
    size_t operator() (const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

unordered_set<pair<int, int>, HashPair> s, t, u, v;
unordered_map<pair<int, int>, bool, HashPair> vis;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    for(int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        s.insert({a, b});
        t.insert({a, b});
        u.insert({a - b, b});
        v.insert({a + b, b});
    }
    
    ll ans = (n - s.size()) * (n - t.size());
    
    for(auto [a, b] : s) {
        if(u.find({a, b}) != end(u)) {
            ans -= (n - abs(a + b));
        }
        if(v.find({a, b}) != end(v)) {
            ans -= (n - abs(a - b));
        }
        if(a == b) {
            ans--;
        }
        if(a + b == n) {
            ans--;
        }
    }
    
    cout << ans;
    return 0;
}