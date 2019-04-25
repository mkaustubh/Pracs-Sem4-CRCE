#include <stdio.h>
#include<stdlib.h>

struct MinMax {
   int Min;
   int Max;
};

struct MinMax FindMinMax (int* arr, int left, int right)
{
   if (left == right)
   {
      struct MinMax minMax;
      minMax.Min = minMax.Max = arr[left];
      return minMax;
   }
   else if (left == right + 1) {
      struct MinMax minMax;
      minMax.Min = min (arr[left], arr[right]);
      minMax.Max = max (arr[left], arr[right]);
      return minMax;
   }
   else {
      int mid = (left + right) / 2;
      struct MinMax leftR = FindMinMax (arr, left, mid);
      struct MinMax rightR = FindMinMax (arr, mid + 1, right);

      struct MinMax minMax;
      minMax.Min = min (leftR.Min, rightR.Min);
      minMax.Max = max (leftR.Max, rightR.Max);
      return minMax;
   }
}

struct MinMax MinMaxVal (int* arr, int n)
{
   return FindMinMax (arr, 0, n - 1/*Last Elem Index*/);
}

int main ()
{
   int arr[] = { 1, 12, 0, 4 };
   struct MinMax r = MinMaxVal (arr, 4);
   printf ("%d %d", r.Min, r.Max);
}