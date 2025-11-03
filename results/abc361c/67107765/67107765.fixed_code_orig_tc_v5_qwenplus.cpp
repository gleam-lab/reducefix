#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
using ll = long long;
using P = pair<int, int>;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define yes cout<<"Yes"<<endl
#define yesr {cout<<"Yes"<<endl; return 0;}
#define no cout<<"No"<<endl
#define nor {cout<<"No"<<endl; return 0;}
#define yn {cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}
#define dame cout<<-1<<endl
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    // We are removing exactly K elements, so we keep (n - k) elements.
    int keep = n - k;
    int ans = a[keep - 1] - a[0]; // Initial candidate: take first 'keep' elements
    
    // Try all possible contiguous segments of length 'keep'
    // The idea is that the optimal remaining sequence is a contiguous block in the sorted array
    for (int i = 1; i + keep - 1 < n; i++) {
        chmin(ans, a[i + keep - 1] - a[i]);
    }
    
    cout << ans << endl;
}