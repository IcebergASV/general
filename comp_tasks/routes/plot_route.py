# import pandas as pd
# import matplotlib.pyplot as plt
# import numpy as np
# import argparse

# # Set up argument parser
# parser = argparse.ArgumentParser(description="Plot waypoints from a CSV file with arrows.")
# parser.add_argument("file_path", type=str, help="Path to the CSV file containing waypoints.")
# args = parser.parse_args()

# # Load CSV file
# df = pd.read_csv(args.file_path)
# # # Load CSV file
# # csv_file = "bb.csv"  # Change this to your actual file path
# # df = pd.read_csv(csv_file)

# # Extract X and Y columns
# x = df["X"].values
# y = df["Y"].values

# # Create figure
# plt.figure(figsize=(8, 6))

# # Plot points
# plt.scatter(x, y, color="red", label="Waypoints")

# # Draw arrows between consecutive points
# for i in range(len(x) - 1):
#     plt.annotate(
#         "",  # No text, just an arrow
#         xy=(x[i+1], y[i+1]),  # Arrow tip
#         xytext=(x[i], y[i]),  # Arrow start
#         arrowprops=dict(arrowstyle="->", lw=2, color="blue")  # Arrow style
#     )

# # Add labels for better visualization
# for i, (xi, yi) in enumerate(zip(x, y)):
#     plt.text(xi, yi, f"{i}", fontsize=12, verticalalignment="bottom", horizontalalignment="right")

# # Labels and grid
# plt.xlabel("X Coordinate")
# plt.ylabel("Y Coordinate")
# plt.title("Path Visualization with Arrows")
# plt.grid(True)
# plt.legend()
# plt.axis('equal')
# plt.show()
import pandas as pd
import matplotlib.pyplot as plt
import argparse

# Set up argument parser
parser = argparse.ArgumentParser(description="Plot multiple waypoints from CSV files with arrows.")
parser.add_argument("file_paths", type=str, nargs="+", help="Paths to the CSV files containing waypoints.")
args = parser.parse_args()

# Iterate over each provided CSV file path
for file_path in args.file_paths:
    # Load CSV file
    df = pd.read_csv(file_path)

    # Extract X and Y columns
    x = df["X"].values
    y = df["Y"].values

    # Create figure
    plt.figure(figsize=(8, 6))

    # Plot points
    plt.scatter(x, y, color="red", label="Waypoints")

    # Draw arrows between consecutive points
    for i in range(len(x) - 1):
        plt.annotate(
            "",  # No text, just an arrow
            xy=(x[i+1], y[i+1]),  # Arrow tip
            xytext=(x[i], y[i]),  # Arrow start
            arrowprops=dict(arrowstyle="->", lw=2, color="blue")  # Arrow style
        )

    # Add labels for better visualization
    for i, (xi, yi) in enumerate(zip(x, y)):
        plt.text(xi, yi, f"{i}", fontsize=12, verticalalignment="bottom", horizontalalignment="right")

    # Labels and grid
    plt.xlabel("X Coordinate")
    plt.ylabel("Y Coordinate")
    plt.title(f"Path Visualization for {file_path}")
    plt.grid(True)
    plt.legend()
    plt.axis('equal')
    plt.show()
