# Simulation of message routing by intelligent agents for the use of traffic control
<br>
<img src="https://github.com/raphym/Simulation-of-routing-problem-with-intelligent-agents/blob/master/Pictures/image_readme.jpg?raw=true" alt="Project logo" width="500" height="300">


## Disclaimer
* This is the repository of my final project B.Sc in Software engineer for year 2016-2017
* The project takes place in the [Jerusale College of Engineering](https://www.jce.ac.il/), in Ramat Bet HaKerem, Jerusalem, Israel.
* The project is scheduled between October 2016 untill July 2017 

## Staff:
Presentor: Raphael Mazouz<br><br>
<a href="https://github.com/raphym">
<img src="https://avatars2.githubusercontent.com/u/17546494?v=3&s=460" alt="Raphael Mazouz" width="100" height="100"></a>
<br>Academic advisor: Guy Kelman

## Abstract:

As part of the requirements for the BSc Software Engineering degree in 
Azrieli – College of Engineering Jerusalem, I will implement a final project for the company SHEMER ENERGY LTD.

This company develop a “smart city” and want to create a smart system to control the traffic in the city by automatically system and without control center.

I need to create an algorithm that will allow data routing in a distributed network.
Each node is a computer component with the ability to transmit and receive packets wirelessly. The difficult is to create a decentralized network when each component can communicate only with its neighbors.
The routing solution that I implement is the construction of sub-graphs linked by nodes called "Quorums" that will help in the routing of the packages. (Backbones and Quorums)


The project ends with a demonstration of the algorithm by simulating events that come from an event journal that feeds events actions into the communications system.

In order to make measurements and comparisons with other networks, it is possible to run the simulation on all nodes of a particular network.

This mode is called "Test mode" and it allows you to check the ability of the system by sending packets from each node to each node.
The output of the simulation will help to improve the ability of the algorithm with statistics and data on the network information.

For more information you can read the [Final Report](https://github.com/raphym/Simulation_of_message_routing_by_intelligent_agents/tree/master/documentations/5_%D7%9E%D7%A1%D7%99%D7%A8%D7%94)

Other informations can be found in the folder Documentations

## How to run:

Requirements:
* Workspace should be Linux
* C / C ++ compiler
* If the selection is run by event log then this file should appear in the input file folder

Compile files with

  g++ -std=c++11 *.cpp *.h -o app
  
Run the simulation

There are two modes for simulation

• Normal mode: events called by log events

• TESTS Mode : This means sending messages from all network nodes to all network nodes.

So run this : ./app W X Y Z > output_files/log.txt

when :

• W = city_name

• X = choice 0 for test OR 1 for Events-Schedule

• Y = max_hop

• Z = id_from_we_start_to_construct_the_quorums

  
  


