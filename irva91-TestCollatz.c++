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

    // ----------
    // fill cache
    // ----------

    //initialize cache for tests to run
    void test_cache_1 (){
        CPPUNIT_ASSERT(cache[0] == 1);
        CPPUNIT_ASSERT(cache[9] == 7);
        CPPUNIT_ASSERT(cache[19] == 8);
    }

    void test_cache_2 (){
        CPPUNIT_ASSERT(cache[78891] == 64);
        CPPUNIT_ASSERT(cache[89999] == 165);
        CPPUNIT_ASSERT(cache[76] == 23);
    }

    void test_cache_3 (){
        CPPUNIT_ASSERT(cache[54321] == 40);
        CPPUNIT_ASSERT(cache[876] == 55);
        CPPUNIT_ASSERT(cache[10001] == 66);
    }

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

    //my tests
    void test_read_2 () {
        std::istringstream r("3 1000000\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    3);
        CPPUNIT_ASSERT(j ==   1000000);}

    void test_read_3 () {
        std::istringstream r("123 213214\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    123);
        CPPUNIT_ASSERT(j ==   213214);}

    void test_read_4 () {
        std::istringstream r("341 10\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    341);
        CPPUNIT_ASSERT(j ==   10);}

    void test_read_5 () {
        std::istringstream r("3274 9437\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    3274);
        CPPUNIT_ASSERT(j ==   9437);}

    void test_read_6 () {
        std::istringstream r("1 3728\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    1);
        CPPUNIT_ASSERT(j ==   3728);}

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

    //my tests
    void test_eval_5 () {
        const int v = collatz_eval(1, 1000000);
        CPPUNIT_ASSERT(v == 525);}

    void test_eval_6 () {
        const int v = collatz_eval(4843, 22485);
        CPPUNIT_ASSERT(v == 279);}

    void test_eval_7 () {
        const int v = collatz_eval(1020, 3040);
        CPPUNIT_ASSERT(v == 217);}

    void test_eval_8 () {
        const int v = collatz_eval(9999, 99990);
        CPPUNIT_ASSERT(v == 351);}

    void test_eval_9 () {
        const int v = collatz_eval(1000000, 1);
        CPPUNIT_ASSERT(v == 525);}

    // -----
    // print
    // -----

    void test_print_1 () {
        std::ostringstream w;
        collatz_print(w, 1, 10, 20);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n");}

    //my tests
    void test_print_2 () {
        std::ostringstream w;
        collatz_print(w, 2, 324, 131);
        CPPUNIT_ASSERT(w.str() == "2 324 131\n");}

    void test_print_3 () {
        std::ostringstream w;
        collatz_print(w, 211, 912, 179);
        CPPUNIT_ASSERT(w.str() == "211 912 179\n");}

    void test_print_4 () {
        std::ostringstream w;
        collatz_print(w, 273, 23832, 282);
        CPPUNIT_ASSERT(w.str() == "273 23832 282\n");}

    // -----
    // solve
    // -----

    void test_solve_1 () {
        std::istringstream r("1 10\n100 200\n201 210\n900 1000\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n100 200 125\n201 210 89\n900 1000 174\n");}

    //my tests
    void test_solve_2 () {
        std::istringstream r("128 12931\n359 919\n111 104\n258 1235\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "128 12931 268\n359 919 179\n111 104 114\n258 1235 182\n");}

    void test_solve_3 () {
        std::istringstream r("88 1204\n77 99123\n58 23218\n9009 78881\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "88 1204 182\n77 99123 351\n58 23218 279\n9009 78881 351\n");}

    void test_solve_4 () {
        std::istringstream r("1712 123784\n2349 12984\n192 12981\n12 8173\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1712 123784 354\n2349 12984 268\n192 12981 268\n12 8173 262\n");}

    void test_solve_5 () {
        std::istringstream r("9942 10325\n1000 9\n67 8127\n6 1911\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "9942 10325 242\n1000 9 179\n67 8127 262\n6 1911 182\n");}

    // ------------
    // cycle length
    // ------------

    void test_length_1 (){
        int const result = cycle_length (1000000);
        CPPUNIT_ASSERT(153 == result);}

    void test_length_2 (){
        int const result = cycle_length (1);
        CPPUNIT_ASSERT(1 == result);}

    void test_length_3 (){
        int const result = cycle_length (877339);
        CPPUNIT_ASSERT(176 == result);}

    void test_length_4 (){
        int const result = cycle_length (232323);
        CPPUNIT_ASSERT(169 == result);}

    void test_length_5 (){
        int const result = cycle_length (123456);
        CPPUNIT_ASSERT(62 == result);}

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestCollatz);

    //test cache
    CPPUNIT_TEST(test_cache_1);
    CPPUNIT_TEST(test_cache_2);
    CPPUNIT_TEST(test_cache_3);

    //test read
    CPPUNIT_TEST(test_read_1);
    CPPUNIT_TEST(test_read_2);
    CPPUNIT_TEST(test_read_3);
    CPPUNIT_TEST(test_read_4);
    CPPUNIT_TEST(test_read_5);
    CPPUNIT_TEST(test_read_6);

    //test eval
    CPPUNIT_TEST(test_eval_1);
    CPPUNIT_TEST(test_eval_2);
    CPPUNIT_TEST(test_eval_3);
    CPPUNIT_TEST(test_eval_4);
    CPPUNIT_TEST(test_eval_5);
    CPPUNIT_TEST(test_eval_6);
    CPPUNIT_TEST(test_eval_7);
    CPPUNIT_TEST(test_eval_8);
    CPPUNIT_TEST(test_eval_9);

    //test print
    CPPUNIT_TEST(test_print_1);
    CPPUNIT_TEST(test_print_2);
    CPPUNIT_TEST(test_print_3);
    CPPUNIT_TEST(test_print_4);

    //test solve
    CPPUNIT_TEST(test_solve_1);
    CPPUNIT_TEST(test_solve_2);
    CPPUNIT_TEST(test_solve_3);
    CPPUNIT_TEST(test_solve_4);
    CPPUNIT_TEST(test_solve_5);

    //test cycle_length
    CPPUNIT_TEST(test_length_1);
    CPPUNIT_TEST(test_length_2);
    CPPUNIT_TEST(test_length_3);
    CPPUNIT_TEST(test_length_4);
    CPPUNIT_TEST(test_length_5);


    CPPUNIT_TEST_SUITE_END();};

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);  // turn off synchronization with C I/O
    cout << "TestCollatz.c++" << endl;

    //needed for my tests to run correctly
    fill_cache(LIMIT);

    CppUnit::TextTestRunner tr;
    tr.addTest(TestCollatz::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;}
