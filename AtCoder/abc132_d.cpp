// SeeAlso: 

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 2e5 + 5;
const int MOD = 1e9+7;

typedef int _loop_int;
#define REP(i,n) for(int i = 0; i < n; i++)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define CHMIN(a,b) a=min((a),(b))
#define CHMAX(a,b) a=max((a),(b))
ll POW(ll a, ll b, bool usemod = true) {ll c = 1LL; while (b > 0) {if (b & 1LL) {if(!usemod)c*=a;else c = a * c%MOD;}if (!usemod) a*=a;else a = a * a%MOD; b >>= 1LL;}return c;}

// 最大公約数
inline constexpr ll gcd(ll a,ll b){if(!a||!b)return 0;while(b){ll c=b;b=a%b;a=c;}return a;}
// 最小公倍数
inline constexpr ll lcm(ll a,ll b){if(!a||!b)return 0;return a*b/gcd(a,b);}

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
template<class T> void print(const T& x){cout << setprecision(12) << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }


int N, K;
ll c[2010][2010];

int main() {
    cin >> N >> K;
    
	REP(i,2010){
		c[i][0]=1;
		c[i][i]=1;
	}
	for(int i=1;i<2010;i++){
		for(int j=1;j<i;j++){
			c[i][j]=c[i-1][j-1]+c[i-1][j];
			c[i][j]%=MOD;
		}
	}

    for(int i=1;i<=K;i++){
        print((c[N-K+1][i]*c[K-1][i-1])%MOD);
    }

    return 0;
}
