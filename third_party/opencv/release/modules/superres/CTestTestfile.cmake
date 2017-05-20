# CMake generated Testfile for 
# Source directory: /home/finn/code/my_projects/blind/opencv/modules/superres
# Build directory: /home/finn/code/my_projects/blind/opencv/release/modules/superres
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(opencv_test_superres "/home/finn/code/my_projects/blind/opencv/release/bin/opencv_test_superres" "--gtest_output=xml:opencv_test_superres.xml")
set_tests_properties(opencv_test_superres PROPERTIES  LABELS "Main;opencv_superres;Accuracy" WORKING_DIRECTORY "/home/finn/code/my_projects/blind/opencv/release/test-reports/accuracy")
add_test(opencv_perf_superres "/home/finn/code/my_projects/blind/opencv/release/bin/opencv_perf_superres" "--gtest_output=xml:opencv_perf_superres.xml")
set_tests_properties(opencv_perf_superres PROPERTIES  LABELS "Main;opencv_superres;Performance" WORKING_DIRECTORY "/home/finn/code/my_projects/blind/opencv/release/test-reports/performance")
add_test(opencv_sanity_superres "/home/finn/code/my_projects/blind/opencv/release/bin/opencv_perf_superres" "--gtest_output=xml:opencv_perf_superres.xml" "--perf_min_samples=1" "--perf_force_samples=1" "--perf_verify_sanity")
set_tests_properties(opencv_sanity_superres PROPERTIES  LABELS "Main;opencv_superres;Sanity" WORKING_DIRECTORY "/home/finn/code/my_projects/blind/opencv/release/test-reports/sanity")