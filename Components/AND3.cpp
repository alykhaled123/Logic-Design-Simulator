#include "AND3.h"

AND3::AND3(const GraphicsInfo& r_GfxInfo, int r_FanOut) : Gate(3, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}

void AND3::Operate()
{
	for (int i = 0; i < m_Inputs; i++)
	{
		if (m_InputPins[i].getStatus() == LOW)
		{
			m_OutputPin.setStatus(LOW);
			break;
		}
		m_OutputPin.setStatus(HIGH);
	}
}

ActionType AND3::getType() {
	return ADD_AND_GATE_3;
}
string AND3::getName()
{
	return "AND3";
}
GraphicsInfo AND3::getCenter()
{
	GraphicsInfo gfx = m_GfxInfo;
	gfx.x1 += UI.AND3_Width / 2;
	gfx.y1 += UI.AND3_Height / 2;
	return gfx;
}

// Function Draw
// Draws 3-input AND gate
void AND3::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawAND3(m_GfxInfo);
}

//returns status of outputpin
int AND3::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}

//returns status of Inputpin #n
int AND3::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

GraphicsInfo AND3::getInputPinPosition(int n)
{
	return GraphicsInfo();
}

GraphicsInfo AND3::getOutputPinPosition()
{
	return GraphicsInfo();
}

//Set status of an input pin ot HIGH or LOW
void AND3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
