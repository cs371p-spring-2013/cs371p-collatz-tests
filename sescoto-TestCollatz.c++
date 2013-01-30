
// --------------------------------
//  TestCollatz.c++
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
    or
    % g++ -ldl -pedantic -std=c++0x -Wall Collatz.c++ TestCollatz.c++ -lcppunit -o TestCollatz.c++.app
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
    /*
    // ----
    //  Student added function
    // cyclelength
    // ----

    void test_cyclelength1 () {
        std::istringstream r("cyclelength of 1:\n");
        const int b = cyclelength(1);
        CPPUNIT_ASSERT(b == 1);
    }
    
    void test_cyclelength2 () {
        std::istringstream r("cyclelength of 3:\n");
        const int b = cyclelength(3);
        CPPUNIT_ASSERT(b == 8);
    }

    void test_cyclelength3 () {
        std::istringstream r("cyclelength of 6:\n");
        const int b = cyclelength(6);
        CPPUNIT_ASSERT(b == 9);
    }
    void test_cyclelength4 () {
        std::istringstream r("cyclelength of 100:\n");
        const int b = cyclelength(100);
        CPPUNIT_ASSERT(b == 26);
    }
    void test_cyclelength5 () {
        std::istringstream r("cyclelength of 999:\n");
        const int b = cyclelength(999);
        CPPUNIT_ASSERT(b == 50);
    }
    void test_cyclelength6 () {
        std::istringstream r("cyclelength of 500:\n");
        const int b = cyclelength(500);
        CPPUNIT_ASSERT(b == 111);
    }
    */
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
    
    //Student added tests:
   void test_read2 () {
        std::istringstream r("10 1\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
        CPPUNIT_ASSERT(i ==   10);
        CPPUNIT_ASSERT(j ==   1);}

    void test_read3 () {
        std::istringstream r("\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == false);
    }
    void test_read4 () {
        std::istringstream r("1 1\n");
        int i;
        int j;
        const bool b = collatz_read(r, i, j);
        CPPUNIT_ASSERT(b == true);
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
    
    //Student added test cases:
    void test_eval_5 () {
        const int v = collatz_eval(451, 3046);
        CPPUNIT_ASSERT(v == 217);}
    void test_eval_6 () {
        const int v = collatz_eval(890, 6476);
        CPPUNIT_ASSERT(v == 262);}
    void test_eval_7 () {
        const int v = collatz_eval(613, 552);
        CPPUNIT_ASSERT(v == 137);}

    // -----
    // print
    // -----

    void test_print () {
        std::ostringstream w;
        collatz_print(w, 1, 10, 20);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n");}
    
    //Student added test cases:
    void test_print2 () {
        std::ostringstream w;
        collatz_print(w, 16, 7299, 262);
        CPPUNIT_ASSERT(w.str() == "16 7299 262\n");}
    void test_print3 () {
        std::ostringstream w;
        collatz_print(w, 594, 450, 142);
        CPPUNIT_ASSERT(w.str() == "594 450 142\n");}
    void test_print4 () {
        std::ostringstream w;
        collatz_print(w, 545, 1754, 182);
        CPPUNIT_ASSERT(w.str() == "545 1754 182\n");}

    // -----
    // solve
    // -----

    void test_solve () {
        std::istringstream r("1 10\n100 200\n201 210\n900 1000\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 10 20\n100 200 125\n201 210 89\n900 1000 174\n");}

    //Student-made tests:
    void test_solve2 () {
        std::istringstream r("4 40\n6 83\n7 6\n9 12\n2 15\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "4 40 112\n6 83 116\n7 6 17\n9 12 20\n2 15 20\n");}


    void test_solve3 () {
        std::istringstream r("1 68\n2 76\n6 21\n4 36\n4 35\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 68 113\n2 76 116\n6 21 21\n4 36 112\n4 35 112\n");}

    void test_solve4 () {
        std::istringstream r("93 6597\n12 6453\n97 5235\n19 9861\n19 4366\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "93 6597 262\n12 6453 262\n97 5235 238\n19 9861 262\n19 4366 238\n");}

    void test_solve5 () {
        std::istringstream r("503 7235\n594 4696\n561 5961\n156 2904\n149 552\n");
        std::ostringstream w;
        collatz_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "503 7235 262\n594 4696 238\n561 5961 238\n156 2904 209\n149 552 144\n");}

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestCollatz);
    /*
    CPPUNIT_TEST(test_cyclelength1);
    CPPUNIT_TEST(test_cyclelength2);
    CPPUNIT_TEST(test_cyclelength3);
    CPPUNIT_TEST(test_cyclelength4);
    CPPUNIT_TEST(test_cyclelength5);
    CPPUNIT_TEST(test_cyclelength6);*/

    CPPUNIT_TEST(test_read);

    CPPUNIT_TEST(test_read2);
    CPPUNIT_TEST(test_read3);
    CPPUNIT_TEST(test_read4);

    CPPUNIT_TEST(test_eval_1);
    CPPUNIT_TEST(test_eval_2);
    CPPUNIT_TEST(test_eval_3);
    CPPUNIT_TEST(test_eval_4);

    CPPUNIT_TEST(test_eval_5);
    CPPUNIT_TEST(test_eval_6);
    CPPUNIT_TEST(test_eval_7);

    CPPUNIT_TEST(test_print);

    CPPUNIT_TEST(test_print2);
    CPPUNIT_TEST(test_print3);
    CPPUNIT_TEST(test_print4);

    CPPUNIT_TEST(test_solve);

    CPPUNIT_TEST(test_solve2);
    CPPUNIT_TEST(test_solve3);
    CPPUNIT_TEST(test_solve4);
    CPPUNIT_TEST(test_solve5);

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