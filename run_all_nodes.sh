#!/bin/bash

# Script to run all delivery robot nodes simultaneously
# Each node runs in the background

echo "🚀 Starting all delivery robot nodes..."

# Source the workspace
source install/setup.bash

# Start sensor nodes
echo "📡 Starting sensor nodes..."
ros2 run sensor_nodes battery_monitor &
ros2 run sensor_nodes lidar_simulator &
ros2 run sensor_nodes odometry_simulator &
ros2 run sensor_nodes sensor_processor &

# Start mission planner
echo "🎯 Starting mission planner..."
ros2 run mission_nodes mission_planner &

echo ""
echo "✅ All nodes started!"
echo "Press Ctrl+C to stop all nodes"
echo ""

# Wait for Ctrl+C and then kill all background jobs
trap 'echo ""; echo "🛑 Stopping all nodes..."; killall -9 ros2; exit 0' INT

# Keep script running
wait
