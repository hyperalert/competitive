#include<bits/stdc++.h>
using namespace std;

int add(int a,int b,int mod){
  int res=(a%mod+b%mod)%mod;
  if(res<0)
    res+=mod;
  return res;
}
int mul(int a,int b,int mod){
  int res=(a*1LL*b)%mod;
  return res;
}
int pow(int a,int b,int mod){
  int res=1;
  while(b){
    if(b&1)
      res=mul(res,a,mod);
    a=mul(a,a,mod);
    b=b>>1;
  }
  return res;
}
int p=33;
void preCalcPow(vector<int>& pw,int mod){
  int n=pw.size();
  pw[0]=1;
  for(int i=1;i<n;++i)
    pw[i]=mul(pw[i-1],p,mod);
}
void preCalcInv(vector<int>& inv_pw,int mod){
  int n=inv_pw.size();
  int inv=pow(p,mod-2,mod);
  inv_pw[0]=1;
  for(int i=1;i<n;++i)
    inv_pw[i]=mul(inv_pw[i-1],inv,mod);
}
void preCalcHash(vector<int>& hash,vector<int>& pow,string& s,int mod){
  int n=hash.size();
  for(int i=0;i<n;++i)
    hash[i]=add((i==0?0:hash[i-1]),mul(s[i]-'a'+1,pow[i],mod),mod);
}

class Hash{
  public:
   vector<int> pw,inv_pw,hash;
   int mod;
   string s;
   Hash(string a,int m){
     s=a;
     mod=m;
     int n=s.length();
     pw.resize(n+1);
     inv_pw.resize(n+1);
     hash.resize(n+1);
     preCalcPow(pw,mod);
     preCalcInv(inv_pw,mod);
     preCalcHash(hash,pw,s,mod);
   }
   int subString(int i,int j){
     int res=add(hash[j],(i==0?0:-hash[i-1]),mod);
     res=mul(res,inv_pw[i],mod);
     return res;
   }
};
int main(){
  
}
