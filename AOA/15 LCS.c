// LCS
// Say you have 2 arrays
// Now we can understand that let's say
// ABCDAK & ABBCDAHKJA
// Now let's see that K is present in both
// As such K is part of LCS
// K is present at (6,7)
// So we now know rest of LCS present in range
// (5,6)
// But we know that this element has LCS value of 1
// Which is more than previous element
// Also in case, we don't have a match
// In such a scenario
// We need to choose in that location
// Which LCS Location to pick up
// As such we can either choose, Element above or below
// We choose Max One

// So formula is
// Init a Matrix LCSVals[0...m+1,0...n+1] & LCSDirection[1...m+1,1...n+1] 
// Now
// At i=0 or j=0, 
//    LCSVals[i,j]=0
// If x[i] == y[j] where i < m && j < n
//    We know we have found a match.
// If x[i] != y[j], where i < m & j < n
//    We have to choose between 2 options
//       Either LCS at Top
//       Or LCS via side
//       We choose the one which gives us Max Result

#include <stdio.h>
#include <string.h>

int matrix[100][100];
int dirs[100][100];
int LCS (const char* left, const char* right)
{
   int lenL = strlen (left);
   int lenR = strlen (right);

   for (int i = 0; i < lenL; ++i)
   {
      matrix[i][0] = 0;
      dirs[i][0] = '.';
   }
   for (int j = 0; j < lenR; ++j)
   {
      matrix[0][j] = 0;
      dirs[0][j] = '.';
   }
   for (int iL = 0; iL < lenL; ++iL)
      for (int iR = 0; iR < lenR; ++iR)
      {
         if (left[iL] == right[iR])
         {
            // Remember that Zeroeth Row and Column is Zeroed Out
            // Because No LCS There
            // Add 1 Count to Previous LCS Count at x-1,y-1
            matrix[iL + 1][iR + 1] = matrix[iL][iR] + 1;
            dirs[iL + 1][iR + 1] = 'D';
         }
         else
         {
            // Not a Match
            // Check if to Take from Up or Side
            if (matrix[iL][iR + 1]/*Up*/ >= matrix[iL + 1][iR])
            {
               matrix[iL + 1][iR + 1] = matrix[iL][iR + 1] + 0;
               dirs[iL + 1][iR + 1] = 'U';
            }
            else
            {
               matrix[iL + 1][iR + 1] = matrix[iL + 1][iR] + 0;
               dirs[iL + 1][iR + 1] = 'L';
            }
         }
      }
   return matrix[lenL][lenR];
}

void Display (const char* left, const char* right)
{
   int lenL = strlen (left);
   int lenR = strlen (right);
   for (int iL = 0; iL < lenL; ++iL)
   {
      printf ("%c - ", left[iL]);
      for (int iR = 0; iR < lenR; ++iR)
      {
         printf ("%d %c : ", matrix[iL + 1][iR + 1], dirs[iL + 1][iR + 1]);
      }
      printf ("\n");
   }
}

void DisplayLCS (const char* left, const char* right, int iL, int iR)
{
   if (iL <= 0 || iR <= 0)
      return;
   if (dirs[iL][iR] == 'D')
   {
      printf ("%c ", right[iR - 1]);
      DisplayLCS (left, right, iL - 1, iR - 1);
   }
   if (dirs[iL][iR] == 'U')
   {
      DisplayLCS (left, right, iL - 1, iR);
   }
   if (dirs[iL][iR] == 'L')
   {
      DisplayLCS (left, right, iL, iR - 1);
   }
}

int RunLCS (const char* left, const char* right)
{
   int result = LCS (left, right);
   Display (left, right);
   printf ("\n\n");
   int lenL = strlen (left);
   int lenR = strlen (right);
   printf ("\n\nLCS Is : ");
   DisplayLCS (left, right, lenL, lenR);
   return result;
}

int main ()
{
   RunLCS ("ABCBDAB", "BDCABA");
}
/*
A - 0 U : 0 U : 0 U : 1 D : 1 L : 1 D :
B - 1 D : 1 L : 1 L : 1 U : 2 D : 2 L :
C - 1 U : 1 U : 2 D : 2 L : 2 U : 2 U :
B - 1 D : 1 U : 2 U : 2 U : 3 D : 3 L :
D - 1 U : 2 D : 2 U : 2 U : 3 U : 3 U :
A - 1 U : 2 U : 2 U : 3 D : 3 U : 4 D :
B - 1 D : 2 U : 2 U : 3 U : 4 D : 4 U :




LCS Is : A B C B Press any key to continue . . .
*/