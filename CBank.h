#pragma once
#include <vector>
#include <string>

enum RENDER_STATE
{
	NONE,
	OPTIONS,
	ACCOUNTLIST,
};

struct SAccount
{
	std::string firstName, lastName, middleName;
	double balance = 0.0;
};

class CBank
{
private:
	std::vector<SAccount> m_accounts;

	RENDER_STATE m_renderState;

	int checkInput();
	 
	void loadAccounts();

	void writeAccountsToFile();

	void createAccount();
	void destroyAccount();
public:
	CBank();
	~CBank();

	bool update();
	void render();
};

