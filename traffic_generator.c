#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateTraffic()
{
    FILE *file = fopen("lanes.txt", "w");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    srand(time(0));
    for (int i = 0; i < 4; i++)
    {
        int vehicles = rand() % 15; // Random vehicles between 0-15
        fprintf(file, "Lane %d: %d vehicles\n", i, vehicles);
    }

    fclose(file);
}

int main()
{
    generateTraffic();
    printf("Traffic data generated.\n");
    return 0;
}
