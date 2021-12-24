cmake_minimum_required(VERSION 3.6)
project(npi-client)

find_package(SFML 2.5.1 COMPONENTS system window graphics REQUIRED)

add_executable(npi-client src/main.cpp)

target_compile_features(npi-client
                        PRIVATE
                        cxx_std_17)

target_compile_options(npi-client
                       PRIVATE
                       $<$<CXX_COMPILER_ID:MSVC>:/W3 /permissive- /TP>
					   $<$<CXX_COMPILER_ID:GNU>:-Wall -Wextra>)

# Any additional include files would go here
#target_include_directories(npi-client
#                           PUBLIC
#                           )

target_compile_definitions(npi-client
                           PRIVATE
                           $<$<CONFIG:Debug>:DEBUG>)

target_link_libraries(npi-client
                      PRIVATE
                      sfml-graphics
                      sfml-system
                      sfml-window)
