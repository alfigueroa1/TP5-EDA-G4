#pragma once
#include <functional>
#include <iostream>
#include <new>

using namespace std;
using namespace std::placeholders;
using stateTypes = unsigned int;

class wormFSM;

typedef struct
{
	stateTypes nextState;
	void (wormFSM::* action) (void);
}cellType;


class wormFSM
{
public:
	wormFSM(const cellType* const table, const unsigned int rows, const unsigned int columns, stateTypes initState);
	void next(int event);

protected:
	void nothing(void);
	cellType temp;
	const unsigned int rowCount;
	const unsigned int columnCount;
	const cellType* const pTableFSM;
	stateTypes state;
};
