#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll min_cost(int n, int k, vector<int>& a, vector<int>& b) {
    vector<pair<int,int>> pairs;
    for(int i = 0; i < n; ++i){
        pairs.emplace_back(a[i], b[i]);
    }

    sort(pairs.begin(), pairs.end(), [](const pair<int,int>& p1, const pair<int,int>& p2){return p1.first > p2.first;});
    multiset<int> s;
    for(int i = 0; i < k; ++i){
        s.insert(pairs[i].second);
    }

    ll res = pairs[k-1].first * accumulate(s.begin(), s.end(), 0LL);
    for(int i = k; i < n; ++i){
        int val = pairs[i].second;
        if(*s.rbegin() > val){
            s.erase(prev(s.end()));
            s.insert(val);
            res = min(res, (ll)pairs[i].first * accumulate(s.begin(), s.end(), 0LL));
        }
    }

    return res;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<int> a(n), b(n);
        for(int i = 0; i < n; ++i){
            cin >> a[i];
        }
        for(int i = 0; i < n; ++i){
            cin >> b[i];
        }

        cout << min_cost(n, k, a, b) << endl;
    }

    return 0;
}