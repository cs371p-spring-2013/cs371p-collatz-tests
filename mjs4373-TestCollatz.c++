// --------------------------------
// projects/collatz/TestCollatz.c++
// Copyright (C) 2013
// Glenn P. Downing
// --------------------------------

// --------------------------------
// Project Editted and Completed by
// Mitch Stephan
// UT EID: mjs4373
// github acount: MitchStephan
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

	//taking read test numbers from given eval tests
	
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
        CPPUNIT_ASSERT(i ==   100);
        CPPUNIT_ASSERT(j ==   200);}
		
	void test_read_3 () {
		std::istringstream r("201 210\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==   201);
        CPPUNIT_ASSERT(j ==   210);}
		
	void test_read_4 () {
		std::istringstream r("900 1000\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==   900);
        CPPUNIT_ASSERT(j ==   1000);}
	

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
        const int v = collatz_eval(50, 365);
        CPPUNIT_ASSERT(v == 144);}
		
	void test_eval_6 () {
        const int v = collatz_eval(1000, 2000);
        CPPUNIT_ASSERT(v == 182);}
		
	void test_eval_7 () {
        const int v = collatz_eval(1000000, 1000000);
        CPPUNIT_ASSERT(v == 153);}
	

    // -----
    // print
    // -----

	//taking print test numbers from given eval tests
	
    void test_print_1 () {
        std::ostringstream w;
        collatz_print(w, 1, 10, 20);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n");}
		
	void test_print_2 () {
        std::ostringstream w;
        collatz_print(w, 100, 200, 125);
        CPPUNIT_ASSERT(w.str() == "100 200 125\n");}
		
	void test_print_3 () {
        std::ostringstream w;
        collatz_print(w, 201, 210, 89);
        CPPUNIT_ASSERT(w.str() == "201 210 89\n");}
		
	void test_print_4 () {
        std::ostringstream w;
        collatz_print(w, 900, 1000, 174);
        CPPUNIT_ASSERT(w.str() == "900 1000 174\n");}

    // -----
    // solve
    // -----

    void test_solve_1 () {
        std::istringstream r("1 10\n100 200\n201 210\n900 1000\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n100 200 125\n201 210 89\n900 1000 174\n");}
	
	void test_solve_2 () {
        std::istringstream r("50 365\n1000 2000\n1000000 1000000\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "50 365 144\n1000 2000 182\n1000000 1000000 153\n");}
	
	void test_solve_3 () {
        std::istringstream r("10 20\n20 30\n30 40\n40 50\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "10 20 21\n20 30 112\n30 40 107\n40 50 110\n");}

	void test_solve_4 () {
        std::istringstream r("100 200\n200 300\n300 400\n400 500\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "100 200 125\n200 300 128\n300 400 144\n400 500 142\n");}

    // -----
    // suite
    // -----

	//included added tests and changed names of previous tests to match changes
    CPPUNIT_TEST_SUITE(TestCollatz);
    CPPUNIT_TEST(test_read_1); 
	CPPUNIT_TEST(test_read_2);
	CPPUNIT_TEST(test_read_3);
	CPPUNIT_TEST(test_read_4);
    CPPUNIT_TEST(test_eval_1);
    CPPUNIT_TEST(test_eval_2);
    CPPUNIT_TEST(test_eval_3);
    CPPUNIT_TEST(test_eval_4);
	CPPUNIT_TEST(test_eval_5);
	CPPUNIT_TEST(test_eval_6);
	CPPUNIT_TEST(test_eval_7); 
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
    ios_base::sync_with_stdio(false);  // turn off synchronization with C I/O
    cout << "TestCollatz.c++" << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest(TestCollatz::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;}