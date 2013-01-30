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
    % g++ -pedantic -std=c++0x -Wall Collatz.c++ TestCollatz.c++ -o TestCollatz.c++.app -lcppunit -ldl
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
		
    void test_read_m1 () {
        std::istringstream r("5 3\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    5);
        CPPUNIT_ASSERT(j ==    3);}
		
    void test_read_m2 () {
        std::istringstream r("");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == false);}
		
    void test_read_m3 () {
        std::istringstream r("500 22\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    500);
        CPPUNIT_ASSERT(j ==    22);}

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
		
    void test_eval_m1 () {
        const int v = collatz_eval(5, 3);
        CPPUNIT_ASSERT(v == 8);}
		
    void test_eval_m2 () {
        const int v = collatz_eval(4, 4);
        CPPUNIT_ASSERT(v == 3);}
		
    void test_eval_m3 () {
        const int v = collatz_eval(200, 100);
        CPPUNIT_ASSERT(v == 125);}

		
    // ------
    // helper
    // ------

    void test_helper_m1 () {
        const int v = collatz_helper(1, 1);
        CPPUNIT_ASSERT(v == 1);}
		
    void test_helper_m2 () {
        const int v = collatz_helper(5, 1);
        CPPUNIT_ASSERT(v == 6);}
		
    void test_helper_m3 () {
        const int v = collatz_helper(64, 1);
        CPPUNIT_ASSERT(v == 7);}
		
    // -----
    // print
    // -----

    void test_print () {
        std::ostringstream w;
        collatz_print(w, 1, 10, 20);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n");}
		
    void test_print_m1 () {
        std::ostringstream w;
        collatz_print(w, 10, 1, 20);
        CPPUNIT_ASSERT(w.str() == "10 1 20\n");}
		
    void test_print_m2 () {
        std::ostringstream w;
        collatz_print(w, 3, 5, 8);
        CPPUNIT_ASSERT(w.str() == "3 5 8\n");}
		
    void test_print_m3 () {
        std::ostringstream w;
        collatz_print(w, 201, 210, 89);
        CPPUNIT_ASSERT(w.str() == "201 210 89\n");}

    // -----
    // solve
    // -----

    void test_solve () {
        std::istringstream r("1 10\n100 200\n201 210\n900 1000\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n100 200 125\n201 210 89\n900 1000 174\n");}
		
    void test_solve_m1 () {
        std::istringstream r("10 1\n200 100\n210 201\n1000 900\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "10 1 20\n200 100 125\n210 201 89\n1000 900 174\n");}
		
    void test_solve_m2 () {
        std::istringstream r("2 5\n1 2\n3 6\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "2 5 8\n1 2 2\n3 6 9\n");}
		
    void test_solve_m3 () {
        std::istringstream r("4 5\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "4 5 6\n");}

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestCollatz);
    CPPUNIT_TEST(test_read);
    CPPUNIT_TEST(test_read_m1);
    CPPUNIT_TEST(test_read_m2);
    CPPUNIT_TEST(test_read_m3);
    CPPUNIT_TEST(test_eval_1);
    CPPUNIT_TEST(test_eval_2);
    CPPUNIT_TEST(test_eval_3);
    CPPUNIT_TEST(test_eval_4);
    CPPUNIT_TEST(test_eval_m1);
    CPPUNIT_TEST(test_eval_m2);
    CPPUNIT_TEST(test_eval_m3);
    CPPUNIT_TEST(test_helper_m1);
    CPPUNIT_TEST(test_helper_m2);
    CPPUNIT_TEST(test_helper_m3);
    CPPUNIT_TEST(test_print);
    CPPUNIT_TEST(test_print_m1);
    CPPUNIT_TEST(test_print_m2);
    CPPUNIT_TEST(test_print_m3);
    CPPUNIT_TEST(test_solve);
    CPPUNIT_TEST(test_solve_m1);
    CPPUNIT_TEST(test_solve_m2);
    CPPUNIT_TEST(test_solve_m3);
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
