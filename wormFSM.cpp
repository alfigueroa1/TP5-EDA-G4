//#pragma once
//#include "wormFSM.h"
//
//wormFSM :: wormFSM(const cellType* const table = NULL, const unsigned int rows = 0, const unsigned int columns = 0, stateTypes initState = 0, double pos_x = 701, double pos_y = 616)
//	: state(initState), rowCount(rows), columnCount(columns), pTableFSM(table), pos_x(pos_x), pos_y(pos_y) {}
//
//void wormFSM::next(int event)
//{
//	temp = pTableFSM[static_cast<unsigned int>(state) * columnCount + event];
//	auto f = bind(temp.action, this);
//	f();
//	state = pTableFSM[state * columnCount + event].nextState;
//}
//
