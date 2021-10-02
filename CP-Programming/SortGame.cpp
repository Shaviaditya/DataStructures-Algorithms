#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

inline bool myCompare( pair<string,int> a , pair<string,int> b)
{
  if(a.second==b.second)
  	return a.first<b.first;

  return a.second>b.second;
}

int main() 
{
  int x,n,i;
  cin>>x;
  pair<string,int> a[100000];
  cin>>n;
  for(i=0;i<n;i++)
  {
    cin>>a[i].first;
    cin>>a[i].second;
  }
  sort(a,a+n,myCompare);
  for(i=0;i<n &&  a[i].second>=x;i++)
  {
      cout<<a[i].first<<" "<<a[i].second<<endl;
      
  }
	return 0;
}