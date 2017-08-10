cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
set(QT_MINIMUM_VERSION 5.5.0)

PROJECT(qtTraits)

OPTION(BUILD_TESTS "Build unit tests" ON)

#-------------------------------------------------------------------------------
#	LIBRARY
#-------------------------------------------------------------------------------

# header-only library target. To use this project as a subdirectory,
# add the following to your code:
#
# add_subdirectory(units) # or whatever you named the directory
# target_link_libraries(${PROJECT_NAME} units)
add_library(${PROJECT_NAME} INTERFACE)
target_sources(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include/qt_traits.h)
target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

#-------------------------------------------------------------------------------
#	COMPILE FLAGS
#-------------------------------------------------------------------------------

SET(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_STANDARD_REQUIRED TRUE)

if(MSVC)
	# enable parallel build
	set( ENV{CL} /MP )
	target_compile_definitions(${PROJECT_NAME} INTERFACE "/permissive-")
elseif(CMAKE_COMPILER_IS_GNUCXX)
	# Increase warning levels
	add_compile_options(-Wall -Wextra -pedantic)
endif()


#-------------------------------------------------------------------------------
#	UNIT TESTS
#-------------------------------------------------------------------------------

if(BUILD_TESTS)
	set(VERSION_GTEST "1.8.0" CACHE STRING "Google Test framework version")
	enable_testing ()
	add_subdirectory(3rdParty/gtest)
	add_subdirectory(unitTests)
endif(BUILD_TESTS)