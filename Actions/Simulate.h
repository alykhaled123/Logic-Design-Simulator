#pragma once
#include "Action.h"
#include "../GUI/UI_Info.h"
#include "../Components/LED.h"
#include "../ApplicationManager.h"
#include "../Components/Switch.h"
#include "../Components/Connection.h"
#include "../Components/Gate.h"
#include "Validation.h"


class Simulate : public Action
{
public:
	Simulate(ApplicationManager* pApp);
	virtual ~Simulate(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();
	void simulate(OutputPin* outpin, Connection* connection);
	virtual void Undo();
	virtual void Redo();
};

