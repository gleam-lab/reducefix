#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (long long i=0;i < (n); i++)
using ll = long long;

int main()
{
    int n; cin >> n;
    vector<long long> a(n);
    rep(i,n) cin >> a[i];

    long long dp_even=0, dp_odd=-1, temp;

    rep(i,n)
    {
        temp=dp_even;
        dp_even=max(dp_odd+2*a[i],dp_even);
        dp_odd=max(temp+a[i],dp_odd);
    }

    cout << max(dp_even, dp_odd) << endl;
}