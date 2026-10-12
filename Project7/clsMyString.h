#pragma once

#include <iostream>
#include "../Project3/clsMyStack.h"
using namespace std;
template <class T>

class clsMyString
{
private:
	clsMyStack<string> _Undo;
	clsMyStack<string> _Redo;
	T _Value;

public:

	void SetValue(T value)
	{
		_Undo.push(_Value);
		_Value = value;
	}
	T GetValue()
	{
		return _Value;
	}

	void Undo()
	{
		if (!_Undo.IsEmpty())
		{
			_Redo.push(_Value);
			_Value = _Undo.Top();
			_Undo.pop();
		}
	}

	void 	Redo()
	{
		if (!_Redo.IsEmpty())
		{
			_Undo.push(_Value);
			_Value = _Redo.Top();
			_Redo.pop();


		}
	}
};
