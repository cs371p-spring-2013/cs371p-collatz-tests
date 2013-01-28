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
		std::istringstream r("1 10 20\n");
		int i;
		int j;
		const bool b = collatz_read(r, i, j);
		CPPUNIT_ASSERT(b == true);}

	void test_read_3 () {
		std::istringstream r("");
		int i;
		int j;
		const bool b = collatz_read(r, i, j);
		CPPUNIT_ASSERT(b == false);}

	void test_read_4 () {
		std::istringstream r("20 30 50\n");
		int i;
		int j;
		const bool b = collatz_read(r, i, j);
		CPPUNIT_ASSERT(b == true);
		CPPUNIT_ASSERT(i ==   20);
		CPPUNIT_ASSERT(j ==   30);}
	
	void test_read_5 () {
		std::istringstream r("03 040\n");
		int i;
		int j;
		const bool b = collatz_read(r, i, j);
		CPPUNIT_ASSERT(b == true);
		CPPUNIT_ASSERT(i ==   3);
		CPPUNIT_ASSERT(j ==   40);}
    
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
        const int v = collatz_eval(1, 1);
        CPPUNIT_ASSERT(v == 1);}

	void test_eval_6 () {
        const int v = collatz_eval(999998, 999999);
        CPPUNIT_ASSERT(v == 259);}

	void test_eval_7 () {
        const int v = collatz_eval(1, 999999);
        CPPUNIT_ASSERT(v == 525);}

	void test_eval_8 () {
        const int v = collatz_eval(50, 100);
        CPPUNIT_ASSERT(v == 119);}

	void test_eval_9 () {
        const int v = collatz_eval(1, 100);
        CPPUNIT_ASSERT(v == 119);}

	void test_eval_10 () {
        const int v = collatz_eval(50000, 100000);
        CPPUNIT_ASSERT(v == 351);}

    // -----
    // print
    // -----

    void test_print () {
        std::ostringstream w;
        collatz_print(w, 1, 10, 20);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n");}

    void test_print_2 () {
        std::ostringstream w;
        collatz_print(w, 2, 20, 40);
        CPPUNIT_ASSERT(w.str() == "2 20 40\n");}

    void test_print_3 () {
        std::ostringstream w;
        collatz_print(w, 3, 30, 70);
        CPPUNIT_ASSERT(w.str() == "3 30 70\n");}
    
	void test_print_4 () {
        std::ostringstream w;
        collatz_print(w, 1, 1, 1);
        CPPUNIT_ASSERT(w.str() == "1 1 1\n");}

	void test_print_5 () {
        std::ostringstream w;
        collatz_print(w, 4, 49, 80);
        CPPUNIT_ASSERT(w.str() == "4 49 80\n");}

    // -----
    // solve
    // -----

    void test_solve () {
        std::istringstream r("1 10\n100 200\n201 210\n900 1000\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n100 200 125\n201 210 89\n900 1000 174\n");}

    void test_solve_2 () {
        std::istringstream r("1 3\n3 5\n4 5\n5 6\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 3 8\n3 5 8\n4 5 6\n5 6 9\n");}
	
    void test_solve_3 () {
        std::istringstream r("10 20\n20 30\n30 40\n40 50\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "10 20 21\n20 30 112\n30 40 107\n40 50 110\n");}

    void test_solve_4 () {
        std::istringstream r("20 10\n30 20\n40 30\n50 40\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "20 10 21\n30 20 112\n40 30 107\n50 40 110\n");}

    void test_solve_5 () {
        std::istringstream r("100 200\n200 300\n300 400\n400 500\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "100 200 125\n200 300 128\n300 400 144\n400 500 142\n");}

    void test_solve_6 () {
        std::istringstream r("200 100\n300 200\n400 300\n500 400\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "200 100 125\n300 200 128\n400 300 144\n500 400 142\n");}
	
    void test_solve_7 () {
        std::istringstream r("50 60\n60 70\n70 80\n80 90\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "50 60 113\n60 70 108\n70 80 116\n80 90 111\n");}

    void test_solve_8 () {
        std::istringstream r("70 80\n200 100\n300 400\n90 80\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "70 80 116\n200 100 125\n300 400 144\n90 80 111\n");}

    void test_solve_9 () {
        std::istringstream r("1 100000\n2 20000\n3 3000\n4 400\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 100000 351\n2 20000 279\n3 3000 217\n4 400 144\n");}

    void test_solve_10 () {
        std::istringstream r("200 400\n400 800\n800 1600\n1600 3200\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "200 400 144\n400 800 171\n800 1600 182\n1600 3200 217\n");}

	// -----------------
	// collatz_cycle_len
	// -----------------
	
	void test_cycle_len () {
		int v = collatz_cycle_len(1);
		CPPUNIT_ASSERT(v == 1);}

	void test_cycle_len_2 () {
		int v = collatz_cycle_len(5);
		CPPUNIT_ASSERT(v == 6);}

	void test_cycle_len_3 () {
		int v = collatz_cycle_len(3);
		CPPUNIT_ASSERT(v == 8);}

	void test_cycle_len_4 () {
		int v = collatz_cycle_len(22);
		CPPUNIT_ASSERT(v == 16);}
	
	void test_cycle_len_5 () {
		int v = collatz_cycle_len(365);
		CPPUNIT_ASSERT(v == 95);}

	void test_cycle_len_6 () {
		int v = collatz_cycle_len(999999);
		CPPUNIT_ASSERT(v == 259);}

	void test_cycle_len_7 () {
		int v = collatz_cycle_len(4073);
		CPPUNIT_ASSERT(v == 96);}

	void test_cycle_len_8 () {
		int v = collatz_cycle_len(2016);
		CPPUNIT_ASSERT(v == 113);}
	
	void test_cycle_len_9 () {
		int v = collatz_cycle_len(700000);
		CPPUNIT_ASSERT(v == 168);}

	void test_cycle_len_10 () {
		int v = collatz_cycle_len(111111);
		CPPUNIT_ASSERT(v == 116);}
	
    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestCollatz);
    CPPUNIT_TEST(test_read);
	CPPUNIT_TEST(test_read_2);
	CPPUNIT_TEST(test_read_3);
	CPPUNIT_TEST(test_read_4);
	CPPUNIT_TEST(test_read_5);

    CPPUNIT_TEST(test_eval_1);
    CPPUNIT_TEST(test_eval_2);
    CPPUNIT_TEST(test_eval_3);
    CPPUNIT_TEST(test_eval_4);
    CPPUNIT_TEST(test_eval_5);
    CPPUNIT_TEST(test_eval_6);
    CPPUNIT_TEST(test_eval_7);
    CPPUNIT_TEST(test_eval_8);
	CPPUNIT_TEST(test_eval_9);
    CPPUNIT_TEST(test_eval_10);

    CPPUNIT_TEST(test_print);
	CPPUNIT_TEST(test_print_2);
	CPPUNIT_TEST(test_print_3);
	CPPUNIT_TEST(test_print_4);
	CPPUNIT_TEST(test_print_5);
    
	CPPUNIT_TEST(test_solve);
    CPPUNIT_TEST(test_solve_2);
    CPPUNIT_TEST(test_solve_3);
    CPPUNIT_TEST(test_solve_4);
    CPPUNIT_TEST(test_solve_5);
    CPPUNIT_TEST(test_solve_6);
    CPPUNIT_TEST(test_solve_7);
    CPPUNIT_TEST(test_solve_8);
    CPPUNIT_TEST(test_solve_9);
    CPPUNIT_TEST(test_solve_10);

	CPPUNIT_TEST(test_cycle_len);
	CPPUNIT_TEST(test_cycle_len_2);
	CPPUNIT_TEST(test_cycle_len_3);
	CPPUNIT_TEST(test_cycle_len_4);
	CPPUNIT_TEST(test_cycle_len_5);
	CPPUNIT_TEST(test_cycle_len_6);
	CPPUNIT_TEST(test_cycle_len_7);
	CPPUNIT_TEST(test_cycle_len_8);
	CPPUNIT_TEST(test_cycle_len_9);
	CPPUNIT_TEST(test_cycle_len_10);

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
