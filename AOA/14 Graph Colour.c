// Graph Colouring
// We use BackTracking to Generate Solution Set
// 
//  Safety Checker:
//   Input Node Value
//   Iterate over all Edges Present till Node
//    Condition is similar to it < node
//   Check if the Connected Vertex has same color
//   If it does
//     Fail
//   If No Edge has same Colour
//     Return Success


// First go to Node
// Now try to assign all colours to it
//  Now check if it's Safe
//   If Safe,
//     Apply the Colour
//     Go to Next Node
//   Obvious Reason being that we only want successful Placements in Node

#include <stdio.h>

int NOT_EDGE = 0;
int adjacancy[100][100];
char colourApplied[100];
char colours[3] = {'R', 'G', 'B'};

void DisplayColours (int size)
{
   for (int it = 0; it < size; ++it)
   {
      printf ("%d : %c ", it, colourApplied[it]);
   }
   printf ("\n");
}
int Safe (int node, char colour)
{
   // Iterate over All Edges
   for (int i = 0; i < node; ++i)
      // If Edge and Vertex Connected has Same Colour Fail
      if (adjacancy[node][i] && colourApplied[i] == colour)
         return 0;
   // As we survived the loop
   // Success
   return 1;
}

void ApplyGraphVertexColour (int node, int size, int coloursMax)
{
   for (int it = 0; it < coloursMax; ++it)
   {
      char colour = colours[it];
      if (Safe (node, colour))
      {
         // As It is safe
         // Apply the colour
         colourApplied[node] = colour;
         if (node == size) {
            DisplayColours (size);
            // As Display Done Terminate
            return;
         }
         else
         {
            // Check for Next Pair
            ApplyGraphVertexColour (node + 1/*Next Node*/, size, coloursMax);
         }
      }
   }
}

int main ()
{
   adjacancy[0][1] = 1;
   adjacancy[1][0] = 1;

   adjacancy[1][2] = 1;
   adjacancy[2][1] = 1;

   adjacancy[2][3] = 1;
   adjacancy[3][2] = 1;

   adjacancy[3][0] = 1;
   adjacancy[0][3] = 1;

   ApplyGraphVertexColour (0, 4, 3);
}

//
//0 : R 1 : G 2 : R 3 : G
//0 : R 1 : G 2 : R 3 : B
//0 : R 1 : G 2 : B 3 : G
//0 : R 1 : B 2 : R 3 : G
//0 : R 1 : B 2 : R 3 : B
//0 : R 1 : B 2 : G 3 : B
//0 : G 1 : R 2 : G 3 : R
//0 : G 1 : R 2 : G 3 : B
//0 : G 1 : R 2 : B 3 : R
//0 : G 1 : B 2 : R 3 : B
//0 : G 1 : B 2 : G 3 : R
//0 : G 1 : B 2 : G 3 : B
//0 : B 1 : R 2 : G 3 : R
//0 : B 1 : R 2 : B 3 : R
//0 : B 1 : R 2 : B 3 : G
//0 : B 1 : G 2 : R 3 : G
//0 : B 1 : G 2 : B 3 : R
//0 : B 1 : G 2 : B 3 : G