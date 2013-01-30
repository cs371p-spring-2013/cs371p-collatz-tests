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
        std::istringstream r("10 10\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==   10);
        CPPUNIT_ASSERT(j ==   10);}
        
    void test_read_mult_numbers () {
        std::istringstream r("2 10\n30 40\n");
        int i;
        int j;
        bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    2);
        CPPUNIT_ASSERT(j ==   10);
        
        b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==   30);
        CPPUNIT_ASSERT(j ==   40);}
        
    void test_read_large_string () {
        std::istringstream r("8 9\n8 9\n8 9\n8 9\n8 9\n8 9\n8 9\n8 9\n8 9\n8 9\n8 9\n8 9\n8 9\n8 9\n8 9\n8 9\n8 9\n8 9\n8 9\n8 9\n8 9\n8 9\n8 9\n8 9\n");
        int i;
        int j;
        for(int x = 0;x<24;x++)
        {
		    const bool b = collatz_read(r, i, j);
		    CPPUNIT_ASSERT(b == true);
		    CPPUNIT_ASSERT(i ==    8);
		    CPPUNIT_ASSERT(j ==    9);
        }
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
       
    //My Tests
    
    void test_eval_no_range () {
        const int v = collatz_eval(1, 1);
        CPPUNIT_ASSERT(v == 1);}
    
    void test_eval_small_range () {
        const int v = collatz_eval(1, 2);
        CPPUNIT_ASSERT(v == 2);}
        
    void test_eval_right_hand_inclusive () {
        const int v = collatz_eval(1, 3);
        CPPUNIT_ASSERT(v == 8);}
    
    void test_eval_left_hand_inclusive () {
        const int v = collatz_eval(3, 4);
        CPPUNIT_ASSERT(v == 8);}
        
    void test_eval_inverted_values () {
        const int v = collatz_eval(4, 2);
        CPPUNIT_ASSERT(v == 8);}
    
    void test_eval_137_104 () {
    	const int v = collatz_eval(137, 104);
        CPPUNIT_ASSERT(v == 122);}
        
        
    // ----
    // calc_cycle
    // ----

	void test_calc_cycle_1 () {
        const int v = collatz_calc_cycle(1);
        CPPUNIT_ASSERT(v == 1);}
    
    void test_calc_cycle_2 () {
        const int v = collatz_calc_cycle(2);
        CPPUNIT_ASSERT(v == 2);}
    
    void test_calc_cycle_3 () {
        const int v = collatz_calc_cycle(4);
        CPPUNIT_ASSERT(v == 3);}
    
    void test_calc_cycle_4 () {
        const int v = collatz_calc_cycle(8);
        CPPUNIT_ASSERT(v == 4);}
    
    void test_calc_cycle_odd_num () {
        const int v = collatz_calc_cycle(3);
        CPPUNIT_ASSERT(v == 8);}
    
    void test_calc_cycle_even_num () {
        const int v = collatz_calc_cycle(10);
        CPPUNIT_ASSERT(v == 7);}
        
    void test_calc_cycle_137 () {
    	const int v = collatz_calc_cycle(137);
        CPPUNIT_ASSERT(v == 91);}
        
    void test_calc_cycle_104 () {
    	const int v = collatz_calc_cycle(104);
        CPPUNIT_ASSERT(v == 13);}

    // -----
    // print
    // -----

    void test_print () {
        std::ostringstream w;
        collatz_print(w, 1, 10, 20);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n");}

    // -----
    // solve
    // -----

    void test_solve () {
        std::istringstream r("1 10\n100 200\n201 210\n900 1000\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n100 200 125\n201 210 89\n900 1000 174\n");}

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestCollatz);
    CPPUNIT_TEST(test_read_1);
    CPPUNIT_TEST(test_read_2);
    CPPUNIT_TEST(test_read_mult_numbers);
    CPPUNIT_TEST(test_read_large_string);
    
    CPPUNIT_TEST(test_eval_1);
    CPPUNIT_TEST(test_eval_2);
    CPPUNIT_TEST(test_eval_3);
    CPPUNIT_TEST(test_eval_4);
    CPPUNIT_TEST(test_eval_no_range);
    CPPUNIT_TEST(test_eval_small_range);
    CPPUNIT_TEST(test_eval_left_hand_inclusive);
    CPPUNIT_TEST(test_eval_right_hand_inclusive);
    CPPUNIT_TEST(test_eval_inverted_values);
    CPPUNIT_TEST(test_eval_137_104);
    
    CPPUNIT_TEST(test_calc_cycle_1);
    CPPUNIT_TEST(test_calc_cycle_2);
    CPPUNIT_TEST(test_calc_cycle_3);
    CPPUNIT_TEST(test_calc_cycle_4);
    CPPUNIT_TEST(test_calc_cycle_odd_num);
    CPPUNIT_TEST(test_calc_cycle_even_num);
    CPPUNIT_TEST(test_calc_cycle_137);
    CPPUNIT_TEST(test_calc_cycle_104);
    
    CPPUNIT_TEST(test_print);
    
    CPPUNIT_TEST(test_solve);
    
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
