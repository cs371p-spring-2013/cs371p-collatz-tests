// --------------------------------
// projects/collatz/TestCollatz.c++
// Copyright (C) 2013
// Glenn P. Downing
// --------------------------------

/*
To test the program:
    % ls /usr/include/cppunit/
    ...
    TestFixture.h
    ...
    % locate libcppunit.a
    /usr/lib/libcppunit.a
    % g++ -lcppunit -ldl -pedantic -std=c++0x -Wall Collatz.c++ TestCollatz.c++ -o TestCollatz.c++.app
    % valgrind TestCollatz.c++.app >& TestCollatz.c++.out
*/

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TextTestRunner

#include "Collatz.h"

// -----------
// TestCollatz
// -----------

struct TestCollatz : CppUnit::TestFixture {
    // ----
    // read
    // ----

    void test_read () {
        std::istringstream r("1 10\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    1);
        CPPUNIT_ASSERT(j ==   10);}

    /////////////// My tests ////////////////////////////////////////////////
    void test_read_1 () {
        std::istringstream r("er65\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == false); }

    void test_read_2 () {
        std::istringstream r("28 91 456\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==   28);
        CPPUNIT_ASSERT(j ==   91);}

    void test_read_3 () {
        std::istringstream r("xcg 10000\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == false); }

    // ----
    // eval
    // ----

    void test_eval_1 () {
        const int v = collatz_eval(1, 10);
        CPPUNIT_ASSERT(v == 20);}

    void test_eval_2 () {
        const int v = collatz_eval(100, 200);
        CPPUNIT_ASSERT(v == 125);}

    void test_eval_3 () {
        const int v = collatz_eval(201, 210);
        CPPUNIT_ASSERT(v == 89);}

    void test_eval_4 () {
        const int v = collatz_eval(900, 1000);
        CPPUNIT_ASSERT(v == 174);}

    /////////////// My tests ////////////////////////////////////////////////

    void test_eval_5 () {
        const int v = collatz_eval(466118, 22391);
        CPPUNIT_ASSERT(v == 449);
    }

    void test_eval_6 () {
        const int v = collatz_eval(723140, 665356);
        CPPUNIT_ASSERT(v == 442);
    }

    void test_eval_7 () {
        const int v = collatz_eval(176212, 703603);
        CPPUNIT_ASSERT(v == 470);
    }

    // -----
    // print
    // -----

    void test_print () {
        std::ostringstream w;
        collatz_print(w, 1, 10, 20);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n");}

    /////////////// My tests ////////////////////////////////////////////////

    void test_print_1 () {
        std::ostringstream w;
        collatz_print(w, 419649, 274866, 449);
        CPPUNIT_ASSERT(w.str() == "419649 274866 449\n");}

    void test_print_2 () {
        std::ostringstream w;
        collatz_print(w, 545558, 133397, 470);
        CPPUNIT_ASSERT(w.str() == "545558 133397 470\n");}

    void test_print_3 () {
        std::ostringstream w;
        collatz_print(w, 112113, 856186, 470);
        CPPUNIT_ASSERT(w.str() == "112113 856186 470\n");}

    // -----
    // solve
    // -----

    void test_solve () {
        std::istringstream r("1 10\n100 200\n201 210\n900 1000\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n100 200 125\n201 210 89\n900 1000 174\n");}

    /////////////// My tests ////////////////////////////////////////////////

    void test_solve_1 () {
        std::istringstream r("291187 931732\n694458 638629\n749750 238759\n886105 762141\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "291187 931732 525\n694458 638629 442\n749750 238759 470\n886105 762141 525\n");}

    void test_solve_2 () {
        std::istringstream r("517245 642610\n203387 491377\n369473 521161\n899807 515893\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "517245 642610 452\n203387 491377 449\n369473 521161 470\n899807 515893 525\n");}

    void test_solve_3 () {
        std::istringstream r("181905 384966\n89476 457039\n5246 595889\n702861 958155\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "181905 384966 443\n89476 457039 449\n5246 595889 470\n702861 958155 525\n");}

    /////////////// My tests ////////////////////////////////////////////////

    void test_cycleLength_1() {
        const int v = collatz_cycleLength(5);
        CPPUNIT_ASSERT(v == 6);
    }

    void test_cycleLength_2() {
        const int v = collatz_cycleLength(10);
        CPPUNIT_ASSERT(v == 7);
    }

    void test_cycleLength_3() {
        const int v = collatz_cycleLength(20);
        CPPUNIT_ASSERT(v == 8);
    }

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestCollatz);
    CPPUNIT_TEST(test_read);

    // My tests
    CPPUNIT_TEST(test_read_1);
    CPPUNIT_TEST(test_read_2);
    CPPUNIT_TEST(test_read_3);

    CPPUNIT_TEST(test_eval_1);
    CPPUNIT_TEST(test_eval_2);
    CPPUNIT_TEST(test_eval_3);
    CPPUNIT_TEST(test_eval_4);

    // My tests
    CPPUNIT_TEST(test_eval_5);
    CPPUNIT_TEST(test_eval_6);
    CPPUNIT_TEST(test_eval_7);

    CPPUNIT_TEST(test_print);

    // My tests
    CPPUNIT_TEST(test_print_1);
    CPPUNIT_TEST(test_print_2);
    CPPUNIT_TEST(test_print_3);

    CPPUNIT_TEST(test_solve);

    // My tests
    CPPUNIT_TEST(test_solve_1);
    CPPUNIT_TEST(test_solve_2);
    CPPUNIT_TEST(test_solve_3);

    // My tests
    CPPUNIT_TEST(test_cycleLength_1);
    CPPUNIT_TEST(test_cycleLength_2);
    CPPUNIT_TEST(test_cycleLength_3);

    CPPUNIT_TEST_SUITE_END();};

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);  // turn off synchronization with C I/O
    cout << "TestCollatz.c++" << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest(TestCollatz::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;}
