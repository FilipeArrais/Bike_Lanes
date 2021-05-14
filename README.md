# Bike_Lanes

Problem C - Bike Lanes
Description
The mayor of a big touristic city asked your help to plan the construction of bike lanes in the city in order to improve the green mobility of tourists. One demand is that bike lanes can only be built in one-way streets, for safety reasons. You are given a map containing direct connections between points of interest (POIs) and their distance. Each direct connection is a one-way street that links directly two POIs. Note there might be no connection between two arbitrary POIs of the map, since we are talking only of the one-way streets of the town.

Although streets are one-way only for car traffic, bikes will be able to travel both ways on the bike lanes.

Because connecting all POIs is expensive and funding is short, instead of building a bike lane in each and every street, you are asked to find touristic circuits from those connections, so you can build lanes connecting the POIs of each circuit independently. A circuit is a set of POIs and connections between those POIs that allows to travel between any pair of POIs and it has maximal size. Note that by definition a circuit is composed by at least two POIs.

So, after identifying these circuits, you have to select a subset of streets to build the bike lanes upon. For each circuit of POIs, you should plan a bike lane that connects all POIs with the minimum possible length.


Figure 1 - Left: POIs map provided, showing the most used connections by the tourists and their length. Middle: Map with the circuits identified. Right: map with the bike lanes to be built on each circuit.

Having all that information, you go to meet the mayor. He might ask you 4 different questions, namely:

How many circuits exist in the city?
How many POIs does the largest circuit contain?
What is the longest lane to build (considering a different lane for each circuit)?
What is the total length of bike lane to build (considering all circuits)?
For the case displayed in Figure 1, your answers should be:
3
6
12
17
Input
The first line of the input gives the number of test cases to process.

Each test case starts with three numbers, 1 ≤ n ≤ 1000 (corresponding to the number of POIs), 1 ≤ m ≤ 100000, corresponding to the number of connections between POIs and 1 ≤ q ≤ 4, corresponding to the number of questions the mayor asks.

Then, m lines follow, each containing 3 values 1 ≤ A ≤ 1000, 1 ≤ B ≤ 1000 and 1 ≤ D ≤ 500. Each line corresponds to a connection from POI A to POI B, with distance D.

Output
For each of the test case of the input, print one line with q values, corresponding to the answers from 1 to q.

Example
Example input:

6
12 18 4
2 1 3
3 2 4
4 1 2
4 2 8
2 5 3
5 2 5
3 6 4
6 3 2
6 5 6
7 5 4
8 6 9
7 8 1
7 9 2
9 10 8
10 7 4
8 11 2
11 12 12
12 10 3
4 4 3
2 1 3
3 2 4
4 1 2
4 2 8
4 4 4
2 1 3
3 2 4
1 4 2
4 2 8
4 4 3
2 1 3
3 2 4
1 4 2
4 2 8
4 4 2
2 1 3
3 2 4
1 4 2
4 2 8
4 4 1
2 1 3
3 2 4
1 4 2
4 2 8

Note: test case 1 of the example input corresponds to the case of Figure 1, having letters A to L replaced by numbers 1 to 12, respectively.

Example output:

3 6 12 17
0 0 0
1 3 5 5
1 3 5 
1 3
1

