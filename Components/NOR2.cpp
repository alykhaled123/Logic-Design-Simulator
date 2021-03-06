#include "NOR2.h"

NOR2::NOR2(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void NOR2::Operate()
{
	for (int i = 0; i < m_Inputs; i++)
	{
		if (m_InputPins[i].getStatus() == HIGH)
		{
			m_OutputPin.setStatus(LOW);
			break;
		}
		m_OutputPin.setStatus(HIGH);

	}
}

ActionType NOR2::getType() {
	return ADD_NOR_GATE_2;
}
string NOR2::getName()
{
	return "NOR2";
}
GraphicsInfo NOR2::getCenter()
{
	GraphicsInfo gfx = m_GfxInfo;
	gfx.x1 += UI.NOR2_Height / 2;
	gfx.y1 += UI.NOR2_Height / 2;
	return gfx;
}


// Function Draw
// Draws 2-input AND gate
void NOR2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawNOR2(m_GfxInfo,selected);
}

//returns status of outputpin
int NOR2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}

//returns status of Inputpin #n
int NOR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

GraphicsInfo NOR2::getInputPinPosition(int n)
{
	GraphicsInfo gfx = m_GfxInfo;
	gfx.x2 -= UI.NOR2_Width / 2;
	if (n == 1)
	{
		gfx.y2 -= 25;
	}
	else
	{
		gfx.y1 += 25;
	}

	return gfx;
}

GraphicsInfo NOR2::getOutputPinPosition()
{
	GraphicsInfo gfx = m_GfxInfo;
	gfx.x1 += UI.NOR2_Width / 2;
	return gfx;
}

//Set status of an input pin ot HIGH or LOW
void NOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
