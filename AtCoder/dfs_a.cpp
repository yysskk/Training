// SeeAlso: https://atc001.contest.atcoder.jp/tasks/dfs_a

#include <bits/stdc++.h>

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define MAX 500

typedef int _loop_int;
#define REP(i,n) for(int i = 0; i < n; i++)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define CHMIN(a,b) a=min((a),(b))
#define CHMAX(a,b) a=max((a),(b))

using namespace std;

int H, W;
int c[MAX][MAX];
int sx, sy;

// 移動4方向のベクトル
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    
    cin >> H >> W;
    REP(h, H) {
        REP(w, W) {
            cin >> c[h][w];
            if (c[h][w] == "s") {
                sx = w;
                sy = h;
            }
        }
    }

    if dfs(0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

bool dfs(int i) {
    return true;
}