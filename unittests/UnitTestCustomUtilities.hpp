// Unfit: Data fitting and optimization software
//
// Copyright (C) 2012- Dr Martin Buist & Dr Alberto Corrias
// Contacts: martin.buist _at_ nus.edu.sg; alberto _at_ nus.edu.sg
//
// See the 'Contributors' file for a list of those who have contributed
// to this work.
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
#ifndef UNFIT_UNITTESTS_UNITTESTCUSTOMUTILITIES_HPP_
#define UNFIT_UNITTESTS_UNITTESTCUSTOMUTILITIES_HPP_

#include <algorithm>
#include <string>
#include <vector>

#include "UnitTest++.h"
#include "TestReporterStdout.h"

namespace Unfit
{
/**
 * \brief Runs all the tests it finds in the project.
 *        it calls RunAllTests() within UnitTests++
 *
 *  Behaviours:
 *    it runs all the test it finds. See documentation of UnitTest::RunAllTests()
 *  Intended use:
 *    int return_code = RunAllTheTests();
 *  Parameters:
 *    None
 *  Return:
 *    \return the return code of UnitTest::RunAllTests()
 *
 */
inline int RunAllTheTests()
{
  return UnitTest::RunAllTests();
}

#define COVERAGE_IGNORE
/**
 * \brief Runs only one test specified by the name.
 *        It runs nothing if the test does not exists.
 *
 *  Behaviours:
 *
 *    it runs one test in isolation.
 *
 *  Intended use (assuming you have TEST(name_of_my_test) among your tests):
 *
 *    int return_code = RunOneTest("name_of_my_test");
 *
 *  Parameters:
 *    \param TestName the name of the test you wish to run
 *  Return:
 *    \return the return code of UnitTest::RunTestsIf()
 *
 */
inline int RunOneTest(std::string TestName)
{
  const UnitTest::TestList& allTests(UnitTest::Test::GetTestList());
  UnitTest::TestList selectedTests;
  UnitTest::Test* p = allTests.GetHead();

  while (p) {
    if (p->m_details.testName == TestName) {
      selectedTests.Add(p);
    }
    UnitTest::Test* q = p;
    p = p->m_nextTest;
    q->m_nextTest = NULL;
  }

  UnitTest::TestReporterStdout reporter;
  UnitTest::TestRunner runner(reporter);

  return runner.RunTestsIf(selectedTests, 0, UnitTest::True(), 0);
}

/**
 * \brief Runs only one test suite (all the tests in the suite) specified by the name.
 *        It runs nothing if the suite does not exists.
 *
 *  Behaviours:
 *      it runs one suite in isolation
 *  Intended use:
 *      int return_code = RunOneSuite("name_of_my_suite");
 *
 *  Parameters:
 *    \param SuiteName the name of the suite you wish to run
 *  Return:
 *    \return the return code of UnitTest::RunTestsIf()
 *
 */
inline int RunOneSuite(std::string SuiteName)
{
  const UnitTest::TestList& allTests(UnitTest::Test::GetTestList());
  UnitTest::TestList selectedTests;
  UnitTest::Test* p = allTests.GetHead();

  while (p) {
    if (p->m_details.suiteName == SuiteName) {
      selectedTests.Add(p);
    }
    UnitTest::Test* q = p;
    p = p->m_nextTest;
    q->m_nextTest = NULL;
  }

  UnitTest::TestReporterStdout reporter;
  UnitTest::TestRunner runner(reporter);

  return runner.RunTestsIf(selectedTests, 0, UnitTest::True(), 0 );
}

/**
 * \brief Runs multiple tests specified by the names.
 *        It runs nothing if all of the tests do not exist.
 *
 *  Behaviours:
 *
 *    it runs multiple tests in isolation.
 *
 *  Intended use (assuming you have TEST(name_of_my_test) among your tests):
 *
 *    int return_code = RunOneTest(name_of_my_tests);
 *
 *  Parameters:
 *    \param TestName A vector containing the names of the tests you wish to run
 *  Return:
 *    \return the return code of UnitTest::RunTestsIf()
 *
 */
inline int RunMultipleTests(std::vector<std::string> test_names)
{
  const UnitTest::TestList& allTests(UnitTest::Test::GetTestList());
  UnitTest::TestList selectedTests;
  UnitTest::Test* p = allTests.GetHead();

  while (p) {
    auto is_desired_test = std::find(begin(test_names), end(test_names),
      p->m_details.testName) != end(test_names);
    if (is_desired_test) {
      selectedTests.Add(p);
    }
    UnitTest::Test* q = p;
    p = p->m_nextTest;
    q->m_nextTest = NULL;
  }

  UnitTest::TestReporterStdout reporter;
  UnitTest::TestRunner runner(reporter);

  return runner.RunTestsIf(selectedTests, 0, UnitTest::True(), 0);
}

/**
 * Runs only multiple test suites (all the tests in the suites) specified by the
 * names.
 * It runs nothing if none of the suites exists.
 *
 *  Behaviours:
 *      it runs multiple suites
 *  Intended use:
 *      int return_code = RunMultipleSuites(names_of_my_suites);
 *
 *  Parameters:
 *    \param suite_names The names of the suites you wish to run
 *  Return:
 *    \return the return code of UnitTest::RunTestsIf()
 *
 */
inline int RunMultipleSuites(std::vector<std::string> suite_names)
{
  const UnitTest::TestList& allTests(UnitTest::Test::GetTestList());
  UnitTest::TestList selectedTests;
  UnitTest::Test* p = allTests.GetHead();

  while (p) {
    auto is_desired_suite = std::find(begin(suite_names), end(suite_names),
        p->m_details.suiteName) != end(suite_names);
    if (is_desired_suite) {
      selectedTests.Add(p);
    }
    UnitTest::Test* q = p;
    p = p->m_nextTest;
    q->m_nextTest = NULL;
  }

  UnitTest::TestReporterStdout reporter;
  UnitTest::TestRunner runner(reporter);

  return runner.RunTestsIf(selectedTests, 0, UnitTest::True(), 0 );
}
#undef COVERAGE_IGNORE

}  // namespace Unfit

#endif
