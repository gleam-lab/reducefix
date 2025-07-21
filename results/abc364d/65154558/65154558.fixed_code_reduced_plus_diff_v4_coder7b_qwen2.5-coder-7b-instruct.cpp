#include<bits/stdc++.h>
using namespace std;

vector<int> a;
vector<pair<int,int>> queries;

bool compare(pair<int,int> p1, pair<int,int> p2) {
    return p1.first < p2.first;
}

int findKthClosest(int target, int k) {
    int left = 0, right = a.size() - 1;
    while(left < right) {
        int mid = (left + right) / 2;
        if(a[mid] - target >= k) right = mid;
        else left = mid + 1;
    }
    return a[left] - target;
}

int main() {
    int n, q; cin >> n >> q;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    
    for(int i = 0; i < q; i++) {
        int x, k; cin >> x >> k;
        queries.push_back({x, k});
    }

    sort(queries.begin(), queries.end(), compare);

    vector<long long> results(q);
    for(int i = 0; i < q; i++) {
        results[i] = findKthClosest(queries[i].first, queries[i].second);
    }

    for(auto res : results) {
        cout << res << '\n';
    }

    return 0;
}