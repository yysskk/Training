// SeeAlso: https://atcoder.jp/contests/abc119/tasks/abc119_c

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define MAX 100000

typedef int _loop_int;
#define REP(i,n) for(int i = 0; i < n; i++)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define CHMIN(a,b) a=min((a),(b))
#define CHMAX(a,b) a=max((a),(b))

// 最大公約数
inline constexpr ll gcd(ll a,ll b){if(!a||!b)return 0;while(b){ll c=b;b=a%b;a=c;}return a;}
// 最小公倍数
inline constexpr ll lcm(ll a,ll b){if(!a||!b)return 0;return a*b/gcd(a,b);}

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
template<class T> void print(const T& x){cout << setprecision(12) << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }

int N,A,B,C;
int l[MAX];

int dfs(int n, int a, int b, int c) {
    if(n==N) {
        if(min(a,min(b,c)) <=0) {
            return 100000;
        } else {
            return abs(A-a) + abs(B-b) + abs(C-c) - 30;
        }
    }
    int r1 = dfs(n+1,a,b,c);
    int r2 = dfs(n+1,a+l[n],b,c)+10;
    int r3 = dfs(n+1,a,b+l[n],c)+10;
    int r4 = dfs(n+1,a,b,c+l[n])+10;
    int m1 = min(r1,r2);
    int m2 = min(r3,r4);
    return min(m1,m2);
}

int main() {
    cin >> N >> A >> B >> C;
    REP(i, N) {
        cin >> l[i];
    }

    print(dfs(0,0,0,0));
    return 0;
}
