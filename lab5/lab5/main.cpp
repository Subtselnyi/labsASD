#include <stdio.h>
#include <math.h>
#include <iostream>
#define PI 3.1415926535897932
#define INF 1000000

using namespace std;

double cosinus(double x)
{
  return cos(x);
}

double secans(double x)
{
    return 1/cos(x);
}

double CalcIntegral(double a, double b, int n,bool f)
{
  int i;
  double result, h;

  result = 0;

  h = (b - a) / n;
  if (f){
  for(i = 0; i < n; i++)
  {
    result += cosinus(a + h * (i + 0.5));
  }
  }

  if (!f){
    if ((tan(b/2+PI/4)>INF)||(tan(a/4+PI/4)>INF)){
    cout<<"The value of the sec DOES NOT EXSIST";
    return 0;
    }
    for(i = 0; i < n; i++)
  {
    result += secans(a + h * (i + 0.5));
  }
  }

  result *= h;

  return result;
}

int main(void)
{
  double integral;

  integral = CalcIntegral(0,PI/2, 500,true);
  printf("The value of the cos is: %lf \n", integral);
  integral = CalcIntegral(0,PI/2, 500,false);
  if (integral!=0){
  printf("The value of the sec is: %lf \n", integral);
  }
  return 0;
}
