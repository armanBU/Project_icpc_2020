

/*
    Sk arman Hossain
    University of Barisal

    Problem name : Spoj LCA
    Algorithm : Lowest Common Ancestor
 */

#include<bits/stdc++.h>
#define nl printf("\n");
#define N 200001
#define PR pair<ll,ll>
#define sf1(n) scanf("%lld", &n)
#define sf2(n, m) scanf("%lld %lld",&n,&m)
#define sf3(n, m,k ) scanf("%lld %lld %lld",&n,&m,&k)
#define pfn(n) printf("%d\n",n)
#define pf1(n) printf("%d ",n)
#define pfl1(n) printf("%lld ",n)
#define pfln(n) printf("%lld\n",n)
#define pfu(n) printf("%llu\n",n)
#define pfs(s) printf("%s",s)
#define YES printf("YES\n")
#define NO printf("NO\n")
#define minus1 printf("-1\n")
#define PB push_back
#define PI 3.1415926536
#define VST(v) sort(v.begin(),v.end())
#define VSTcmp(v,cmp) sort(v.begin(),v.end(),cmp)
#define fori(i,n) for(;i<n;i++)
#define fast ios_base::sync_with_stdio(0);cin.tie(0)
#define MP make_pair
#define ff first
#define ss second
#define tt third
#define mod 1000000007
int dx[] = {0,0,1,-1,2,2,-2,-2,1,-1,1,-1};
int dy[] = {1,-1,0,0,1,-1,1,-1,2,2,-2,-2};
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
vector<ll>edge[200000],euler;
ll Tree[600000];
ll map_labeling_pos[200000];
ll map_labeling_val[200000];
ll first[200000];
bool color[200000];ll cnt=0;
void dfs(ll node){
    cnt++;
    color[node]=1;
    ll m=euler.size();
    map_labeling_pos[node]=m;
    map_labeling_val[m]=node;
    ll siz=edge[node].size();
    first[m]=euler.size();
    euler.PB(m);
    for(ll i=0;i<siz;i++){
        if(color[edge[node][i]]==0){
                //label[edge[node][i]]=label[node]+1;
            color[edge[node][i]]=1;
            dfs(edge[node][i]);
            euler.PB(m);
        }
    }
}
ll build(ll n,ll b, ll e){
    if(b==e){
        Tree[n]=euler[b-1];
        return Tree[n];
    }
    ll left=n*2;
    ll right=n*2+1;
    ll mid=(b+e)/2;
    ll p=build(left,b,mid);
    ll q=build(right,mid+1,e);
    Tree[n]=min(p,q);
    return Tree[n];
}
ll query(ll n,ll b,ll e,ll l,ll r){
    if(e<l||b>r){
        return LONG_MAX;
    }
    if(b>=l&&e<=r){
        return Tree[n];
    }
    ll left=n*2;
    ll right=n*2+1;
    ll mid=(b+e)/2;
    ll p=query(left,b,mid,l,r);
    ll q=query(right,mid+1,e,l,r);
    return min(p,q);
}
int main()
{
    //freopen("1input.txt","r",stdin);
    ///freopen("1output.txt","w",stdout);
    ll tcase=1;
    sf1(tcase);
    for(ll test=1; test<=tcase; test++)
    {
       ll n;
       sf1(n);
       for(ll i=0;i<=n;i++){
        edge[i].clear();
        map_labeling_pos[i]=0;
        map_labeling_val[i]=0;
        color[i]=0;
        first[i]=0;
    }
    euler.clear();
       for(ll i=1;i<=n;i++){
         ll a;
         sf1(a);
         for(ll j=0;j<a;j++){
            ll b;
            sf1(b);
            edge[i].PB(b);
            edge[b].PB(i);
         }
       }
       dfs(1);
       ll xx=build(1,1,euler.size());
       ll q;
       printf("Case %lld:\n",test);
       sf1(q);
       for(ll i=0;i<q;i++){
        ll a,b;
        sf2(a,b);
        ll l=first[map_labeling_pos[a]];
        ll r=first[map_labeling_pos[b]];
        if(l>r)swap(l,r);
        ll ans=query(1,1,euler.size(),l+1,r+1);
         ans=map_labeling_val[ans];
        printf("%lld\n",ans);
        printf("%lld\n",cnt);
       }

        // printf("%d\n",ans);
    }
///*****************************  ALHAMDULILLAH  *****************************/
}


