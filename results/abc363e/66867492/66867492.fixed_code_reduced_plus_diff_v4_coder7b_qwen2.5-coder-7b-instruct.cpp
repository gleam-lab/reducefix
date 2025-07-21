#include <bits/stdc++.h>
using namespace std;

struct Init { Init() { ios::sync_with_stdio(false); cin.tie(nullptr); cout << fixed << setprecision(12); } }init;

#define pb push_back
#define em emplace
#define eb emplace_back
#define pob pop_back
#define el '\n'
#define YES cout<<"Yes"<<el
#define NO cout<<"No"<<el
#define NG cout<<-1<<el
#define ansNG(ans,ng) if(ans==ng){ NG; }else{ cout<<ans<<el; }
#define all(a)  a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define rep(i,n)     for(int i = 0; i < (n); ++i)
#define rep3(i,l,r)  for(int i = (l); i < (r); ++i)
#define rrep(i,n)    for(int i = (n)-1; i >= 0; --i)
#define rrep3(i,l,r) for(int i = (r)-1; i >= (l); --i)
#define next_p(x) next_permutation( x )

template<typename T> inline bool chmin(T &a, T b){if(a > b){a = b; return true;}return false;}
template<typename T> inline bool chmax(T &a, T b){if(a < b){a = b; return true;}return false;}

int main() {
    int H, W, Y; cin >> H >> W >> Y;
    vector<vector<int>> A(H, vector<int>(W));
    cin >> A;

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    
    vector<vector<bool>> used(H, vector<bool>(W, false));

    // Add boundary sections to the priority queue
    rep(i, H) {
        pq.emplace(A[i][0], make_pair(i, 0));
        pq.emplace(A[i][W-1], make_pair(i, W-1));
        used[i][0] = true;
        used[i][W-1] = true;
    }

    rep3(i, 1, W-1) {
        pq.emplace(A[0][i], make_pair(0, i));
        pq.emplace(A[H-1][i], make_pair(H-1, i));
        used[0][i] = true;
        used[H-1][i] = true;
    }

    vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};

    int ans = H * W;
    rep3(y, 1, Y+1) {
        while (!pq.empty() && pq.top().first <= y) {
            auto [height, pos] = pq.top();
            pq.pop();
            --ans;

            rep(d, 4) {
                int ny = pos.first + dy[d], nx = pos.second + dx[d];
                if (ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
                if (!used[ny][nx]) {
                    used[ny][nx] = true;
                    pq.emplace(A[ny][nx], make_pair(ny, nx));
                }
            }
        }
        cout << ans << el;
    }

    return 0;
}