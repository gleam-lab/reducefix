#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<long long, long long> pii;

long long solve(long long n, long long k, vector<pii>& a, vector<pii>& b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    long long ans = LLONG_MAX;
    long long sum = 0;
    for(int i = 0; i < k; ++i) {
        sum += b[i].second;
    }

    for(int i = k-1; i < n; ++i) {
        ans = min(ans, (sum + b[i].second) * a[i-k+1].second);
        sum -= b[i-k+1].second;
        if(i+1 < n) {
            sum += b[i+1].second;
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    long long t;
    cin >> t;

    while(t--) {
        long long n, k;
        cin >> n >> k;

        vector<pii> a(n), b(n);
        for(long long i = 0; i < n; ++i) {
            cin >> a[i].second >> a[i].first;
        }
        for(long long i = 0; i < n; ++i) {
            cin >> b[i].second >> b[i].first;
        }

        cout << solve(n, k, a, b) << '\n';
    }

    return 0;
}