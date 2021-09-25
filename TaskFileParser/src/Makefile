SUBDIRS = file_parser
SOURCES = main parser_factory
INCLUDE = 

export BUILD
export CXX
export CXXFLAGS

CXXFLAGS += -c -Ifile_parser/file_parser_implementations -Ifile_parser

.PHONY: all

all: setup
	for SOURCE in $(SOURCES) ; do \
		$(CXX) $(CXXFLAGS) $$SOURCE.cpp -o $(BUILD)/$$SOURCE.o ; \
	done

setup:
	$(MAKE) -C $(SUBDIRS)
