#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const int MAXN = 100005;
vector<int> a[MAXN];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, q; cin >> n >> q;
    for(int i = 0; i < n; ++i) {
        int ai; cin >> ai;
        a[ai].push_back(i + 1);
    }
    for(int i = 0; i < MAXN; ++i)
        sort(a[i].begin(), a[i].end());
    
    for(int i = 0; i < q; ++i) {
        int bi, ki; cin >> bi >> ki;
        --ki;
        if(ki < a[bi].size())
            cout << abs(bi - a[bi][ki]) << endl;
        else
            cout << "No valid point found" << endl; // Handle this case appropriately
    }
    return 0;
}