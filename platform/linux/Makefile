# make -f platform/linux/Makefile test -j12

CLIENT_LIB_SOURCES = $(wildcard src/lcp-client-lib/*.cpp)
CLIENT_LIB_OBJECTS = $(patsubst %.cpp,%.o,$(CLIENT_LIB_SOURCES))

TEST_SOURCES = $(wildcard test/lcp-client-lib/tests/*.cpp)
TEST_OBJECTS = $(patsubst %.cpp,%.o,$(TEST_SOURCES))

THIRD_LIBS = src/third-parties/ziplib/libzip.a src/third-parties/cryptopp/libcryptopp.a src/third-parties/time64/libtime64.a src/third-parties/gtest/build/libgtest.a
LIBS = lcp_client_lib.a ${THIRD_LIBS} -lc -lz -lcurl -pthread -lstdc++

CXXFLAGS = -g -std=c++11 -march=native -fPIC -fpermissive -Isrc/third-parties -Isrc/lcp-client-lib -Itest/lcp-client-lib/tools -DENABLE_NET_PROVIDER_ACQUISITION
CXX = g++

%.o: %.cpp
	${CXX} ${CXXFLAGS} -c $< -o $@

libcryptopp.a:
	cd src/third-parties/cryptopp && make -j4

libgtest.a:
	cd src/third-parties/gtest && mkdir -p build && cd build && cmake ../ && make -j4

libzip.a:
	cd src/third-parties/ziplib && make -j4

libtime64.a:
	gcc ${CXXFLAGS} -c src/third-parties/time64/time64.c -o src/third-parties/time64/time64.o
	ar rcs src/third-parties/time64/libtime64.a src/third-parties/time64/time64.o 

lcp_client_lib.a: libcryptopp.a libgtest.a libzip.a libtime64.a ${CLIENT_LIB_OBJECTS}
	ar rcs $@ $(CLIENT_LIB_OBJECTS)

test: lcp_client_lib.a $(TEST_OBJECTS)
	${CXX} ${CXXFLAGS} ${TEST_OBJECTS} -o test/lcp-client-lib/tests/test ${LIBS}
	cd test/lcp-client-lib/tests/ && ./test

clean:
	rm -f lcp-client-lib.a
	rm -f src/lcp-client-lib/*.o
	rm -f test/lcp-client-lib/tests/*.o

distclean: clean
	cd src/third-parties/cryptopp && make clean
	cd src/third-parties/gtest && rm -fr build
	cd src/third-parties/ziplib && make clean
