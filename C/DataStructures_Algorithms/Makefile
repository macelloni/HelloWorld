TARGET := a.out
MAIN_SRC := main.c

DIRS := menu cli_io sort graph datastructures
OBJS :=

ALL_OBJS := 
CLEAN_FILES := $(TARGET) $(OBJS)
DIST_CLEAN_FILES := $(OBJS)

rwildcard=$(foreach d,$(wildcard $(addsuffix *,$(1))),$(call rwildcard,$(d)/,$(2))$(filter $(subst *,%,$(2)),$(d)))

default: show-info all

$(TARGET): build-subdirs $(OBJS) find-all-objs
	@echo -e "\t" CC $(CCFLAGS) $(ALL_OBJS) $(MAIN_SRC) -o $@
	@$(CC) $(CCFLAGS) $(ALL_OBJS) $(MAIN_SRC) -o $@

.PHONY: all
all: $(TARGET)
	@echo Target $(TARGET) build finished.

.PHONY: clean
clean: clean-subdirs
	@echo CLEAN $(CLEAN_FILES)
	@rm -f $(CLEAN_FILES)

.PHONY: distclean
distclean: clean-subdirs
	@echo CLEAN $(DIST_CLEAN_FILES)
	@rm -f $(DIST_CLEAN_FILES)

.PHONY: find-all-objs
find-all-objs:
	$(eval ALL_OBJS += $(call rwildcard,$(DIRS),*.o))

.PHONY: show-info
show-info:
	@echo Building Project

mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
export PROJECT_PATH := $(patsubst %/,%,$(dir $(mkfile_path)))
export MAKE_INCLUDE=$(PROJECT_PATH)/.buildconfig/make.global
export SUB_MAKE_INCLUDE=$(PROJECT_PATH)/.buildconfig/submake.global
include $(MAKE_INCLUDE)
