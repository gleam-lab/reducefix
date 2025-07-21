#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int q;
    cin >> q;
    set<int> unique;
    unordered_map<int, int> freq;
    
    for (int i = 0; i < q; i++)
    {
        int type;
        cin >> type;
        
        if (type == 1)
        {
            int x;
            cin >> x;
            freq[x]++;
            if (freq[x] == 1) // Only insert if it's the first occurrence
                unique.insert(x);
        }
        else if (type == 2)
        {
            int x;
            cin >> x;
            freq[x]--;
            if (freq[x] == 0) // Only erase if it's the last occurrence
                unique.erase(x);
        }
        else if (type == 3)
        {
            cout << unique.size() << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    return 0;
}