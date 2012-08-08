CPP = `which g++`
CPP_FLAGS = -std=c++0x
EXE = breakout
LIBS = -lSDL -lSDL_image
INTERFACES = 
OBJECTS = BoundingObject.o BoundingBox.o BoundingSphere.o BoundingPlane.o CollisionDetector.o CollisionResolver.o \
          Vector2.o Application.o BreakOut.o ColorConstants.o Color.o Screen.o StarField.o Collision.o \
		  CollisionObject.o Edge.o Animation.o ImageInfo.o GameObject.o ImageResources.o ImageAnimation.o
TARBALL = breakout.tar.gz
TMP = /tmp
DIST_DIR = BreakOut

release: main.o $(OBJECTS)
	@$(CPP) $(CPP_FLAGS) -o $(EXE) main.o $(OBJECTS) $(LIBS) 

#main.o : main.cpp $(OBJECTS) 
#	@$(CPP) -c -o main.o main.cpp
	
#$(OBJECTS): %.o: %.cpp %.h $(INTERFACES)
#	@$(CPP) -c -o $@ $<

.cpp.o:
	$(CPP) $(CPP_FLAGS) -g -c $< -o $@

clean:
	@rm -f *.o $(EXE) $(TARBALL)

tarball:
	@rm -rf $(TMP)/$(DIST_DIR)
	@mkdir $(TMP)/$(DIST_DIR)
	@cp -r . $(TMP)/$(DIST_DIR)
	@tar czf $(TARBALL) -C $(TMP) --exclude=.*.swp --exclude=*.o --exclude=.svn --exclude=*.tar.gz $(DIST_DIR)
	@rm -rf $(TMP)/$(DIST_DIR)
