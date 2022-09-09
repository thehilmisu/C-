#include <stdio.h>

#include <gtest/gtest.h>

struct BankAccount{
    int balance = 0;

    BankAccount()
    {

    }

    void deposit(int amount)
    {
        balance += amount;
    }
    bool withdraw(int amount)
    {
        if(balance >= amount)
            return true;
        
        return false;
    }


};

struct BankAccountTest : testing::Test
{
    BankAccount *account;

    BankAccountTest()
    {
        account = new BankAccount();
    }

    ~BankAccountTest()
    {
        delete account;
    }

    
};

TEST_F(BankAccountTest, BankAccountStartsEmpty)
{
    EXPECT_EQ(0, account->balance);
}
TEST_F(BankAccountTest, CanDepositMoney)
{
    account->deposit(100);
    EXPECT_EQ(100,account->balance);

}


struct account_state
{
    int initial_balance;
    int withdraw_amount;
    int final_balance;
    bool success;

};

struct WithDrawAccountTest : BankAccountTest, testing::WithParamInterface<account_state>
{
    WithDrawAccountTest()
    {
        account->balance = GetParam().initial_balance;
    }
};

TEST_P(WithDrawAccountTest,FinalBalance)
{
    auto as = GetParam();
    auto success = account->withdraw(as.withdraw_amount);

    EXPECT_EQ(as.final_balance,account->balance);
    EXPECT_EQ(as.success,success);

}

int main()
{

    testing::InitGoogleTest();
    int i = RUN_ALL_TESTS();

    return 0;
}