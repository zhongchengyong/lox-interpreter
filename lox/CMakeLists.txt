aux_source_directory(. LOX_SRC)
find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS} )
add_library(liblox STATIC ${LOX_SRC})
target_link_libraries(liblox libcommon)

# Specify here the include directories exported by this library
target_include_directories(liblox PUBLIC ${CMAKE_SOURCE_DIR})