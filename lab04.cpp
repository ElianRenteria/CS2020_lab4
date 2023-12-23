//Elian Renteria
//CSE2020_Lab04
//The second fuction is a better option when dealing with larger numbers because the time it takes to complete the calculation is much less because it is not relying on a nested for loop which takes more time and we can see how the first function is linear meaning the bigger the number the more time it will take compared to the exponential second function that is able to do larger calcultaions with a smaller increase in the time compared to that of the first function.

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>

using namespace std;

long long int geom_sum1 (int x, int n);

long long int geom_sum2 (int x, int n);

int main()
{
  int n = 1;
  int x = 1;

  cout << "Please enter x: ";
  cin >> x;

  cout << "Please enter n: ";
  cin >> n;

  using clock = chrono::steady_clock;

  clock::time_point start = clock::now();

  cout << geom_sum1(x, n) << endl;

  clock::time_point end = clock::now();

  clock::duration time_span = end - start;
  double nseconds = double(time_span.count()) * clock::period::num / clock::period::den;
  cout << "The execution time is : " << nseconds << endl;
  
  start = clock::now();

  cout << geom_sum2(x, n) << endl;

  end = clock::now();

  time_span = end - start;
  nseconds = double(time_span.count()) * clock::period::num / clock::period::den;
  cout << "The execution time is : " << nseconds << "\n";

  return 0; 
}

long long int geom_sum1 (int x, int n)//I believe i implemented the function correctly, however when solving for larger numbers it yields a negative solution I am not sure why this is the case. With smaller numbers though the function works fine.
{
  long long int result = 0;//changed the data type to long long int but the value still become negative after a certain amount of time
  for(int i = 0; i <= n; i++)
  {
    long long int xpow = 1;
    for(int j = 0; j < i; j++)
    {
      xpow = xpow * x;
    }
    result = result + xpow;
  }
  return result;
}

long long int geom_sum2 (int x, int n)
{
  long long int result = 0;
  for (int i =0; i <= n; i++)
  {
    result = result * x + 1;
  }
  return result;
}
