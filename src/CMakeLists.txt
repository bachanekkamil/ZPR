#Minimum required version of CMake
cmake_minimum_required (VERSION 2.8.11)

# Set project name
project (MEUM)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

set(CMAKE_PREFIX_PATH "C:/Qtt/5.7/msvc2015")
# Find the QtWidgets library
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Sql REQUIRED)

# Set boost root directory
set(BOOST_ROOT "C:/boost_1_62_0")

# Find the Boost library
find_package(Boost REQUIRED) 

message(${Boost_INCLUDE_DIRS})

# Include Boost .h headers
include_directories(${Boost_INCLUDE_DIRS})

# Include .h headers
include_directories(include)

# Find all .ui files
file(GLOB UIS_HEADERS "ui_include/*.ui")

# Wrap .ui files
QT5_WRAP_UI(UIS ${UIS_HEADERS})

# Find all .h files
file(GLOB H_HEADERS "include/*.h")

# Wrap .h files
qt5_wrap_cpp(MOC_HEADERS ${H_HEADERS})

# Find all .cpp files
file(GLOB CPP_FILES "src/*.cpp")

add_definitions( -DBOOST_ALL_NO_LIB )

# Add executable
add_executable(${PROJECT_NAME} ${CPP_FILES} ${UIS} ${MOC_HEADERS})

# Use the Widgets module from Qt 5.
target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::Sql)

target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})