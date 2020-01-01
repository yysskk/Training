// SeeAlso: https://atcoder.jp/contests/abc144/tasks/abc144_e

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define MAX 100000
#define NIL -1
#define MOD 1000000007

typedef int _loop_int;
#define rep(i,n) for(int i = 0; i < n; i++)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define debug(x) cout<<#x<<": "<<x<<endl
#define debig_vec(v) cout<<#v<<":";rep(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

// 最大公約数
inline constexpr ll gcd(ll a,ll b){if(!a||!b)return 0;while(b){ll c=b;b=a%b;a=c;}return a;}
// 最小公倍数
inline constexpr ll lcm(ll a,ll b){if(!a||!b)return 0;return a*b/gcd(a,b);}

#define print2D(h, w, arr) rep(i, h) { rep(j, w) cout << arr[i][j] << " "; cout << endl; }
template<class T> void print(const T& x){cout << setprecision(12) << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }

ll N, K;
vector<ll> A,F;
 
bool judge(ll lim){
  ll res=0;
  for(int i=0;i<N;i++){
    ll z=lim/F[i];
    if(z>=A[i]) continue;
    res+=(A[i]-z);
    if(res>K) return false; 
  }
  return true;
}

int main() {

    cin >> N >> K;

    A.resize(N);
    F.resize(N);
    rep(i,N) cin>>A[i];
    rep(i,N) cin>>F[i];
 
    sort(A.begin(),A.end());
    sort(F.begin(),F.end());
    reverse(F.begin(),F.end());
 
    ll ok=1e15,ng=-1;
    while(ok-ng>1){
        ll mid=(ok+ng)/2;
        if(judge(mid)) ok=mid;
        else ng=mid;
    }

    print(ok);
    return 0;
}
