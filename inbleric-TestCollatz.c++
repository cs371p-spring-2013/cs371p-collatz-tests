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

	void test_read_2 () {
		std::istringstream r("10 1\n");
		int i;
		int j;
		const bool b = collatz_read(r, i, j);
		CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==  10);
        CPPUNIT_ASSERT(j ==   1);}
		
	void test_read_3 () {
		std::istringstream r("5 5\n");
		int i;
		int j;
		const bool b = collatz_read(r, i, j);
		CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==  5);
        CPPUNIT_ASSERT(j ==  5);}
	
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

	void test_cycle_1 () {
		const int v = cycle(5);
		CPPUNIT_ASSERT(v == 6);}
	
	void test_cycle_2 () {
		const int v = cycle(1);
		CPPUNIT_ASSERT(v == 1);}
		
	void test_cycle_3 () {
		const int v = cycle(10);
		CPPUNIT_ASSERT(v == 7);}
		
	void test_cycle_4 () {
		const int v = cycle(512);
		CPPUNIT_ASSERT(v == 10);}
	
    // -----
    // print
    // -----

    void test_print () {
        std::ostringstream w;
        collatz_print(w, 1, 10, 20);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n");}
		
	void test_print_2 () {
        std::ostringstream w;
        collatz_print(w, 5, 5, 6);
        CPPUNIT_ASSERT(w.str() == "5 5 6\n");}
		
	void test_print_3 () {
        std::ostringstream w;
        collatz_print(w, 100, 500, 20);
        CPPUNIT_ASSERT(w.str() == "100 500 20\n");}

    // -----
    // solve
    // -----

    void test_solve () {
        std::istringstream r("1 10\n100 200\n201 210\n900 1000\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n100 200 125\n201 210 89\n900 1000 174\n");}

	 void test_solve_2 () {
        std::istringstream r("3 33\n1 100\n500 600\n100 1000");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "3 33 112\n1 100 119\n500 600 137\n100 1000 179\n");}
	
	 void test_solve_3 () {
        std::istringstream r("111 1111\n222 2222\n256 512\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "111 1111 179\n222 2222 182\n256 512 144\n");}
		
    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestCollatz);
    CPPUNIT_TEST(test_read);
	CPPUNIT_TEST(test_read_2);
	CPPUNIT_TEST(test_read_3);
    CPPUNIT_TEST(test_eval_1);
    CPPUNIT_TEST(test_eval_2);
    CPPUNIT_TEST(test_eval_3);
    CPPUNIT_TEST(test_eval_4);
    CPPUNIT_TEST(test_print);
	CPPUNIT_TEST(test_print_2);
	CPPUNIT_TEST(test_print_3);
    CPPUNIT_TEST(test_solve);
	CPPUNIT_TEST(test_solve_2);
	CPPUNIT_TEST(test_solve_3);
	CPPUNIT_TEST(test_cycle_1);
	CPPUNIT_TEST(test_cycle_2);
	CPPUNIT_TEST(test_cycle_3);
	CPPUNIT_TEST(test_cycle_4);
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