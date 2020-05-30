#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

ll N,A,B,C,D;
ll hoge[] = {2,3,5};

map<ll, ll> memo;

ll func(ll n) {
  if (n == 0) return 0;
  if (n == 1) return D;
  if (memo.count(n)) return memo[n];

  ll res = 1LL << 61;

  if (D < res / n + 10000000)
  {
    chmin(res, D * n);
  }

  for (ll h : hoge) {
    ll cost = 0;
    if (h == 2) cost = A;
    else if (h == 3) cost = B;
    else cost = C;
    chmin(res, func(n / h) + D * abs(n - n / h * h) + cost);
    if (n % h != 0) {
      chmin(res, func(n / h + 1) + D * abs((n / h + 1) * h - n) + cost);
    }
  }

  return memo[n] = res;
}

int main() {
  int T;
  cin >> T;
  while(T--) {
    cin >> N >> A >> B >> C >> D;
    memo.clear();
    cout << func(N) << endl;
  }
}
