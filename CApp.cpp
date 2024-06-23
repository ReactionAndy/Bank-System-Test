#include "CApp.h"

CApp::CApp()
{
}

CApp::~CApp()
{
}

void CApp::run()
{
	while (true)
	{
		m_bank.render();
		if (!m_bank.update())
			return;
	}
}
