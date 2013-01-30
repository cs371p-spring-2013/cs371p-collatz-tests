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

    void ddg625_test_read_1 () {
        std::istringstream r("100 100\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==  100);
        CPPUNIT_ASSERT(j ==  100);}

    void ddg625_test_read_2 () {
        std::istringstream r("99 200\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==   99);
        CPPUNIT_ASSERT(j ==  200);}
        
    void ddg625_test_read_3 () {
        std::istringstream r("\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == false);}
        
    void ddg625_test_read_4 () {
        std::istringstream r("800 801\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==  800);
        CPPUNIT_ASSERT(j ==  801);}

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

    void ddg625_test_eval_1 () {
        const int v = collatz_eval(10, 1);
        CPPUNIT_ASSERT(v == 20);}

    void ddg625_test_eval_2 () {
        const int v = collatz_eval(25, 56);
        CPPUNIT_ASSERT(v == 113);}

    void ddg625_test_eval_3 () {
        const int v = collatz_eval(13, 13);
        CPPUNIT_ASSERT(v == 10);}

    void ddg625_test_eval_4 () {
        const int v = collatz_eval(150, 200);
        CPPUNIT_ASSERT(v == 125);}

    // -----
    // cycle
    // -----

	void ddg625_test_cycle_1() {
		const int v = collatz_cycle(5);
		CPPUNIT_ASSERT(v == 6);}
	
	void ddg625_test_cycle_2() {
		const int v = collatz_cycle(13);
		CPPUNIT_ASSERT(v == 10);}

	void ddg625_test_cycle_3() {
		const int v = collatz_cycle(3);
		CPPUNIT_ASSERT(v == 8);}

	void ddg625_test_cycle_4() {
		const int v = collatz_cycle(20);
		CPPUNIT_ASSERT(v == 8);}

    // -----
    // print
    // -----

    void test_print () {
        std::ostringstream w;
        collatz_print(w, 1, 10, 20);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n");}

    void ddg625_test_print_1() {
        std::ostringstream w;
        collatz_print(w, 1, 2, 3);
        CPPUNIT_ASSERT(w.str() == "1 2 3\n");}
        
    void ddg625_test_print_2() {
        std::ostringstream w;
        collatz_print(w, 100, 200, 80);
        CPPUNIT_ASSERT(w.str() == "100 200 80\n");}
        
    void ddg625_test_print_3() {
        std::ostringstream w;
        collatz_print(w, 99, 99, 99);
        CPPUNIT_ASSERT(w.str() == "99 99 99\n");}
        
    void ddg625_test_print_4() {
        std::ostringstream w;
        collatz_print(w, 23, 30, 7);
        CPPUNIT_ASSERT(w.str() == "23 30 7\n");}

    // -----
    // solve
    // -----

    void test_solve () {
        std::istringstream r("1 10\n100 200\n201 210\n900 1000\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n100 200 125\n201 210 89\n900 1000 174\n");}

    void ddg625_test_solve_1 () {
        std::istringstream r("900 1000\n25 56\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "900 1000 174\n25 56 113\n");}
    
    void ddg625_test_solve_2 () {
        std::istringstream r("13 13\n5 5\n20 20\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "13 13 10\n5 5 6\n20 20 8\n");}
    
    void ddg625_test_solve_3 () {
        std::istringstream r("1000 900\n13 13\n900 1000\n1 10\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1000 900 174\n13 13 10\n900 1000 174\n1 10 20\n");}

    // -----
    // suite
    // -----
    CPPUNIT_TEST_SUITE(TestCollatz);
    CPPUNIT_TEST(test_read);
    CPPUNIT_TEST(ddg625_test_read_1);
    CPPUNIT_TEST(ddg625_test_read_2);
    CPPUNIT_TEST(ddg625_test_read_3);
    CPPUNIT_TEST(ddg625_test_read_4);
    CPPUNIT_TEST(test_eval_1);
    CPPUNIT_TEST(test_eval_2);
    CPPUNIT_TEST(test_eval_3);
    CPPUNIT_TEST(test_eval_4);
    CPPUNIT_TEST(ddg625_test_eval_1);
    CPPUNIT_TEST(ddg625_test_eval_2);
    CPPUNIT_TEST(ddg625_test_eval_3);
    CPPUNIT_TEST(ddg625_test_eval_4);
    CPPUNIT_TEST(ddg625_test_cycle_1);
    CPPUNIT_TEST(ddg625_test_cycle_2);
    CPPUNIT_TEST(ddg625_test_cycle_3);
    CPPUNIT_TEST(ddg625_test_cycle_4);
    CPPUNIT_TEST(test_print);
    CPPUNIT_TEST(ddg625_test_print_1);
    CPPUNIT_TEST(ddg625_test_print_2);
    CPPUNIT_TEST(ddg625_test_print_3);
    CPPUNIT_TEST(ddg625_test_print_4);
    CPPUNIT_TEST(test_solve);
    CPPUNIT_TEST(ddg625_test_solve_1);
    CPPUNIT_TEST(ddg625_test_solve_2);
    CPPUNIT_TEST(ddg625_test_solve_3);
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
