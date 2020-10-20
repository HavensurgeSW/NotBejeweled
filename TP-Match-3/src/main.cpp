#include "Mainframe.h"
using namespace M3;


void main() {
Mainframe* Match3 = new Mainframe;
	Match3->init();
	Match3->mainLoop();

	delete Match3;
}