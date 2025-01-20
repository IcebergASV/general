import os
import json

def get_lat_lon():
    """Fetch the robot's current latitude and longitude."""
    command = (
        "ros2 topic echo /mavros/global_position/global --once | "
        "grep -E 'latitude:|longitude:' | awk '{print $2}'"
    )
    result = os.popen(command).read().strip().split("\n")
    if len(result) >= 2:
        lat, lon = result[0], result[1]
        return float(lat), float(lon)
    else:
        raise RuntimeError("Failed to fetch latitude and longitude.")

def main():
    positions = []
    print("Type 'r' to record a red marker, 'g' for a green marker, and 'done' to finish.")

    while True:
        user_input = input("Enter marker type ('r', 'g', or 'done'): ").strip().lower()

        if user_input == "done":
            print("Finished recording positions.")
            break
        elif user_input in ("r", "g"):
            try:
                lat, lon = get_lat_lon()
                print(f"Marker recorded at: {lat}, {lon} with label '{user_input}'")
                positions.append({"label": user_input, "latitude": lat, "longitude": lon})
            except RuntimeError as e:
                print(f"Error: {e}")
        else:
            print("Invalid input. Please enter 'r', 'g', or 'done'.")

    # Generate markers for RViz
    markers = []
    for idx, position in enumerate(positions):
        color = "red" if position["label"] == "r" else "green"
        marker = {
            "id": idx,
            "type": 2,  # Sphere
            "action": 0,  # Add
            "pose": {
                "position": {"x": position["latitude"], "y": position["longitude"], "z": 0},
                "orientation": {"x": 0, "y": 0, "z": 0, "w": 1},
            },
            "scale": {"x": 0.5, "y": 0.5, "z": 0.5},
            "color": {
                "r": 1.0 if color == "red" else 0.0,
                "g": 1.0 if color == "green" else 0.0,
                "b": 0.0,
                "a": 1.0,
            },
        }
        markers.append(marker)

    ros_command = (
        "ros2 topic pub /visualization_marker_array visualization_msgs/MarkerArray '{markers: "
        f"{json.dumps(markers)}'"
    )

    # Write markers to a file
    with open("positions.json", "w") as file:
        json.dump(positions, file, indent=2)

    print("Markers written to positions.json")
    print(f"Run the following command to visualize in RViz:\n{ros_command}")

if __name__ == "__main__":
    main()
