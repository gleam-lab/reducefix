#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q,k;
long long a[N],b[N];

bool compare(int x,int y)
{
    return a[x]<a[y];
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=q;i++)
        cin>>b[i]>>k;
    
    vector<int> indices(n);
    iota(indices.begin(),indices.end(),1);
    sort(indices.begin(),indices.end(),compare);

    for(int i=1;i<=q;i++)
    {
        int target=b[i];
        int pos = lower_bound(indices.begin(),indices.end(),target,[&](int x,int y){return a[x]<target;})-indices.begin();
        int index=indices[pos]+(pos<k?1:-1);
        if(index<1 || index>n)
            cout<<"0\n";
        else
            cout<<abs(target-a[index])<<"\n";
    }
    return 0;
}