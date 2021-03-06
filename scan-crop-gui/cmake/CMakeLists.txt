cmake_minimum_required(VERSION 2.7)
PROJECT(scan-crop-gui)

SET(CMAKE_BUILD_TYPE release)
SET(CMAKE_CXX_FLAGS_RELEASE "-O2 -std=c++14 -march=native -Wall -Wextra -pedantic")
SET(CMAKE_C_FLAGS_RELEASE "-O2 -std=c++14 -march=native -Wall -Wextra -pedantic")

IF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
  SET(CMAKE_EXE_LINKER_FLAGS "-L/usr/local/opt/gettext/lib")
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")


INCLUDE(../../cmake/ConfigureARMADILLO.cmake)
INCLUDE(../../cmake/ConfigureJSONCPP.cmake)

find_package(PkgConfig)
pkg_check_modules(CAIROMM REQUIRED cairomm-1.0)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)
pkg_check_modules(GLIB REQUIRED glib-2.0)

IF(ARMADILLO_FOUND AND JSONCPP_FOUND)
  SET(SRC_FILE "../src/bin/main.cpp")

  add_definitions("-DUIDIR=\"${CMAKE_INSTALL_PREFIX}/share\"")

  INCLUDE_DIRECTORIES("../src/include")
  INCLUDE_DIRECTORIES("../../shared_include")
  INCLUDE_DIRECTORIES(${ARMADILLO_INCLUDE_DIR})
  INCLUDE_DIRECTORIES(${JSONCPP_INCLUDE_DIR})
  INCLUDE_DIRECTORIES(${CAIROMM_INCLUDE_DIRS})
  INCLUDE_DIRECTORIES(${GTKMM_INCLUDE_DIRS})
  INCLUDE_DIRECTORIES(${GLIB_INCLUDE_DIRS})

  ADD_EXECUTABLE(${PROJECT_NAME} ${SRC_FILE})
  TARGET_LINK_LIBRARIES(${PROJECT_NAME}
    ${ARMADILLO_LIBRARIES}
    ${JSONCPP_LIBRARIES}
    ${CAIROMM_LIBRARIES}
    ${GTKMM_LIBRARIES}
    ${GLIB_LIBRARIES}
    )

  INSTALL (TARGETS ${PROJECT_NAME} DESTINATION bin)
  INSTALL (FILES ../ui/ui_description_scan_crop.glade DESTINATION share)

ELSE(ARMADILLO_FOUND AND JSONCPP_FOUND)
  Message("PROBLEM: One of the required libraries not found. ${PROJECT_NAME} will not be compiled.")
ENDIF(ARMADILLO_FOUND AND JSONCPP_FOUND)
