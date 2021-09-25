SUBDIRS = file_parser_implementations
SOURCES = file_parser
BASE_DIR = $(shell pwd)

export BUILD
export CXX
export CXXFLAGS
export BASE_DIR

.PHONY: all

all: setup
	for SOURCE in $(SOURCES) ; do \
		$(CXX) $(CXXFLAGS) $$SOURCE.cpp -o $(BUILD)/$$SOURCE.o ; \
	done

setup:
	$(MAKE) -C $(SUBDIRS)

