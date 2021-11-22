/*
    Programmers : Alexandru Olteanu
*/
#include<bits/stdc++.h>
using namespace std;
// GCC Optimizations
// #pragma GCC optimize("Ofast");
// #pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt")
// #pragma GCC target("abm,mmx,avx,avx2,tune=native")
// #pragma GCC optimize(3)
// #pragma GCC optimize("inline")
// #pragma GCC optimize("-fgcse")
// #pragma GCC optimize("-fgcse-lm")
// #pragma GCC optimize("-fipa-sra")
// #pragma GCC optimize("-ftree-pre")
// #pragma GCC optimize("-ftree-vrp")
// #pragma GCC optimize("-fpeephole2")
// #pragma GCC optimize("-ffast-math")
// #pragma GCC optimize("-fsched-spec")
// #pragma GCC optimize("unroll-loops")
// Useful
mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define FastEverything  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define HighPrecision cout<<fixed<<setprecision(17);
typedef long long ll;
typedef pair<int,int> pii;
ll const mod=1000000007LL;
ll const mod2 = 100000000LL;
ll const md=998244353LL;
ll mypowr(ll a,ll b, ll mod1) {ll res=1;if(b<0)b=0;a%=mod1; assert(b>=0);
for(;b;b>>=1){if(b&1)res=res*a%mod1;a=a*a%mod1;}return res;}
ll mypow(ll a,ll b) {ll res=1;if(b<0)b=0;assert(b>=0);
for(;b;b>>=1){if(b&1)res=res*a;a=a*a;}return res;}
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(), x.rend()

// ifstream in("input.txt");
// ofstream out("output.txt");
// #define cin in
// #define cout out

const ll infll = 9e18;
const int inf = 2e9;
const ll maxn = 1e4 + 2;

deque<ll> v, v1;

int main()
{
    FastEverything
    HighPrecision

    int test = 1;
    cin>>test;
    for(int tt = 1; tt <= test; ++tt){
        int n;
        cin>>n;
        n = (1 << n);
        v.clear();
        v1.clear();
        for(int i = 1; i <= n; ++i){
            int x;cin>>x;
            v.pb(x);
        }
        bool ok = 1;
        sort(all(v));
        while(ok){
            if(v.size() == 1)break;
            while(!v.empty()){
                ll x = v.back();
                v.pop_back();
                ll sum = 1;
                while(!v.empty()){
                    if(v.back() == x){
                        ++sum;
                        v.pop_back();
                    }
                    else{
                        break;
                    }
                }
                ll sum2 = 0;
                while(!v.empty()){
                    if(sum2 == sum)break;
                    if(v.back() == x - 1){
                        ++sum2;
                        v.pop_back();
                    }
                    else{
                        break;
                    }
                }
                ll need = sum - sum2;
                if(need % 2 != 0){
                    ok = 0;
                    break;
                }
                while(need){
                    v1.push_front(2 * x);
                    need -= 2;
                }
                while(sum2){
                    v1.push_front(2 * x - 1);
                    --sum2;
                }
            }
            while(!v1.empty()){
                v.push_front(v1.back());
                v1.pop_back();
            }
        }
        cout<<(ok ? "YES" : "NO")<<'\n';

    }
    

    return 0;
}
