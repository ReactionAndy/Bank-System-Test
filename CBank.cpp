#include "CBank.h"
#include <fstream>
#include <iostream>

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

CBank::CBank()
{
	loadAccounts();
}

CBank::~CBank()
{
	writeAccountsToFile();
}

void CBank::update()
{
	createAccount();
}

void CBank::render()
{
	for (unsigned int i = 0; i < m_accounts.size(); i++)
	{
		std::cout << m_accounts[i].firstName << " " << m_accounts[i].middleName << " " << m_accounts[i].lastName << " " << m_accounts[i].balance << std::endl;
	}
}
