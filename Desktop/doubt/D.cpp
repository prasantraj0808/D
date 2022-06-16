//https://practice.geeksforgeeks.org/problems/count-smaller-elements2214/1
//https://www.youtube.com/watch?v=_sA1xI4XK0c
// { Driver Code Starts
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
// int countInv=0;
    void merge(int arr[],int temp[],vector<int>&ans,unordered_map<int,int>&ump,int left,int mid,int right)
    {
        int i=left,j=mid,k=left;
        while(i<=mid-1 && j<=right)
        {
            if(arr[i]>arr[j])
            {
                temp[k++]=arr[i];
                ans[ump[arr[i]]]+=(right-j+1);
                i++;
            }
            else
            {
                temp[k++]=arr[j++];
                //countInv+=(mid-i);
                //ans[i]++;
            }
        }
        while(i<=mid-1)
        temp[k++]=arr[i++];
        while(j<=right)
        temp[k++]=arr[j++];
        for(i=left;i<=right;i++)
        {
            arr[i]=temp[i];
        }
        
    }
     void mergeSort(int arr[],int temp[],vector<int>&ans,unordered_map<int,int>&ump,int left,int right)
     {
        int mid;
         if(right>left)
         {
             mid=(left+right)/2;
             mergeSort(arr,temp,ans,ump,left,mid);
              mergeSort(arr,temp,ans,ump,mid+1,right);
              merge(arr,temp,ans,ump,left,mid+1,right);
              
             
         }
     }
     /*
     long long inversionCount(long long arr[], long long N)
    {
        // Your Code Here
       long long temp[N]; 
       
        mergeSort(arr,temp,0,N-1);
        return countInv;
        
    }
    */
    
	vector<int> constructLowerArray(int *arr, int n) {
	    // code here
	     int temp[n];
	     vector<int>ans;
	     /*
	     pair<int,int >p;
	      vector<int>count(n,0);
	     for(int i=0;i<n;i++)
	     {
	         p.first=arr[i];
	         p.second=i;
	         ans[i]=p;
	     }
	      */
	     ans.resize(n,0);
	     unordered_map<int,int>ump;
	     for(int i=0;i<n;i++)
	     {
	         ump[arr[i]]=i;
	     }
      
        mergeSort(arr,temp,ans,ump,0,n-1);
       
      
        return ans;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.constructLowerArray(arr, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends