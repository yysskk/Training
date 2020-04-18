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

ll ans = MOD;
int n, m;
multimap<int, pair<int, int>> mm;
pair<int ,int> start;
pair<int, int> goal;

void rec(int currentIndex, pair<int, int> position, ll counter) {
    if(currentIndex==9) {
        counter += (abs(position.first - goal.first) + abs(position.second - goal.second));
        ans = min(ans, counter);
        return;
    }

    currentIndex++;
    auto p = mm.equal_range(currentIndex);
    if (p.first==p.second) {
        ans = -1;
        return;
    }

    for(auto it=p.first;it!=p.second;it++) {
        pair<int, int> next_position = it->second;
        counter += (abs(position.first - next_position.first) + abs(position.second - next_position.second));
        rec(currentIndex, next_position, counter);
    }
    return;
}

int main() {
    cin >> n >> m;
    if(n*m<10) {
        print(-1);
        return 0;
    }
    rep(i, n) {
        rep(j, m) {
            char c;
            cin >> c;
            if(c=='S') {
                start = make_pair(i, j);
            } else if (c=='G') {
                goal = make_pair(i, j);
            } else {
                int v = c - '0';
                mm.emplace(v, make_pair(i, j));
            }
        }
    }

    rec(0, start, 0);
    print(ans);
    return 0;
}
