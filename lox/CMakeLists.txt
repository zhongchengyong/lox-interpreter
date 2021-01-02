aux_source_directory(. LOX_SRC)
add_library(liblox STATIC ${LOX_SRC})
target_link_libraries(liblox libcommon)

# Specify here the include directories exported by this library
target_include_directories(liblox PUBLIC ${CMAKE_SOURCE_DIR})