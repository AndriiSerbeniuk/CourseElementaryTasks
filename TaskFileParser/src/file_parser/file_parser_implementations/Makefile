#SUBDIRS = 
SOURCES = file_line_counter file_replacer

export BUILD
export CXX
export CXXFLAGS

CXXFLAGS += -I$(BASE_DIR)

.PHONY: all

all:
	for SOURCE in $(SOURCES) ; do \
		$(CXX) $(CXXFLAGS) $$SOURCE.cpp -o $(BUILD)/$$SOURCE.o ; \
	done

