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
        std::istringstream r("10 1\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==		10);
        CPPUNIT_ASSERT(j ==		1);}


    void test_read_3 () {
        std::istringstream r("1000000 1000000\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==		1000000);
        CPPUNIT_ASSERT(j ==		1000000);}

    // ----
    // eval
    // ----

    void test_eval_1 () {
        const int v = collatz_eval(1, 1);
        CPPUNIT_ASSERT(v == 1);}

    void test_eval_2 () {
        const int v = collatz_eval(1, 1000000);
        CPPUNIT_ASSERT(v == 525);}

    void test_eval_3 () {
        const int v = collatz_eval(50, 950000);
        CPPUNIT_ASSERT(v == 525);}


    // -----
    // print
    // -----

    void test_print_1 () {
        std::ostringstream w;
        collatz_print(w, 1, 10, 20);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n");}


    void test_print_2 () {
        std::ostringstream w;
        collatz_print(w, 1, 1, 1);
        CPPUNIT_ASSERT(w.str() == "1 1 1\n");}


    void test_print_3 () {
        std::ostringstream w;
        collatz_print(w, 1, 1000000, 525);
        CPPUNIT_ASSERT(w.str() == "1 1000000 525\n");}

    // -----
    // solve
    // -----

    void test_solve_1 () {
        std::istringstream r("1 10\n100 200\n201 210\n900 1000\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n100 200 125\n201 210 89\n900 1000 174\n");}


    void test_solve_2 () {
        std::istringstream r("1 10\n1 1000000\n1 1000\n5000 15000");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n1 1000000 525\n1 1000 179\n5000 15000 276\n");}


    void test_solve_3 () {
        std::istringstream r("1 10\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n");}

	void test_cycle_1 ()
	{
		int cache[1000001] = {0};
		int v = collatz_cycle(10, cache);
		CPPUNIT_ASSERT(v == 7);
	}
	void test_cycle_2 ()
	{
		int cache[1000001] = {0};
		int v = collatz_cycle(1000000, cache);
		CPPUNIT_ASSERT(v == 153);
	}
	void test_cycle_3 ()
	{
		int cache[1000001] = {0};
		int v = collatz_cycle(1, cache);
		CPPUNIT_ASSERT(v == 1);
	}

	void test_meta_1 ()
	{
		int v = collatz_meta(1, 1);
		CPPUNIT_ASSERT(v == 0);
	}
	void test_meta_2 ()
	{
		int v = collatz_meta(1, 100);
		CPPUNIT_ASSERT(v == 119);
	}
	void test_meta_3 ()
	{
		int v = collatz_meta(805, 1105);
		CPPUNIT_ASSERT(v == 174);
	}
    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestCollatz);
    CPPUNIT_TEST(test_read_1);
    CPPUNIT_TEST(test_read_2);
    CPPUNIT_TEST(test_read_3);

    CPPUNIT_TEST(test_eval_1);
    CPPUNIT_TEST(test_eval_2);
    CPPUNIT_TEST(test_eval_3);
    
	CPPUNIT_TEST(test_print_1);
	CPPUNIT_TEST(test_print_2);
	CPPUNIT_TEST(test_print_3);

    CPPUNIT_TEST(test_solve_1);
    CPPUNIT_TEST(test_solve_2);
    CPPUNIT_TEST(test_solve_3);

	CPPUNIT_TEST(test_cycle_1);
	CPPUNIT_TEST(test_cycle_2);
	CPPUNIT_TEST(test_cycle_3);

	CPPUNIT_TEST(test_meta_1);
	CPPUNIT_TEST(test_meta_2);
	CPPUNIT_TEST(test_meta_3);

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
