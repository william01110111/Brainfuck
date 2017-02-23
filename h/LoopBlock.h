#pragma once

#include "utils.h"
#include "Action.h"

class LoopBlockBase
{
public:
	LoopBlockBase();
	shared_ptr<LoopBlockBase> makeCopy();
	void mergeFrom(shared_ptr<LoopBlockBase> src);
	void shiftPos(int dist);
	void add(char c);
	void addToCell(SubActionType type, int pos, Expr val);
	//void zeroPos();
	bool canUnroll();
	void unroll(int offset, int iters);
	string getC();
	
	int pos;
	//int totalOffset;
	vector<Action> actions;
};

typedef shared_ptr<LoopBlockBase> LoopBlock;

LoopBlock makeLoopBlock();
