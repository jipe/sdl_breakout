CPP := $(shell which g++)
STRIP := $(shell which strip)
CPPFLAGS = -std=c++14 -g
EXE = sdl_breakout
LIBS = -lSDL2 -lSDL2_image
OBJECTS := $(patsubst %.cpp,%.o,$(wildcard *.cpp))
TARBALL = sdl-breakout.tar.gz
TMP = /tmp
DIST_DIR = sdl-breakout

all: release

release: debug
	@echo Building release version \(removing debugging symbols\)
	@$(STRIP) --strip-debug $(EXE)

debug: $(OBJECTS)
	@echo Linking and building executable \'$(EXE)\' \(with debugging symbols\)
	@$(CPP) $(CPPFLAGS) -o $(EXE) $(OBJECTS) $(LIBS) 

clean:
	@rm -f $(OBJECTS) $(EXE) $(TARBALL)

tarball:
	@rm -rf $(TMP)/$(DIST_DIR)
	@mkdir $(TMP)/$(DIST_DIR)
	@cp -r . $(TMP)/$(DIST_DIR)
	@tar czf $(TARBALL) -C $(TMP) --exclude=.*.swp --exclude=*.o --exclude=.git* --exclude=*.tar.gz --exclude=$(EXE) $(DIST_DIR)
	@rm -rf $(TMP)/$(DIST_DIR)
