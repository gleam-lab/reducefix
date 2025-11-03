#include <iostream>
#include <set>

using namespace std;

// Fast IO
void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Solve()
{
    int Q;
    cin >> Q;
    multiset<int> bag;
    
    while (Q--)
    {
        int type;
        cin >> type;
        
        if (type == 1)
        {
            int x;
            cin >> x;
            bag.insert(x);
        }
        else if (type == 2)
        {
            int x;
            cin >> x;
            // Find and remove one occurrence of x
            auto it = bag.find(x);
            if (it != bag.end())
                bag.erase(it);
        }
        else if (type == 3)
        {
            // Count distinct integers in the bag
            set<int> distinct(bag.begin(), bag.end());
            cout << distinct.size() << '\n';
        }
    }
}

int main()
{
    fastIO();
    Solve();
    return 0;
}