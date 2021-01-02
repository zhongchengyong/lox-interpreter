file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(testlox ${SRCS})

TARGET_LINK_LIBRARIES(testlox
    liblox
    libgtest
    libgmock
)

add_test(NAME testlox
         COMMAND testlox)
