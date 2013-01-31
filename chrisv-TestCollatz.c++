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

    void test_read_1 () {
        std::istringstream r("1 10\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    1);
        CPPUNIT_ASSERT(j ==   10);
    }

    void test_read_2 () {
        std::istringstream r("90 99\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    90);
        CPPUNIT_ASSERT(j ==   99);
    }

    void test_read_3 () {
        std::istringstream r("1234 18923\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    1234);
        CPPUNIT_ASSERT(j ==   18923);
    }

    void test_read_4 () {
        std::istringstream r("11234 98\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    11234);
        CPPUNIT_ASSERT(j ==   98);
    }

    // ----
    // MaxNum
    // ----

    void test_max_num_1 () {
        int i = 1;
        int j = 10;
        const int result = GetMaxNumber(i, j);
        CPPUNIT_ASSERT(result == 10);
    }

    void test_max_num_2 () {
        int i = 999;
        int j = 999;
        const int result = GetMaxNumber(i, j);
        CPPUNIT_ASSERT(result == 999);
    }

    void test_max_num_3 () {
        int i = 1234123;
        int j = 5234;
        const int result = GetMaxNumber(i, j);
        CPPUNIT_ASSERT(result == 1234123);
    }

    void test_max_num_4 () {
        int i = 2934857;
        int j = 230495;
        const int result = GetMaxNumber(i, j);
        CPPUNIT_ASSERT(result == 2934857);
    }
    // ----
    // RunCollatz
    // ----

    void test_RunCollatz_1 () {
        int i = 5;
        int cache[1000000];
        const int result = RunCollatz(i, cache);
        CPPUNIT_ASSERT(result == 6);
    }

    void test_RunCollatz_2 () {
        int i = 10;
        int cache[1000000];
        const int result = RunCollatz(i, cache);
        CPPUNIT_ASSERT(result == 7);
    }

    void test_RunCollatz_3 () {
        int i = 999;
        int cache[1000000];
        const int result = RunCollatz(i, cache);
        CPPUNIT_ASSERT(result == 50);
    }

    void test_RunCollatz_4 () {
        int i = 999999;
        int cache[1000000];
        const int result = RunCollatz(i, cache);
        CPPUNIT_ASSERT(result == 259);
    }

    // ----
    // eval
    // ----

    void test_eval_1 () {
        const int v = collatz_eval(1, 10);
        CPPUNIT_ASSERT(v == 20);
    }

    void test_eval_2 () {
        const int v = collatz_eval(100, 200);
        CPPUNIT_ASSERT(v == 125);
    }

    void test_eval_3 () {
        const int v = collatz_eval(201, 210);
        CPPUNIT_ASSERT(v == 89);
    }

    void test_eval_4 () {
        const int v = collatz_eval(900, 1000);
        CPPUNIT_ASSERT(v == 174);
    }

    // -----
    // print
    // -----

    void test_print_1 () {
        std::ostringstream w;
        collatz_print(w, 1, 10, 20);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n");
    }

    void test_print_2 () {
        std::ostringstream w;
        collatz_print(w, 571843, 691242, 509);
        CPPUNIT_ASSERT(w.str() == "571843 691242 509\n");
    }

    void test_print_3 () {
        std::ostringstream w;
        collatz_print(w, 490761, 970665, 525);
        CPPUNIT_ASSERT(w.str() == "490761 970665 525\n");
    }

    void test_print_4 () {
        std::ostringstream w;
        collatz_print(w, 16624, 412472, 449);
        CPPUNIT_ASSERT(w.str() == "16624 412472 449\n");
    }

    // -----
    // solve
    // -----

    void test_solve_1 () {
        std::istringstream r("1 10\n100 200\n201 210\n900 1000\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n100 200 125\n201 210 89\n900 1000 174\n");
    }

    void test_solve_2 () {
        std::istringstream r("207246 786116\n427604 992021\n684715 767811\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "207246 786116 470\n427604 992021 476\n684715 767811 442\n");
    }

    void test_solve_3 () {
        std::istringstream r("76 23\n234 2345\n13 653\n123 123\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "76 23 116\n234 2345 183\n13 653 145\n123 123 47\n");
    }

    void test_solve_4 () {
        std::istringstream r("567 35\n356 245\n98 976\n0008 234\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "567 35 144\n356 245 144\n98 976 179\n8 234 128\n");
    }

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestCollatz);
    CPPUNIT_TEST(test_read_1);
    CPPUNIT_TEST(test_read_2);
    CPPUNIT_TEST(test_read_3);
    CPPUNIT_TEST(test_read_4);
    CPPUNIT_TEST(test_max_num_1);
    CPPUNIT_TEST(test_max_num_2);
    CPPUNIT_TEST(test_max_num_3);
    CPPUNIT_TEST(test_max_num_4);
    CPPUNIT_TEST(test_RunCollatz_1);
    CPPUNIT_TEST(test_RunCollatz_2);
    CPPUNIT_TEST(test_RunCollatz_3);
    CPPUNIT_TEST(test_RunCollatz_4);
    CPPUNIT_TEST(test_eval_1);
    CPPUNIT_TEST(test_eval_2);
    CPPUNIT_TEST(test_eval_3);
    CPPUNIT_TEST(test_eval_4);
    CPPUNIT_TEST(test_print_1);
    CPPUNIT_TEST(test_print_2);
    CPPUNIT_TEST(test_print_3);
    CPPUNIT_TEST(test_print_4);
    CPPUNIT_TEST(test_solve_1);
    CPPUNIT_TEST(test_solve_2);
    CPPUNIT_TEST(test_solve_3);
    CPPUNIT_TEST(test_solve_4);
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
