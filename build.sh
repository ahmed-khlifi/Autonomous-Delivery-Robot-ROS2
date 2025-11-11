echo "====Building the project..."
colcon build 
echo "====Build completed."
echo "====Sourcing the setup file..."
source install/setup.bash
echo "====Setup file sourced."