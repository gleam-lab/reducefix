#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<numeric>
#include <iomanip>

using namespace std;
using ll = long long;

const double PI = acos(-1.0);

int main()
{
    int N;
    cin >> N;
    vector<ll> H(N);
    for (int i = 0; i < N; i++)
    {
        cin >> H[i];
    }
    ll T = 0;
    for (int i = 0; i < N; i++)
    {
        ll remaining = H[i];
        ll full_cycles = remaining / 5;
        T += full_cycles * 3;
        remaining %= 5;
        if (remaining == 0)
            continue;
        if (T % 3 == 0)
        {
            T += 1;
            remaining -= 3;
            if (remaining > 0)
            {
                T += remaining;
            }
        }
        else if (T % 3 == 1)
        {
            T += 1;
            remaining -= 1;
            if (remaining > 0)
            {
                T += 1;
                remaining -= 1;
                if (remaining > 0)
                {
                    T += 1;
                }
            }
        }
        else // T % 3 == 2
        {
            T += 1;
            remaining -= 1;
            if (remaining > 0)
            {
                T += 1;
                remaining -= 3;
                if (remaining > 0)
                {
                    T += remaining;
                }
            }
        }
    }
    cout << T << endl;
}