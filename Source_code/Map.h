#ifndef MAP_H
#define MAP_H
#include <string>
#include <stdlib.h>
#include <iostream>
#include <cmath>
#include <vector>

#include "FileStream.h"
#include "Node.h"


class Map
{
public:
        Map(std::string name,std::string fileProviders, std::string fileLamps, std::string fileTrafficLights);
        virtual ~Map();
        std::vector<Node*> loadLamps(); //return the Lamps vector on the boot
        std::vector<Node*> loadProviders(); // return the Providers vector on the boot
        std::vector<Node*> loadTrafficLights(); // return the TrafficLights vector on the boot
        void loadMap(); // Load the entire map to the memory
        void PrintMap(); // print the map
        std::vector<Node*> getNodes(); // return a vectors of all elements of the map (nodes)
        void addNode(Node *n); // add a node
        void removeNode(int id); // remove a node
        void refreshMap();//Refresh the scan hotspots of each node in the map
        void Garbage_Collector();//clear the map of deleted elements


protected:
        std::string name;
        std::string fileProviders;
        std::string fileLamps;
        std::string fileTrafficLights;
        std::vector<Node*> vecElementsOfTheMap;


private:

};

#endif // MAP_H
