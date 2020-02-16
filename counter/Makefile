# Check if CMake is installed and of correct version
ifeq ($(shell which cmake),)
	TARGET := nocmake
else
#CMAKE_VERSION := $(shell cmake --version | head -1 | grep -Po '(\d[\.\d]+)')
CMAKE_VERSION := $(shell cmake --version | head -1 | cut -f3 -d' ')

CMAKE_MAJOR := $(shell echo $(CMAKE_VERSION) | cut -f1 -d.)
CMAKE_MINOR := $(shell echo $(CMAKE_VERSION) | cut -f2 -d.)
CMAKE_GT_3_8 := $(shell [ $(CMAKE_MAJOR) -gt 3 -o \( $(CMAKE_MAJOR) -eq 3 -a $(CMAKE_MINOR) -ge 8 \) ] && echo true)
ifneq ($(CMAKE_GT_3_8),true)
TARGET := oldcmake
else

# Test existence of SYSTEMC_INCLUDE and SYSTEMC_LIBDIR environment variabless
ifneq (,$(SYSTEMC_INCLUDE))
ifneq (,${SYSTEMC_LIBDIR})
SYSTEMC_SET := true
endif
endif

# Test existence of SYSTEMC_ROOT environment variable
ifneq (SYSTEMC_SET, true)
ifneq (,${SYSTEMC_ROOT})
SYSTEMC_SET := true
endif
endif

# Test existence of SYSTEMC environment variable
ifneq (SYSTEMC_SET, true)
ifneq (,${SYSTEMC})
SYSTEMC_SET := true
endif
endif


endif
endif

#printvar:
#	@echo $(CMAKE_VERSION)
#	@echo $(CMAKE_MAJOR)
#	@echo $(CMAKE_MINOR)
#	@echo $(TARGET)

default: run
	
run:
	@echo
	@echo "--  CMake Run "

	@echo
	@echo "-- CMake ----------------"
	mkdir -p build && cd build && cmake ..

	@echo
	@echo "-- COMPILE -----------------"
	cmake --build build

	@echo
	@echo "-- RUN ---------------------"
	@mkdir -p logs
	build/sim

	@echo
	@echo "-- DONE --------------------"
	@echo

clean mostlyclean distclean maintainer-clean:
	@rm -rf build

nocmake:
	@echo
	@echo "%Skip: CMake has not been found"
	@echo

oldcmake:
	@echo
	@echo "%Skip: CMake version is too old (need at least 3.8)"
	@echo

nosc:
	@echo
	@echo "%Skip: CMake could not find SystemC."
	@echo "% Make sure that either:"
	@echo "% - The environment variables SYSTEMC_INCLUDE and SYSTEMC_LIBDIR are exported."
	@echo "% - Or, the environment variable SYSTEMC_ROOT is exported."
	@echo "% - Or, The environment variable SYSTEMC is exported."
	@echo "% - Or, if the SystemC installation provides CMake support,"
	@echo "%   that its installation prefix is in CMAKE_PREFIX_PATH."
	@echo "% Also that the C++ standard of the SystemC library is the same as this example."
	@echo "% Please see the Verilator documentation's CMake section for more information."
	@echo
