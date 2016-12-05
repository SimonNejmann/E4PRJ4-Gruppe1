SOURCES=main.cpp MsgQueue.cpp MsgQueuePipe.cpp util.cpp
SOURCES+=SocketHandler.cpp ComModule.cpp
EXE=PipeTest
CXXFLAGS=-I. -pthread -g

# Making for host
# > make ARCH=host
ifeq (${ARCH},host)
CXX=g++
BUILD_DIR=build/host
EXE_DIR=bin/host
endif

# Making for target
# > make ARCH=target
ifeq (${ARCH},target)
CXX=arm-devkit-g++
BUILD_DIR=build/target
EXE_DIR=bin/target
endif

OBJECTS=$(addprefix $(BUILD_DIR)/,$(SOURCES:.cpp=.o))
DEPS=$(addprefix $(BUILD_DIR)/,$(SOURCES:.cpp=.d))

all:	$(EXE) SenderUDP.cpp
	$(CXX) SenderUDP.cpp -o $(EXE_DIR)/SenderUDP

$(EXE): $(DEPS) $(OBJECTS) | $(BUILD_DIR) $(EXE_DIR)
	$(CXX) $(CXXFLAGS) -o $(EXE_DIR)/$@ $(OBJECTS)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(EXE_DIR):
	mkdir -p $(EXE_DIR)

$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule that describes how a .d (dependency) file is created from a .cpp file
# Similar to the assigment that you just completed %.cpp -> %.o
$(BUILD_DIR)/%.d: %.cpp | $(BUILD_DIR)
	$(CXX) -MT$(@:.d=.o) -MM $(CXXFLAGS) $< > $@

clean:
	rm -rf bin build *~

ifneq ($(MAKECMDGOALS),clean)
-include $(DEPS)
endif
