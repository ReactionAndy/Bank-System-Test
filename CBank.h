#pragma once
#include <vector>
#include <string>

struct SAccount
{
	std::string firstName, lastName, middleName;
	double balance = 0.0;;
};

class CBank
{
private:
	std::vector<SAccount> m_accounts;
	 
	void loadAccounts();

	void writeAccountsToFile();

	void createAccount();
public:
	CBank();
	~CBank();

	void update();
	void render();
};

