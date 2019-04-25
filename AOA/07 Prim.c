// Prim's Algorithm

#include <stdio.h>

int const INFINIT = 400;
int adjacancy[100][100];

// Store if Visited or NOT
int Visited[100];
int Distances[100];
int Parent[100];

void Initialise (int size)
{
   for (int i = 0; i < size; ++i)
   {
      // Set All Nodes Visited as False
      Visited[i] = 0;
      // Set All Nodes Distance as Infinite
      Distances[i] = INFINIT;
      Parent[i] = INFINIT;
   }
   // Root Node is Visited
   Visited[0] = 1;
   Parent[0] = 0;
   Distances[0] = 0;

   // Set All Edges as NOT CONNECTED
   for (int i = 0; i < size; ++i)
      for (int j = 0; j < size; ++j)
         adjacancy[i][j] = INFINIT;
}

void Display (int size)
{
   for (int i = 0; i < size; ++i)
   {
      printf ("%d\t", i);
      if (i == 0)
         printf ("Src\tSrc\n");
      else
         printf ("%d\t%d\n", Distances[i], Parent[i]);
   }
}

void RunPrim (int size)
{
   // Iterate till Last Element Connection Found
   // That is till Second Last
   for (int count = 0; count < size - 1 /*Ignore Last Element*/; ++count)
   {
      int vMin = INFINIT;
      int uMin = INFINIT;
      int weightMin = INFINIT;

      // Find All Visited Nodes
      for (int u = 0; u < size; ++u)
      {
         // Check if Node has already been visited
         if (Visited[u])
         {
            // As Node has already been visited
            // Means a Link Exists to this Node
            // Now to start by finding next Proper Link
            for (int v = 0; v < size; ++v)
            {
               // IS EDGE
               if (adjacancy[u][v] != INFINIT)
               {
                  // Check if Weight < Minimum Weight
                  // Also verify if NODE NOT VISITED
                  if (adjacancy[u][v] < weightMin && !Visited[v])
                  {
                     // SET MINIMUM WEIGHT as Adjacancy
                     weightMin = adjacancy[u][v];
                     // Set Iterator Mins as (v,u)
                     vMin = v;
                     uMin = u;
                  }
               }// Edge or Not
            }//v for
         }// visited or not
      }// u for
      // Check if we visited any Node in this Iteration
      if (vMin != INFINIT) {
         // Set Visited as True
         Visited[vMin] = 1;
         // Set Distance as Weight
         Distances[vMin] = weightMin;
         Parent[vMin] = uMin;
         // Show Visits
         printf ("Edge added %d -> %d\n", uMin, vMin);
      }
   }

   Display (size);
}

int main ()
{
   Initialise (6);
   // Source: Kevlyn
   {
      adjacancy[0][1] = 3;
      adjacancy[0][5] = 5;
      adjacancy[0][4] = 6;
      adjacancy[1][0] = 3;
      adjacancy[5][0] = 5;
      adjacancy[4][0] = 6;

      adjacancy[1][2] = 1;
      adjacancy[1][5] = 4;
      adjacancy[2][1] = 1;
      adjacancy[5][1] = 4;

      adjacancy[2][3] = 6;
      adjacancy[2][5] = 4;
      adjacancy[3][2] = 6;
      adjacancy[5][2] = 4;

      adjacancy[3][5] = 5;
      adjacancy[3][4] = 8;
      adjacancy[5][3] = 5;
      adjacancy[4][3] = 8;

      adjacancy[4][5] = 2;
      adjacancy[5][4] = 2;
   }
   RunPrim (6);
}

//Edge added 0 -> 1
//Edge added 1 -> 2
//Edge added 1 -> 5
//Edge added 5 -> 4
//Edge added 5 -> 3
//0       Src     Src
//1       3       0
//2       1       1
//3       5       5
//4       2       5
//5       4       1