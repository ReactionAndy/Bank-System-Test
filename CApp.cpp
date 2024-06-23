#include "CApp.h"

CApp::CApp()
{
}

CApp::~CApp()
{
}

void CApp::run()
{
	m_bank.update();
	m_bank.render();
}
