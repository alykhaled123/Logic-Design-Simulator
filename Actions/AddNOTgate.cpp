#include "AddNOTgate.h"
#include "..\ApplicationManager.h"

AddNOTgate::AddNOTgate(ApplicationManager* pApp) :Action(pApp)
{

}

AddNOTgate::~AddNOTgate(void)
{

}

void AddNOTgate::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Inverter Gate: Click to add the gate");

	//Wait for User Input
	
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddNOTgate::Execute()
{
	Output* pOut = pManager->GetOutput();

	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.NOT_Width;
	int Wdth = UI.NOT_Height;
	int yup, ybot;
	for (int i = 0; i < pManager->getComponetsNumber(); i++)
	{
		GraphicsInfo gfx = pManager->getComponents()[i]->getPosition();
		if (gfx.x1 <= Cx && gfx.x2 >= Cx && gfx.y1 <= Cy && gfx.y2 >= Cy || (Cy >= 0 && Cy < UI.ToolBarHeight + UI.ActionToolBarHeight))
		{
			pOut->PrintMsg("Invaild Position");
			return;
		}

	}
	if (Cy >= 0 && Cy < UI.ToolBarHeight + UI.ActionToolBarHeight)
	{
		pOut->PrintMsg("Invaild Position");
		return;
	}
	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

	yup = Cy / 100;
	yup *= 100;
	yup += 30;

	ybot = Cy / 100;
	ybot *= 100;
	ybot += 80;

	if (abs((Cy - yup)) > abs(Cy - ybot))
	{
		GInfo.y1 = ybot;
		Cy = ybot;
	}
	else
	{
		GInfo.y1 = yup;
		Cy = yup;
	}

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;

	GraphicsInfo border = GInfo;
	border.x1 -= 3;
	border.x2 += 3;
	border.y1 -= 3;
	border.y2 += 3;
	//pOut->DrawRectangle(border);

	
	INVERTER* pA = new INVERTER(GInfo, AND2_FANOUT);
	Input* pIn = pManager->GetInput();
	string label = pIn->GetSrting(pOut);

	GraphicsInfo labelgfx = GInfo;
	labelgfx.y1 -= 20;

	pA->setLabel(label);

	pOut->DrawString(labelgfx, label);
	pManager->AddComponent(pA);
}

void AddNOTgate::Undo()
{

}

void AddNOTgate::Redo()
{

}