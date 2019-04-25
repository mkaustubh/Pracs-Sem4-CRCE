// Bellman Ford
//
// Init
//  Initialise
//   All Previous to NULL
//   All DISTANCE to INFINITE
//   Set DISTANCE[Source] = 0
//
// Relax(u,v) Input
//  Verify first if Edge
//   if DISTANCE[v] > DISTANCE[u] + Weight[u,v]
//       Distance[v] = Distance[u] + Weight[u,v]
//       Previous[v] = u
//
// Negative Cycle Check
//  If For Any Element [u,v]
//   DISTANCE[v] > DISTANCE[u] + Weight[u,v]
//    Then this is bad news.
//
// RUN
//  Loop Across all Elements [u,v] Except Second last

int Previous[100];
int Distance[100];

int adjacancy[100][100];

int INFINIT = 1000;

void Display (int source, int size)
{
   for (int i = 0; i < size; ++i)
   {
      printf ("%d",i);
      if (i == source)
         printf ("Src\tSrc\n");
      else
         printf ("%d\t%d",Distance[i], Previous[i]);
   }
}

void Initialise (int source, int size)
{
   for (int i = 0;i < size; ++i)
   {
      Previous[i] = 0;
      Distance[i] = INFINIT;
   }
   Distance[0] = 0;
   for (int i = 0; i < size; ++i)
      for (int j = 0; j < size; ++j)
         adjacancy[i][j] = INFINIT;
   }

void Relax (int u, int v)
{
   // Check if Edge
   if (adjacancy[u][v] == INFINIT)
      return;
   // Check if Distance[v] > Distance[u] + Weight[u,v]
   if (Distance[v] > Distance[u] + adjacancy[u][v])
   {
      Distance[v] = Distance[u] + adjacancy[u][v];
      Previous[v] = u;
   }
}

void BellmanFord (int source, int size)
{
   Initialise (source, size);
   for (int u = 0; u < size - 1/*Last Elem Counted*/; ++u)
      for (int v = 0; v < size; ++v)
         Relax (u,v);
   for (int u = 0; u < size - 1/*Last Elem Counted*/; ++u)
      for (int v = 0; v < size; ++v)
         if (Distance[v] > Distance[u] + adjacancy[u][v])
            return;
   Display (source, size);
}

int main ()
{
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
   BellmanFord (0,6);
}