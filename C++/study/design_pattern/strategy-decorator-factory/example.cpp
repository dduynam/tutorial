#ifndef model
#define model
#endif
//#pragma once
#include <iostream>
#include <string>

#ifdef model
class _computer
{
public:
    std::string decription()
    {
        return "You're getting a computer and a disk";
        // If we want to implement more devices, we have to modidy code here.
    }
};
#endif

#ifndef decorator
//#define decorator
//Create computer class
class computer
{
public:
    virtual std::string description()
    {
        return "Computer";
    }
};

//Create additional responsibilities classes
class CD : public computer
{
private:
    computer *Computer;

public:
    CD(computer *c)
    {
        Computer = c;
    }
    std::string description()
    {
        return Computer->description().append(" and a CD");
    }
};

class Disk : public computer
{
private:
    computer *Computer;

public:
    Disk(computer *c)
    {
        Computer = c;
    }
    std::string description()
    {
        return Computer->description().append(" and a Disk");
    }
};

class Monitor : public computer
{
private:
    computer *Computer;

public:
    Monitor(computer *c)
    {
        Computer = c;
    }
    std::string description()
    {
        return Computer->description().append(" and a Monitor");
    }
};
#endif

#ifndef factory
#define factory
//Create computer class
class Connection
{
public:
    virtual std::string description() = 0;
};

//Create additional responsibilities classes
class OracelConnection : public Connection
{
public:
    std::string description() override
    {
        return "Oracel";
    }
};

class MySqlConnection : public Connection
{
public:
    std::string description() override
    {
        return "MySql";
    }
};

class SqlServerConnection : public Connection
{
public:
    std::string description() override
    {
        return "SqlServer";
    }
};
#endif

//If customer wants to change the implementiation from insecure to secure, or changes depending on area
//Create abstract factory
class ConnectionFactory
{
public:
    virtual Connection *createConnection(std::string type) = 0;
};

//Make the core code no change --> play a role as USB port...
void coreOracleWork(ConnectionFactory *factoryi)
{
    Connection *connection = factoryi->createConnection("Oracle");
    std::cout << connection->description() << std::endl;
}

//Create the subclasses and make subclasses decide which object will be create.
class VietnamConnectionFactory : public ConnectionFactory
{
public:
    //Create Object
    Connection *createConnection(std::string type) override
    {
        if (type.compare("Oracle") == 0)
            return new VietnamOracelConnection();
        else if (type.compare("SqlServer") == 0)
            return new VietnamSqlServerConnection();
        else if (type.compare("MySql") == 0)
            return new VietnamMySqlConnection();
        else
            return nullptr;
    }
};

class KoreaConnectionFactory : public ConnectionFactory
{
public:
    //Create Object
    Connection *createConnection(std::string type) override
    {
        if (type.compare("Oracle") == 0)
            return new KoreaOracelConnection();
        else if (type.compare("SqlServer") == 0)
            return new KoreaSqlServerConnection();
        else if (type.compare("MySql") == 0)
            return new KoreaMySqlConnection();
        else
            return nullptr;
    }
};

int main()
{

#ifdef decorator
    computer *com1 = new computer();
    computer *com2 = new Disk(com1);
    computer *com3 = new CD(com2);
    computer *com4 = new Monitor(com3);
    computer *com5 = new Disk(com2);
    computer *com6 = new Monitor(com5);

    std::cout << "com 1: " << com1->description() << std::endl;
    std::cout << "com 2: " << com2->description() << std::endl;
    std::cout << "com 3: " << com3->description() << std::endl;
    std::cout << "com 4: " << com4->description() << std::endl;
    std::cout << "com 5: " << com5->description() << std::endl;
    std::cout << "com 6: " << com6->description() << std::endl;

#endif

#ifdef factory
    //Connection *connect = createConnection("Oracle"); apply when createConnection is a function, in that case it is modified as class.
    //std::cout << connect->description();
    coreOracleWork(new VietnamConnectionFactory());
    coreOracleWork(new KoreaConnectionFactory());

#endif

    return 0;
}