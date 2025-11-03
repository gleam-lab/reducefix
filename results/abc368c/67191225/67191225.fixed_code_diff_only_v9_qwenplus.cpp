#include<iostream>
#include<vector>

using namespace std;
using ll = long long;

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
    int current_enemy = 0;
    
    while (current_enemy < N)
    {
        T++;
        // Attack the frontmost enemy with health > 0
        if (H[current_enemy] > 0)
        {
            if (T % 3 == 0)
            {
                H[current_enemy] -= 3;
            }
            else
            {
                H[current_enemy] -= 1;
            }
            
            // If current enemy is defeated, move to next
            if (H[current_enemy] <= 0)
            {
                current_enemy++;
            }
        }
    }
    
    cout << T << endl;
    return 0;
}