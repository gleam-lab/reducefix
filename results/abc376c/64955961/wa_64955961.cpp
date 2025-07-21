//<<In the name of Allah, The Most Gracious and The Most Merciful>>
#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n;
    cin>>n;
    ll a[n],b[n];
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(ll i=0;i<n-1;i++)
    {
        cin>>b[i];
    }
    sort(a,a+n); sort(b,b+n);
    ll c=0,ans=a[0];
    for(ll i=n-1,j=n-2;i>=0,j>=0;)
    {
        if(a[i]<=b[j])
        {
            i--; j--;
        }
        else
        {
            c++; ans=a[i]; i--;
        }
    }
    if(c>1)cout<<-1<<endl;
    else cout<<ans<<endl;

}

int main()
{
    solve();
}