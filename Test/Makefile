

GOOGLEMAKEFILE := C:/Repo/GoogleTest/TestProjekt/cpp_makefile_template/googletest/googletest/scripts/test
# Build flag der bruges til at invoke c++ compileren.
CPP      := g++

# Ekstra flag der bruges til:
#	-> pedantic-errors: wtf
#	-> Wall:			Tilføjer warnings til nogle af de ting der anses for værende "questionable".
#	-> Wextra:			

CPPFLAGS := -std=gnu++17 -pedantic-errors -Wall -Wextra -MMD -MP -pthread

# No linker flags for now. Maybe include them later on.
LINKERFLAGS  := #-L/usr/lib -lm

# Creating alias for the build directory.
BUILD    := build

# Setting up the object directory. Path equals build/objects.
OBJ_DIR  := $(BUILD)/objects

# Setting up the dependency directory.
DEP_DIR	 := $(BUILD)/dependencies

# Setting up the app-directory. Path is at build/apps.
APP_DIR  := $(BUILD)/apps

# Setting up a name for the actual executable to be made.
TARGET   := funMRItests

# The place in which the include files are placed.
INCLUDEPATH  := 																	\
	-Iinclude/ 																		\
	-IGoogleTest/googletest/googletest/include/ 									\
	-IGoogleTest/googletest/googletest/ 											\
	-IGoogleTest/googletest/googlmock/												\
	-IGoogleTest/googletest/googlemock/include/gmock/								\
	-I../src																		\
	-I../src/FunMRI/Include/ 														\
	-I../src/FunMRIController/Include/												\
	-I../src/FunMRIFactory/Include/													\
	-I../src/Protocol/Include/ 														\
	-I../src/State/Include/															\
	-I../src/Modules/SupplyModule/Include/ 											\
	-I../src/Modules/CommunicationModule/Include/ 									\
	-I../src/Modules/ScannerModule/Include/ 										\
	-I../src/Modules/SoundModule/Include/ 											\

# Alias for source files placed at src/subfolders.
# wildcard is a function that returns a space-seperated string of all files with the extension .cpp. 
# The several wildcards, check the different folders. 
# THUS, a folder needs to be added if src-files are contained in a diff. folder.

SRC      :=                      																		\
   $(wildcard *.cpp)																					\
   $(wildcard ../src/FunMRI/Src/FunMRI.cpp) 															\
   $(wildcard ../src/FunMRIController/Src/TestModeWithoutSmartphone.cpp)													\
   $(wildcard ../src/FunMRIFactory/Src/TestFactory.cpp) 												\
   $(wildcard ../src/Protocol/Src/*.cpp) 																\
   $(wildcard ../src/State/Src/IdleState.cpp) 																	\
   $(wildcard ../src/Modules/SupplyModule/Src/SupplyDummyTest.cpp) 										\
   $(wildcard ../src/Modules/CommunicationModule/Src/CommunicationDummyTest.cpp) 						\

# This line creates the string of object files.
# It takes all the src-files, and replace them with the same name, but with /build/objects prepended.
# This essentially means that all object files are placed in a similar tree as the src files.
# The same tree is placed in the OBJ_DIR folder.
# OBJECTS := $(SRC:%.cpp=$(OBJ_DIR)/%.o)
OBJECTS := $(SRC:%.cpp=$(OBJ_DIR)/%.o)

# Objects path-free ( with OBJ_DIR path )
PATHFREEOBJS = $(addprefix $(OBJ_DIR)/,$(notdir $(OBJECTS)))

# Creation of dependency-files.
DEPS 	:= $(SRC:%.cpp=$(DEP_DIR)/%.d)


# When invoking "make" or "make all", it runs "build" and then the target build.
# "build" invokes the process of creating app and obj directories.
# Target build is invoked, and placed in APP_DIR/target.
all: build $(APP_DIR)/$(TARGET) 

rebuild: clean build $(APP_DIR)/$(TARGET) 

#@echo "This is the path that you are trying to invoke:"	$(GOOGLEMAKEFILE)/*
secondMake:
	(cd $(GOOGLEMAKEFILE);) \
	(@echo $(CURDIR))


# Invoking "make .depend" works. It just places all the dependencies as text in the bottom...
# Find a way to insert it into .d files, and place them in dependency folder.
.depend:
	makedepend -- $(CPPFLAGS) -- $(SRC)



# Invokes the build of all the object files, which all depends on the cpp file with the same name.
# Also invokes "mkdir" which creates a folder named (@D) which just means the path without filename. 
# Build the .o file from the .cpp file. Using the c++ compiler with c++-flags.
# I check for include files in the include folder.
# $@ means that it creates the .o file with the same name as the invoked command.
# $< is the first prerequisite, i.e. the sourcefile.
$(OBJ_DIR)/%.o: %.cpp
	#@mkdir -p $(@D)
	$(CPP) $(CPPFLAGS) $(INCLUDEPATH) -o $(OBJ_DIR)/$(notdir $@) -c $<


# When invoking the build/app/program, it uses ":" to show dependencies.
# This means it has to call the invoction on all the .o files.
# It creates a path with mkdir. 
# It also includes all .o files in the build.
$(APP_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CPP) $(CPPFLAGS) $(INCLUDEPATH) $(LINKERFLAGS) -o $@ $(PATHFREEOBJS)



# Invoking phony will build all, then build, then clean, then debug, then release.
.PHONY: all build clean debug release


# This is invoked by other makes. It creates the app and object folders.
build:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(DEP_DIR)


# Running debug inserts the -DDEBUG and -g compiler flags, before making all.
debug: CPPFLAGS += -DDEBUG -g
debug: all


# Making release inserts the -O2 compiler flag before making all.
release: CPPFLAGS += -O2
release: all


# Making clean removes everything in the object and app folders recursively.
clean:
	-@rm -rvf $(OBJ_DIR)/*
	-@rm -rvf $(APP_DIR)/*
	-@rm -rvf $(BUILD)


-include $(DEPS)# DO NOT DELETE

# DO NOT DELETE

src/module1/mod1c1.o: C\:\Repo\GoogleTest\TestProjekt\cpp_makefile_template\googletest\googletest\include\gtest\gtest.h
src/module1/mod1c2.o: C\:\Repo\GoogleTest\TestProjekt\cpp_makefile_template\googletest\googletest\include\gtest\gtest.h
src/program.o: googletest/googletest/src/gtest-all.cc
