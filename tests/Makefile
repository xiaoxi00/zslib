#File	: Makefile
#Project:
#Author	: zerozakiGeek
#Email	: zerozakiGeek@gmail.com
#Date	: 2016-10-10
LOCAL_SRC_FILES := \
	utility.cpp \
	tuple.cpp
LOCAL_CXX := \
	clang++
LOCAL_CXXFLAGS := \
	-std=c++11 -Wall -Werror
all:
	$(foreach f,$(LOCAL_SRC_FILES),$(info $(LOCAL_CXX) $(basename $(f)) <= $(f))$(shell $(LOCAL_CXX) $(LOCAL_CXXFLAGS) -o $(basename $(f)) $(f)))
