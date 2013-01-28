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

    void test_read2 () {
        std::istringstream r("10 3\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==   10);
        CPPUNIT_ASSERT(j ==    3);}

    void test_read3 () {
        std::istringstream r("1 1000000\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b ==    true);
        CPPUNIT_ASSERT(i ==       1);
        CPPUNIT_ASSERT(j == 1000000);}

    void test_read4 () {
        std::istringstream r("3 3\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    3);
        CPPUNIT_ASSERT(j ==    3);}

    // ----
    // find
    // ----

    void test_find_1 () {
        const int v = collatz_find(1);
        CPPUNIT_ASSERT(v == 1);}

    void test_find_2 () {
        const int v = collatz_find(1000000);
        CPPUNIT_ASSERT(v == 153);}

    void test_find_3 () {
        const int v = collatz_find(3);
        CPPUNIT_ASSERT(v == 8);}

    void test_find_4 () {
        const int v = collatz_find(22);
        CPPUNIT_ASSERT(v == 16);}

    // ----
    // check_cache
    // ----

    void test_check_cache_1 () {
        const int v = collatz_check_cache(0,2);
        CPPUNIT_ASSERT(v == 217);}

    void test_check_cache_2 () {
        const int v = collatz_check_cache(5,5);
        CPPUNIT_ASSERT(v == 236);}

    void test_check_cache_3 () {
        const int v = collatz_check_cache(998,999);
        CPPUNIT_ASSERT(v == 396);}

    void test_check_cache_4 () {
        const int v = collatz_check_cache(0,999);
        CPPUNIT_ASSERT(v == 525);}

    void test_check_cache_5 () {
        const int v = collatz_check_cache(998,997);
        CPPUNIT_ASSERT(v == 0);}

    void test_check_cache_6 () {
        const int v = collatz_check_cache(0,-1);
        CPPUNIT_ASSERT(v == 0);}

    void test_check_cache_7 () {
        const int v = collatz_check_cache(1000,999);
        CPPUNIT_ASSERT(v == 0);}

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

    void test_eval_5 () {
        const int v = collatz_eval(1, 1000000);
        CPPUNIT_ASSERT(v == 525);}

    void test_eval_6 () {
        const int v = collatz_eval(3, 3);
        CPPUNIT_ASSERT(v == 8);}

    void test_eval_7 () {
        const int v = collatz_eval(10, 1);
        CPPUNIT_ASSERT(v == 20);}

    void test_eval_8 () {
        const int v = collatz_eval(9000, 10000);
        CPPUNIT_ASSERT(v == 260);}

    // -----
    // print
    // -----

    void test_print () {
        std::ostringstream w;
        collatz_print(w, 1, 10, 20);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n");}

    void test_print2 () {
        std::ostringstream w;
        collatz_print(w, 1, 1000000, 525);
        CPPUNIT_ASSERT(w.str() == "1 1000000 525\n");}

    void test_print3 () {
        std::ostringstream w;
        collatz_print(w, 3, 3, 8);
        CPPUNIT_ASSERT(w.str() == "3 3 8\n");}

    void test_print4 () {
        std::ostringstream w;
        collatz_print(w, 10, 1, 20);
        CPPUNIT_ASSERT(w.str() == "10 1 20\n");}

    // -----
    // solve
    // -----

    void test_solve () {
        std::istringstream r("1 10\n100 200\n201 210\n900 1000\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n100 200 125\n201 210 89\n900 1000 174\n");}

    void test_solve2 () {
        std::istringstream r("\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "");}

    void test_solve3 () {
        std::istringstream r("10 1\n200 100\n210 201\n1000 900\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "10 1 20\n200 100 125\n210 201 89\n1000 900 174\n");}

    void test_solve4 () {
        std::istringstream r("1 1000000\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 1000000 525\n");}

    void test_solve5 () {
        std::istringstream r("630606 498361\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "630606 498361 470\n");}

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestCollatz);
    CPPUNIT_TEST(test_read);
    CPPUNIT_TEST(test_read2);
    CPPUNIT_TEST(test_read3);
    CPPUNIT_TEST(test_read4);
    CPPUNIT_TEST(test_find_1);
    CPPUNIT_TEST(test_find_2);
    CPPUNIT_TEST(test_find_3);
    CPPUNIT_TEST(test_find_4);
    CPPUNIT_TEST(test_check_cache_1);
    CPPUNIT_TEST(test_check_cache_2);
    CPPUNIT_TEST(test_check_cache_3);
    CPPUNIT_TEST(test_check_cache_4);
    CPPUNIT_TEST(test_check_cache_5);
    CPPUNIT_TEST(test_check_cache_6);
    CPPUNIT_TEST(test_check_cache_7);
    CPPUNIT_TEST(test_eval_1);
    CPPUNIT_TEST(test_eval_2);
    CPPUNIT_TEST(test_eval_3);
    CPPUNIT_TEST(test_eval_4);
    CPPUNIT_TEST(test_eval_5);
    CPPUNIT_TEST(test_eval_6);
    CPPUNIT_TEST(test_eval_7);
    CPPUNIT_TEST(test_eval_8);
    CPPUNIT_TEST(test_print);
    CPPUNIT_TEST(test_print2);
    CPPUNIT_TEST(test_print3);
    CPPUNIT_TEST(test_print4);
    CPPUNIT_TEST(test_solve);
    CPPUNIT_TEST(test_solve2);
    CPPUNIT_TEST(test_solve3);
    CPPUNIT_TEST(test_solve4);
    CPPUNIT_TEST(test_solve5);
    CPPUNIT_TEST_SUITE_END();};

// ----
// main
// ----

int main () {
    using namespace std;
    // Removing to fix the memory leak reported by Valgrind
    // Discussed with Fiona on Piazza
    //ios_base::sync_with_stdio(false);  // turn off synchronization with C I/O
    cout << "TestCollatz.c++" << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest(TestCollatz::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;}
