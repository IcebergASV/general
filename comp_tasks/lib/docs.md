
---

# Vision and Task Utility Libraries

This document describes the APIs provided by the `bbox_calculations` and `task_lib` C++ libraries. These libraries support vision-based target processing (YOLOv8 detections) and navigation / geometry utilities for ROS 2–based autonomous systems.

---

## Library: `bbox_calculations`

**Purpose**
Utilities for processing YOLOv8 bounding boxes, computing angular offsets from image pixels, filtering detections, and reasoning about gates and target positions.

**Namespace**

```cpp
namespace bbox_calculations
```

---

### Angle and Pixel Utilities

#### `double pixelToAngle(double fov_in_degrees, int res, int pixel)`

Converts a horizontal pixel coordinate into an angle relative to the camera center.

**Parameters**

* `fov_in_degrees` – Camera horizontal field of view (degrees)
* `res` – Horizontal image resolution (pixels)
* `pixel` – Pixel x-coordinate

**Returns**

* Angle in radians

---

### Target Angle Computation

#### `double getAngleBetween2DiffTargets(...)`

Computes a heading angle based on two *different* target classes (e.g., gate buoys).

**Behavior**

* If only one side is detected, offsets from that target
* If both sides are detected, heads toward the midpoint
* Optional angular offset can be applied

**Returns**

* Heading angle (radians, centered to robot frame)

---

#### `double getAngleBetween2SameTargets(...)`

Computes heading angle between multiple detections of the *same* target class.

**Behavior**

* Merges overlapping detections
* Uses average x-center
* Applies optional offset

---

#### `double getAngleToLargestTarget(...)`

Computes angle to the largest detected bounding box of a given class.

---

### Bounding Box Processing

#### `bool isOverlapping(const BoundingBox2D& a, const BoundingBox2D& b)`

Checks if two bounding boxes overlap.

---

#### `BoundingBox2D mergeBoundingBoxes(const BoundingBox2D& a, const BoundingBox2D& b)`

Returns a bounding box that encloses both input boxes.

---

#### `std::vector<Detection> mergeOverlappingDetections(...)`

Merges overlapping YOLO detections into combined bounding boxes.

---

#### `double getAverageXCenter(...)`

Computes the average x-center of multiple bounding boxes.

---

### Detection Filtering and Sorting

#### `std::vector<Detection> extractTargetDetections(...)`

Filters detections by class name(s).

---

#### `std::vector<Detection> sortLeftToRight(...)`

Sorts detections by x-center (left → right).

---

#### `std::vector<Detection> getLargest(...)`

Returns the single detection with the largest area.

---

#### `std::vector<Detection> filterAndSort(...)`

Filters detections by class and applies a selection method:

* `"LARGEST"`
* `"INNERMOST"`

---

### Gate and Detection Queries

#### `bool hasDesiredDetections(...)`

Checks if any detection matches a set of desired class names.

---

#### `bool hasGate(...)`

Determines whether a valid gate (left + right markers) is detected.

---

#### `bool isLeft(...)`

Determines whether the largest target is left of the image center.

---

## Library: `task_lib`

**Purpose**
General navigation, geometry, coordinate transforms, and mission utility functions.

**Namespace**

```cpp
namespace task_lib
```

---

### Formatting Utilities

#### `std::string toStringWithTwoDecimals(double value)`

Formats a floating-point value to a string with two decimal places.

---

### Geometry and Sorting

#### `geometry_msgs::msg::Point computeCentroid(...)`

Computes the centroid of a set of 2D points.

---

#### `double computeRelativeAngle(...)`

Computes the relative angle of a point with respect to a forward direction.

---

#### `void orderPointsRightToLeft(...)`

Sorts points from right to left relative to a reference point.

---

### Vehicle State Checks

#### `bool inGuided(const mavros_msgs::msg::State& state)`

#### `bool inHold(const mavros_msgs::msg::State& state)`

#### `bool inManual(const mavros_msgs::msg::State& state)`

Checks the MAVROS flight mode.

---

### Distance and Navigation

#### `bool isReached(...)`

Checks if the vehicle is within a given distance of a GPS waypoint.

---

#### `double haversine(...)`

Computes distance between two GPS coordinates (kilometers).

---

### Coordinate Transformations

#### `PoseStamped relativePolarToLocalCoords(...)`

Converts relative polar coordinates into local map coordinates.

---

#### `PoseStamped rel_to_local_cord_converter(...)`

Transforms relative pose into global map frame using robot yaw.

---

#### `double quaternionToHeading(...)`

Extracts yaw (heading) from a quaternion.

---

### Waypoint Creation

#### `GeoPoseStamped getGlobalWPMsg(double lat, double lon)`

Creates a global GPS waypoint message.

---

#### `PoseStamped getLocalWPMsg(double x, double y)`

Creates a local map-frame waypoint.

---

### Point Generation and Geometry

#### `Point polarToCartesian(double radius, double angle)`

Converts polar coordinates to Cartesian.

---

#### `double distBetween2Pnts(Point p1, Point p2)`

Computes Euclidean distance between two points.

---

#### `std::vector<Point> generateCirclePoints(...)`

Generates evenly spaced points on a circle.

---

#### `std::vector<Point> createSemicirce(...)`

Generates a semicircle from a set of circle points.

---

#### `std::vector<Point> createQuarterCircle(...)`

Filters a semicircle into a left or right quarter-circle.

---

#### `std::vector<Point> translateSemicircle(...)`

Translates a semicircle to align with a reference point.

---

### Debug / Logging Utilities

#### `void writePointsToCSV(...)`

Writes a set of points to a CSV file for debugging or visualization.

---

## Notes

* All angles are in **radians** unless explicitly stated otherwise.
* Logging assumes a globally available ROS 2 logger.
* Functions are designed for **YOLOv8 + ROS 2 + MAVROS** workflows.

---

If you want, this can be:

* Split into two separate Markdown files
* Converted into Doxygen-style comments
* Embedded into a ROS 2 package README
* Auto-linked with message type references
