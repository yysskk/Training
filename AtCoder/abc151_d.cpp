// SeeAlso: https://atcoder.jp/contests/abc151/tasks/abc151_d

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

int h,w;

ll ans = 0;
int arr[4][2] = { 
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0} 
};

int rec(const vector<string> &v, int x, int y) {
    
    int H = v.size(), W = v[0].size();
    vector<vector<int>> dist(H, vector<int>(W, -1));
    queue<pair<int,int>> que;

    int res = 0;
    que.push({x, y});
    dist[x][y] = 0;
    while (!que.empty()) {
        int x = que.front().first;
        int y = que.front().second;
        res = max(res, dist[x][y]);
        que.pop();
        rep(i, 4) {
            int nx = x + arr[i][0];
            int ny = y + arr[i][1];
            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if (v[nx][ny] == '#') continue;
            if (dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                que.push({nx, ny});
            }
        }
    }
    return res;
}

int main() {
    cin >> h >> w;
    vector<string> v(h);
    rep(i, h) {
        cin >> v[i];
    }

    int ans = 0;
    rep(i, h) {
        rep(j,w) {
            if (v[i][j] == '#') continue;
            ans = max(ans, rec(v,i,j));    
        }
    }    
    print(ans);
    return 0;
}
