#include "../h/Optimizer.h"

Optimizer::Optimizer()
{
	
}

void Optimizer::add(char c)
{
	switch (c)
	{
	case '[':
		stack.push_back(makeLoopBlock());
		break;
		
	case ']':
		if (stack.size()>=2)
		{
			stack[stack.size()-2]->mergeFrom(stack[stack.size()-1]);
			stack.pop_back();
		}
		else
		{
			cout << "']' without '['" << endl;
		}
		break;
		
	default:
		stack.back()->add(c);
	}
}

string Optimizer::getC()
{
	if (stack.size()>1)
	{
		cout << "no matching ']'" << endl;
	}
	else if (stack.size()!=1)
	{
		cout << "stack of bad length" << endl;
	}
	else
	{
		string out="";
		
		out+=
			"#include <stdio.h>\n"
			"int _data["+to_string(DATA_SIZE)+"];\n"
			"int* _p = _data;\n"
			"int main(void)\n{\n";
		
		out += indentString(stack[0]->getC());
		
		out += "}\n";
		
		return out;
	}
	
	return "// error\n";
}


