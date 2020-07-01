// SeeAlso: https://atcoder.jp/contests/arc031/tasks/arc031_2

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

int a[10][10];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

void rec(int y, int x) {
    if (a[y][x]<0) return;
    if (a[y][x]==y*x) return;
    a[y][x] = x*y;
    rep(k, 4) {
        int diffX = x + dx[k];
        int diffY = y + dy[k];
        if(diffX<0||diffX>=10) continue;
        if(diffY<0||diffY>=10) continue;
        rec(y+dy[k], x+dx[k]);
    }
    return;
}

int main() {
    
    rep(i, 10) {
        rep(j, 10) {
            char c; cin >> c;
            if (c=='x') a[i][j] = -1;
            else a[i][j] = 0;
        }
    } 
    
    rep(i, 10) {
        rep(j, 10) {
            if (a[i][j]<0) continue;
            rec(i, j);
        }
    }

    rep(i, 10) {
        rep(j, 10) {
            if (a[i][j]<0) cout << "x";
            else cout << a[i][j];
        }
        cout << endl;
    }

    rep(i, 10) {
        rep(j, 10) {
            if (a[i][j]>=0) continue;
            set<char> mawari;
            rep(k, 4) {
                int diffX = j + dx[k];
                int diffY = i + dy[k];
                if(diffX<0||diffX>=10) continue;
                if(diffY<0||diffY>=10) continue;
                if(a[diffY][diffX]<0) continue;
                mawari.insert(a[diffY][diffX]);
            }

            if(mawari.size()<2) continue;
            print("YES");
            return 0;
        }
    }
    print("NO");
    return 0;
}
