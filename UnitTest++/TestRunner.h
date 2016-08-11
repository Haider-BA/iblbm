#ifndef UNITTEST_TESTRUNNER_H
#define UNITTEST_TESTRUNNER_H

#include "Test.h"
#include "TestList.h"
#include "CurrentTest.h"

namespace UnitTest {

   class TestReporter;
   class TestResults;
   class Timer;

   UNITTEST_LINKAGE int RunAllTests();

   struct True
   {
      bool operator()(const Test* const) const
      {
         return true;
      }
   };

   class UNITTEST_LINKAGE TestRunner
   {
   public:
      explicit TestRunner(TestReporter& reporter);
      ~TestRunner();
      TestRunner(const TestRunner&) = delete;
      TestRunner& operator=(const TestRunner&) = delete;

      template< class Predicate >
      int RunTestsIf(TestList const& list, char const* suiteName,
                     const Predicate& predicate, int maxTestTimeInMs) const
      {
         Test* curTest = list.GetHead();

         while (curTest != nullptr)
         {
            if (IsTestInSuite(curTest, suiteName) && predicate(curTest))
               RunTest(m_result, curTest, maxTestTimeInMs);

            curTest = curTest->m_nextTest;
         }

         return Finish();
      }

      TestResults* GetTestResults();

   private:
      TestReporter* m_reporter;
      TestResults* m_result;
      Timer* m_timer;

      int Finish() const;
      bool IsTestInSuite(const Test* const curTest, char const* suiteName) const;
      void RunTest(TestResults* const result, Test* const curTest, int const maxTestTimeInMs) const;
   };

}

#endif
