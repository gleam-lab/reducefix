#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define vi vector<int>
#define vl vector<ll>
#define vd vector<double>
#define vb vector<bool>
#define vs vector<string>
#define vc vector<char>
#define ull unsigned long long

int big = 1000000000;
int get(vector<pair<int, int>> &v, int m) {
    auto it = lower_bound(v.begin(), v.end(), make_pair(m, INT_MAX));
    if (it == v.end() || it->first > m) return 0;
    return it->second + 1;
}

int main() {
    int n, q, b, k; cin >> n >> q;
    vector<pair<int, int>> v(n);
    rep(i, n) {
        cin >> v[i].first;
        v[i].second = i + 1;
    }
    
    sort(v.begin(), v.end());
    
    rep(i, q) {
        cin >> b >> k;
        int l = -big, r = big;
        while (r - l > 1) {
            int m = (r + l) / 2;
            if (get(v, b + m) - get(v, b - m - 1) >= k) r = m;
            else l = m;
        }
        cout << abs(b + r) << endl;
    }
}