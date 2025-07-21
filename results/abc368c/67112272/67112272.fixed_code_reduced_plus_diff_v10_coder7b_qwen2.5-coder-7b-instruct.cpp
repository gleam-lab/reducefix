#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (ll i=0;i < (n); i++)
typedef long long ll;
const int mod = 1e9 + 7;

class Solution {
public:
    int minimumTime(vector<int>& healths) {
        int n = healths.size();
        sort(healths.begin(), healths.end());
        int time = 0;
        for(int i = 0; i < n; ++i){
            if(healths[i] == 0) continue;
            if((time / 3) % 2 == 0) healths[i] -= 3;
            else healths[i] -= 1;
            if(healths[i] > 0){
                time++;
                --i;
            }
        }
        return time;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> healths(n);
    rep(i,n) cin >> healths[i];

    Solution sol;
    cout << sol.minimumTime(healths) << "\n";

    return 0;
}