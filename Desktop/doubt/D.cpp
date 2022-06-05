#include<bits/stdc++.h>

using namespace std;

long long gcd(long long int a, long long int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
 
// Function to return LCM of two numbers
long long lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}
  

int main()
{
	//cout<<lcm(1,3)<<endl<<gcd(1,3);
	
	int t;
	cin>>t;
	int n,maxi;
	while(t--)
	{
		cin>>n;
		maxi=lcm(1,n-1)-gcd(1,n-1);
		for(int i=1;i<=n/2;i++)
		{
			if(maxi<lcm(i,n-i)-gcd(i,n-i))
			maxi=lcm(i,n-i)-gcd(i,n-i);
		}
		cout<<maxi<<endl;

	}
	
	return 0;
}