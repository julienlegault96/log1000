#include <string>
#include <list>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include <netinet/in.h>

#include "../Vector.h"

using namespace CppUnit;
using namespace std;

//-----------------------------------------------------------------------------

class insertTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(insertTest);
    CPPUNIT_TEST(test1);
    CPPUNIT_TEST(test2);
    CPPUNIT_TEST(test3);
    CPPUNIT_TEST_SUITE_END();
    
public:
    void setUp(void);
    void tearDown(void);
    
protected:
    void test1(void);
    void test2(void);
    void test3(void);
    
private:
    
    Vector *vec;
};

// ------------------------ IMPLEMENTATION ------------------------
/* Comme nous ne connaissons pas la capacité, nous assumons quelle
est supérieure au count et pouvons ainsi regrouper certains chemins*/

void insertTest::test1(void) // bleu et vert 
{
	vec->push_back("test");
	CPPUNIT_ASSERT(false==vec->insert(-1,"test"));
}

void insertTest::test2(void) // jaune et rouge
{
	vec->push_back("test");
   CPPUNIT_ASSERT(false==vec->insert(2,"test"));
}

void insertTest::test3(void) // rose et cyan
{
    vec->push_back("test");
   CPPUNIT_ASSERT(true==vec->insert(0,"test"));
}

void insertTest::setUp(void)
{
	
		vec = new Vector();
}

void insertTest::tearDown(void)
{
    delete vec;
}
