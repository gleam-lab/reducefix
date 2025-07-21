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
        ll full_cycles = H[i] / 5;
        T += full_cycles * 3;
        ll remaining = H[i] % 5;
        if (remaining == 0)
            continue;
        if (T % 3 == 0)
        {
            // First attack is 3 damage (T is multiple of 3)
            if (remaining <= 3)
            {
                T += 1;
            }
            else
            {
                T += 3;
            }
        }
        else if (T % 3 == 1)
        {
            // First attack is 1 damage
            if (remaining <= 1)
            {
                T += 1;
            }
            else if (remaining <= 2)
            {
                T += 2;
            }
            else
            {
                T += 3;
            }
        }
        else
        {
            // T % 3 == 2, first attack is 1 damage, second is 3 damage
            if (remaining <= 1)
            {
                T += 1;
            }
            else if (remaining <= 4)
            {
                T += 2;
            }
            else
            {
                T += 3;
            }
        }
    }
    cout << T << endl;
}