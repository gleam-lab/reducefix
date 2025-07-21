#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

typedef long long ll;

struct DistanceInfo {
    int index;
    ll distance;
};

struct CompareDistance {
    bool operator()(const DistanceInfo& a, const DistanceInfo& b) {
        return a.distance > b.distance;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    
    vector<ll> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    while(q--) {
        ll b, k;
        cin >> b >> k;
        
        priority_queue<DistanceInfo, vector<DistanceInfo>, CompareDistance> pq;
        
        for(int i = 0; i < n; ++i) {
            ll dist = abs(a[i] - b);
            if(pq.size() < k) {
                pq.push({i, dist});
            } else if(dist < pq.top().distance) {
                pq.pop();
                pq.push({i, dist});
            }
        }
        
        cout << pq.top().distance << '\n';
    }

    return 0;
}