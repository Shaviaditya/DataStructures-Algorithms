problem statemnt :
leet
httpsleetcode.comproblemssudoku-solver
gfg
https://practice.geeksforgeeks.org/problems/solve-the-sudoku-1587115621/1


Video link solution
https://www.youtube.com/watch?v=uyetDh-DyDg&t=1185s

#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


 // } Driver Code Ends


class Solution {
  public:
  
 bool check(int grid[N][N],int n1,int x1,int x2)
{
        
        for(int i=0;i<9;i++)
        {
            if(grid[x1][i]==n1)
             return false;
        }
        
        for(int i=0;i<9;i++)
        {
            if(grid[i][x2]==n1)
             return false;
        }
        
        //cout<<x1<<" "<<x2<<endl;
        
        x1=x1/3;
        x2=x2/3;
        
        if(x2==1)
          x2=3;
        else if(x2==2)  
           x2=6;
        if(x1==1)
          x1=3;
        else if(x1==2)  
           x1=6;
           
        //cout<<x1<<" "<<x2<<endl;
        
        for(int i=x1;i<x1+3;i++)
        {
            
            for(int j=x2;j<x2+3;j++)
            {
                
                if(grid[i][j]==n1)
                 return false;
            
            }
            
        }
        
        return true;
        
    }

  
  
    bool SolveSudoku(int grid[N][N],int j1=0,int j2=0)  
    { 
       
       bool f1;
       for(int i=j1;i<N;i++)
       {
           
           for(int j=j2;j<N;j++)
           {
               
                  
                if(grid[i][j]==0)
                {
                
                  for(int x1=1;x1<10;x1++)    
                  {
                      
                      if(check(grid,x1,i,j))
                      { 
                        
                        
                        //cout<<i<<" "<<j<<" "<<x1<<endl;      
                        grid[i][j] = x1;
           
          
                      if (SolveSudoku(grid,i, j+1))
                         return true;
                          
                          
                      }
                      
                      grid[i][j]=0;
                    
                      
                  }
                 
                 return 0;
                
                }
               
               
           }
           
           j2=0;
           
       }
       
       return true;
        
    }
    
    void printGrid(int grid[N][N]) 
    {
        // Your code here 
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                
                cout<<grid[i][j]<<" ";
                
            }
            
       
        }
        
    }
    
    

	
	
	
};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}  // } Driver Code Ends