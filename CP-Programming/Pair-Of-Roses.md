## Problem Name: Pair of Roses 
### Problem Difficulty: None
#### Problem Constraints: 
1≤ T ≤100<br>
2 ≤ N ≤ 10000<br>
Price[i]<1000001


#### Problem Description:
Deepak has a limited amount of money that he can spend on his girlfriend. So he decides to buy two roses
for her. Since roses are of varying sizes, their prices are different. Deepak wishes to completely spend that fixed amount of money on buying roses for her.<br>
As he wishes to spend all the money, he should choose a pair of roses whose prices when summed up are equal to the money that he has.<br>
Help Deepak choose such a pair of roses for his girlfriend.<br /><br>
NOTE:</b> If there are multiple solutions print the solution that minimizes the difference between the prices i and j. After each test case, you must print a blank line.

#### Input Format: 
Format: The first line indicates the number of test cases T.<br>
Then, in the next line, the number of available roses, N is given.<br>
The next line will have N integers, representing the price of each rose, a rose that costs less than 1000001.<br>
Then there is another line with an integer M, representing how much money Deepak has.<br>
There is a blank line after each test case.

* Sample Input: 
<pre>
2
2
40 40
80

5
10 2 6 8 4
10
</pre>

#### Output Format: 
For each test case, you must print the message: ‘Deepak should buy roses whose prices are i and
j.’, where i and j are the prices of the roses whose sum is equal do M and i ≤ j. You can consider that it
is always possible to find a solution. If there are multiple solutions print the solution that minimizes
the difference between the prices i and j.

* Sample Output:
<pre> 
Deepak should buy roses whose prices are 40 and 40.
Deepak should buy roses whose prices are 4 and 6.
</pre>