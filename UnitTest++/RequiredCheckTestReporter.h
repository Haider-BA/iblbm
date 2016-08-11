#ifndef UNITTEST_REQUIRED_CHECK_TEST_REPORTER_H
#define UNITTEST_REQUIRED_CHECK_TEST_REPORTER_H

#include "HelperMacros.h"
#include "ThrowingTestReporter.h"

namespace UnitTest {

   class TestResults;

   // This RAII class decorates the current TestReporter with
   // a version that throws after reporting a failure.
   class UNITTEST_LINKAGE RequiredCheckTestReporter
   {
   public:
      explicit RequiredCheckTestReporter(TestResults& results);
      ~RequiredCheckTestReporter();
      RequiredCheckTestReporter(const RequiredCheckTestReporter&) = delete;
      RequiredCheckException operator=(const RequiredCheckTestReporter&) =
          delete;

      bool Next();

   private:
      TestResults& m_results;
      TestReporter* m_originalTestReporter;
      ThrowingTestReporter m_throwingReporter;
      int m_continue;
   };
}

#endif

