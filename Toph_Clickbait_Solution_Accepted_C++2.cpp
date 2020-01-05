#include<bits/stdc++.h>
#define VST(v) sort(v.begin(),v.end())
#define fast ios_base::sync_with_stdio(0);cin.tie(0)
#define PB push_back
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
void fastIO (){ios_base::sync_with_stdio(false);cin.tie(0);cout.precision(20);}
int main()
{
    fastIO();
    ll n;
    cin>>n;
    vector<string>V1,trend;
    for(ll i=0; i<n; i++){
        string s3;cin>>s3;
        if(s3[0]=='#'){
            s3.erase(s3.begin());
            trend.PB(s3);
            }
        else
            V1.PB(s3);
    }
    VST(trend);VST(V1);
    if(V1.size()&&trend.size())
    {
        ll left=0,right=0,ck=1;
        ll lenv=V1.size(),lentrend=trend.size();
        if(lenv<lentrend)
            lentrend=lenv;
        while(left<lenv&&right<lentrend){
            if(V1[left]<trend[right]){
                if(lenv-left>=lentrend-right){
                    cout<<V1[left]<<" ";
                    ck=1;left++;
                }
                else{
                    cout<<trend[right]<<" ";
                    ck=0;right++;
                }
            }
            else{
                if(ck==1){
                    cout<<trend[right]<<" ";
                    ck=0;right++;
                }
                else{
                    cout<<V1[left]<<" ";
                    ck=1;left++;
                }
            }
        }
        while(left<lenv)
        {
            cout<<V1[left];
            if(left<lenv-1)
                cout<<" ";
            left++;
        }
        if(right<lentrend)
        {
            cout<<trend[right];
        }
        cout<<endl;
    }
    else{
        if(trend.size()==0)
        {
            ll len=V1.size();
            for(ll i=0; i<len; i++)
            {
                cout<<V1[i];
                if(i<len-1)
                    cout<<" ";
            }
            cout<<endl;
        }
    }
}
