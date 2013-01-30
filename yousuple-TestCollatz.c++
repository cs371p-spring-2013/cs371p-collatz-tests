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
    % g++ Collatz.c++ TestCollatz.c++ -lcppunit -ldl -pedantic -std=c++0x -Wall -o TestCollatz.c++.app
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
	unsigned a;
	unsigned cache[200000];

// -----------
// TestCollatz
// -----------

struct TestCollatz : CppUnit::TestFixture {
    // ----
    // read
    // ----

    void test_read () {
        std::istringstream r("1 10\n");
        unsigned i;
        unsigned j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    1);
        CPPUNIT_ASSERT(j ==   10);}

    void my_test_read1 () {
        std::istringstream r("1 100\n");
        unsigned i;
        unsigned j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    1);
        CPPUNIT_ASSERT(j ==   100);}

    void my_test_read2 () {
        std::istringstream r("40000 45000\n");
        unsigned i;
        unsigned j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    40000);
        CPPUNIT_ASSERT(j ==   45000);}

    void my_test_read3 () {
        std::istringstream r("135 276\n");
        unsigned i;
        unsigned j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    135);
        CPPUNIT_ASSERT(j ==   276);}

    // ----
    // eval
    // ----
	// initialize cache (an array)


    void test_eval_1 () {
        const unsigned v = collatz_eval(1, 10, cache);
        CPPUNIT_ASSERT(v == 20);}

    void test_eval_2 () {
        const unsigned v = collatz_eval(100, 200, cache);
        CPPUNIT_ASSERT(v == 125);}

    void test_eval_3 () {
        const unsigned v = collatz_eval(201, 210, cache);
        CPPUNIT_ASSERT(v == 89);}

    void test_eval_4 () {
        const unsigned v = collatz_eval(900, 1000, cache);
        CPPUNIT_ASSERT(v == 174);}

    void my_test_eval_1 () {
        const unsigned v = collatz_eval(200, 700, cache);
        CPPUNIT_ASSERT(v == 145);}

    void my_test_eval_2 () {
        const unsigned v = collatz_eval(1, 1, cache);
        CPPUNIT_ASSERT(v == 1);}

    void my_test_eval_3 () {
        const unsigned v = collatz_eval(3, 7, cache);
        CPPUNIT_ASSERT(v == 17);}


    // -----
    // print
    // -----

    void test_print () {
        std::ostringstream w;
        collatz_print(w, 1, 10, 20);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n");}

    void my_test_print1 () {
        std::ostringstream w;
        collatz_print(w, 10, 100, 119);
        CPPUNIT_ASSERT(w.str() == "10 100 119\n");}

    void my_test_print2 () {
        std::ostringstream w;
        collatz_print(w, 20, 22, 16);
        CPPUNIT_ASSERT(w.str() == "20 22 16\n");}

    void my_test_print3 () {
        std::ostringstream w;
        collatz_print(w, 51234, 64567, 340);
        CPPUNIT_ASSERT(w.str() == "51234 64567 340\n");}

    // -----
    // solve
    // -----

    void test_solve () {
        std::istringstream r("1 10\n100 200\n201 210\n900 1000\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n100 200 125\n201 210 89\n900 1000 174\n");}

    void my_test_solve1 () {
        std::istringstream r("1 100\n5 7\n13 19\n700 701\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 100 119\n5 7 17\n13 19 21\n700 701 83\n");}

    void my_test_solve2 () {
        std::istringstream r("20 22\n50 75\n1120 5000\n897 1345\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "20 22 16\n50 75 116\n1120 5000 238\n897 1345 182\n");}

    void my_test_solve3 () {
        std::istringstream r("2 45\n6 433\n128 182\n345 543\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "2 45 112\n6 433 144\n128 182 125\n345 543 142\n");}

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestCollatz);
    CPPUNIT_TEST(test_read);
    CPPUNIT_TEST(my_test_read1);
    CPPUNIT_TEST(my_test_read2);
    CPPUNIT_TEST(my_test_read3);
    CPPUNIT_TEST(test_eval_1);
    CPPUNIT_TEST(test_eval_2);
    CPPUNIT_TEST(test_eval_3);
    CPPUNIT_TEST(test_eval_4);
    CPPUNIT_TEST(my_test_eval_1);
    CPPUNIT_TEST(my_test_eval_2);
    CPPUNIT_TEST(my_test_eval_3);
    CPPUNIT_TEST(test_print);
    CPPUNIT_TEST(my_test_print1);
    CPPUNIT_TEST(my_test_print2);
    CPPUNIT_TEST(my_test_print3);
    CPPUNIT_TEST(test_solve);
    CPPUNIT_TEST(my_test_solve1);
    CPPUNIT_TEST(my_test_solve2);
    CPPUNIT_TEST(my_test_solve3);
    CPPUNIT_TEST_SUITE_END();};

// ----
// main
// ----

int main () {
	for (a=0; a<200000; a++) cache[a]=0;
    using namespace std;
    ios_base::sync_with_stdio(false);  // turn off synchronization with C I/O
    cout << "TestCollatz.c++" << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest(TestCollatz::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;}
