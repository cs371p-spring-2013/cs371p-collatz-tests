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
    % valgrind ./TestCollatz >& TestCollatz.c++.out
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
        std::istringstream r("100 200\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    100);
        CPPUNIT_ASSERT(j ==   200);}

    void test_read_3 () {
        std::istringstream r("100 2000\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    100);
        CPPUNIT_ASSERT(j ==   2000);}

    void test_read_4 () {
        std::istringstream r("900 1000\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    900);
        CPPUNIT_ASSERT(j ==   1000);}

    void test_read_5 () {
        std::istringstream r("201 200\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    201);
        CPPUNIT_ASSERT(j ==   200);}


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
        const int v = collatz_eval(1000, 900);
        CPPUNIT_ASSERT(v == 174);}

    void test_eval_6 () {
        const int v = collatz_eval(210, 201);
        CPPUNIT_ASSERT(v == 89);}

    void test_eval_7 () {
        const int v = collatz_eval(1, 1);
        CPPUNIT_ASSERT(v == 1);}

    // ----
    // cached_eval
    // ----

    void test_cached_eval_1 () {
        const int v = cached_collatz_eval(998000, 999999);
        CPPUNIT_ASSERT(v == 396);}

    void test_cached_eval_2 () {
        const int v = cached_collatz_eval(1534, 10999);
        CPPUNIT_ASSERT(v == 268);}

    void test_cached_eval_3 () {
        const int v = cached_collatz_eval(345, 1357);
        CPPUNIT_ASSERT(v == 182);}

    void test_cached_eval_4 () {
        const int v = cached_collatz_eval(526878, 538912);
        CPPUNIT_ASSERT(v == 377);}

    void test_cached_eval_5 () {
        const int v = cached_collatz_eval(370503, 375385);
        CPPUNIT_ASSERT(v == 361);}

    void test_cached_eval_6 () {
        const int v = cached_collatz_eval(987435, 989314);
        CPPUNIT_ASSERT(v == 352);}

    void test_cached_eval_7 () {
        const int v = cached_collatz_eval(448207, 837458);
        CPPUNIT_ASSERT(v == 509);}

    void test_cached_eval_8 () {
        const int v = cached_collatz_eval(356243, 837779);
        CPPUNIT_ASSERT(v == 509);}


    // ----
    // simple_eval
    // ----

    void test_simple_eval_1 () {
        const int v = simple_collatz_eval(1, 10);
        CPPUNIT_ASSERT(v == 20);}

    void test_simple_eval_2 () {
        const int v = simple_collatz_eval(100, 200);
        CPPUNIT_ASSERT(v == 125);}

    void test_simple_eval_3 () {
        const int v = simple_collatz_eval(201, 210);
        CPPUNIT_ASSERT(v == 89);}

    void test_simple_eval_4 () {
        const int v = simple_collatz_eval(900, 1000);
        CPPUNIT_ASSERT(v == 174);}

    void test_simple_eval_5 () {
        const int v = simple_collatz_eval(1, 1);
        CPPUNIT_ASSERT(v == 1);}

    // ----
    // eval_cycle
    // ----

    void test_eval_cycle_1 () {
        const long v = collatz_eval_cycle(5);
        CPPUNIT_ASSERT(v == 6);}

    void test_eval_cycle_2 () {
        const long v = collatz_eval_cycle(10);
        CPPUNIT_ASSERT(v == 7);}

    void test_eval_cycle_3 () {
        const long v = collatz_eval_cycle(3);
        CPPUNIT_ASSERT(v == 8);}

    void test_eval_cycle_4 () {
        const long v = collatz_eval_cycle(1);
        CPPUNIT_ASSERT(v == 1);}
    // -----
    // print
    // -----

    void test_print_1 () {
        std::ostringstream w;
        collatz_print(w, 1, 10, 20);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n");}

    void test_print_2 () {
        std::ostringstream w;
        collatz_print(w, 100, 200, 120);
        CPPUNIT_ASSERT(w.str() == "100 200 120\n");}

    void test_print_3 () {
        std::ostringstream w;
        collatz_print(w, 1, 1, 2);
        CPPUNIT_ASSERT(w.str() == "1 1 2\n");}

    void test_print_4 () {
        std::ostringstream w;
        collatz_print(w, 1111, 301, 2);
        CPPUNIT_ASSERT(w.str() == "1111 301 2\n");}

    // -----
    // solve
    // -----

    void test_solve_1 () {
        std::istringstream r("1 10\n100 200\n201 210\n900 1000\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n100 200 125\n201 210 89\n900 1000 174\n");}

    void test_solve_2 () {
        std::istringstream r("10 1\n200 100\n210 201\n1000 900\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "10 1 20\n200 100 125\n210 201 89\n1000 900 174\n");}

    void test_solve_3 () {
        std::istringstream r("999999 1\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "999999 1 525\n");}

    // -----
    // suite
    // -----
    CPPUNIT_TEST_SUITE(TestCollatz);
    CPPUNIT_TEST(test_read_1);
    CPPUNIT_TEST(test_read_2);
    CPPUNIT_TEST(test_read_3);
    CPPUNIT_TEST(test_read_4);
    CPPUNIT_TEST(test_read_5);
    CPPUNIT_TEST(test_eval_cycle_1);
    CPPUNIT_TEST(test_eval_cycle_2);
    CPPUNIT_TEST(test_eval_cycle_3);
    CPPUNIT_TEST(test_eval_1);
    CPPUNIT_TEST(test_eval_2);
    CPPUNIT_TEST(test_eval_3);
    CPPUNIT_TEST(test_eval_4);
    CPPUNIT_TEST(test_eval_5);
    CPPUNIT_TEST(test_eval_6);
    CPPUNIT_TEST(test_eval_7);
    CPPUNIT_TEST(test_cached_eval_1);
    CPPUNIT_TEST(test_cached_eval_2);
    CPPUNIT_TEST(test_cached_eval_3);
    CPPUNIT_TEST(test_cached_eval_4);
    CPPUNIT_TEST(test_cached_eval_5);
    CPPUNIT_TEST(test_cached_eval_6);
    CPPUNIT_TEST(test_cached_eval_7);
    CPPUNIT_TEST(test_cached_eval_8);
    CPPUNIT_TEST(test_simple_eval_1);
    CPPUNIT_TEST(test_simple_eval_2);
    CPPUNIT_TEST(test_simple_eval_3);
    CPPUNIT_TEST(test_simple_eval_4);
    CPPUNIT_TEST(test_simple_eval_5);
    CPPUNIT_TEST(test_print_1);
    CPPUNIT_TEST(test_print_2);
    CPPUNIT_TEST(test_print_3);
    CPPUNIT_TEST(test_print_4);
    CPPUNIT_TEST(test_solve_1);
    CPPUNIT_TEST(test_solve_2);
    CPPUNIT_TEST(test_solve_3);
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

