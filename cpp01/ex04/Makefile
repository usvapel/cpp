# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/15 20:55:03 by jpelline          #+#    #+#              #
#    Updated: 2025/08/07 23:08:41 by jpelline         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ PARALLEL ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ #

# Detect CPU core count (Linux/macOS/Windows)
NUM_CORES := $(shell \
	if command -v nproc >/dev/null 2>&1; then \
		nproc; \
	elif command -v sysctl >/dev/null 2>&1; then \
		sysctl -n hw.ncpu; \
	else \
		echo 4; \
	fi)

# Enable parallelism by default, unless user specified -j or we're in recursive make
ifeq (,$(filter -j%, $(MAKEFLAGS)))
ifeq ($(MAKELEVEL),0)
	MAKEFLAGS += -j$(NUM_CORES)
endif
endif

# ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ SETTINGS ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ #

# Project configuration
NAME			:= seduction
CXX				:= g++

# Compiler flags
CXXFLAGS		:= -Wall -Wextra -Werror -std=c++20
DEBUG_FLAGS		:= -g3 -fsanitize=address -fsanitize=undefined
OPTFLAGS		:= -O2

# Directory structure
SRC_DIR			:= src
OBJ_DIR			:= obj
DEP_DIR			:= $(OBJ_DIR)/.deps

VPATH			:= $(SRC_DIR)

# Include paths and libraries
INC				:= -I./include

# Dependency generation flags
DEPFLAGS		= -MT $@ -MMD -MP -MF $(DEP_DIR)/$*.d

# ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ VISUAL STYLING ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ #

# Terminal colors for build output
BOLD			:= $(shell tput bold)
GREEN			:= $(shell tput setaf 2)
YELLOW			:= $(shell tput setaf 3)
BLUE			:= $(shell tput setaf 4)
MAGENTA			:= $(shell tput setaf 5)
CYAN			:= $(shell tput setaf 6)
WHITE			:= $(shell tput setaf 7)
RESET			:= $(shell tput sgr0)

# ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ SOURCE FILES ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ #

# Parsing and syntax analysis
SRCS_MAIN := \
	main.cpp

# Combine all source files
SRCS := \
	$(SRCS_MAIN)

# ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ BUILD VARIABLES ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ #

# Object files and build tracking
OBJS				:= $(addprefix $(OBJ_DIR)/,$(SRCS:.cpp=.o))
TOTAL_SRCS			:= $(words $(SRCS))

# Build markers and progress tracking
MARKER_STANDARD		:= .standard_build
PROGRESS_FILE		:= $(OBJ_DIR)/.progress
LOCK_FILE			:= $(OBJ_DIR)/.lock

# Utility variables for build optimization
LATEST_SRC			:= $(shell find $(SRC_DIR) -name "*.cpp" -type f \
							-print0 2>/dev/null | xargs -0 ls -t 2>/dev/null \
							| head -n 1)
OBJ_FILES_EXIST		:= $(shell [ -n "$(wildcard $(OBJ_DIR)/*.o)" ] \
							&& echo yes)

# Looking for updated header files
LATEST_HEADER		:= $(shell find include \
							-name "*.hpp" -type f -print0 2>/dev/null | xargs -0 ls -t \
							2>/dev/null | head -n 1)

# Check if binary is up to date
is_up_to_date = \
	[ -f $(NAME) ] && \
	[ "$(NAME)" -nt $(LATEST_SRC) ] && \
	[ "$(NAME)" -nt $(LATEST_HEADER) ] && \
	[ -n "$(OBJ_FILES_EXIST)" ]

# ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ BUILD TARGETS ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ #

# Default target with intelligent rebuild detection
all:
	@if [ -f $(MARKER_STANDARD) ] && $(is_up_to_date) 2>/dev/null; then \
		echo ">$(BOLD)$(YELLOW) $(NAME) is already up to date.$(RESET)"; \
	else \
		echo ">$(BOLD)$(WHITE) Starting to build $(NAME)...$(RESET)"; \
		$(MAKE) -s $(NAME) --no-print-directory; \
		touch $(MARKER_STANDARD); \
		echo ">$(BOLD)$(GREEN) All components built successfully!$(RESET)"; \
	fi

# Main executable linking with dependency checking
$(NAME): $(OBJS)
	@echo ">$(BOLD)$(GREEN) Linking $(NAME)...$(RESET)"
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS) $(OPTFLAGS)
	@touch $(MARKER_STANDARD)
	@rm -f $(PROGRESS_FILE) $(LOCK_FILE)
	@echo ">$(BOLD)$(GREEN) $(NAME) successfully compiled!$(RESET)"

# Individual object file compilation with progress tracking
$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR) $(DEP_DIR)
	@{ \
		flock 9; \
		CURRENT=$$(cat $(PROGRESS_FILE)); \
		NEXT=$$((CURRENT + 1)); \
		echo "$$NEXT" > $(PROGRESS_FILE); \
		BAR_COLOR="$(GREEN)"; ETA="--"; \
		PERCENT=$$((NEXT*100/$(TOTAL_SRCS))); \
		BAR_WIDTH=20; \
		FILLED=$$((PERCENT * BAR_WIDTH / 100)); \
		EMPTY=$$((BAR_WIDTH - FILLED)); \
		BAR="$$(printf '%*s' $$FILLED '' | tr ' ' '=')$$(printf '%*s' $$EMPTY '' | tr ' ' '-')"; \
		printf "> %b$(WHITE)[$(GREEN)%-*s$(WHITE)]$(GREEN)%b %3d%% $(CYAN)(%d/%d files)$(RESET) | Compiling %s...\n" \
			"$$BAR_COLOR" $$BAR_WIDTH "$$BAR" "$(RESET)" $$PERCENT $$NEXT $(TOTAL_SRCS) "$<"; \
	} 9>>$(LOCK_FILE)
	@$(CXX) $(CXXFLAGS) $(OPTFLAGS) $(DEPFLAGS) -c $< -o $@ $(INC)

# ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ ADDITIONAL TARGETS ■■■■■■■■■■■■■■■■■■■■■■■■■■ #

# Directory creation and dependency management
$(OBJ_DIR):
	@mkdir -p $@
	@echo "0" > $(PROGRESS_FILE)

$(DEP_DIR): | $(OBJ_DIR)
	@mkdir -p $@

# Include auto-generated dependency files
-include $(wildcard $(DEP_DIR)/*.d)

# Development and debugging build configuration
debug: CXXFLAGS	+= $(DEBUG_FLAGS)
debug: OPTFLAGS	:= -O0
debug: clean $(NAME)
	@echo ">$(BOLD)$(CYAN)  Debug build completed!$(RESET)"

# ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ CLEAN TARGETS ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ #

# Remove object files and build artifacts
clean:
	@if [ -d $(OBJ_DIR) ]; then \
		echo "> [ $(NAME) ] $(YELLOW) Cleaning object files...$(RESET)"; \
		rm -rf $(OBJ_DIR); \
		printf "> [ %-5s ] %b %s Object files cleaned!%b\n" "$(NAME)" \
		"$(YELLOW)" "$(NAME)" "$(RESET)"; \
	else \
		echo "> [ $(NAME) ] $(BOLD)$(YELLOW) Nothing to be done with \
		$(RESET)$(WHITE)clean$(RESET)"; \
	fi

# Complete cleanup including executables and external libraries
fclean: clean
	@if [ -f $(NAME) ]; then \
		echo "> [ $(NAME) ] $(YELLOW) Removing $(NAME)...$(RESET)"; \
		rm -f $(NAME) $(MARKER_STANDARD); \
		printf "> [ %-5s ] %b %s removed!%b\n" "$(NAME)" "$(YELLOW)" \
		"$(NAME)" "$(RESET)"; \
	else \
		echo "> [ $(NAME) ] $(BOLD)$(YELLOW) Nothing to be done with \
		$(RESET)$(BOLD)$(WHITE)fclean$(RESET)"; \
	fi

# Full rebuild from clean slate
re:
	@echo "> [ $(NAME) ] $(BOLD)$(WHITE) Rebuilding from scratch...$(RESET)"
	@$(MAKE) -s fclean --no-print-directory
	@$(MAKE) -s $(NAME) --no-print-directory

# ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■ TARGET DECLARATIONS ■■■■■■■■■■■■■■■■■■■■■■■■■ #

# Preserve intermediate object files and declare phony targets
.SECONDARY: $(OBJS)
.PHONY: all debug clean fclean re
