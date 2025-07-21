#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    int cnt = 0;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        if (i == 0 || s[i] == s[i - 1])
        {
            cnt++;
        }
        else
        {
            ans += (cnt + 1) / 2;
            v.push_back(cnt);
            cnt = 1;
        }
    }
    ans += (cnt + 1) / 2;
    v.push_back(cnt);
    for(int i=1;i<v.size()-1;i++){
        if(v[i]>1&&v[i-1]>1){
            ans-=1;
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}