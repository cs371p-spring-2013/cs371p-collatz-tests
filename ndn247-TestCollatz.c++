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
    % g++ -ldl -pedantic -std=c++0x -Wall Collatz.c++ TestCollatz.c++ -lcppunit -o TestCollatz.c++.app
    % valgrind ./TestCollatz.c++.app >& TestCollatz.c++.out
*/

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==
#include <tr1/unordered_map> //cache container

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

    // my read tests

    void test_read_1 () {
        std::istringstream r("\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == false);}

    void test_read_2 () {
        std::istringstream r("");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == false);}

    void test_read_3 () {
        std::istringstream r("1000 2\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i == 1000);
        CPPUNIT_ASSERT(j ==    2);}

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

    //my eval tests

    void test_eval_5 () {
        const int v = collatz_eval(1, 1);
        CPPUNIT_ASSERT(v == 1);}

    void test_eval_6 () {
        const int v = collatz_eval(16128, 2216);
        CPPUNIT_ASSERT(v == 276);}
 
    void test_eval_7 () {
        const int v = collatz_eval(384281, 417720);
        CPPUNIT_ASSERT(v == 449);}


    // ------------
    // cycle_length
    // ------------

    void test_cycle_length_1 () {
        const int l = get_cycle_length(10);
        CPPUNIT_ASSERT(l == 7);
    }

    void test_cycle_length_2 () {
        const int l = get_cycle_length(3);
        CPPUNIT_ASSERT(l == 8);
    }

    void test_cycle_length_3 () {
        const int l = get_cycle_length(1);
        CPPUNIT_ASSERT(l == 1);
    }

    // -----
    // print
    // -----

    void test_print () {
        std::ostringstream w;
        collatz_print(w, 1, 10, 20);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n");}

    //my print tests

    void test_print_1 () {
        std::ostringstream w;
        collatz_print(w, 100, 200, 125);
        CPPUNIT_ASSERT(w.str() == "100 200 125\n");}

    void test_print_2 () {
        std::ostringstream w;
        collatz_print(w, 201, 210, 89);
        CPPUNIT_ASSERT(w.str() == "201 210 89\n");}

     void test_print_3 () {
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
        CPPUNIT_ASSERT(w.str() == "1 10 20\n100 200 125\n201 210 89\n900 1000 174\n");}

    //my solve tests

    void test_solve_1 () {
        std::istringstream r("2 2\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "2 2 2\n");}    

    void test_solve_2 () {
        std::istringstream r("10 1\n200 100\n210 201\n1000 900\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "10 1 20\n200 100 125\n210 201 89\n1000 900 174\n");}

    void test_solve_3 () {
        std::istringstream r("4 1\n474581 82339\n39022 19219\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "4 1 8\n474581 82339 449\n39022 19219 324\n");}

    void test_solve_4 () {
        std::istringstream r("1 5\n5 6\n10 10\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 5 8\n5 6 9\n10 10 7\n");
        //additional test of cache content
        std::tr1::unordered_map<unsigned int, int> cache;
        cache[2] = 2;
        cache[4] = 3;
        cache[8] = 4;
        cache[16] = 5;
        cache[5] = 6;
        cache[10] = 7;
        cache[3] = 8;
        cache[6] = 9;
        equals(cache, cl_cache);}

    void equals(std::tr1::unordered_map<unsigned int, int> cache1, std::tr1::unordered_map<unsigned int, int> cache2) {
        CPPUNIT_ASSERT(cache1.size() == cache2.size());
        std::tr1::unordered_map<unsigned int, int>::iterator iterator1 = cache1.begin();
        for(std::tr1::unordered_map<unsigned int, int>::iterator iterator2 = cache2.begin(); iterator2 != cache2.end(); iterator2++) {
            CPPUNIT_ASSERT((iterator1->first == iterator2->first) && (iterator1->second == iterator2->second));
            iterator1++;}}

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestCollatz);
    CPPUNIT_TEST(test_read);
    CPPUNIT_TEST(test_read_1);
    CPPUNIT_TEST(test_read_2);
    CPPUNIT_TEST(test_read_3);
    CPPUNIT_TEST(test_solve_4);
    CPPUNIT_TEST(test_eval_1);
    CPPUNIT_TEST(test_eval_2);
    CPPUNIT_TEST(test_eval_3);
    CPPUNIT_TEST(test_eval_4);
    CPPUNIT_TEST(test_eval_5);
    CPPUNIT_TEST(test_eval_6);
    CPPUNIT_TEST(test_eval_7);
    CPPUNIT_TEST(test_cycle_length_1);
    CPPUNIT_TEST(test_cycle_length_2);
    CPPUNIT_TEST(test_cycle_length_3);
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
