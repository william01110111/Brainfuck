#include "../h/LoopBlock.h"

LoopBlock makeLoopBlock()
{
	return LoopBlock(new LoopBlockBase());
}

LoopBlockBase::LoopBlockBase()
{
	//this->pos = expr(0);
	//this->totalOffset = expr(0);
	
	pos = 0;
	//totalOffset = 0;
}

void LoopBlockBase::add(char c)
{
	switch (c)
	{
	case '<':
		shiftPos(-1);
		//zeroPos();
		//add(makeActionShift(expr(-1)));
		break;
		
	case '>':
		shiftPos(1);
		//zeroPos();
		//add(makeActionShift(expr(1)));
		break;
		
	case '+':
		//add(makeActionAdd(pos, expr(1)));
		addToCell(ACTION_ADD, expr(1));
		break;
		
	case '-':
		//add(makeActionAdd(pos, expr(-1)));
		addToCell(ACTION_ADD, expr(-1));
		break;
		
	case '.':
		//add(makeActionOut(pos));
		addToCell(ACTION_OUT, expr());
		break;
		
	case ',':
		//cout << "',' input operator not yet implemented" << endl;
		addToCell(ACTION_IN, expr());
		break;
	
	default:
		break;
	}
}

void LoopBlockBase::add(Action a)
{
	actions.push_back(a);
}

void LoopBlockBase::addToCell(SubActionType type, Expr val)
{
	if (actions.empty() || !actions.back()->isMapAdd())
	{
		actions.push_back(makeActionMapAdd());
	}
	
	actions.back()->addSubAction(pos, type, val);
}

void LoopBlockBase::mergeFrom(LoopBlock src)
{
	//zeroPos();
	//src->zeroPos();
	actions.push_back(makeActionLoop(src, pos));
	pos = 0;
}

/*
void LoopBlockBase::zeroPos()
{
	actions.push_back(makeActionShift(pos));
	pos = 0;
}
*/

void LoopBlockBase::shiftPos(int dist)
{
	pos += dist;
	//totalOffset += dist;
}

string LoopBlockBase::getC()
{
	string out="";
	
	for (auto i: actions)
	{
		out+=i->getC();
	}
	
	return out;
}

