add_library(gcd SHARED gcd_impl.cpp)

add_executable(gcd_test gcd_test.cpp)

target_link_libraries(gcd_test PUBLIC gcd)