#include <iostream>
#include <set>
#include <vector>

using namespace std;
using ll = long long int;
using vvpil = vector<vector<pair<int, ll>>>;
using plli = pair<ll, int>;
using pii = pair<int, int>;

set<pii> iord, jord;

const ll INF = 1e16;

void printstate() {
  cout << "------ iord ---------" << endl;
  for (pii x : iord) cout << x.first << " " << x.second << endl;
  
  cout << "\n------ jord ---------" << endl;
  for (pii x : jord) cout << x.second << " " << x.first << endl;

  cout << "---------------------" << endl;
}

vector<pii> gettargs(int i, int j) {
  auto it = iord.lower_bound({i, j});

  vector<pii> res;

  if (it != iord.end()) {
    pii idown = *it;
    // cout << "itdown " << idown.first << " " << idown.second << endl;
    if (idown.first == i) {
      res.push_back(idown);
    }
    if (idown.first == i && idown.second == j) {
      return res;
    }
  }

  if (it != iord.begin()) {
    it--;
    pii iup = *it;
    // cout << "itup: " << iup.first << " " << iup.second << endl;
    if (iup.first == i)
      res.push_back(iup);
  }

  auto jit = jord.lower_bound({j, i});
  if (jit != jord.end()) {
    pii jright = *jit;
    // cout << "jright " << jright.first << " " << jright.second << endl;
    if (jright.first == j) {
      res.push_back({jright.second, jright.first});
    }
  }

  if (jit != jord.begin()) {
    jit--;
    pii jleft = *jit;
    // cout << "jleft " << jleft.first << " " << jleft.second << endl;
    if (jleft.first == j) {
      res.push_back({jleft.second, jleft.first});
    }
  }

  // ll mindist = 1e8;
  // for (pii x : res) {
  //   ll ld = (ll) x.first - i, rd = (ll) x.second - j;
  //   ll curd = ld * ld + rd * rd;
  //   if (curd < mindist)
  //     mindist = curd;
  // }

  // vector<pii> rr;
  // for (pii x : res) {
  //   ll ld = (ll) x.first - i, rd = (ll) x.second - j;
  //   ll curd = ld * ld + rd * rd;
  //   if (curd == mindist) rr.push_back(x);
  // }
  
  // cout << "mindist found: " << mindist << endl;
  // for (pii x : rr) cout << x.first << " " << x.second << endl;

  // cout << "--------------------" << endl;

  return res;
}

void iter1() {
  ll h, w, q;
  cin >> h >> w >> q;

  vector<pii> qs;
  for (int i = 0; i < q; i++) {
    int r, c; cin >> r >> c;
    qs.push_back({r, c});
  }


  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      iord.insert({i, j});
      jord.insert({j, i});
    }
  }

  for (auto [r, c] : qs) {
    // cout << "getargs for " << r << " " << c << endl;
    vector<pii> curcoord = gettargs(r, c);
    for (pii x : curcoord) {
      iord.erase({x.first, x.second});
      jord.erase({x.second, x.first});
    }
    // printstate();
  }

  cout << iord.size() << endl;
}

/*

. . . . .
. . . . .
. . o . .
. . . . .


. . . . .
. . o . .
. o o o .
. . o . .


g y g . .
y v o . .
v o o o .
. v o . .
. . . . .



. . . . .
. . . . .
. . . . .
. . . . .
. . . . .

*/

int main (int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int d = 1;
  while (d--) {
    iter1();
  }

  return 0;
}
