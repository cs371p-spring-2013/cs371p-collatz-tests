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
#include <sstream> // istringtstream, ostringstream
#include <string> // ==

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h" // TestFixture
#include "cppunit/TextTestRunner.h" // TextTestRunner

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
        CPPUNIT_ASSERT(i == 1);
        CPPUNIT_ASSERT(j == 10);}

    void test_read_2 () {
        std::istringstream r("10000 50\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i == 10000);
        CPPUNIT_ASSERT(j == 50);}

    void test_read_3 () {
        std::istringstream r("10 1\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i == 10);
        CPPUNIT_ASSERT(j == 1);}

    void test_read_4 () {
        std::istringstream r("\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == false);}

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

//Bigger Numbers
    void test_eval_7 () {
        const int v = collatz_eval(5013, 5245);
        CPPUNIT_ASSERT(v == 179);}

    void test_eval_8 () {
        const int v = collatz_eval(301608, 466857);
        CPPUNIT_ASSERT(v == 449);}

	//----
	// Cycle
	//----
	void test_cycle_1 () {
		const int v = collatz_cycle(985);
		CPPUNIT_ASSERT(v==24);}

	void test_cycle_2 () {
		const int v = collatz_cycle(18);
		CPPUNIT_ASSERT(v==21);}

	void test_cycle_3 () {
		const int v = collatz_cycle(215);
		CPPUNIT_ASSERT(v==102);}


    // -----
    // print
    // -----

    void test_print_1 () {
        std::ostringstream w;
        collatz_print(w, 1, 10, 20);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n");}

    void test_print_2 () {
        std::ostringstream w;
        collatz_print(w, 50, 50, 50);
        CPPUNIT_ASSERT(w.str() == "50 50 50\n");}

    void test_print_3 () {
        std::ostringstream w;
        collatz_print(w, 1, 1, 1);
        CPPUNIT_ASSERT(w.str() == "1 1 1\n");}

    void test_print_4 () {
        std::ostringstream w;
        collatz_print(w, 1090, 10, 20);
        CPPUNIT_ASSERT(w.str() == "1090 10 20\n");}

    // -----
    // solve
    // -----

    void test_solve_1 () {
        std::istringstream r("1 10\n100 200\n201 210\n900 1000\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n100 200 125\n201 210 89\n900 1000 174\n");}

	//reversed inputs
    void test_solve_2 () {
        std::istringstream r("10 1\n200 100\n210 201\n1000 900\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "10 1 20\n200 100 125\n210 201 89\n1000 900 174\n");}

	//empty string
    void test_solve_3 () {
        std::istringstream r("");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "");}
	//large inputs
    void test_solve_4 () {
        std::istringstream r("9836 9854\n8175 8749\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "9836 9854 211\n8175 8749 234\n");}
    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestCollatz);
    CPPUNIT_TEST(test_read_1);
    CPPUNIT_TEST(test_read_2);
    CPPUNIT_TEST(test_read_3);
    CPPUNIT_TEST(test_read_4);
    CPPUNIT_TEST(test_eval_1);
    CPPUNIT_TEST(test_eval_2);
    CPPUNIT_TEST(test_eval_3);
    CPPUNIT_TEST(test_eval_4);
    CPPUNIT_TEST(test_eval_7);
    CPPUNIT_TEST(test_eval_8);
	CPPUNIT_TEST(test_cycle_1);
	CPPUNIT_TEST(test_cycle_2);
	CPPUNIT_TEST(test_cycle_3);
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
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O
    cout << "TestCollatz.c++" << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest(TestCollatz::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;}
