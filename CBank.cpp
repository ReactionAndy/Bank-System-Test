#include "CBank.h"
#include <fstream>
#include <iostream>
#include <conio.h>

int CBank::checkInput()
{
	return _getch();
}

void CBank::loadAccounts()
{
	std::ifstream myfile("data/accounts.txt");
	if (myfile.is_open())
	{
		SAccount tAccount;
		while (!myfile.eof())
		{

			std::string line;
			if (std::getline(myfile, line))
			{
				/*
				f - First Name
				l - Last Name
				m - Middle Name

				c - Currency
				b - Balance
				
				. - end of Account
				*/
				std::string lineWithNoJunk;
				for (unsigned int i = 0; i < line.length(); i++)
				{
					if (i >= 2)
					{
						lineWithNoJunk += line[i];
					}
				}
				switch (line[0])
				{
				case 'f':
					tAccount.firstName = lineWithNoJunk;
					break;
				case 'l':
					tAccount.lastName = lineWithNoJunk;
					break;
				case 'm':
					tAccount.middleName = lineWithNoJunk;
					break;
				case 'c':
					break;
				case 'b':
					tAccount.balance = stod(lineWithNoJunk);
					break;
				case '.':
					m_accounts.push_back(tAccount);
					break;
				default:
					break;
				}
			}
		}
		myfile.close();
	}

}

void CBank::writeAccountsToFile()
{
	std::ofstream myfile;
	myfile.open("data/accounts.txt");

	for (unsigned int i = 0; i < m_accounts.size(); i++)
	{
		myfile << "f " + m_accounts[i].firstName + '\n';
		myfile << "m " + m_accounts[i].middleName + '\n';
		myfile << "l " + m_accounts[i].lastName + '\n';
		myfile << "b " + std::to_string(m_accounts[i].balance) + '\n';

		myfile << ".\n"; // End of account;
	}

	myfile.close();
}

void CBank::createAccount()
{
	system("cls");
	std::cout << "Creating Account\n";
	SAccount tAccount;
	std::cout << "First Name: ";
	std::cin >> tAccount.firstName;

	std::cout << "Last Name: ";
	std::cin >> tAccount.lastName;

	std::cout << "Middle Name: ";
	std::cin >> tAccount.middleName;

	std::cout << "Balance: ";
	std::cin >> tAccount.balance;

	m_accounts.push_back(tAccount);
}

void CBank::destroyAccount()
{
	system("cls");
	int aSize = m_accounts.size();
	std::cout << "Account List Size:" << aSize + 1 << '\n';

	for (unsigned int i = 0; i < m_accounts.size(); i++)
	{
		std::cout << m_accounts[i].firstName << " " << m_accounts[i].middleName << " " << m_accounts[i].lastName << '\n';
	}
}

CBank::CBank() : m_renderState(OPTIONS)
{
	loadAccounts();
}

CBank::~CBank()
{
	writeAccountsToFile();
}

bool CBank::update()
{
	int keyVal = checkInput();
	if (keyVal != 27)
	{
		std::cout << keyVal << std::endl;
		switch (keyVal)
		{
		case 49: // 1
			createAccount();
			break;
		case 50: // 2
			destroyAccount();
			break;
		case 51: // 3
			m_renderState = RENDER_STATE::ACCOUNTLIST;
			break;
		default:
			break;
		}
		//createAccount();
	}
	else
		return false;
	return true;
}

void CBank::render()
{
	system("cls");
	switch (m_renderState)
	{
	case NONE:
		break;
	case OPTIONS:
		std::cout << "Options:\n"
			<< "Create Account (1)\n"
			<< "Delete Account (2)\n"
			<< "Show Accounts (3)\n";
		break;
	case ACCOUNTLIST:
		for (unsigned int i = 0; i < m_accounts.size(); i++)
		{
			std::cout << m_accounts[i].firstName << " " << m_accounts[i].middleName << " " << m_accounts[i].lastName << " " << m_accounts[i].balance << std::endl;
		}
		m_renderState = RENDER_STATE::OPTIONS;
		break;
	default:
		break;
	}
}
