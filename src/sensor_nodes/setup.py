from setuptools import find_packages, setup

package_name = 'sensor_nodes'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='ahmed',
    maintainer_email='ahmed22khelifi@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    extras_require={
        'test': [
            'pytest',
        ],
    },
    entry_points={
        'console_scripts': [
            'sensor_processor = sensor_nodes.sensor_processor:main',
            'lidar_simulator = sensor_nodes.lidar_simulator:main',
            'odometry_simulator = sensor_nodes.odometry_simulator:main',
        ],
    },
)
