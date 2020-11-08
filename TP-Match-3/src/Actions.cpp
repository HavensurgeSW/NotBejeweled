#include "Actions.h"

namespace M3 {
	void initBoard(){
		for (int i = 0; i < jlMax; i++){
			for (int j = 0; j < jlMax; j++) {
				jl[i][j].rec.x = 100 + j * 90;
				jl[i][j].rec.y = 100 + i * 90;
			}
		}
	}
}