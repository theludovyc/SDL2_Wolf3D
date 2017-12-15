MLCC_FOLDER = ../MyLibCC/
MLCC_BUILD_FOLDER = $(MLCC_FOLDER)Build/
BIN_FOLDER = Bin

MKDIR = @mkdir -p $(BIN_FOLDER)

IFLAGS = -I$(MLCC_FOLDER)

IGM = -I"../Geom" $(IFLAGS)
IDS = -I"../DataStruct" $(IFLAGS)

BUILD0 = @g++ -o $(BIN_FOLDER)/$@.exe $@.cc $(IFLAGS)

BUILD1 = @printf "%s.exe compiled\n" $@

all:

main:
	$(MKDIR)
	$(BUILD0) $(MLCC_BUILD_FOLDER)tool.o -lSDL2
	$(BUILD1)