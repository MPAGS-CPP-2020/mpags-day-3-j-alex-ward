add_executable(testHello testHello.cpp)
add_test(NAME test-hello COMMAND testHello)

add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CMAKE_CURRENT_LIST_DIR})
target_compile_features(Catch INTERFACE cxx_noexcept)

add_executable(testCatch testCatch.cpp)
#target_include_directories(testCatch PRIVATE ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(testCatch Catch)
add_test(NAME test-catch COMMAND testCatch -s)

add_executable(testTransformChar testTransformChar.cpp)
#target_include_directories(testCatch PRIVATE ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(testTransformChar MPAGSCipher Catch)
add_test(NAME test-transformchar COMMAND testTransformChar -s)

add_executable(testCaesarCipher testCaesarCipher.cpp)
target_link_libraries(testCaesarCipher MPAGSCipher Catch)
add_test(NAME test-caesarcipher COMMAND testCaesarCipher -s)