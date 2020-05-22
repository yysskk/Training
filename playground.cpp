#include <bits/stdc++.h>

typedef long long ll;
using namespace std;


#define MAX 1000

typedef int _loop_int;
#define rep(i,n) for(int i = 0; i < n; i++)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<=(_loop_int)(b);++i)
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

#define print2D(h, w, arr) rep(i, h) { rep(j, w) cout << arr[i][j] << " "; cout << endl; }
template<class T> void print(const T& x){cout << setprecision(12) << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }


void heapify(vector<int>& array, int index) {
    int right = index * 2;
    int left = index * 2 + 1;
    if (array[right] > array[index] && array[right] > array[left]) {
        swap(array[right], array[index]);
        heapify(array, right);
    } else if (array[right] > array[index] && array[right] > array[left]) {
        swap(array[right], array[index]);
        heapify(array, right);
    }
}

int main() {

    vector<int> array;
    heapify(array, array.size()-1);
    return 0;
}
