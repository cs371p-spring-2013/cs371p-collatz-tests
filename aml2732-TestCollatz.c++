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

    /**
    * This test sees if integers 1 and 10 can be pulled from istringstream
    */
    void test_read () {
        std::istringstream r("1 10\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    1);
        CPPUNIT_ASSERT(j ==   10);}

    /**
    * This test makes sure an empty istringstream does not 'read'
    */
    void test_read_1 (){
        std::istringstream r("\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == false);}

    /**
    * This test sees if random integers 301 and 459 can be pulled from istringstream
    */
    void test_read_2 (){
        std::istringstream r("301 459\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i == 301);
        CPPUNIT_ASSERT(j == 459);}

    /**
    * This test sees if duplicate integers 1 and 1 can be pulled from istringstream
    */
    void test_read_3 (){
        std::istringstream r("1 1\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i == 1);
        CPPUNIT_ASSERT(j == 1);}

    // -----
    // cycle_length
    // -----
    
    /**
    * This test sees if the correct cycle length is returned for 1 (min case)
    */
    void test_len_1(){
        const int v = cycle_length(1);
        CPPUNIT_ASSERT(v == 1);}

    /**
    * This test sees if the correct cycle length is returned for 10 (regular case) that requires many  
    *  odd/even conversions
    */
    void test_len_2(){
        const int v = cycle_length(10);
        CPPUNIT_ASSERT(v == 7);}

    /**
    * This test sees if the correct cycle length is returned for 1million (max case)
    */
    void test_len_3(){
        const int v = cycle_length(1000000);
        CPPUNIT_ASSERT(v == 153);}


    // ----
    // eval
    // ----

    /**
    * This test sees if the eval method returns the max cycle length for 1 through 10
    */
    void test_eval_1 () {
        const int v = collatz_eval(1, 10);
        CPPUNIT_ASSERT(v == 20);}

    /**
    * This test sees if the eval method returns the max cycle length for 100 through 200
    */
    void test_eval_2 () {
        const int v = collatz_eval(100, 200);
        CPPUNIT_ASSERT(v == 125);}

    /**
    * This test sees if the eval method returns the max cycle length for 201 through 210
    */
    void test_eval_3 () {
        const int v = collatz_eval(201, 210);
        CPPUNIT_ASSERT(v == 89);}

    /**
    * This test sees if the eval method returns the max cycle length for 900 through 1000
    */
    void test_eval_4 () {
        const int v = collatz_eval(900, 1000);
        CPPUNIT_ASSERT(v == 174);}

    /**
    * This test sees if the eval method returns the cycle_length of 10 (inclusive test)
    */
    //10 --> 5 -->16 -->8 -->4 -->2 -->1
    void test_eval_5 () {
        const int v = collatz_eval(10, 10); // max should be of one number only (10)
        CPPUNIT_ASSERT(v == 7);}

    /**
    * This test sees if the eval method returns the max cycle length for 500 through 1000
    */
    void test_eval_6 () {
        const int v = collatz_eval(500, 1000); // large range
        CPPUNIT_ASSERT(v == 179);}

    /**
    * This test sees if the eval method returns the max cycle length for 500 through 10000
    */
    void test_eval_7 () {
        const int v = collatz_eval(500, 10000); // larger range
        CPPUNIT_ASSERT(v == 262);}

    /**
    * This test sees if the eval method returns the max cycle length for 500 through 100000
    */
    void test_eval_8 () {
        const int v = collatz_eval(500, 100000); // largest range
        CPPUNIT_ASSERT(v == 351);}

    /**
    * This test sees if the eval method returns the max cycle length for 8989 through 9898
    * Tests larger numbers
    */
    void test_eval_9 () {
        const int v = collatz_eval(8989, 9898); 
        CPPUNIT_ASSERT(v == 260);}

    /**
    * This test sees if the eval method returns the max cycle length for 900 through 1000
    * This tests ordering
    */
    //Test ordering:
    void test_eval_4_2 () {
        const int v = collatz_eval(1000, 900);
        CPPUNIT_ASSERT(v == 174);}

    /**
    * This test sees if the eval method returns the max cycle length for 1 through 1million
    * This tests extremely large range of huge numbers. 
    */
    //Test way big numbers:
    void test_eval_v2_1(){
        const int v = collatz_eval(1, 1000000);
        CPPUNIT_ASSERT(v == 525);}


    // -----
    // print
    // -----

    /**
    * The following are print methods that test if the program is successfully wirting to outstream
    */
    void test_print () {
        std::ostringstream w;
        collatz_print(w, 1, 10, 20);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n");}

    void test_print_1 () {
        std::ostringstream w;
        collatz_print(w, 566, 457, 890);
        CPPUNIT_ASSERT(w.str() == "566 457 890\n");}

    void test_print_2 () {
        std::ostringstream w;
        collatz_print(w, 1, 1, 1);
        CPPUNIT_ASSERT(w.str() == "1 1 1\n");}

    void test_print_3 () {
        std::ostringstream w;
        collatz_print(w, 999, 999, 999);
        CPPUNIT_ASSERT(w.str() == "999 999 999\n");}

    // -----
    // solve
    // -----

    /**
    * The following tests, test whether Collatz as a whole is working altogether properly.
    * This simulates what we would do on the command line.
    */
    void test_solve () {
        std::istringstream r("1 10\n100 200\n201 210\n900 1000\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n100 200 125\n201 210 89\n900 1000 174\n");}

    void test_solve_1 () {
        std::istringstream r("500 1000\n10 10\n500 10000\n500 100000\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "500 1000 179\n10 10 7\n500 10000 262\n500 100000 351\n");}

    void test_solve_2 () {
        std::istringstream r("8989 9898\n100 200\n200 300\n300 400\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "8989 9898 260\n100 200 125\n200 300 128\n300 400 144\n");}

    void test_solve_3 () {
        std::istringstream r("1 500\n500 1000\n1 1000\n1000 5000\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 500 144\n500 1000 179\n1 1000 179\n1000 5000 238\n");}
    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestCollatz);
    //Read
    CPPUNIT_TEST(test_read);
    CPPUNIT_TEST(test_read_1);
    CPPUNIT_TEST(test_read_2);
    CPPUNIT_TEST(test_read_3);
    
    //cycle_length
    CPPUNIT_TEST(test_len_1);
    CPPUNIT_TEST(test_len_2);
    CPPUNIT_TEST(test_len_3);

    //eval
    CPPUNIT_TEST(test_eval_1);
    CPPUNIT_TEST(test_eval_2);
    CPPUNIT_TEST(test_eval_3);
    CPPUNIT_TEST(test_eval_4);
    CPPUNIT_TEST(test_eval_5);
    CPPUNIT_TEST(test_eval_6);
    CPPUNIT_TEST(test_eval_7);
    CPPUNIT_TEST(test_eval_8);
    CPPUNIT_TEST(test_eval_9);
    CPPUNIT_TEST(test_eval_4_2);
    CPPUNIT_TEST(test_eval_v2_1);

    CPPUNIT_TEST(test_print);
    CPPUNIT_TEST(test_print_1);
    CPPUNIT_TEST(test_print_2);
    CPPUNIT_TEST(test_print_3);

    CPPUNIT_TEST(test_solve);
    CPPUNIT_TEST(test_solve_1);
    CPPUNIT_TEST(test_solve_2);
    CPPUNIT_TEST(test_solve_3);
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
