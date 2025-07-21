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
    sort(va.rbegin(), va.rend());
    sort(vb.rbegin(), vb.rend());
    int ind = n;
    bool isPossible=false;
    for (int i =0; i<n-1; i++)
    {
        if (va[i]>vb[i])
        {
            for(int j=i;j>0;j--){
                if(va[j+1]>vb[j]){
                    cout<<-1<<endl;
                    return 0;
                }        
            }
            ind=i;
            isPossible=true;
            break;
        }
    }
    if(isPossible)cout<<va[ind]<<endl;
    else cout<<va[n-1]<<endl;
    
}