#include "Actions.h"

namespace M3 {
	void initBoard(){
		for (int i = 0; i < 6; i++){
			for (int j = 0; j < 6; j++) {
				jl[i][j].rec.x = 0;
			}
		}
	}
}