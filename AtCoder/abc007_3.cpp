// SeeAlso: https://atcoder.jp/contests/abc007/tasks/abc007_3

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

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int main() {

    int R, C;
    int sy, sx, gy, gx;
    char c[50][50];
    int distance[50][50];
    
    cin >> R >> C;
    cin >> sy >> sx;
    cin >> gy >> gx;

    rep(r, R) {
        rep(j, C) {
            cin >> c[r][j];
            distance[r][j] = -1;
        }
    }
    
    sy--;
    sx--;
    gy--;
    gx--;
    
    queue<pair<int, int>> q;
    q.push(make_pair(sx, sy));
    distance[sy][sx] = 0;
                    
    while(!q.empty()) {
        pair<int, int> current_coordinate = q.front();
        q.pop();
        rep(i, 4) {
            pair<int, int> new_coordinate;
            new_coordinate = make_pair(current_coordinate.first + dx[i], current_coordinate.second + dy[i]);

            if(c[new_coordinate.second][new_coordinate.first] == '#') continue;

            if(distance[new_coordinate.second][new_coordinate.first]==-1) {
                q.push(new_coordinate);
                distance[new_coordinate.second][new_coordinate.first] = distance[current_coordinate.second][current_coordinate.first] + 1;
            }
        }
    }
    
    print(distance[gy][gx]);

    return 0;
}
