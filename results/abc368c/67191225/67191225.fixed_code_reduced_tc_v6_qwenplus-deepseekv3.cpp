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

ll compute_attacks(ll health) {
    ll low = 0, high = 2 * health;
    ll answer = high;
    while (low <= high) {
        ll mid = (low + high) / 2;
        ll full_cycles = mid / 3;
        ll remainder = mid % 3;
        ll damage = full_cycles * 5;
        if (remainder == 1) {
            damage += 1;
        } else if (remainder == 2) {
            damage += 2;
        }
        if (damage >= health) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return answer;
}

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
        ll required_attacks = compute_attacks(H[i]);
        if (i > 0) {
            // The attacks on the previous enemy might have T already at a multiple of 3,
            // but we need to ensure the attacks for the current enemy start right after.
            required_attacks = max(required_attacks, compute_attacks(H[i]));
        }
        T += required_attacks;
    }
    cout << T << endl;
}