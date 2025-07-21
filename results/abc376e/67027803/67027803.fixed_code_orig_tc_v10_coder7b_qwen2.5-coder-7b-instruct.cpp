#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

bool compare(const pii& a, const pii& b){
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

ll min_cost(int n, int k, vector<int>& a, vector<int>& b){
    vector<pii> ab(n);
    for(int i = 0; i < n; i++){
        ab[i] = {a[i], b[i]};
    }
    sort(ab.begin(), ab.end(), compare);

    ll res = LLONG_MAX;
    priority_queue<int> pq;
    ll sum = 0;
    for(int i = 0; i < k; i++){
        pq.push(-ab[i].second);
        sum += ab[i].second;
    }

    res = min(res, (ll)ab[k-1].first * sum);

    for(int i = k; i < n; i++){
        int cur = -pq.top();
        pq.pop();

        if(cur <= ab[i].second){
            sum -= cur;
            sum += ab[i].second;
            pq.push(-ab[i].second);
        } else {
            break;
        }
        res = min(res, (ll)ab[i].first * sum);
    }

    return res;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<int> a(n), b(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];

        cout << min_cost(n, k, a, b) << endl;
    }
    return 0;
}