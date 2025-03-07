#!/bin/bash

# Function to get the latitude and longitude from the ROS 2 topic
get_lat_lon() {
    # Echo the topic and extract the latitude and longitude values
    LAT_LON=$(ros2 topic echo /mavros/global_position/global --once | grep -E 'latitude:|longitude:' | awk '{print $2}')
    
    # Extract latitude and longitude values
    LAT=$(echo "$LAT_LON" | head -n 1)
    LON=$(echo "$LAT_LON" | tail -n 1)

    echo "$LAT $LON"
}

# Function to find the path to the ROS 2 workspace and the comp_tasks package
update_yaml() {
    NODE_NAME=$1
    IDENTIFIER=$2
    LAT=$3
    LON=$4

    if [[ "$NODE_NAME" == "m" ]]; then
        FULL_NODE_NAME="maneuvering"
    elif [[ "$NODE_NAME" == "n" ]]; then
        FULL_NODE_NAME="nav_channel"
    elif [[ "$NODE_NAME" == "d" ]]; then
        FULL_NODE_NAME="docking"
    elif [[ "$NODE_NAME" == "s" ]]; then
        FULL_NODE_NAME="speed"
    elif [[ "$NODE_NAME" == "h" ]]; then
        FULL_NODE_NAME="home"
    else
        echo "Invalid node name. Use 'm' (maneuvering), 'n' (nav channel), 'd' (docking), or 's' (speed challenge), 'h' (home)"
        exit 1
    fi

    # Get the directory where the script is located
    SCRIPT_DIR=$(dirname "$(realpath "$0")")

    # Build the full path to the comp_tasks package
    COMP_TASKS_PATH="$SCRIPT_DIR/comp_tasks"
    
    # Check if the comp_tasks package exists
    if [ ! -d "$COMP_TASKS_PATH" ]; then
        echo "Error: ROS 2 package 'comp_tasks' not found in the script's directory."
        exit 1
    fi

    # Build the full path to the gps_points.yaml file
    YAML_FILE="$COMP_TASKS_PATH/config/gps_points.yaml"
    
    # Check if the yaml file exists
    if [ ! -f "$YAML_FILE" ]; then
        echo "Error: YAML file '$YAML_FILE' not found."
        exit 1
    fi
    
    # Make a backup of the original YAML file
    cp "$YAML_FILE" "$YAML_FILE.bak"
    
    # Update the correct field based on the node name and identifier
    if [[ "$IDENTIFIER" == "r" ]]; then
        # Update the recovery_lat and recovery_lon values
        sed -i "/^\s*\/\?$FULL_NODE_NAME:/,/^[^ ]/s/^\(\s*recovery_lat: \).*/\1 $LAT/" "$YAML_FILE"
        sed -i "/^\s*\/\?$FULL_NODE_NAME:/,/^[^ ]/s/^\(\s*recovery_lon: \).*/\1 $LON/" "$YAML_FILE"
    elif [[ "$IDENTIFIER" == "s" ]]; then
        # Update the finish_lat and finish_lon values
        sed -i "/^\s*\/\?$FULL_NODE_NAME:/,/^[^ ]/s/^\(\s*start_lat: \).*/\1 $LAT/" "$YAML_FILE"
        sed -i "/^\s*\/\?$FULL_NODE_NAME:/,/^[^ ]/s/^\(\s*start_lon: \).*/\1 $LON/" "$YAML_FILE"
    elif [[ "$IDENTIFIER" == "f" ]]; then
        # Update the finish_lat and finish_lon values
        sed -i "/^\s*\/\?$FULL_NODE_NAME:/,/^[^ ]/s/^\(\s*finish_lat: \).*/\1 $LAT/" "$YAML_FILE"
        sed -i "/^\s*\/\?$FULL_NODE_NAME:/,/^[^ ]/s/^\(\s*finish_lon: \).*/\1 $LON/" "$YAML_FILE"
    else
        echo "Invalid identifier. Use 'r' (recovery), 's' (start), or 'f' (finish)."
        exit 1
    fi
    
    # Print a success message
    echo "Updated $IDENTIFIER coordinates for $FULL_NODE_NAME in $YAML_FILE."
}

# Main Script
if [[ $# -ne 2 ]]; then
    echo "Usage: $0 <node_name> <identifier>"
    echo "Example: $0 my_node recovery"
    exit 1
fi

NODE_NAME=$1
IDENTIFIER=$2

# Get the latitude and longitude from the ROS 2 topic
LAT_LON=$(get_lat_lon)
LAT=$(echo "$LAT_LON" | awk '{print $1}')
LON=$(echo "$LAT_LON" | awk '{print $2}')

# Update the YAML file with the new coordinates
update_yaml "$NODE_NAME" "$IDENTIFIER" "$LAT" "$LON"

