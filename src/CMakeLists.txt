#Path to Qt libraries
set(Qt_path "C:/Qtt/5.7/msvc2015")

#Path to Boost libraries
set(Boost_path "C:/boost_1_62_0")

#Minimum required version of CMake
cmake_minimum_required (VERSION 2.8.11)

# Set project name
project (SuperMemo)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# One more poath tosearch
set(CMAKE_PREFIX_PATH ${Qt_path})

# Find the QtWidgets library.
find_package(Qt5Widgets REQUIRED)

# Find the QtSql library.
find_package(Qt5Sql REQUIRED)

# One more path to search
set(BOOST_ROOT ${Boost_path})

# Find the Boost library.
find_package(Boost REQUIRED)

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


################TESTS################################

enable_testing()

find_package(Boost COMPONENTS system filesystem unit_test_framework REQUIRED)

#I like to keep test files in a separate source directory called test
file(GLOB TEST_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src_test/*.cpp)

#Run through each source
foreach(testSrc ${TEST_SRCS})
        #Extract the filename without an extension (NAME_WE)
        get_filename_component(testName ${testSrc} NAME_WE)

        #Add compile target
        add_executable(${testName} ${testSrc})
		
		target_link_libraries(${testName}
                      ${Boost_FILESYSTEM_LIBRARY}
                      ${Boost_SYSTEM_LIBRARY}
                      ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
                      )
		
		# Use the Widgets module from Qt 5.
		target_link_libraries(${testName} Qt5::Widgets)

        #Finally add it to test execution - 
        #Notice the WORKING_DIRECTORY and COMMAND
        add_test(NAME ${testName} 
                 WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/src_test 
                 COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/src_test/${testName} )

endforeach(testSrc)
