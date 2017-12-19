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

class removeTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(removeTest);
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

void removeTest::test1(void) /* chemin vert et bleu tester ensemble 
car il n'est pas possible d'incrementer la boucle*/
{
	vec->push_back("test");
	vec->push_back("test");
     CPPUNIT_ASSERT(true==vec->remove(1));
}

void removeTest::test2(void) // chemin rouge
{
	vec->push_back("test");
	vec->push_back("test");
     CPPUNIT_ASSERT(false==vec->remove(-1));
}

void removeTest::test3(void)  // chemin jaune
{  vec->push_back("test");
	vec->push_back("test");
   CPPUNIT_ASSERT(false==vec->remove(3));
}




void removeTest::setUp(void) 
{
    vec = new Vector();
}

void removeTest::tearDown(void) 
{
    delete vec;
}
