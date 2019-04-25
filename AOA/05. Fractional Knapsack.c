#include <stdio.h>
#include <stdlib.h>

typedef struct {
   float Weight;
   float Cost;
   float Ratio;
}Item;

void Swap (Item* left, Item* right)
{
   Item temp = *left;
   *left = *right;
   *right = temp;
}

void BubbleSortRatios (Item* items, int count)
{
   for (int i = 0; i < count - 1; ++i)
   {
      int done = 0;
      for (int j = 0; j < count - i - 1; ++j)
      {
         if (items[j].Ratio < items[j + 1].Ratio)
         {
            Swap (&items[j], &items[j + 1]);
            done = 1;
         }
      }
      if (!done)
      {
         break;
      }
   }
}

void FindRatio (Item * items, int count)
{
   for (int i = 0; i < count; ++i)
      items[i].Ratio = items[i].Cost / items[i].Weight;
}

float Profit (Item * items, int count, float Weight)
{
   FindRatio (items, count);
   BubbleSortRatios (items, count);
   float Cost = 0.0;
   for (int i = 0; i < count; ++i)
   {
      if (Weight <= 0)
         break;
      if (Weight >= items[i].Weight)
      {
         Cost += items[i].Cost;
         Weight -= items[i].Weight;
         items[i].Weight = 0;
      }
      else
      {
         Cost += items[i].Ratio * Weight;
         items[i].Weight -= Weight;
         Weight = 0;
      }
   }
   return Cost;
}

int main ()
{
   Item items[4];
   items[0].Weight = 10;
   items[0].Cost = 10;
   items[1].Weight = 5;
   items[1].Cost = 10;
   items[2].Weight = 30;
   items[2].Cost = 10;
   items[3].Weight = 50;
   items[3].Cost = 10;

   printf ("Profit %f\n", Profit (items, 4, 20));
}