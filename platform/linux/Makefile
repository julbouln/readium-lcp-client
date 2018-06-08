# make -f platform/linux/Makefile test -j12

CLIENT_LIB_SOURCES = $(wildcard src/lcp-client-lib/*.cpp)
CLIENT_LIB_OBJECTS = $(patsubst %.cpp,%.o,$(CLIENT_LIB_SOURCES))

TEST_SOURCES = $(wildcard test/lcp-client-lib/tests/*.cpp)
TEST_OBJECTS = $(patsubst %.cpp,%.o,$(TEST_SOURCES))

LIBS = lcp-client-lib.a src/third-parties/ziplib/libzip.a src/third-parties/cryptopp/libcryptopp.a src/third-parties/gtest/build/libgtest.a -lc -lz -lcurl -pthread -lstdc++

CXXFLAGS = -g -std=c++11 -march=native -fPIC -fpermissive -Isrc/third-parties -Isrc/lcp-client-lib -Itest/lcp-client-lib/tools -DENABLE_NET_PROVIDER_ACQUISITION
CXX = g++

%.o: %.cpp
	${CXX} ${CXXFLAGS} -c $< -o $@

cryptopp:
	cd src/third-parties/cryptopp && make -j4

gtest:
	cd src/third-parties/gtest && mkdir -p build && cd build && cmake ../ && make -j4

ziplib:
	cd src/third-parties/ziplib && make -j4

lcp-client-lib.a: cryptopp gtest ziplib ${CLIENT_LIB_OBJECTS}
	ar rcs $@ $(CLIENT_LIB_OBJECTS)

test: lcp-client-lib.a $(TEST_OBJECTS)
	${CXX} ${CXXFLAGS} ${TEST_OBJECTS} src/third-parties/time64/time64.c -o test/lcp-client-lib/tests/test ${LIBS}
	cd test/lcp-client-lib/tests/ && ./test

clean:
	rm -f lcp-client-lib.a
	rm -f src/lcp-client-lib/*.o
	rm -f test/lcp-client-lib/tests/*.o

distclean: clean
	cd src/third-parties/cryptopp && make clean
	cd src/third-parties/gtest && rm -fr build
	cd src/third-parties/ziplib && make clean
