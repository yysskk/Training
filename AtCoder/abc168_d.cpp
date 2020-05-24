// SeeAlso: 

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

int main() {
    ll n,m;
    cin >> n >> m;
    ll a[m], b[m];
    vector<ll> route[n];
    memset(route, 0, sizeof(route));
    rep(i, m) {
        cin >> a[i] >> b[i];
        a[i]--;b[i]--;
        route[a[i]].push_back(b[i]);
        route[b[i]].push_back(a[i]);
    }
    ll ans[n];
    bool visited[n];
    memset(visited, false, sizeof(visited));
    deque<ll> q;
    q.push_back(0);

    while(!q.empty()) {
        ll v = q.front();
        q.pop_front();
        for (int i : route[v]) {
            if(visited[i]) continue;
            ans[i] = v;
            q.push_back(i);
            visited[i] = true;
        }
    }
    print("Yes");
    FOR(i, 1, n) {
        print(ans[i]+1);
    }
    return 0;
}
