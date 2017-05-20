# Install script for directory: /home/finn/code/my_projects/blind/opencv/modules

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "RELEASE")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/finn/code/my_projects/blind/opencv/release/modules/calib3d/.calib3d/cmake_install.cmake")
  include("/home/finn/code/my_projects/blind/opencv/release/modules/core/.core/cmake_install.cmake")
  include("/home/finn/code/my_projects/blind/opencv/release/modules/cudaarithm/.cudaarithm/cmake_install.cmake")
  include("/home/finn/code/my_projects/blind/opencv/release/modules/cudabgsegm/.cudabgsegm/cmake_install.cmake")
  include("/home/finn/code/my_projects/blind/opencv/release/modules/cudacodec/.cudacodec/cmake_install.cmake")
  include("/home/finn/code/my_projects/blind/opencv/release/modules/cudafeatures2d/.cudafeatures2d/cmake_install.cmake")
  include("/home/finn/code/my_projects/blind/opencv/release/modules/cudafilters/.cudafilters/cmake_install.cmake")
  include("/home/finn/code/my_projects/blind/opencv/release/modules/cudaimgproc/.cudaimgproc/cmake_install.cmake")
  include("/home/finn/code/my_projects/blind/opencv/release/modules/cudalegacy/.cudalegacy/cmake_install.cmake")
  include("/home/finn/code/my_projects/blind/opencv/release/modules/cudaobjdetect/.cudaobjdetect/cmake_install.cmake")
  include("/home/finn/code/my_projects/blind/opencv/release/modules/cudaoptflow/.cudaoptflow/cmake_install.cmake")
  include("/home/finn/code/my_projects/blind/opencv/release/modules/cudastereo/.cudastereo/cmake_install.cmake")
  include("/home/finn/code/my_projects/blind/opencv/release/modules/cudawarping/.cudawarping/cmake_install.cmake")
  include("/home/finn/code/my_projects/blind/opencv/release/modules/cudev/.cudev/cmake_install.cmake")
  include("/home/finn/code/my_projects/blind/opencv/release/modules/features2d/.features2d/cmake_install.cmake")
  include("/home/finn/code/my_projects/blind/opencv/release/modules/flann/.flann/cmake_install.cmake")
  include("/home/finn/code/my_projects/blind/opencv/release/modules/highgui/.highgui/cmake_install.cmake")
  include("/home/finn/code/my_projects/blind/opencv/release/modules/imgcodecs/.imgcodecs/cmake_install.cmake")
  include("/home/finn/code/my_projects/blind/opencv/release/modules/imgproc/.imgproc/cmake_install.cmake")
  include("/home/finn/code/my_projects/blind/opencv/release/modules/java/.java/cmake_install.cmake")
  include("/home/finn/code/my_projects/blind/opencv/release/modules/ml/.ml/cmake_install.cmake")
  include("/home/finn/code/my_projects/blind/opencv/release/modules/objdetect/.objdetect/cmake_install.cmake")
  include("/home/finn/code/my_projects/blind/opencv/release/modules/photo/.photo/cmake_install.cmake")
  include("/home/finn/code/my_projects/blind/opencv/release/modules/python/.python/cmake_install.cmake")
  include("/home/finn/code/my_projects/blind/opencv/release/modules/shape/.shape/cmake_install.cmake")
  include("/home/finn/code/my_projects/blind/opencv/release/modules/stitching/.stitching/cmake_install.cmake")
  include("/home/finn/code/my_projects/blind/opencv/release/modules/superres/.superres/cmake_install.cmake")
  include("/home/finn/code/my_projects/blind/opencv/release/modules/ts/.ts/cmake_install.cmake")
  include("/home/finn/code/my_projects/blind/opencv/release/modules/video/.video/cmake_install.cmake")
  include("/home/finn/code/my_projects/blind/opencv/release/modules/videoio/.videoio/cmake_install.cmake")
  include("/home/finn/code/my_projects/blind/opencv/release/modules/videostab/.videostab/cmake_install.cmake")
  include("/home/finn/code/my_projects/blind/opencv/release/modules/viz/.viz/cmake_install.cmake")
  include("/home/finn/code/my_projects/blind/opencv/release/modules/world/.world/cmake_install.cmake")
  include("/home/finn/code/my_projects/blind/opencv/release/modules/core/cmake_install.cmake")
  include("/home/finn/code/my_projects/blind/opencv/release/modules/flann/cmake_install.cmake")
  include("/home/finn/code/my_projects/blind/opencv/release/modules/imgproc/cmake_install.cmake")
  include("/home/finn/code/my_projects/blind/opencv/release/modules/ml/cmake_install.cmake")
  include("/home/finn/code/my_projects/blind/opencv/release/modules/photo/cmake_install.cmake")
  include("/home/finn/code/my_projects/blind/opencv/release/modules/video/cmake_install.cmake")
  include("/home/finn/code/my_projects/blind/opencv/release/modules/imgcodecs/cmake_install.cmake")
  include("/home/finn/code/my_projects/blind/opencv/release/modules/shape/cmake_install.cmake")
  include("/home/finn/code/my_projects/blind/opencv/release/modules/videoio/cmake_install.cmake")
  include("/home/finn/code/my_projects/blind/opencv/release/modules/highgui/cmake_install.cmake")
  include("/home/finn/code/my_projects/blind/opencv/release/modules/objdetect/cmake_install.cmake")
  include("/home/finn/code/my_projects/blind/opencv/release/modules/superres/cmake_install.cmake")
  include("/home/finn/code/my_projects/blind/opencv/release/modules/ts/cmake_install.cmake")
  include("/home/finn/code/my_projects/blind/opencv/release/modules/features2d/cmake_install.cmake")
  include("/home/finn/code/my_projects/blind/opencv/release/modules/calib3d/cmake_install.cmake")
  include("/home/finn/code/my_projects/blind/opencv/release/modules/stitching/cmake_install.cmake")
  include("/home/finn/code/my_projects/blind/opencv/release/modules/videostab/cmake_install.cmake")
  include("/home/finn/code/my_projects/blind/opencv/release/modules/python2/cmake_install.cmake")

endif()

