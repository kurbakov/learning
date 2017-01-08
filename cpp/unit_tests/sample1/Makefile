# ==========================================================
# global variables:
# ==========================================================

# Points to the root of Google Test, relative to where this file is.
GTEST_DIR = /Users/dmytrokurbakov/Desktop/googletest_cpp_framework/googletest

# Where to find user code.
USER_DIR = /Users/dmytrokurbakov/Desktop/googletest_cpp_framework

# Flags passed to the preprocessor.
CPPFLAGS += -isystem $(GTEST_DIR)/include

# Flags passed to the C++ compiler.
CXXFLAGS += -g -Wall -Wextra -pthread -O3 -std=c++14

# All Google Test headers. CONSTANT
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h $(GTEST_DIR)/include/gtest/internal/*.h

# source data for gtest
GTEST_SRCS = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

# libs to use
LIBS =


# ==========================================================
# gtest compilation
# ==========================================================

gtest-all.o : $(GTEST_SRCS)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c $(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o 
	$(AR) $(ARFLAGS) $@ $^


# ==========================================================
# preparation files:
# ==========================================================

my_math.o : $(USER_DIR)/source/my_math.cc $(USER_DIR)/source/my_math.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/source/my_math.cc

unittest.o : $(USER_DIR)/utests/unittest.cc $(USER_DIR)/source/my_math.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -I$(USER_DIR) -c $(USER_DIR)/utests/unittest.cc

main.o : $(USER_DIR)/source/main.cpp $(USER_DIR)/source/my_math.h
	$(CXX) $(CXXFLAGS) -I$(USER_DIR) -c $(USER_DIR)/source/main.cpp


# ==========================================================
# Make run setup:
# ==========================================================

unittest : my_math.o unittest.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

main : my_math.o main.o
	$(CXX) $(CXXFLAGS) $^ -o $@

clean :
	rm -f $(TESTS) gtest.a gtest_main.a *.o unittest main
