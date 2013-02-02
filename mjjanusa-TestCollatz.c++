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
        std::istringstream r("456 546\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    456);
        CPPUNIT_ASSERT(j ==   546);}

    void test_read3 () {
        std::istringstream r("864852 10\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    864852);
        CPPUNIT_ASSERT(j ==   10);}

    void test_read4 () {
        std::istringstream r("1000000 100\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    1000000);
        CPPUNIT_ASSERT(j ==   100);}

    // ----
    // eval
    // ----

    void test_eval_1 () {
	int cycleLengths[450000] = {0};
        const int v = collatz_eval(1, 10, cycleLengths);
        CPPUNIT_ASSERT(v == 20);}

    void test_eval_2 () {
	int cycleLengths[450000] = {0};
        const int v = collatz_eval(100, 200, cycleLengths);
        CPPUNIT_ASSERT(v == 125);}

    void test_eval_3 () {
	int cycleLengths[450000] = {0};
        const int v = collatz_eval(201, 210, cycleLengths);
        CPPUNIT_ASSERT(v == 89);}

    void test_eval_4 () {
	int cycleLengths[450000] = {0};
        const int v = collatz_eval(900, 1000, cycleLengths);
        CPPUNIT_ASSERT(v == 174);}

    void test_eval_5 () {
	int cycleLengths[450000] = {0};
        const int v = collatz_eval(40330, 81110, cycleLengths);
        CPPUNIT_ASSERT(v == 351);}

    void test_eval_6 () {
	int cycleLengths[450000] = {0};
        const int v = collatz_eval(11701, 38663, cycleLengths);
        CPPUNIT_ASSERT(v == 324);}

    void test_eval_7 () {
	int cycleLengths[450000] = {0};
        const int v = collatz_eval(91770, 24736, cycleLengths);
        CPPUNIT_ASSERT(v == 351);}

    void test_eval_8 () {
	int cycleLengths[450000] = {0};
        const int v = collatz_eval(60401, 53664, cycleLengths);
        CPPUNIT_ASSERT(v == 322);}

    // -----
    // length
    // -----

   void test_length () {
	int cycleLengths[450000] = {0};
	const int v = collatz_length(1, cycleLengths);
        CPPUNIT_ASSERT(v == 1);}

   void test_length2 () {
	int cycleLengths[450000] = {0};
	const int v = collatz_length(100, cycleLengths);
        CPPUNIT_ASSERT(v == 26);}

   void test_length3 () {
	int cycleLengths[450000] = {0};
	const int v = collatz_length(5, cycleLengths);
        CPPUNIT_ASSERT(v == 6);}

   void test_length4 () {
	int cycleLengths[450000] = {0};
	const int v = collatz_length(16, cycleLengths);
        CPPUNIT_ASSERT(v == 5);}




    // -----
    // print
    // -----

    void test_print () {
        std::ostringstream w;
        collatz_print(w, 1, 10, 20);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n");}

    void test_print2 () {
        std::ostringstream w;
        collatz_print(w, 54, 24, 854);
        CPPUNIT_ASSERT(w.str() == "54 24 854\n");}

    void test_print3 () {
        std::ostringstream w;
        collatz_print(w, 87, 8462, 4745);
        CPPUNIT_ASSERT(w.str() == "87 8462 4745\n");}

    void test_print4 () {
        std::ostringstream w;
        collatz_print(w, 56456, 645645, 20);
        CPPUNIT_ASSERT(w.str() == "56456 645645 20\n");}

    // -----
    // solve
    // -----

   void test_solve () {
        std::istringstream r("1 10\n100 200\n201 210\n900 1000\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n100 200 125\n201 210 89\n900 1000 174\n");}

    void test_solve2 () {
        std::istringstream r("14997 15119\n62892 63281\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "14997 15119 271\n62892 63281 317\n");}

   void test_solve3 () {
        std::istringstream r("1 10\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n");}

   void test_solve4 () {
        std::istringstream r("981 1072\n2352 2658\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "981 1072 169\n2352 2658 209\n");}

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestCollatz);
    CPPUNIT_TEST(test_read);
    CPPUNIT_TEST(test_read2);
    CPPUNIT_TEST(test_read3);
    CPPUNIT_TEST(test_read4);
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
    CPPUNIT_TEST(test_length);
    CPPUNIT_TEST(test_length2);
    CPPUNIT_TEST(test_length3);
    CPPUNIT_TEST(test_length4);
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
