// SeeAlso: https://atcoder.jp/contests/arc074/tasks/arc074_b

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define MAX 300000

typedef int _loop_int;
#define REP(i,n) for(int i = 0; i < n; i++)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define CHMIN(a,b) a=min((a),(b))
#define CHMAX(a,b) a=max((a),(b))

int N;
ll a[MAX];
priority_queue<ll, vector<ll>, greater<ll>> a1;
priority_queue<ll> a2;

ll dp[2][100100];

int main() {

    ll sum = 0;
    cin >> N;

    REP(i, (3*N)) {
        cin >> a[i];
    }   

    REP(i, N) {
        sum += a[i];
        a1.push(a[i]);
    }

	dp[0][0] = sum;

    REP(i,N) {
		a1.push(a[i+N]);
		sum += a[i+N];
		sum -= a1.top();
		a1.pop();
		dp[0][i+1] = sum;
	}

	sum = 0;
	REP(i,N) {
		sum += a[N*2+i];
		a2.push(a[N*2+i]);
	}
	dp[1][N] = sum;
	for(ll i=(N-1); i >= 0; --i) {
		a2.push(a[i+N]);
		sum += a[i+N];
		sum -= a2.top();
		a2.pop();
		dp[1][i] = sum;
	}
	ll res = -1e15;
	REP(i,N+1) {
		res = max(res, dp[0][i] - dp[1][i]);
	}
	cout << res << endl;

    return 0;
}
