#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> va(n);
    vector<int> vb(n);
    vb[0] = 0;
    for (int i = 0; i < n; i++)
        cin >> va[i];
    for (int i = 1; i < n; i++)
        cin >> vb[i];
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());
    // for(auto u:va)cout<<u<<' ';
    // cout<<endl;
    // for(auto u:vb)cout<<u<<' ';
    // cout<<endl;
    bool isPoosible = true;
    int ind = n;
    vector<int> v;
    for (int i = n - 1; i > 0; i--)
    {
        if (vb[i] < va[i])
        {
            if (vb[i] < va[i - 1])
                cout << -1 << endl;
            else
                cout << va[i] << endl;
            //isPoosible = false;
            break;
        }
        ind=i;
    }
    if(ind==1)cout<<va[0]<<endl;
}