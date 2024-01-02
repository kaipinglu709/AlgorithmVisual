// GraphAlgorithms.hpp

#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <limits>
#include <map>

class Graph {
    int numVertices;
    std::map<int, std::list<std::pair<int, int> > > adjList;

public:
    Graph(int vertices) : numVertices(vertices) {}

    void addEdge(int start, int end, int weight = 1) {
        adjList[start].push_back(std::make_pair(end, weight));
    }

    void DFS(int start) {
        std::vector<bool> visited(numVertices, false);
        std::stack<int> stack;

        stack.push(start);

        while (!stack.empty()) {
            int current = stack.top();
            stack.pop();

            if (!visited[current]) {
                visited[current] = true;
                std::cout << current << " ";

                std::list<std::pair<int, int> >::iterator it;
                for (it = adjList[current].begin(); it != adjList[current].end(); ++it) {
                    if (!visited[it->first]) {
                        stack.push(it->first);
                    }
                }
            }
        }
        std::cout << std::endl;
    }

    void BFS(int start) {
        std::vector<bool> visited(numVertices, false);
        std::queue<int> queue;

        visited[start] = true;
        queue.push(start);

        while (!queue.empty()) {
            int current = queue.front();
            queue.pop();
            std::cout << current << " ";

            std::list<std::pair<int, int> >::iterator it;
            for (it = adjList[current].begin(); it != adjList[current].end(); ++it) {
                if (!visited[it->first]) {
                    visited[it->first] = true;
                    queue.push(it->first);
                }
            }
        }
        std::cout << std::endl;
    }

    // Dijkstra's Algorithm - Find Shortest Path from start to all other vertices
    void Dijkstra(int start) {
        std::vector<int> distance(numVertices, std::numeric_limits<int>::max());
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, std::greater<std::pair<int, int> > > minHeap;

        distance[start] = 0;
        minHeap.push(std::make_pair(0, start));

        while (!minHeap.empty()) {
            int current = minHeap.top().second;
            minHeap.pop();

            std::list<std::pair<int, int> >::iterator it;
            for (it = adjList[current].begin(); it != adjList[current].end(); ++it) {
                int node = it->first;
                int weight = it->second;

                if (distance[node] > distance[current] + weight) {
                    distance[node] = distance[current] + weight;
                    minHeap.push(std::make_pair(distance[node], node));
                }
            }
        }

        for (int i = 0; i < numVertices; i++) {
            std::cout << "Vertex " << i << ", Min Distance: " << distance[i] << std::endl;
        }
    }
};
