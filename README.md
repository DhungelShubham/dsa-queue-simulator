# dsa-queue-simulator

This is a DSA project using c and implementing traffic simulation
Traffic Simulation Project
This project simulates traffic flow at a four-way intersection with traffic lights and multiple lanes. The simulation demonstrates vehicle movement, lane changing, and traffic light management for optimal traffic flow.

## Features

Dynamic Vehicle Handling: Vehicles are enqueued into their respective lanes upon arrival.

Lane-Specific Logic:

Lane 2: Vehicles move forward with a controlled gap and stop at the junction if the light is red. If green, they proceed to their destination.

Lane 1: Vehicles appear at the front of the road and are dequeued when they reach at the end of lane.

Lane 3: Vehicles move to the junction and directly enter their destination without checking the light.

Priority Lane:

A2 has priority: If A2 has more than 10 vehicles, all other lanes receive red signals until A2's count drops below 5.

File Input & Socket Integration: Vehicle data is read from a file or received via a socket.

Real-Time Updates: The system continuously processes incoming vehicles and updates their positions.

## Prerequisites

Before running this project, ensure you have the following installed:

SDL2 Library
C Compiler (GCC recommended)

## Build Instructions

Follow these steps to compile and run the simulation:

Compile receiver2.c:
gcc receiver2.c -o receiver2.exe -lws2_32

Compile traffic_generator.c:
gcc -o traffic_generator.exe traffic_generator.c -lws2_32

Run receiver2.exe and traffic_generator.exe.

Compile and run the simulator:
gcc simulator.c queue.c -o simulator -lSDL2 -lSDL2_ttf
Run the simulation.
