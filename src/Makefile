CPP := $(shell which g++)
STRIP := $(shell which strip)
CPPFLAGS = -std=c++0x -g
EXE = breakout
LIBS = -lSDL -lSDL_image
OBJECTS := $(patsubst %.cpp,%.o,$(wildcard *.cpp))
TARBALL = breakout.tar.gz
TMP = /tmp
DIST_DIR = BreakOut

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
	@tar czf $(TARBALL) -C $(TMP) --exclude=.*.swp --exclude=*.o --exclude=.svn --exclude=*.tar.gz $(DIST_DIR)
	@rm -rf $(TMP)/$(DIST_DIR)
