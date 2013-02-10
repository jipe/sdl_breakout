#include "BreakOut.h"

#include <cstdlib>
#include <time.h>

int main(int argc, char** argv) {
  srand(time(0)); 
	BreakOut game = BreakOut(800, 800, 30);
	game.run();
	return 0;
}
