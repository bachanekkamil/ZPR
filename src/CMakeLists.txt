#Path to Qt libraries
set(Qt_path "C:/Qt/5.7/msvc2015_64")

#Path to Boost libraries
set(Boost_path "C:/boost_1_62_0")

#Minimum required version of CMake
cmake_minimum_required (VERSION 2.8.11)

# Set project name
project (SuperMemo)

# Flag for gcc compiler
SET ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11" )

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
add_definitions(-std=c++0x)

#add_definitions (-DBOOST_TEST_DYN_LINK)

# Coverage test
SET(CMAKE_CXX_FLAGS "-g -O0 --coverage")
SET(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE_1)
 

# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# One more poath tosearch
set(CMAKE_PREFIX_PATH ${Qt_path})

# Find the QtWidgets library.
find_package(Qt5Widgets REQUIRED)

# Find the QtSql library.
find_package(Qt5Sql REQUIRED)

#set(QT5_LIBRARIES Qt5::Widgets Qt5::PrintSupport Qt5::Sql)

# One more path to search
set(BOOST_ROOT ${Boost_path})

#set(QT_USE_QTSQL 1)

# Find the Boost library.
find_package(Boost REQUIRED)

# Include Boost .h headers
include_directories(${Boost_INCLUDE_DIRS})

# Include .h headers
include_directories("include")

# Include .h headers
include_directories("include/GUI")

# Include .h headers
include_directories("include/logic")

# Find all .ui files
file(GLOB UIS_HEADERS "ui_include/*.ui")

# Wrap .ui files
QT5_WRAP_UI(UIS ${UIS_HEADERS})

# Find all .h files
file(GLOB H_HEADERS "include/GUI/*.h" "include/logic/*.h")

# Wrap .h files
qt5_wrap_cpp(MOC_HEADERS ${H_HEADERS})

# Find all .cpp files
file(GLOB CPP_FILES "src/logic/*.cpp" "src/GUI/*.cpp")

add_definitions( -DBOOST_ALL_NO_LIB )

# Add executable
add_executable(${PROJECT_NAME} ${CPP_FILES} ${UIS} ${MOC_HEADERS})


# Use the Widgets module from Qt 5.
target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::Sql)

target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})

################TESTS################################
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
		target_link_libraries(${testName} Qt5::Widgets Qt5::Sql)

        #Finally add it to test execution - 
        #Notice the WORKING_DIRECTORY and COMMAND
        add_test(NAME ${testName} 
                 WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/src_test 
                 COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/src_test/${testName} )

endforeach(testSrc)

configure_file("db/db_test.db" "db_test.db" COPYONLY)




