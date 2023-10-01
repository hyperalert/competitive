/** author: harshit
  Slytherin
 This is the property of half blood prince
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n" 
class SGT{
  public:
    vector<int> seg;
    SGT(int n)
    {
      seg.resize(4*n);
    }
    void build(int i,int l,int r,vector<int> &arr)
    {
      if(l==r)
      {
        seg[i]=arr[l];
        return;
      }
      int mid=(l+r)/2;
      build(2*i+1,l,mid,arr);
      build(2*i+2,mid+1,r,arr);
      seg[i]=min(seg[2*i+1],seg[2*i+2]);
    }
    void update(int i,int l,int r,int ind,int val)
    {
      if(l==r)
      {
        seg[i]=val;
        return;
      }
      int mid=(l+r)/2;
      if(ind<=mid) update(2*i+1,l,mid,ind,val);
      else update(2*i+2,mid+1,r,ind,val);
      seg[i]=min(seg[2*i+1],seg[2*i+2]);
    }
    int query(int i,int L,int R,int l,int r)
    {
      if(R<l || L>r) return INT_MAX;
      if(L<=l && R>=r) return seg[i];
      int mid=(l+r)/2;
      int q1=query(2*i+1,L,R,l,mid);
      int q2=query(2*i+2,L,R,mid+1,r);
      return min(q1,q2);
    }
};
void solve()
{ 
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i=0;i<n;++i)
  {
    cin>>arr[i];
  }
  SGT s1(n);
  s1.build(0,0,n-1,arr);
  s1.update(0,0,n-1,0,0);
  cout<<s1.query(0,0,2,0,3);
  return ;
}
int32_t main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
  int t;
  t=1;
  while(t--)
  {
  solve();
  }
}
