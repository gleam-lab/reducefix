#include <iostream>
#include <set>

using namespace std;

void Solve()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;
    set<int> s;
    
    while (Q--)
    {
        int a;
        cin >> a;
        if (a == 1)
        {
            int tp;
            cin >> tp;
            s.insert(tp);
        }
        else if (a == 2)
        {
            int tp;
            cin >> tp;
            s.erase(tp);
        }
        else
        {
            cout << s.size() << "\n";
        }
    }
}

int main()
{
    Solve();
    return 0;
}