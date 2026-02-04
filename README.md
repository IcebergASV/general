# Nodes #

## Visualization ##

A node for detecting and catolouging objects
 - Just uses camera, no lidar
 - Uses realsense node to parse objects such as bouy's
 - Logs bouys to then create gates and set heading
 - publishes to the detected objects topic

Gauge distance using diameter of bouys at different distances with monocular distance estimation using the size of a known object and perceived size at known distances to gauge distance.

Output the objects and how offset they are from the current heading along with how far away it seems

## Challenge Packages ##

### Navigation ###

Subscribes to the 'detected objects' topic, and keeps track of a gate, then sets heading and shoots forward a known distance (the total distance of the gates as a parameter)

### Follow the Path ###

Subscribes to the 'detected objects' topic, very similar to follow the path but watches for gates more often

### Docking ###

Looks for image, runs into it, reverses

### Speed ###

Runs a foot past first detected gates, stays logs position, moves forward, detects blue bouy, runs set circle, returns to logged gate position.

## Retracking Node ##

Tracks previous path before starting detection, allowing the boat to get farther and farther 

## Core Node ##

Control node that keeps track of what tasks to run
Has a time limit on tasks and switches between them by publishing to the 'Active Task' topic, each task node will subscribe to this topic and only run when the core calls upon it.

