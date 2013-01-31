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
        CPPUNIT_ASSERT(j ==   10);}

    void test_read_2 () {
        std::istringstream r("3 20\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    3);
        CPPUNIT_ASSERT(j ==   20);}

    void test_read_3 () {
        std::istringstream r("999999 1000000\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    999999);
        CPPUNIT_ASSERT(j ==   1000000);}

    void test_read_4 () {
        std::istringstream r("38743 99352\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    38743);
        CPPUNIT_ASSERT(j ==   99352);}

    void test_read_5 () {
        std::istringstream r("1 873999\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    1);
        CPPUNIT_ASSERT(j ==   873999);}

    // ----
    // eval
    // ----

    void test_eval_0 () {
        const int v = collatz_eval(1, 2);
        CPPUNIT_ASSERT(v == 2);}

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

    void test_eval_5 () {
        const int v = collatz_eval(1, 1000000);
        CPPUNIT_ASSERT(v == 525);}

    void test_eval_6 () {
        const int v = collatz_eval(500000, 1000000);
        CPPUNIT_ASSERT(v == 525);}

    void test_eval_7 () {
        const int v = collatz_eval(1, 500000);
        CPPUNIT_ASSERT(v == 449);}

    void test_eval_8 () {
        const int v = collatz_eval(1, 100);
        CPPUNIT_ASSERT(v == 119);}

    // -----
    // print
    // -----

    void test_print_1 () {
        std::ostringstream w;
        collatz_print(w, 1, 10, 20);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n");}

    void test_print_2 () {
        std::ostringstream w;
        collatz_print(w, 1, 1000000, 525);
        CPPUNIT_ASSERT(w.str() == "1 1000000 525\n");}

    void test_print_3 () {
        std::ostringstream w;
        collatz_print(w, 24938, 47396, 309);
        CPPUNIT_ASSERT(w.str() == "24938 47396 309\n");}

    void test_print_4 () {
        std::ostringstream w;
        collatz_print(w, 100, 1000, 174);
        CPPUNIT_ASSERT(w.str() == "100 1000 174\n");}

    // -----
    // solve
    // -----

    void test_solve_1 () {
        std::istringstream r("1 10\n100 200\n201 210\n900 1000\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n100 200 125\n201 210 89\n900 1000 174\n");}

    void test_solve_2 () {
        std::istringstream r("1 1000000\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 1000000 525\n");}

    void test_solve_3 () {
        std::istringstream r("1 100\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 100 119\n");}

    void test_solve_4 () {
        std::istringstream r("1 500000\n500000 1000000\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 500000 449\n500000 1000000 525\n");}

    void test_solve_5 () {
        std::istringstream r("1 1\n1 200\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 1 1\n1 200 125\n");}

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestCollatz);
    CPPUNIT_TEST(test_read_1);
	CPPUNIT_TEST(test_read_2);
	CPPUNIT_TEST(test_read_3);
	CPPUNIT_TEST(test_read_4);
	CPPUNIT_TEST(test_read_5);
	CPPUNIT_TEST(test_eval_0);
    CPPUNIT_TEST(test_eval_1);
    CPPUNIT_TEST(test_eval_2);
    CPPUNIT_TEST(test_eval_3);
    CPPUNIT_TEST(test_eval_4);
	CPPUNIT_TEST(test_eval_5);
	CPPUNIT_TEST(test_eval_6);
	CPPUNIT_TEST(test_eval_7);
	CPPUNIT_TEST(test_eval_8);
    CPPUNIT_TEST(test_print_1);
    CPPUNIT_TEST(test_print_2);
    CPPUNIT_TEST(test_print_3);
    CPPUNIT_TEST(test_print_4);
    CPPUNIT_TEST(test_solve_1);
    CPPUNIT_TEST(test_solve_2);
    CPPUNIT_TEST(test_solve_3);
    CPPUNIT_TEST(test_solve_4);
    CPPUNIT_TEST(test_solve_5);
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
