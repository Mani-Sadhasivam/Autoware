cmake_minimum_required(VERSION 2.8.11)
project(vehicle_abstraction) # autoware math utility
find_package(catkin REQUIRED COMPONENTS
        roscpp
        autoware_msgs
        )

set(CMAKE_CXX_FLAGS "-std=c++11 -O2 -Wall ${CMAKE_CXX_FLAGS}")

catkin_package(
        INCLUDE_DIRS include
        LIBRARIES vehicle_abstraction
        CATKIN_DEPENDS roscpp autoware_msgs
)

include_directories(vehicle_abstraction
        include
        ${catkin_INCLUDE_DIRS}
        )

add_library(vehicle_abstraction
	src/VehicleAbstraction.cpp
        )
target_link_libraries(vehicle_abstraction
        ${catkin_LIBRARIES}
        )

add_dependencies(vehicle_abstraction
        ${catkin_EXPORTED_TARGETS}
        )

install(DIRECTORY include/${PROJECT_NAME}/
        DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
        FILES_MATCHING PATTERN "*.hpp"
        )

install(TARGETS vehicle_abstraction
        ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
        LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
        RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
        )
