#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

#define pb push_back
#define pf push_front
#define lb lower_bound
#define ub upper_bound

#define all(v) v.begin(),v.end() 
#define rall(v) v.rbegin(),v.rend()

#define ii    pair<int,int> 
#define iii   pair<int, ii>
#define iiii  pair<ii,ii>

#define TYPE_OF_DATA int
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#define ORDERED_SET tree<TYPE_OF_DATA, null_type,less<TYPE_OF_DATA>, rb_tree_tag,tree_order_statistics_node_update> 
using namespace __gnu_pbds;

#define LINE                    if(debug) { cerr << " ------------------------------------------ " << endl; }
#define DEBUG1(A)           	if(debug) { cerr << "? " << #A << " : " << A << endl; }
#define DEBUG2(A, B)            if(debug) { cerr << "? [ " << #A << " = " << A << " | " << #B << " = " << B << " ]" << endl; }
#define DEBUG3(A, B, C)         if(debug) { cerr << "? [ " << #A << " = " << A << " | " << #B << " = " << B << " | " << #C << " = " << C << " ]" << endl; }
#define DEBUG4(A, B, C, D)      if(debug) { cerr << "? [ " << #A << " = " << A << " | " << #B << " = " << B << " | " << #C << " = " << C << " | " << #D << " = " << D << " ]" << endl; }
#define DEBUG_PAIR(A) 			if(debug) { cerr << "? " << #A << ": ( " << A.first << " , " << A.second << " )" << endl; }
#define DEBUG_LIST(A)            if(debug) { cerr << "? " << #A << ": "; if(debug) { bool leonelCheems = 0; cerr << "[ ";  for(auto x : A) { if(!leonelCheems) cerr << x , leonelCheems = 1; else cerr << " , " << x ;} cerr << " ]" << endl; } }
#define PRINT_LIST(A) 		    { bool leonelCheems = 0; for(auto x : A) { if(!leonelCheems) {cout << x; leonelCheems = 1;}else {cout << " " << x;}} cout << endl; }
#define DEBUG_ITERABLE_PAIRS(P) 	if(debug) {  cerr << "? " << #P << " : "; cerr << "{ " << endl; for(auto it : P) { cerr << "    " << it.first << " -> " << it.second << endl; } cerr << "} " << endl;  }
#define DEBUG_GRAPH(GP)          if(debug) { cerr << "? " << #GP << " = "; cerr << "{ " << endl; int cntNodes = 0; for(vector<int> adj : GP) { if(adj.size()) { cerr << "   "; cerr << cntNodes << " => "; DEBUG_LIST(adj) } cntNodes ++;} cerr << "}" << endl;}
#define DEBUG_GRAPH_WEIGHT(GP) 	if(debug) { cerr << "? " << #GP << " = {" << endl; int cntNodes = 0; for(auto it : GP ){ if( it.size() ){ cerr << cntNodes << " => [ "; for(auto iter : it){ cerr << iter.first << "-w{" << iter.second << "} "; } cerr << "]" << endl; } cntNodes++; } }
#define DEBUG_MATRIX(arr,F, C)   if(debug) { cerr << "? " << #arr << endl; for(int i = 0 ; i < F ; i++){ cerr << "[ "; for(int j = 0 ; j < C ; j++){ cerr << arr[i][j] << " "; } cerr << "]" << endl;} }
#define EXECUTE_TIME         	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#define FOR(i, l, r)        	for(int i = l; i < r ; i ++)
#define ENDL '\n'
#define SZ(A) 					(int)A.size()

typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;

const int    N    = 2e5  + 9;
const int    MOD  = 1e9  + 7;
const int    INF  = 2e9  + 9;
const ll     MODL = 1e9  + 7;
const ll     INF_L = 2e18 + 9;
const double PI   = acos(-1);

int U[N];
ORDERED_SET V[N];

int Find(int u) {
	if(U[u] == u) return u;
	return U[u] = Find(U[u]);
}

void Union(int u, int v) {
	u = Find(u); v = Find(v);
	if(u != v) {
		U[v] = u;
		if(V[v].size() > V[u].size()) swap(V[u], V[v]);
		// u is the main set
		for(int num : V[v]) {
			V[u].insert(num);
			if(V[u].size() > 30) break;
		}
	}
}

void solveTestCase(int testCase) {
	int n, q; cin >> n >> q;
	for(int i = 1; i <= n; i++) V[i].insert(-i);

	int cmd, u, v, k;
	for(int i = 0; i < q; i++) {
		cin >> cmd;
		if(cmd == 1) {
			cin >> u >> v; Union(u, v);
		}
		else {
			cin >> u >> k;
			u = Find(u);
			if(V[u].size() < k) {
				cout << -1 << ENDL;
			}
			else {
				auto it = V[u].find_by_order(k - 1);
				cout << -(*it) << ENDL; 
			}
		}
	}
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	bool debug = false;
	if(debug)
		cerr << "Debug mode enabled." << ENDL;
    
    FOR(i, 0, N) U[i] = i;
	
	int t = 1;
	//cin >> t;
	solveTestCase(t);
	return 0;
}