from setuptools import setup

package_name = 'sensor_nodes'

setup(
    name=package_name,
    version='0.0.1',
    packages=[package_name],
    package_dir={'': 'src'},  # <-- this tells setuptools to look inside src/
    data_files=[
        ('share/ament_index/resource_index/packages', ['resource/sensor_nodes']),
        ('share/sensor_nodes', ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='hidri',
    maintainer_email='ritta.hidri@gmail.com',
    description='Sensor monitoring nodes',
    license='MIT',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'battery_monitor = sensor_nodes.battery_monitor:main',  # <-- points to your main()
        ],
    },
)
