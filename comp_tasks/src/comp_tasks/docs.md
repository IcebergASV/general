
---

## File: `home_component.cpp`

### Purpose

Implements the **Home task state machine**, responsible for guiding the vehicle back toward a target (black buoy gate) with configurable **recovery behaviors** when detections are lost.
This task extends the generic `Task` base class and runs as a **ROS 2 lifecycle component**.

---

## Namespace

```cpp
namespace comp_tasks
```

---

## Class: `Home`

Inherits from:

```cpp
Task
```

### Constructor

```cpp
Home(const rclcpp::NodeOptions & options);
```

#### Arguments

* `options`: ROS 2 node options used for component composition.

#### Behavior

* Constructs the Home task.
* Passes `"home"` as the task name to the `Task` base class.

---

## Lifecycle Callbacks

### Method: `on_configure`

```cpp
rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn
on_configure(const rclcpp_lifecycle::State &);
```

#### Arguments

* Lifecycle state (unused).

#### Behavior

* Calls base `Task::on_configure`.
* Declares and loads parameters:

  * `max_consec_recoveries`
  * `time_between_recovery_actions`
  * `time_to_stop_before_recovery`
  * `state`
* Registers a dynamic parameter callback.
* Initializes state machine variables.
* Sets initial state from parameters.

#### Returns

* `CallbackReturn::SUCCESS` on successful configuration.

---

## Parameter Handling

### Method: `param_callback`

```cpp
rcl_interfaces::msg::SetParametersResult
param_callback(const std::vector<rclcpp::Parameter> & params);
```

#### Arguments

* `params`: Vector of updated ROS parameters.

#### Behavior

* Delegates to `Task::param_callback` first.
* Updates internal parameters and YAML config for:

  * `max_consec_recoveries`
  * `time_between_recovery_actions`
  * `time_to_stop_before_recovery`
  * `state`
* Rejects unknown parameters.

#### Returns

* `successful = true` if parameter is valid.
* `successful = false` otherwise.

---

## State Management

### Method: `setState`

```cpp
void setState(std::string str_state);
```

#### Arguments

* `str_state`: Target state name as a string.

#### Supported States

* `"RECOVERING"`
* `"HEADING_TO_TARGET"`

#### Behavior

* Resets detection and waypoint counters.
* Configures timers and internal enums.
* Logs error on invalid state string.

---

## Recovery Logic

### Method: `executeRecoveryBehaviour`

```cpp
void executeRecoveryBehaviour();
```

#### Behavior

Executes recovery behavior based on parameter `p_recovery_behaviour_`:

| Behavior          | Action                                |
| ----------------- | ------------------------------------- |
| `"STOP"`          | No action                             |
| `"RECOVERY_PNT"`  | Publishes global recovery waypoint    |
| `"RECOVERY_GATE"` | Publishes local waypoint to last gate |
| Invalid           | Logs warning                          |

---

## Detection Handling

### Method: `handleDetections`

```cpp
void handleDetections(
  const yolov8_msgs::msg::DetectionArray & detections
);
```

#### Arguments

* `detections`: YOLOv8 detection array.

#### Behavior

* Publishes waypoint toward detected black buoy gate.
* Sets or expires pause timer.
* Publishes `"Found"` search status.

---

## Task Execution Logic

### Method: `taskLogic`

```cpp
void taskLogic(
  const yolov8_msgs::msg::DetectionArray & detections
);
```

#### Arguments

* `detections`: YOLOv8 detection array.

#### Behavior

Executes state machine logic **only when in guided mode**.

---

### State: `RECOVERING`

* Publishes recovering status.
* Transitions to `HEADING_TO_TARGET` if black buoy detected.
* Executes recovery behavior when timer expires.

---

### State: `HEADING_TO_TARGET`

* Publishes heading and search state.
* If detection found → handles detections.
* If waypoint reached or timer expires → switches back to `RECOVERING`.

---

## Component Registration

```cpp
RCLCPP_COMPONENTS_REGISTER_NODE(comp_tasks::Home);
```

Registers `Home` as a composable ROS 2 component.

---

## File: `home_main.cpp`

### Purpose

Standalone executable wrapper for running the `Home` task **without composition**.

---

### Function: `main`

```cpp
int main(int argc, char * argv[]);
```

#### Arguments

* `argc`: Argument count.
* `argv`: Argument vector.

#### Behavior

* Disables stdout buffering for immediate logs.
* Initializes ROS 2.
* Creates a single-threaded executor.
* Instantiates and spins `comp_tasks::Home`.
* Shuts down ROS cleanly.

---


---

## File: `maneuvering_component.cpp`

### Purpose

Implements the **Maneuvering task state machine**, responsible for navigating through buoy gates using vision detections, handling loss-of-detection recovery, and determining task completion after repeated failures.

This task extends the shared `Task` base class and is implemented as a **ROS 2 lifecycle component**.

---

## Namespace

```cpp
namespace comp_tasks
```

---

## Class: `Maneuvering`

Inherits from:

```cpp
Task
```

---

## Constructor

### `Maneuvering`

```cpp
Maneuvering(const rclcpp::NodeOptions & options);
```

#### Arguments

* `options`: ROS 2 node options used when loading the component.

#### Behavior

* Constructs the maneuvering task.
* Passes `"maneuvering"` as the task name to the `Task` base class.

---

## Lifecycle Callbacks

### Method: `on_configure`

```cpp
rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn
on_configure(const rclcpp_lifecycle::State &);
```

#### Arguments

* Lifecycle state (unused).

#### Behavior

* Calls `Task::on_configure`.
* Declares and loads parameters:

  * `max_consec_recoveries`
  * `time_between_recovery_actions`
  * `time_to_stop_before_recovery`
  * `state`
* Registers a dynamic parameter callback.
* Initializes timers based on configuration.
* Sets initial task state.

#### Returns

* `CallbackReturn::SUCCESS` on successful configuration.

---

## Parameter Handling

### Method: `param_callback`

```cpp
rcl_interfaces::msg::SetParametersResult
param_callback(const std::vector<rclcpp::Parameter> & params);
```

#### Arguments

* `params`: Vector of updated ROS parameters.

#### Behavior

* Delegates first to `Task::param_callback`.
* Handles maneuvering-specific parameters:

  * `max_consec_recoveries`
  * `time_between_recovery_actions`
  * `time_to_stop_before_recovery`
  * `state`
* Updates YAML configuration.
* Rejects invalid parameters.

#### Returns

* `successful = true` if accepted.
* `successful = false` if rejected.

---

## State Management

### Method: `setState`

```cpp
void setState(std::string str_state);
```

#### Arguments

* `str_state`: Target state name as a string.

#### Supported States

* `"STOPPED"`
* `"RECOVERING"`
* `"HEADING_TO_TARGET"`

#### Behavior

* Resets detection counters and waypoint flags.
* Configures timers and internal enum state.
* Logs error on invalid state string.

---

## Task Completion Logic

### Method: `checkIfFinished`

```cpp
void checkIfFinished();
```

#### Behavior

* Decrements `p_max_consec_recoveries_`.
* Calls `signalTaskFinish()` when recovery attempts are exhausted.

---

## Recovery Logic

### Method: `executeRecoveryBehaviour`

```cpp
void executeRecoveryBehaviour();
```

#### Behavior

Executes recovery action based on `p_recovery_behaviour_`:

| Behavior          | Action                                      |
| ----------------- | ------------------------------------------- |
| `"STOP"`          | No action                                   |
| `"RECOVERY_PNT"`  | Publishes global recovery waypoint          |
| `"RECOVERY_GATE"` | Publishes local waypoint to last known gate |
| Invalid           | Logs warning                                |

---

## Detection Handling

### Method: `handleDetections`

```cpp
void handleDetections(
  const yolov8_msgs::msg::DetectionArray & detections
);
```

#### Arguments

* `detections`: YOLOv8 detection array.

#### Behavior

* Publishes waypoint toward detected gate.
* Optionally pauses search via timer.
* Updates last-known gate position if a valid gate is detected.
* Publishes `"Found"` search status.

---

## Core Task Logic

### Method: `taskLogic`

```cpp
void taskLogic(
  const yolov8_msgs::msg::DetectionArray & detections
);
```

#### Arguments

* `detections`: YOLOv8 detection array.

#### Behavior

Executes the maneuvering state machine **only while in guided mode**.

---

### State: `STOPPED`

* Publishes stopped status.
* Transitions to `HEADING_TO_TARGET` on detection.
* Transitions to `RECOVERING` when stop timer expires.

---

### State: `RECOVERING`

* Publishes recovering status.
* Transitions to `HEADING_TO_TARGET` on detection.
* Executes recovery behavior when timer expires.
* Tracks recovery attempts and may signal task completion.

---

### State: `HEADING_TO_TARGET`

* Publishes heading-to-waypoint status.
* If detections found → handles detections.
* If no detections:

  * Transitions to `STOPPED` (if stop delay enabled).
  * Otherwise transitions directly to `RECOVERING`.
* Handles waypoint-reached events similarly.

---

## Component Registration

```cpp
RCLCPP_COMPONENTS_REGISTER_NODE(comp_tasks::Maneuvering);
```

Registers the maneuvering task as a composable ROS 2 component.

---

## File: `maneuvering_main.cpp`

### Purpose

Provides a **standalone executable** for running the `Maneuvering` task outside of a composed container.

---

### Function: `main`

```cpp
int main(int argc, char * argv[]);
```

#### Arguments

* `argc`: Argument count.
* `argv`: Argument vector.

#### Behavior

* Disables stdout buffering for immediate logging.
* Initializes ROS 2.
* Creates a single-threaded executor.
* Instantiates and spins `comp_tasks::Maneuvering`.
* Shuts down ROS cleanly.

---


---

## File: `speed_component.cpp`

### Purpose

Implements the **Speed task state machine**, responsible for navigating through a bay, detecting and passing a blue buoy, and returning along a computed path.
This task performs **route generation, waypoint sequencing, and conditional task completion** based on visual detections and traveled distance.

The task extends the shared `Task` base class and runs as a **ROS 2 lifecycle component**.

---

## Free Functions (File Scope Utilities)

### `isWithinDistance`

```cpp
bool isWithinDistance(
  const geometry_msgs::msg::Point & p1,
  const geometry_msgs::msg::Point & p2,
  double dist
);
```

#### Arguments

* `p1`: First point.
* `p2`: Second point.
* `dist`: Distance threshold.

#### Returns

* `true` if Euclidean distance between `p1` and `p2` is less than or equal to `dist`.

---

### `removeClosePoints`

```cpp
void removeClosePoints(
  std::vector<geometry_msgs::msg::Point> & points,
  const geometry_msgs::msg::Point & reference_point,
  double dist
);
```

#### Arguments

* `points`: Vector of points to filter (modified in place).
* `reference_point`: Reference position.
* `dist`: Distance threshold.

#### Behavior

* Removes all points in `points` within `dist` of `reference_point`.

---

## Namespace

```cpp
namespace comp_tasks
```

---

## Class: `Speed`

Inherits from:

```cpp
Task
```

---

## Constructor

### `Speed`

```cpp
Speed(const rclcpp::NodeOptions & options);
```

#### Arguments

* `options`: ROS 2 node options for component instantiation.

#### Behavior

* Constructs the Speed task.
* Passes `"speed"` as the task name to the `Task` base class.

---

## Lifecycle Callbacks

### Method: `on_configure`

```cpp
rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn
on_configure(const rclcpp_lifecycle::State &);
```

#### Arguments

* Lifecycle state (unused).

#### Behavior

* Calls `Task::on_configure`.
* Declares and loads all Speed-specific parameters:

  * Timing limits for bay and buoy detection
  * Route geometry and circling configuration
  * Start/finish point usage flags
  * Waypoint filtering distances
  * Initial state
* Registers dynamic parameter callback.
* Initializes internal state variables and cached poses.

#### Returns

* `CallbackReturn::SUCCESS` on successful configuration.

---

## Parameter Handling

### Method: `param_callback`

```cpp
rcl_interfaces::msg::SetParametersResult
param_callback(const std::vector<rclcpp::Parameter> & params);
```

#### Arguments

* `params`: Vector of updated ROS parameters.

#### Behavior

* Delegates to `Task::param_callback` first.
* Updates Speed-specific parameters and YAML config.
* Rejects invalid parameters.

#### Returns

* `successful = true` if accepted.
* `successful = false` if rejected.

---

## State Management

### Method: `setState`

```cpp
void setState(std::string str_state);
```

#### Arguments

* `str_state`: Target state name.

#### Supported States

* `"SENDING_START_PNT"`
* `"MANEUVER_THRU_BAY"`
* `"GOING_STRAIGHT"`
* `"PASSING_BUOY"`
* `"CONTINUE_PASSING_BUOY"`
* `"RETURNING"`

#### Behavior

* Resets counters, flags, and detection state.
* Initializes timers for each state.
* Logs error on invalid state string.

---

## Route Generation and Manipulation

### `calculateRouteFromGates`

```cpp
std::vector<geometry_msgs::msg::Point>
calculateRouteFromGates(const yolov8_msgs::msg::DetectionArray & detections);
```

#### Arguments

* `detections`: YOLOv8 detection array containing gate detections.

#### Behavior

* Computes a waypoint near the buoy using relative polar coordinates.
* Builds a forward route using:

  * Estimated buoy waypoint
  * Last-seen bay pose
  * First-seen bay pose
* Caches detections used to compute the route.

---

### `calculateReturnRoute`

```cpp
std::vector<geometry_msgs::msg::Point>
calculateReturnRoute(const yolov8_msgs::msg::DetectionArray & detections);
```

#### Arguments

* `detections`: YOLOv8 detection array containing blue buoy detections.

#### Behavior

* Generates a circular route around the buoy.
* Reduces the route to a semicircle based on bay position.
* Determines whether the buoy is passed on the left or right.
* Caches detections.

---

### `updateReturnRoute`

```cpp
void updateReturnRoute(std::vector<geometry_msgs::msg::Point> & route);
```

#### Arguments

* `route`: Return route to update (modified in place).

#### Behavior

* Translates route based on current position.
* Reverses route if buoy was passed on the left.
* Removes waypoints too close to the current pose.
* Appends bay poses to close the loop.

---

## Navigation Helpers

### `continuePastBuoy`

```cpp
void continuePastBuoy();
```

Publishes a waypoint that continues straight past the buoy before returning.

---

### `isFarEnoughFromBay`

```cpp
bool isFarEnoughFromBay();
```

#### Returns

* `true` if distance traveled from last seen bay exceeds `p_min_dist_from_bay_b4_return_`.

---

### `getDistFromBay`

```cpp
double getDistFromBay();
```

#### Returns

* Distance between last seen bay and last seen blue buoy.

---

### `sendNextWP`

```cpp
void sendNextWP(
  std::vector<geometry_msgs::msg::Point> route,
  std::string route_name
);
```

#### Arguments

* `route`: Waypoint route.
* `route_name`: Human-readable route identifier.

#### Behavior

* Publishes the next waypoint in the route.
* Updates behavior status and resets waypoint-reached flag.

---

## Detection Handlers

### `handleGateDetections`

```cpp
void handleGateDetections(
  const yolov8_msgs::msg::DetectionArray & detections
);
```

#### Behavior

* Updates bay pose history.
* Computes forward route when a full gate is detected.
* Publishes waypoint toward the gate.
* Resets bay-detection timeout timer.

---

### `handleBlueBuoyDetections`

```cpp
void handleBlueBuoyDetections(
  const yolov8_msgs::msg::DetectionArray & detections
);
```

#### Behavior

* Computes return route around buoy.
* Applies offset angle based on buoy side.
* Publishes waypoint toward buoy.
* Computes a continuation waypoint past the buoy.
* Resets buoy-detection timeout timer.

---

## Core Task Logic

### Method: `taskLogic`

```cpp
void taskLogic(
  const yolov8_msgs::msg::DetectionArray & detections
);
```

#### Arguments

* `detections`: YOLOv8 detection array.

#### Behavior

* When **not in guided mode**:

  * Passively caches bay and buoy detections.
* When **in guided mode**:

  * Executes a multi-stage state machine controlling:

    * Start-point navigation
    * Bay traversal
    * Buoy passing
    * Return routing
    * Task completion

Each state publishes consistent **search**, **behavior**, and **state** status messages.

---

## Component Registration

```cpp
RCLCPP_COMPONENTS_REGISTER_NODE(comp_tasks::Speed);
```

Registers the Speed task as a composable ROS 2 component.

---

## File: `speed_main.cpp`

### Purpose

Provides a **standalone executable** for running the Speed task without component composition.

---

### Function: `main`

```cpp
int main(int argc, char * argv[]);
```

#### Arguments

* `argc`: Argument count.
* `argv`: Argument vector.

#### Behavior

* Disables stdout buffering.
* Initializes ROS 2.
* Creates a single-threaded executor.
* Instantiates and spins `comp_tasks::Speed`.
* Shuts down ROS cleanly.

---

