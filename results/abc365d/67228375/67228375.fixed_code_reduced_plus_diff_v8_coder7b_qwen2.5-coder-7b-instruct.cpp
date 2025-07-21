#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<char, char> beats = {{'R', 'P'}, {'P', 'S'}, {'S', 'R'}};
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    for(int i=2;i<=n;i++){
        if(s[i-1]==s[i-2]){
            dp[i]=dp[i-1]+1;
        }else{
            dp[i]=max(dp[i-1],dp[i-2]+1);
        }
    }

    cout << dp[n] << endl;

    return 0;
}