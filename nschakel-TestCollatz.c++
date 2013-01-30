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
	
	void test_read2()
	{
		std::istringstream r("100 200\n");
		int i;
		int j;
		const bool b = collatz_read(r, i, j);
        	CPPUNIT_ASSERT(b == true);
        	CPPUNIT_ASSERT(i ==    100);
        	CPPUNIT_ASSERT(j ==   200);
	}

	void test_read3()
	{
		std::istringstream r("150 250\n");
		int i;
		int j;
		const bool b = collatz_read(r, i, j);
        	CPPUNIT_ASSERT(b == true);
        	CPPUNIT_ASSERT(i ==    150);
        	CPPUNIT_ASSERT(j ==   250);
	}

	// ---
	// cacheCycleLength
	// ---
	void test_cacheCycleLength()
	{
		cacheCycleLength(5, 6);
		int i = getCachedCycleLength(5);
		CPPUNIT_ASSERT(i == 6);	
	}
	void test_cacheCycleLength2()
	{
		cacheCycleLength(1000000, 7);
		int i = getCachedCycleLength(1000000);
		CPPUNIT_ASSERT(i == 7);	
	}
	void test_cacheCycleLength3()
	{
		cacheCycleLength(150, 8);
		int i = getCachedCycleLength(150);
		CPPUNIT_ASSERT(i == 8);	
	}

	// ---
	// getCachedCycleLength
	// ---
	void test_getCachedCycleLength()
	{
		cacheCycleLength(1, 1);
		int i = getCachedCycleLength(1);
		CPPUNIT_ASSERT(i == 1);
	}

	void test_getCachedCycleLength2()
	{
		cacheCycleLength(1000000, 1);
		int i = getCachedCycleLength(1000000);
		CPPUNIT_ASSERT(i == 1);
	}

	void test_getCachedCycleLength3()
	{
		cacheCycleLength(50, 128);
		int i = getCachedCycleLength(50);
		CPPUNIT_ASSERT(i == 128);
	}

	// ----
	// findCycleLength
	// ----
	
	void test_findCycleLength()
	{
		int i = findCycleLength(5);
		CPPUNIT_ASSERT(i == 6);
	}

	void test_findCycleLength2()
	{
		int i = findCycleLength(1);
		CPPUNIT_ASSERT(i == 1);
	}

	void test_findCycleLength3()
	{
		int i = findCycleLength(1000000);
		CPPUNIT_ASSERT(i == 153);
	}



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

    // -----
    // print
    // -----

    void test_print () {
        std::ostringstream w;
        collatz_print(w, 1, 10, 20);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n");}

    void test_print2 () {
        std::ostringstream w;
        collatz_print(w, 100, 200, 125);
        CPPUNIT_ASSERT(w.str() == "100 200 125\n");}

    void test_print3 () {
        std::ostringstream w;
        collatz_print(w, 900, 1000, 174);
        CPPUNIT_ASSERT(w.str() == "900 1000 174\n");}

    // -----
    // solve
    // -----

    void test_solve () {
        std::istringstream r("1 10\n100 200\n201 210\n900 1000\n");
        std::ostringstream w;
        collatz_solve(r, w);
	w.flush();
        CPPUNIT_ASSERT(w.str() == "1 10 20\n100 200 125\n201 210 89\n900 1000 174\n");}

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestCollatz);
    CPPUNIT_TEST(test_read);
    CPPUNIT_TEST(test_read2);
    CPPUNIT_TEST(test_read3);
    CPPUNIT_TEST(test_solve);
    CPPUNIT_TEST(test_eval_1);
    CPPUNIT_TEST(test_eval_2);
    CPPUNIT_TEST(test_eval_3);
    CPPUNIT_TEST(test_eval_4);
    CPPUNIT_TEST(test_findCycleLength);
    CPPUNIT_TEST(test_findCycleLength2);
    CPPUNIT_TEST(test_findCycleLength3);
    CPPUNIT_TEST(test_cacheCycleLength);
    CPPUNIT_TEST(test_cacheCycleLength2);
    CPPUNIT_TEST(test_cacheCycleLength3);
    CPPUNIT_TEST(test_getCachedCycleLength);
    CPPUNIT_TEST(test_getCachedCycleLength2);
    CPPUNIT_TEST(test_getCachedCycleLength3);
    CPPUNIT_TEST(test_print);
    CPPUNIT_TEST(test_print2);
    CPPUNIT_TEST(test_print3);
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
