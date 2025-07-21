#include <bits/stdc++.h>

using namespace std;
using ll=long long;
using Graph = vector<vector<int>>;

#define rep(i,n) for (int i=0; i<(n); ++i)
#define reps(i,n) for (int i=0; i<=(n); ++i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb(a) push_back(a)
#define Yes(b) cout << ((b)?"Yes":"No") << endl
#define YES(b) cout << ((b)?"YES":"NO") << endl

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(){
    int N;
    cin >> N;
    vector<ll> X(N), P(N+1);
    P[0] = 0;
    rep(i, N) cin >> X[i];
    rep(i, N){
        int p;
        cin >> p;
        P[i+1] = P[i] + p;
    }
    
    vector<pair<int, int>> x_index(N);
    rep(i, N){
        x_index[i] = {X[i], i};
    }
    sort(all(x_index));

    int Q;
    cin >> Q;
    rep(q, Q){
        int L, R;
        cin >> L >> R;
        
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first < b.first;
        };
        
        auto left_it = lower_bound(all(x_index), make_pair(L, 0), cmp);
        auto right_it = upper_bound(all(x_index), make_pair(R, N), cmp);
        
        int l = (left_it == x_index.end()) ? N : left_it->second;
        int r = (right_it == x_index.end()) ? N : right_it->second;
        
        // Need to include all elements where X[i] is in [L, R]
        // So we need to find the minimal l and maximal r
        if (left_it != x_index.end() && right_it != x_index.begin()) {
            l = left_it->second;
            r = (--right_it)->second + 1;
        } else {
            // No elements in range
            cout << 0 << endl;
            continue;
        }
        
        if (l > r) {
            // No elements in range
            cout << 0 << endl;
        } else {
            cout << P[r] - P[l] << endl;
        }
    }
}