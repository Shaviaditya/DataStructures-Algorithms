#include<iostream>

int findLowerBound(int num, int a[],int n){
    int lowerBound = -1;
    
    int s=0;
    int e=n;
    
    while(s<=e){
      int mid = (s+e)/2;
      if(a[mid]==num){
          lowerBound=mid;
          e=mid-1;
      }else if(a[mid]>num){
          e=mid-1;
      }else{
          s=mid+1;
      }
    }
    
    return lowerBound;
}

int findUpperBound(int num, int a[],int n){
    int upperBound =-1;
    
    int s=0;
    int e=n;
    
    while(s<=e){
      int mid = (s+e)/2;
      if(a[mid]==num){
          upperBound=mid;
          s=mid+1;
      }else if(a[mid]>num){
          e=mid-1;
      }else{
          s=mid+1;
      }
    }
    
    return upperBound;
}


int main() {
    int n;
    std::cin >> n;
    
    int a[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    int t;
    std::cin >> t;
    
    while(t--){
        int num;
        std::cin >> num;
        
        int lowerBound = findLowerBound(num,a,n);
        int upperBound = findUpperBound(num,a,n);
        
        std::cout << lowerBound<<" "<<upperBound << std::endl;
    }
	return 0;
}