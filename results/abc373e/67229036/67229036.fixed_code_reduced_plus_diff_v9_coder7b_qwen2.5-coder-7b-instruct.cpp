#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Candidate {
    ll votes;
    int index;
};

bool cmp(Candidate &a, Candidate &b) {
    return a.votes > b.votes;
}

vector<ll> min_additional_votes(int n, int m, ll k, vector<int>& a) {
    vector<Candidate> candidates(n);
    for(int i = 0; i < n; ++i) {
        candidates[i] = {a[i], i + 1};
    }
    
    sort(candidates.begin(), candidates.end(), cmp);

    vector<ll> result(n, -1);
    vector<ll> prefix_sum(n + 1, 0);
    
    for(int i = 0; i < n; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + candidates[i].votes;
    }

    for(int i = 0; i < n; ++i) {
        if(prefix_sum[n] - prefix_sum[i] <= k) {
            // This candidate can win without any additional votes
            continue;
        }

        ll needed = (prefix_sum[n] - prefix_sum[i]) - k;
        
        // Find the smallest j such that prefix_sum[j] >= needed
        int j = upper_bound(prefix_sum.begin(), prefix_sum.end(), needed) - prefix_sum.begin();
        j--;

        if(j != i) {
            result[candidates[i].index - 1] = prefix_sum[j + 1] - prefix_sum[i] - needed;
        } else {
            // Special case where we need at least one vote to ensure win
            if(candidates[i].votes == prefix_sum[i]) {
                result[candidates[i].index - 1] = 1;
            }
        }
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m;
    ll k;
    cin >> n >> m >> k;

    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    vector<ll> res = min_additional_votes(n, m, k, a);
    
    for(auto val : res) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}