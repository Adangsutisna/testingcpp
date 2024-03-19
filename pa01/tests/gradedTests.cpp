#include <sstream>
#include <fstream>
#include <vector>

#include "catch.hpp"

#include "money.h"
#include "stock.h"
#include "portfolio.h"
#include "driver.h"


// Helper function declarations (don't change these)
extern bool CheckTextFilesSame(const std::string& fileNameA,
	const std::string& fileNameB);

TEST_CASE("Test MONEY class", "[graded]")
{
	SECTION("Default constructor and output operator | 2")
	{
		Money m1;

		if (m1.getCents() != 0)
		{
			std::stringstream ss;
			ss << "Constructor set mCents to: " << m1.getCents() << std::endl;
			ss << "I was expecting: 0" << std::endl;
			FAIL(ss.str());
		}

		std::stringstream sst;
		sst << m1;
		sst.flush();

		if (sst.str() != "$0.00")
		{
			std::stringstream ss;
			ss << "Your output operator gave me: " << sst.str() << std::endl;
			ss << "I was expecting: $0.00" << std::endl;
			FAIL(ss.str());
		}
	}

	SECTION("2 long parameter constructor and output operator | 2")
	{
		Money m1(11, 50);

		if (m1.getCents() != 1150)
		{
			std::stringstream ss;
			ss << "Constructor set mCents to: " << m1.getCents() << std::endl;
			ss << "I was expecting: 1150" << std::endl;
			FAIL(ss.str());
		}

		std::stringstream sst;
		sst << m1;
		sst.flush();

		if (sst.str() != "$11.50")
		{
			std::stringstream ss;
			ss << "Your output operator gave me: " << sst.str() << std::endl;
			ss << "I was expecting: $11.50" << std::endl;
			FAIL(ss.str());
		}
	}

	SECTION("Double constructor and output operator | 2")
	{
		Money m1(-32.11);

		if (m1.getCents() != -3211)
		{
			std::stringstream ss;
			ss << "Default constructor set mCents to: " << m1.getCents() << std::endl;
			ss << "I was expecting: -3211" << std::endl;
			FAIL(ss.str());
		}

		std::stringstream sst;
		sst << m1;
		sst.flush();

		if (sst.str() != "$-32.11")
		{
			std::stringstream ss;
			ss << "Your output operator gave me: " << sst.str() << std::endl;
			ss << "I was expecting: $-32.11" << std::endl;
			FAIL(ss.str());
		}
	}

	SECTION("1 long long constructor and output operator | 2")
	{
		Money m1((long long)10001);

		if (m1.getCents() != 10001)
		{
			std::stringstream ss;
			ss << "Default constructor set mCents to: " << m1.getCents() << std::endl;
			ss << "I was expecting: 10001" << std::endl;
			FAIL(ss.str());
		}

		std::stringstream sst;
		sst << m1;
		sst.flush();

		if (sst.str() != "$100.01")
		{
			std::stringstream ss;
			ss << "Your output operator gave me: " << sst.str() << std::endl;
			ss << "I was expecting: $100.01" << std::endl;
			FAIL(ss.str());
		}
	}

	SECTION("1 int constructor and output operator | 2")
	{
		Money m1(-101);

		if (m1.getCents() != -101)
		{
			std::stringstream ss;
			ss << "Default constructor set mCents to: " << m1.getCents() << std::endl;
			ss << "I was expecting: 10001" << std::endl;
			FAIL(ss.str());
		}

		std::stringstream sst;
		sst << m1;
		sst.flush();

		if (sst.str() != "$-1.01")
		{
			std::stringstream ss;
			ss << "Your output operator gave me: " << sst.str() << std::endl;
			ss << "I was expecting: $-1.01" << std::endl;
			FAIL(ss.str());
		}
	}

	SECTION("Check < operator | 2")
	{
		Money m1(11, 50);
		Money m2(110, 50);

		if (!(m1 < m2))
		{
			std::stringstream ss;
			ss << "You said " << m1 << " >= " << m2 << std::endl;
			ss << "I was expecting " << m1 << " < " << m2 << std::endl;
			FAIL(ss.str());
		}

		if (m2 < m1)
		{
			std::stringstream ss;
			ss << "You said " << m2 << " < " << m1 << std::endl;
			ss << "I was expecting " << m2 << " >= " << m1 << std::endl;
			FAIL(ss.str());
		}
	}

	SECTION("Check <= operator | 2")
	{
		Money m1(11, 50);
		Money m2(110, 50);
		Money m3(11.50);

		if (!(m1 <= m2))
		{
			std::stringstream ss;
			ss << "You said " << m1 << " > " << m2 << std::endl;
			ss << "I was expecting " << m1 << " <= " << m2 << std::endl;
			FAIL(ss.str());
		}

		if (m2 <= m1)
		{
			std::stringstream ss;
			ss << "You said " << m2 << " > " << m1 << std::endl;
			ss << "I was expecting " << m2 << " <= " << m1 << std::endl;
			FAIL(ss.str());
		}

		if (!(m1 <= m3))
		{
			std::stringstream ss;
			ss << "You said " << m1 << " > " << m3 << std::endl;
			ss << "I was expecting " << m1 << " <= " << m3 << std::endl;
			FAIL(ss.str());
		}
	}

	SECTION("Check > operator | 2")
	{
		Money m1(11, 50);
		Money m2(110, 50);

		if (!(m2 > m1))
		{
			std::stringstream ss;
			ss << "You said " << m2 << " <= " << m1 << std::endl;
			ss << "I was expecting " << m2 << " > " << m1 << std::endl;
			FAIL(ss.str());
		}

		if (m1 > m2)
		{
			std::stringstream ss;
			ss << "You said " << m1 << " >= " << m2 << std::endl;
			ss << "I was expecting " << m1 << " < " << m2 << std::endl;
			FAIL(ss.str());
		}
	}

	SECTION("Check >= operator | 2")
	{
		Money m1(11, 50);
		Money m2(110, 50);
		Money m3(11.50);

		if (!(m2 >= m1))
		{
			std::stringstream ss;
			ss << "You said " << m2 << " < " << m1 << std::endl;
			ss << "I was expecting " << m2 << " >= " << m1 << std::endl;
			FAIL(ss.str());
		}

		if (m1 >= m2)
		{
			std::stringstream ss;
			ss << "You said " << m1 << " >= " << m2 << std::endl;
			ss << "I was expecting " << m2 << " >= " << m1 << std::endl;
			FAIL(ss.str());
		}

		if (!(m1 <= m3))
		{
			std::stringstream ss;
			ss << "You said " << m1 << " > " << m3 << std::endl;
			ss << "I was expecting " << m1 << " >= " << m3 << std::endl;
			FAIL(ss.str());
		}
	}

	SECTION("Check == operator | 2")
	{
		Money m1(11, 50);
		Money m2(110, 50);
		Money m3(11.50);

		if (m1 == m2)
		{
			std::stringstream ss;
			ss << "You said " << m1 << " == " << m2 << std::endl;
			ss << "I was expecting " << m1 << " != " << m2 << std::endl;
			FAIL(ss.str());
		}

		if (m2 == m1)
		{
			std::stringstream ss;
			ss << "You said " << m2 << " == " << m1 << std::endl;
			ss << "I was expecting " << m2 << " != " << m1 << std::endl;
			FAIL(ss.str());
		}

		if (!(m1 == m3))
		{
			std::stringstream ss;
			ss << "You said " << m1 << " != " << m3 << std::endl;
			ss << "I was expecting " << m1 << " == " << m3 << std::endl;
			FAIL(ss.str());
		}

	}

	SECTION("Check != operator | 2")
	{
		Money m1(11, 50);
		Money m2(110, 50);
		Money m3(11.50);

		if (!(m1 != m2))
		{
			std::stringstream ss;
			ss << "You said " << m1 << " == " << m2 << std::endl;
			ss << "I was expecting " << m1 << " != " << m2 << std::endl;
			FAIL(ss.str());
		}

		if (!(m2 != m1))
		{
			std::stringstream ss;
			ss << "You said " << m2 << " == " << m1 << std::endl;
			ss << "I was expecting " << m2 << " != " << m1 << std::endl;
			FAIL(ss.str());
		}

		if (m1 != m3)
		{
			std::stringstream ss;
			ss << "You said " << m1 << " != " << m3 << std::endl;
			ss << "I was expecting " << m1 << " == " << m3 << std::endl;
			FAIL(ss.str());
		}	
	}

	SECTION("+ operator and output operator | 2")
	{
		Money m1(101);
		Money m2(10,10);
		Money m3 = m1 + m2;

		std::stringstream sst;
		sst << m3;
		sst.flush();

		if (sst.str() != "$11.11")
		{
			std::stringstream ss;
			ss << "You said " << m1 << " + " << m2 << " = " << m3 << std::endl;
			ss << "I was expecting: $11.11" << std::endl;
			FAIL(ss.str());
		}
	}

	SECTION("- operator and output operator | 2")
	{
		Money m1(101);
		Money m2(10, 1);
		Money m3 = m2 - m1;
		Money m4 = m1 - Money(190);


		std::stringstream sst;
		sst << m3;
		sst.flush();

		if (sst.str() != "$9.00")
		{
			std::stringstream ss;
			ss << "You said " << m2 << " - " << m1 << " = " << m3 << std::endl;
			ss << "I was expecting: $9.00" << std::endl;
			FAIL(ss.str());
		}

		sst.str("");
		sst << m4;
		sst.flush();

		if (sst.str() != "$-0.89")
		{
			std::stringstream ss;
			ss << "You said " << m1 << " - $1.90 = " << m4 << std::endl;
			ss << "I was expecting: $-0.89" << std::endl;
			FAIL(ss.str());
		}

	}

	SECTION("* operator and output operator | 2")
	{
		Money m1(101);
		Money m2 = m1 * -0.9;
		Money m3 = m1 * 3;


		std::stringstream sst;
		sst << m2;
		sst.flush();

		if (sst.str() != "$-0.90")
		{
			std::stringstream ss;
			ss << "You said " << m1 << " * -0.9 = " << m2 << std::endl;
			ss << "I was expecting: $-0.90" << std::endl;
			FAIL(ss.str());
		}

		sst.str("");
		sst << m3;
		sst.flush();

		if (sst.str() != "$3.03")
		{
			std::stringstream ss;
			ss << "You said " << m1 << " * 3 = " << m3 << std::endl;
			ss << "I was expecting: $3.03" << std::endl;
			FAIL(ss.str());
		}
	}

	SECTION("/ operator and output operator | 2")
	{
		Money m1(101);
		Money m2 = m1 / -0.9;
		Money m3 = m1 / 3;

		std::stringstream sst;
		sst << m2;
		sst.flush();

		if (sst.str() != "$-1.12")
		{
			std::stringstream ss;
			ss << "You said " << m1 << " / -0.9 = " << m2 << std::endl;
			ss << "I was expecting: $-1.12" << std::endl;
			FAIL(ss.str());
		}

		sst.str("");
		sst << m3;
		sst.flush();

		if (sst.str() != "$0.33")
		{
			std::stringstream ss;
			ss << "You said " << m1 << " / 3 = " << m3 << std::endl;
			ss << "I was expecting: $0.33" << std::endl;
			FAIL(ss.str());
		}
	}

	SECTION("+= operator and output operato | 2")
	{
		Money m1(101);
		Money m2(10, 10);
		m2 += m1;

		std::stringstream ss;
		ss << m2;
		ss.flush();

		if(ss.str() != "$11.11")
		{
			std::stringstream ss;
			ss << "You said $10.10 += " << m1 << " becomes " << m2 << std::endl;
			ss << "I was expecting: $11.11" << std::endl;
			FAIL(ss.str());
		}
	}

	SECTION("-= operator and output operator | 2")
	{
		Money m1(101);
		Money m2(10, 1);
		m2 -= m1;

		std::stringstream ss;
		ss << m2;
		ss.flush();
		
		if (ss.str() != "$9.00")
		{
			std::stringstream ss;
			ss << "You said $10.01 -= " << m1 << " becomes " << m2 << std::endl;
			ss << "I was expecting: $9.00" << std::endl;
			FAIL(ss.str());
		}
	}

	SECTION("*= operator and output operator | 2")
	{
		Money m1(101);
		m1 *= -0.9;

		std::stringstream ss;
		ss << m1;
		ss.flush();

		if (ss.str() != "$-0.90")
		{
			std::stringstream ss;
			ss << "You said $1.01 *= -0.9 becomes " << m1 << std::endl;
			ss << "I was expecting: $-0.90" << std::endl;
			FAIL(ss.str());
		}
	}

	SECTION("/= operator and output operator | 2")
	{
		Money m1(101);
		m1 /= 3;

		std::stringstream ss;
		ss << m1;
		ss.flush();
		
		if (ss.str() != "$0.33")
		{
			std::stringstream ss;
			ss << "You said $1.01 /= -3 becomes " << m1 << std::endl;
			ss << "I was expecting: $0.33" << std::endl;
			FAIL(ss.str());
		}
	}

	SECTION("input and output operator | 2")
	{
		Money m1;
		
		std::stringstream ss;
		ss << "10.01";
		ss.flush();
		ss >> m1;

		std::stringstream ss2;
		ss2 << m1;
		ss2.flush();
		
		if (ss2.str() != "$10.01")
		{
			std::stringstream sserr;
			sserr << "When doing cin >> m1, and the user types 10.01, you said m1 is " << m1 << std::endl;
			sserr << "I was expecting: $10.01" << std::endl;
			FAIL(sserr.str());			
		}

		std::stringstream ss3;
		ss3 << "-0.01";
		ss3.flush();
		ss3 >> m1;

		std::stringstream ss4;
		ss4 << m1;
		ss4.flush();
		
		if (ss4.str() != "$-0.01")
		{
			std::stringstream sserr;
			sserr << "When doing cin >> m1, and the user types -0.01, you said m1 is " << m1 << std::endl;
			sserr << "I was expecting: $-0.01" << std::endl;
			FAIL(sserr.str());				
		}
	}
}


TEST_CASE("Test STOCK class", "[graded]")
{
	SECTION("Default constructor, setters and getters | 2")
	{
		Stock s1("Disney", "DIS", Money(10001), 2.01);

		if (s1.getName() != "Disney")
		{
			std::stringstream sserr;
			sserr << "You said stock name was: " << s1.getName() << std::endl;
			sserr << "I was expecting: Disney" << std::endl;
			FAIL(sserr.str());	
		}

		if (s1.getSymbol() != "DIS")
		{
			std::stringstream sserr;
			sserr << "You said stock symbol was: " << s1.getSymbol() << std::endl;
			sserr << "I was expecting: DIS" << std::endl;
			FAIL(sserr.str());	
		}

		if (s1.getNumShares() != 2.01)
		{
			std::stringstream sserr;
			sserr << "You said number of shares was: " << s1.getNumShares() << std::endl;
			sserr << "I was expecting: 2.01" << std::endl;
			FAIL(sserr.str());	
		}

		if (s1.getCurrPrice() != Money(100, 01))
		{
			std::stringstream sserr;
			sserr << "You said current price was: " << s1.getCurrPrice() << std::endl;
			sserr << "I was expecting: " << Money(100, 01) << std::endl;
			FAIL(sserr.str());	
		}

		if (s1.getPurPrice() != Money(10001))
		{
			std::stringstream sserr;
			sserr << "You said purchase price was: " << s1.getPurPrice() << std::endl;
			sserr << "I was expecting: " << Money(10001) << std::endl;
			FAIL(sserr.str());	
		}

		s1.setCurrentPrice(Money(110001));

		if (s1.getChange() != Money(2009.99))
		{
			std::stringstream sserr;
			sserr << "After setting the price to " << Money(2009.99) <<  
				" you said the change was " << s1.getChange() << std::endl;
			sserr << "I was expecting: " << Money(2009.99) << std::endl;
			FAIL(sserr.str());	
		}
	}

	SECTION("Test << operator | 2")
	{
		Stock s1("Disney", "DIS", Money(10010), 2.01);
		Stock s2("Birkshire", "BRK", Money(200000), 99.2);

		std::stringstream ss1;
		ss1 << s1;
		ss1.flush();
		if (ss1.str() != "DIS : 2.01 @ $100.10")
		{
			std::stringstream sserr;
			sserr << "Stock constructor got: \"Disney\", \"DIS\", Money(10010), 2.01 " << std::endl;
			sserr << "The doing cout << stock gave me: " << ss1.str() << std::endl;
			sserr << "I was expecting: \"DIS : 2.01 @ $100.10\""<< std::endl;
			FAIL(sserr.str());	
		}

		std::stringstream ss2;
		ss2 << s2;
		ss2.flush();
		if (ss2.str() != "BRK : 99.2 @ $2000.00")
		{
			std::stringstream sserr;
			sserr << "Stock constructor got: \"Birkshire\", \"BRK\", Money(200000), 99.2 " << std::endl;
			sserr << "The doing cout << stock gave me: " << ss2.str() << std::endl;
			sserr << "I was expecting: \"BRK : 99.2 @ $2000.00\"" << std::endl;
			FAIL(sserr.str());
		}

	}
}


TEST_CASE("Test PORTFOLIO class", "[graded]")
{
	SECTION("Constructor, getTotalValue | 2")
	{
		StockPortfolio port;

		if (port.getOrigValue() != Money(0) || !(port.getOrigValue() == Money(0)))
		{
			std::stringstream sserr;
			sserr << "An empty portfolio's original value is " << port.getOrigValue() << std::endl;
			sserr << "I was expecting: $0.00" << std::endl;
			FAIL(sserr.str());
		}

	}

	SECTION("Constructor, add stocks, containsStock | 4")
	{
		StockPortfolio port;

		Stock s1("Disney", "DIS", Money(10001), 2.01);
		Stock s2("Birkshire", "BRK", Money(2000001), 1);
		Stock s3("ABC Corp", "ABC", Money(1001), 30);
		Stock s4("XYZ Corp", "XYZ", Money(5001), 5.5);

		port.addStock(s1);
		port.addStock(s2);
		port.addStock(s3);
		port.addStock(s4);

		if (port.containsStock("DIS") != true)
		{
			std::stringstream sserr;
			sserr << "Created a portfolio and added DIS, BRK, ABC, and XYZ " << std::endl;
			sserr << "You said DIS isn't in there" << std::endl;
			FAIL(sserr.str());
		}

		if (port.containsStock("XYZ") != true)
		{
			std::stringstream sserr;
			sserr << "Created a portfolio and added DIS, BRK, ABC, and XYZ " << std::endl;
			sserr << "You said XYZ isn't in there" << std::endl;
			FAIL(sserr.str());
		}

		if (port.containsStock("BOB") != false)
		{
			std::stringstream sserr;
			sserr << "Created a portfolio and added DIS, BRK, ABC, and XYZ " << std::endl;
			sserr << "You said BOB is in there" << std::endl;
			FAIL(sserr.str());

		}

		if (port.containsStock("NATE") != false)
		{
			std::stringstream sserr;
			sserr << "Created a portfolio and added DIS, BRK, ABC, and XYZ " << std::endl;
			sserr << "You said NATE isn't in there" << std::endl;
			FAIL(sserr.str());
		}

	}

	SECTION("Constructor, add stocks, operator[] | 4")
	{
		StockPortfolio port;

		Stock s1("Disney", "DIS", Money(10001), 2.01);
		Stock s2("Birkshire", "BRK", Money(2000001), 1);
		Stock s3("ABC Corp", "ABC", Money(1001), 30);
		Stock s4("XYZ Corp", "XYZ", Money(5001), 5.5);

		port.addStock(s1);
		port.addStock(s2);
		port.addStock(s3);
		port.addStock(s4);

		std::stringstream ss1;
		ss1 << port["DIS"];
		ss1.flush();

		if (ss1.str() != "DIS : 2.01 @ $100.01")
		{
			std::stringstream sserr;
			sserr << "Created a portfolio and tried to fetch stock DIS" << std::endl;
			sserr << "Got: " << ss1.str() << std::endl;
			sserr << "Expected: DIS : 2.01 @ $100.01" << std::endl;
			FAIL(sserr.str());
		}

		port["BRK"].setCurrentPrice(Money(1001));
		std::stringstream ss2;
		ss2 << port["BRK"];
		ss2.flush();

		if (ss2.str() != "BRK : 1 @ $10.01")
		{
			std::stringstream sserr;
			sserr << "Created a portfolio and tried to fetch stock BRK" << std::endl;
			sserr << "Got: " << ss2.str() << std::endl;
			sserr << "Expected: BRK : 1 @ $10.01" << std::endl;
			FAIL(sserr.str());
		}
	}

	SECTION("Constructor, add stocks, getOrigValue | 4")
	{
		StockPortfolio port;

		Stock s1("Disney", "DIS", Money(10001), 2.01);
		Stock s2("Birkshire", "BRK", Money(2000001), 1);
		Stock s3("ABC Corp", "ABC", Money(1001), 30);
		Stock s4("XYZ Corp", "XYZ", Money(5001), 5.5);

		port.addStock(s1);
		port.addStock(s2);
		port.addStock(s3);
		port.addStock(s4);

		if (port.getOrigValue() != Money(2077638) || !(port.getOrigValue() != Money(0)))
		{
			std::stringstream sserr;
			sserr << "You gave an original value of : " << port.getOrigValue() << std::endl;
			sserr << "Expected: " << Money(2077638) << std::endl;
			FAIL(sserr.str());
		}
	}

	SECTION("Constructor, add stocks, operator[], getTotalValue | 4")
	{
		StockPortfolio port;

		Stock s1("Disney", "DIS", Money(10001), 2.01);
		Stock s2("Birkshire", "BRK", Money(2000001), 1);
		Stock s3("ABC Corp", "ABC", Money(1001), 30);
		Stock s4("XYZ Corp", "XYZ", Money(5001), 5.5);

		port.addStock(s1);
		port.addStock(s2);
		port.addStock(s3);
		port.addStock(s4);

		port["DIS"].setCurrentPrice(port["DIS"].getPurPrice() * 2);
		port["BRK"].setCurrentPrice(port["BRK"].getPurPrice() * 2);
		port["ABC"].setCurrentPrice(port["ABC"].getPurPrice() * 2);
		port["XYZ"].setCurrentPrice(port["XYZ"].getPurPrice() * 2);

		if (port.getTotalValue() != Money(4155277) || !(port.getTotalValue() != Money(0)))
		{
			std::stringstream sserr;
			sserr << "You gave an total value of : " << port.getTotalValue() << std::endl;
			sserr << "Expected: " << Money(4155277) << std::endl;
			FAIL(sserr.str());
		}
	}

	SECTION("Constructor, add stocks, operator[], getProfit | 4")
	{
		StockPortfolio port;

		Stock s1("Disney", "DIS", Money(10001), 2.01);
		Stock s2("Birkshire", "BRK", Money(2000001), 1);
		Stock s3("ABC Corp", "ABC", Money(1001), 30);
		Stock s4("XYZ Corp", "XYZ", Money(5001), 5.5);

		port.addStock(s1);
		port.addStock(s2);
		port.addStock(s3);
		port.addStock(s4);

		port["DIS"].setCurrentPrice(port["DIS"].getPurPrice() * 2);
		port["BRK"].setCurrentPrice(port["BRK"].getPurPrice() * 2);
		port["ABC"].setCurrentPrice(port["ABC"].getPurPrice() * 2);
		port["XYZ"].setCurrentPrice(port["XYZ"].getPurPrice() * 2);

		if (port.getProfit() != Money(30925.83) || !(port.getProfit() != Money(0)))
		{
			std::stringstream sserr;
			sserr << "You gave profit as : " << port.getProfit() << std::endl;
			sserr << "Expected: " << Money(30925.83) << std::endl;
			FAIL(sserr.str());
		}
	}

	SECTION("Constructor, add stocks, operator[], getAlphaList | 4")
	{
		StockPortfolio port;

		std::vector<std::string> expectedStockList = { "ABC", "BRK", "DIS", "XYZ" };

		Stock s1("Disney", "DIS", Money(10001), 2.01);
		Stock s2("Birkshire", "BRK", Money(2000001), 1);
		Stock s3("ABC Corp", "ABC", Money(1001), 30);
		Stock s4("XYZ Corp", "XYZ", Money(5001), 5.5);

		port.addStock(s1);
		port.addStock(s2);
		port.addStock(s3);
		port.addStock(s4);

		std::vector<std::string> alphaList = port.getAlphaList();

		if (alphaList.size() != 4)
		{
				std::stringstream sserr;
				sserr << "Alpha list has " << alphaList.size() << " items" << std::endl;
				sserr << "Expected: 4" << std::endl;
				FAIL(sserr.str());
		}

		for (int i = 0; i < expectedStockList.size(); i++)
		{
			if (alphaList[i] != expectedStockList[i])
			{
				std::stringstream sserr;
				sserr << "Alpha list at " << i << " is " << alphaList[i] << std::endl;
				sserr << "Expected: " << expectedStockList[i] << std::endl;
				FAIL(sserr.str());
			}
		}
	}

	SECTION("Constructor, add stocks, operator[], getValueList | 4")
	{
		StockPortfolio port;
		std::vector<std::string> expectedStockList = { "BRK", "DIS", "XYZ", "ABC" };

		Stock s1("Disney", "DIS", Money(10001), 2.01);
		Stock s2("Birkshire", "BRK", Money(2000001), 1);
		Stock s3("ABC Corp", "ABC", Money(1001), 30);
		Stock s4("XYZ Corp", "XYZ", Money(5001), 5.5);

		port.addStock(s1);
		port.addStock(s2);
		port.addStock(s3);
		port.addStock(s4);

		port["DIS"].setCurrentPrice(port["DIS"].getPurPrice() * 2);
		port["BRK"].setCurrentPrice(port["BRK"].getPurPrice() * 2);
		port["ABC"].setCurrentPrice(port["ABC"].getPurPrice() * 2);
		port["XYZ"].setCurrentPrice(port["XYZ"].getPurPrice() * 2);

		std::vector<std::string> valueList = port.getValueList();

		if (valueList.size() != 4)
		{
				std::stringstream sserr;
				sserr << "Value list has " << valueList.size() << " items" << std::endl;
				sserr << "Expected: 4" << std::endl;
				FAIL(sserr.str());
		}

		for (int i = 0; i < expectedStockList.size(); i++)
		{
			if (valueList[i] != expectedStockList[i])
			{
				std::stringstream sserr;
				sserr << "Value list at " << i << " is " << valueList[i] << std::endl;
				sserr << "Expected: " << expectedStockList[i] << std::endl;
				FAIL(sserr.str());
			}
		}
	}

	SECTION("Constructor, add stocks, operator[], getDiffList | 4")
	{
		StockPortfolio port;
		std::vector<std::string> expectedStockList = { "XYZ", "DIS", "ABC", "BRK" };

		Stock s1("Disney", "DIS", Money(10001), 2.01);
		Stock s2("Birkshire", "BRK", Money(2000001), 1);
		Stock s3("ABC Corp", "ABC", Money(1001), 30);
		Stock s4("XYZ Corp", "XYZ", Money(5001), 5.5);

		port.addStock(s1);
		port.addStock(s2);
		port.addStock(s3);
		port.addStock(s4);

		port["DIS"].setCurrentPrice(port["DIS"].getPurPrice() * 2);
		port["BRK"].setCurrentPrice(port["BRK"].getPurPrice() * 0.5);
		port["ABC"].setCurrentPrice(port["ABC"].getPurPrice() * 1.1);
		port["XYZ"].setCurrentPrice(port["XYZ"].getPurPrice() * 5);

		std::vector<std::string> diffList = port.getDiffList();

		if (diffList.size() != 4)
		{
				std::stringstream sserr;
				sserr << "Diff list has " << diffList.size() << " items" << std::endl;
				sserr << "Expected: 4" << std::endl;
				FAIL(sserr.str());
		}

		for (int i = 0; i < expectedStockList.size(); i++)
		{
			if (diffList[i] != expectedStockList[i])
			{
				std::stringstream sserr;
				sserr << "Difference list at " << i << " is " << diffList[i] << std::endl;
				sserr << "Expected: " << expectedStockList[i] << std::endl;
				FAIL(sserr.str());
			}
		}
	}
}

TEST_CASE("Test DRIVER functions", "[graded]")
{
	SECTION("buyStock test | 4")
	{
		StockPortfolio port;

		if (!buyStock(port, "APPL|Apple Inc.|0.11|10000.50"))
		{
			std::stringstream sserr;
			sserr << "Buy stock with input \"APPL|Apple Inc.|0.11|10000.50\" failed!" << std::endl;
			FAIL(sserr.str());
		}

		if (!buyStock(port, "KHC|Kraft Heinz Co.|88.22|10"))
		{
			std::stringstream sserr;
			sserr << "Buy stock with input \"KHC|Kraft Heinz Co.|88.22|10\" failed!" << std::endl;
			FAIL(sserr.str());
		}

		if (port.containsStock("APPL"))
		{
			if ((port["APPL"].getName() != "Apple Inc.") ||
				(port["APPL"].getNumShares() != 10000.5) ||
				(port["APPL"].getCurrPrice() != Money(11)) ||
				(port["APPL"].getPurPrice() != Money(11)) ||
				(port["APPL"].getChange() != Money(0)) ||
				(port["APPL"].getSymbol() != "APPL"))
			{
				std::stringstream sserr;
				sserr << "The stock object created from \"APPL|Apple Inc.|0.11|10000.50\" isn't correct!" << std::endl;
				FAIL(sserr.str());
			}
		}
		else
		{
			std::stringstream sserr;
			sserr << "The portfolio is missing the stock created from \"APPL|Apple Inc.|0.11|10000.50\"" << std::endl;
			FAIL(sserr.str());
		}

		if (port.containsStock("KHC"))
		{
			if ((port["KHC"].getName() != "Kraft Heinz Co.") ||
				(port["KHC"].getNumShares() != 10) ||
				(port["KHC"].getCurrPrice() != Money(8822)) ||
				(port["KHC"].getPurPrice() != Money(8822)) ||
				(port["KHC"].getChange() != Money(0)) ||
				(port["KHC"].getSymbol() != "KHC"))
			{
				std::stringstream sserr;
				sserr << "The stock object created from \"KHC|Kraft Heinz Co.|88.22|10\" isn't correct!" << std::endl;
				FAIL(sserr.str());
			}
		}
		else
		{
			std::stringstream sserr;
			sserr << "The the portfolio is missing the stock created from \"APPL|Apple Inc.|0.11|10000.50\"" << std::endl;
			FAIL(sserr.str());

		}
	}

	SECTION("updateStock test | 4")
	{
		StockPortfolio port;

		if (!buyStock(port, "APPL|Apple Inc.|0.11|10000.50"))
		{
			std::stringstream sserr;
			sserr << "Buy stock with input \"APPL|Apple Inc.|0.11|10000.50\" failed!" << std::endl;
			FAIL(sserr.str());
		}

		if (!buyStock(port, "KHC|Kraft Heinz Co.|88.22|10"))
		{
			std::stringstream sserr;
			sserr << "Buy stock with input \"KHC|Kraft Heinz Co.|88.22|10\" failed!" << std::endl;
			FAIL(sserr.str());
		}

		if (updateStock(port, "BTI|38.03"))
		{
			std::stringstream sserr;
			sserr << "Was able to update the stock BTI, but it shouldn't exist!" << std::endl;
			FAIL(sserr.str());
		}

		if (!updateStock(port, "APPL|135.43"))
		{
			std::stringstream sserr;
			sserr << "Update stock with \"APPL|135.43\" failed!" << std::endl;
			FAIL(sserr.str());
		}

		if (port.containsStock("APPL"))
		{
			if ((port["APPL"].getName() != "Apple Inc.") ||
				(port["APPL"].getNumShares() != 10000.5) ||
				(port["APPL"].getCurrPrice() != Money(13543)) ||
				(port["APPL"].getPurPrice() != Money(11)) ||
				(port["APPL"].getChange() != Money(135326766)) ||
				(port["APPL"].getSymbol() != "APPL"))
			{
				std::stringstream sserr;
				sserr << port["APPL"].getChange() << std::endl;
				sserr << "Updating the stock with \"APPL|135.43\" isn't correct!" << std::endl;
				FAIL(sserr.str());
			}
		}
		else
		{
			std::stringstream sserr;
			sserr << "After updating the stock with \"APPL|135.43\", it's missing in the portfolio!" << std::endl;
			FAIL(sserr.str());
		}
	}

	SECTION("processFile test | 4")
	{
		StockPortfolio port;

		if (!processFile(port, "input/test01.txt"))
		{
			std::stringstream sserr;
			sserr << "Wasn't able to process the file \"input/test01.txt\"" << std::endl;
			FAIL(sserr.str());
		}

		// Check for non-existant stock
		if (port.containsStock("ABC"))
		{
			std::stringstream sserr;
			sserr << "Reporting stock \"ABC\" is there, but shouldn't be." << std::endl;
			FAIL(sserr.str());
		}

		// Check an updated stock
		if (port.containsStock("APPL"))
		{
			if ((port["APPL"].getName() != "Apple Inc.") ||
				(port["APPL"].getNumShares() != 10000) ||
				(port["APPL"].getCurrPrice() != Money(13543)) ||
				(port["APPL"].getPurPrice() != Money(11)) ||
				(port["APPL"].getChange() != Money(135320000)) ||
				(port["APPL"].getSymbol() != "APPL"))
			{
				std::stringstream sserr;
				sserr << port["APPL"].getChange() << std::endl;
				sserr << "Apple stock is listed incorrectly." << std::endl;
				FAIL(sserr.str());
			}
		}
		else
		{
			std::stringstream sserr;
			sserr << "Apple stock is missing!" << std::endl;
			FAIL(sserr.str());
		}

		// Check an updated stock
		if (port.containsStock("BRK.A"))
		{
			if ((port["BRK.A"].getName() != "Berkshire Hathaway Inc. Cl A") ||
				(port["BRK.A"].getNumShares() != 11) ||
				(port["BRK.A"].getCurrPrice() != Money(365500.00)) ||
				(port["BRK.A"].getPurPrice() != Money(130700)) ||
				(port["BRK.A"].getChange() != Money(400612300)) ||
				(port["BRK.A"].getSymbol() != "BRK.A"))
			{
				std::stringstream sserr;
				sserr << port["BRK.A"].getChange() << std::endl;
				sserr << "Berkshire stock is listed incorrectly." << std::endl;
				FAIL(sserr.str());
			}
		}
		else
		{
			std::stringstream sserr;
			sserr << "Birkshire stock is missing!" << std::endl;
			FAIL(sserr.str());
		}

		// Check an regular stock
		if (port.containsStock("MDLZ"))
		{
			if ((port["MDLZ"].getName() != "Mondelez International Inc. Cl A") ||
				(port["MDLZ"].getNumShares() != 30) ||
				(port["MDLZ"].getCurrPrice() != Money(31.07)) ||
				(port["MDLZ"].getPurPrice() != Money(31.07)) ||
				(port["MDLZ"].getChange() != Money(0)) ||
				(port["MDLZ"].getSymbol() != "MDLZ"))
			{
				std::stringstream sserr;
				sserr << port["MDLZ"].getChange() << std::endl;
				sserr << "Mondelez stock is listed incorrectly." << std::endl;
				FAIL(sserr.str());
			}
		}
		else
		{
			std::stringstream sserr;
			sserr << "Mondelez stock is missing!" << std::endl;
			FAIL(sserr.str());
		}
	}
}
