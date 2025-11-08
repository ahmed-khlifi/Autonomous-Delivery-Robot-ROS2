import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/root/Autonomous-Delivery-Robot-ROS2/install/command_nodes'
