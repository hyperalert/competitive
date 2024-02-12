#include<bits/stdc++.h>
using namespace std;

const int N=1e6+6;
const int mod=1e9+7;
const int base=31;
int pw[N];
int inv[N];
int Hash[N];


int add(int a,int b,int mod){
    int res=(a+b)%mod;
    if(res<0)
        res+=mod;
    return res;
}
int mul(int a,int b,int mod){
    int res=(a*1LL*b)%mod;
    if(res<0)
        res+=mod;
    return res;
}
int power(int a,int b,int mod){
    int res=1;
    while(b)
    {
        if(b&1)
            res=mul(res,a,mod);
        a=mul(a,a,mod);
        b=b>>1;
    }
    return res;
}
void precalc(){
    pw[0]=1;
    for(int i=1;i<N;++i)
        pw[i]=mul(pw[i-1],base,mod);
    
    int pw_inv=power(base,mod-2,mod);
    inv[0]=1;
    for(int i=1;i<N;++i)
        inv[i]=mul(inv[i-1],pw_inv,mod);
}
void build(string &s){
    int n=s.length();
    for(int i=0;i<n;++i){
        Hash[i]=add((i==0)?0:Hash[i-1],mul(pw[i],s[i]-'a'+1,mod),mod);
    }
}
int getHash(int x,int y){
    int res=add(Hash[y],(x==0)?0 : -Hash[x-1],mod);
    res=mul(res,(x==0)?1:inv[x],mod);
    return res;
}
int main()
{
 string s="abcabc";
 precalc();
 build(s);
 cout<<getHash(0,2)<<' '<<getHash(3,5)<<endl;
}
