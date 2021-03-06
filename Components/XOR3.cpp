#include "XOR3.h"

XOR3::XOR3(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(3, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void XOR3::Operate()
{
	int C = 0;
	for (int i = 0; i < m_Inputs; i++)
	{
		if (m_InputPins[i].getStatus() == HIGH)
		{
			C++;
		}
	}
	if (C % 2 == 0)
	{
		m_OutputPin.setStatus(LOW);
	}
	else
	{
		m_OutputPin.setStatus(HIGH);
	}
}

ActionType XOR3::getType() {
	return ADD_XOR_GATE_3;
}
string XOR3::getName()
{
	return "Xor3";
}
GraphicsInfo XOR3::getCenter()
{
	GraphicsInfo gfx = m_GfxInfo;
	gfx.x1 += UI.XOR3_Width / 2;
	gfx.y1 += UI.XOR3_Height / 2;
	return gfx;
}


// Function Draw
// Draws 3-input AND gate
void XOR3::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawXOR3(m_GfxInfo,selected);
}

//returns status of outputpin
int XOR3::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}

//returns status of Inputpin #n
int XOR3::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

GraphicsInfo XOR3::getInputPinPosition(int n)
{
	GraphicsInfo gfx = m_GfxInfo;
	gfx.x2 -= UI.XOR3_Width / 2;
	if (n == 1)
	{
		gfx.y2 -= 38;
	}
	else if (n == 2)
	{
		gfx.y1 += 12;
		gfx.y2 -= 12;
	}
	else
	{
		gfx.y1 += 38;
	}

	return gfx;
}

GraphicsInfo XOR3::getOutputPinPosition()
{
	GraphicsInfo gfx = m_GfxInfo;
	gfx.x1 += UI.XOR3_Width / 2;
	return gfx;
}
//Set status of an input pin ot HIGH or LOW
void XOR3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

