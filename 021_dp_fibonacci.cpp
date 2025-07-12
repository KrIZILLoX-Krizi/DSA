



#include<bits/stdc++.h>

using namespace std;

/* NOTICE THE TIME DIFFERENCE IN THE RESULTS OF ALL THREE METHODS */

// recursion method for fibonacci problem
int recursion_fibonacci(int n)
{
  // if 0-th or 1-st term
  if(n == 0 || n == 1)
  {
    return n;
  }

  // recursion function
  int res = recursion_fibonacci(n - 1) + recursion_fibonacci(n - 2);

  return res;
}
// ---------------------------------------------
// TC: O(2^n)
// SC: O(2^n - 1) // call stack space
// ---------------------------------------------


// memoization method for fibonacci problem
int memoization_fibonacci(int n, vector<int>& memoize_dp)
{
  // if 0-th or 1-st term
  // recursion termination condition
  if(n == 0 || n == 1)
  {
    return n;
  }

  // if already calculated and present in the dp vector
  // return value
  if(memoize_dp[n] != -1) { return memoize_dp[n]; }

  // recursion function
  // if newly calculated value
  // store in global vector
  return memoize_dp[n] = memoization_fibonacci(n - 1, memoize_dp) + memoization_fibonacci(n - 2, memoize_dp);
}
// ---------------------------------------------
// TC: O(n)
// SC: O(n + n) // call stack space + extra array
// ---------------------------------------------

// two vars method for fibonacci problem
int two_vars_fibonacci(int n)
{
  // storing values for first and second element
  // storing initial result
  int first = 0;
  int second = 1;
  int res = 0;

  // if first or second element
  if(n == first) return first;
  if(n == second) return second;

  // store sum of previous two elements till n
  for(int i = 2; i <= n; ++i)
  {
    res = first + second;
    first = second;
    second = res;
  }

  return res;
}
// ---------------------------------------------
// TC: O(n)
// SC: O(1)
// ---------------------------------------------

// driver method
void fibonacci(int n)
{
  vector<int> memoize_dp(n + 1, -1);
  cout << "two vars fib: " << two_vars_fibonacci(n) << endl;
  cout << "memoized fib: " << memoization_fibonacci(n, memoize_dp) << endl;
  cout << "recurson fib: " << recursion_fibonacci(n) << endl;
}

// main driver
int main(void)
{
  int n;

  cout << "Enter n: ";
  cin >> n;

  // call functional driver
  fibonacci(n);

  return 0;
}
