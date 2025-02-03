#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VEHICLES 100

// managing vehicles
typedef struct
{
    int vehicles[MAX_VEHICLES];
    int front, rear, count;
} Queue;

// initializing queue
void initQueue(Queue *q)
{
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

// Check if queue is empty
bool isEmpty(Queue *q)
{
    return (q->count == 0);
}

// Enqueue a vehicle
void enqueue(Queue *q, int vehicle)
{
    if (q->count < MAX_VEHICLES)
    {
        q->rear = (q->rear + 1) % MAX_VEHICLES;
        q->vehicles[q->rear] = vehicle;
        q->count++;
    }
}

// Dequeue a vehicle
int dequeue(Queue *q)
{
    if (!isEmpty(q))
    {
        int vehicle = q->vehicles[q->front];
        q->front = (q->front + 1) % MAX_VEHICLES;
        q->count--;
        return vehicle;
    }
    return -1; // Queue empty
}

// Priority queue for traffic lanes
typedef struct
{
    int lane;
    int priority;
} PriorityQueue;

PriorityQueue lanes[4]; // AL2, BL2, CL3, DL4
int totalLanes = 4;

// Function to update priority of AL2
void updatePriority()
{
    if (lanes[0].priority > 10)
    {
        lanes[0].priority = 100; // Set high priority
    }
    else if (lanes[0].priority <= 5)
    {
        lanes[0].priority = 1; // Reset to normal
    }
}

// Function to serve vehicles
void serveTraffic(Queue queues[])
{
    updatePriority();

    int maxPriority = 0, index = -1;
    for (int i = 0; i < totalLanes; i++)
    {
        if (lanes[i].priority > maxPriority)
        {
            maxPriority = lanes[i].priority;
            index = i;
        }
    }

    if (index != -1 && !isEmpty(&queues[index]))
    {
        printf("Serving vehicle from Lane %d\n", lanes[index].lane);
        dequeue(&queues[index]);
        lanes[index].priority--; // Reduce priority after serving
    }
}

// Main function
int main()
{
    Queue vehicleQueues[4];
    for (int i = 0; i < 4; i++)
    {
        initQueue(&vehicleQueues[i]);
        lanes[i].lane = i;
        lanes[i].priority = 1; // Normal priority
    }

    // Simulate adding vehicles
    enqueue(&vehicleQueues[0], 1);
    enqueue(&vehicleQueues[0], 2);
    enqueue(&vehicleQueues[1], 3);
    enqueue(&vehicleQueues[2], 4);
    enqueue(&vehicleQueues[3], 5);

    // Increase priority of AL2 for testing
    lanes[0].priority = 12;

    // Serve vehicles
    for (int i = 0; i < 5; i++)
    {
        serveTraffic(vehicleQueues);
    }

    return 0;
}
