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
  //my test_read's()
 void test_read1 ()
 {
        std::istringstream r("2 20\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    2);
        CPPUNIT_ASSERT(j ==   20);
}
void test_read2 () 
{
        std::istringstream r("3 30\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    3);
        CPPUNIT_ASSERT(j ==   30);
}
void test_read3 ()
 {
        std::istringstream r("4 40\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==    4);
        CPPUNIT_ASSERT(j ==   40);
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

   //My 3 tests for test_eval
     void test_eval_5(){
        const int v = collatz_eval(767415 , 378829);
        CPPUNIT_ASSERT(v == 470);}
  
     void test_eval_6(){
        const int v = collatz_eval(217533 , 392721);
        CPPUNIT_ASSERT(v == 443);}

    void test_eval_7(){
        const int v = collatz_eval(670513 , 476062);
        CPPUNIT_ASSERT(v == 470);}
    // -----
    // print
    // -----

    void test_print () {
        std::ostringstream w;
        collatz_print(w, 1, 10, 20);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n");}

    //My test_print()'s
     void test_print1 () 
{
        std::ostringstream w;
        collatz_print(w, 767415, 378829, 470);
        CPPUNIT_ASSERT(w.str() == "767415 378829 470\n");
}

 void test_print2 () 
{
        std::ostringstream w;
        collatz_print(w, 217533,  392721, 443);
        CPPUNIT_ASSERT(w.str() == "217533 392721 443\n");
}

   void test_print3 () 
{
        std::ostringstream w;
        collatz_print(w, 670513 ,  476062, 470);
        CPPUNIT_ASSERT(w.str() == "670513 476062 470\n");
}

    // -----
    // solve
    // -----

    void test_solve () {
        std::istringstream r("1 10\n100 200\n201 210\n900 1000\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n100 200 125\n201 210 89\n900 1000 174\n");}
   //my test_solve()'s
  void test_solve1 () {
        std::istringstream r("767415 378829\n217533 392721\n670513 476062\n934149 959022\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "767415 378829 470\n217533 392721 443\n670513 476062 470\n934149 959022 445\n");
}

  void test_solve2() {
        std::istringstream r("5553 232625\n356812 501391\n347760 358534\n343007 833393\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "5553 232625 443\n356812 501391 449\n347760 358534 379\n343007 833393 470\n");
}
  void test_solve3 () {
        std::istringstream r("535071 172090\n576030 179266\n302755 921726\n970366 172907\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "535071 172090 470\n576030 179266 470\n302755 921726 476\n970366 172907 476\n");
}

	
    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestCollatz);
    CPPUNIT_TEST(test_read);
   //my test_read()'s
   CPPUNIT_TEST(test_read1);
   CPPUNIT_TEST(test_read2);
   CPPUNIT_TEST(test_read3);

    CPPUNIT_TEST(test_eval_1);
    CPPUNIT_TEST(test_eval_2);
    CPPUNIT_TEST(test_eval_3);
    CPPUNIT_TEST(test_eval_4);
   //my test_eval()'s
    CPPUNIT_TEST(test_eval_5);
    CPPUNIT_TEST(test_eval_6);
    CPPUNIT_TEST(test_eval_7);

    CPPUNIT_TEST(test_print);
    //my test_print()'s
   CPPUNIT_TEST(test_print1);
   CPPUNIT_TEST(test_print2);
   CPPUNIT_TEST(test_print3);
   
 CPPUNIT_TEST(test_solve);
   //my test_solve()'s
   CPPUNIT_TEST(test_solve1);
  CPPUNIT_TEST(test_solve2);
CPPUNIT_TEST(test_solve3);
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