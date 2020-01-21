/*
* Zachary Leggett
* zjl0002
* hw3_zjl0002.cpp
* 
* This program simulates 10,000 duels with 3 shooters with different
* accuracies and strategies.
*
* Compile using "g++ hw3_zjl0002.cpp"
* Run using "./a.out"
*
* No sources were used.
*/

# include <iostream>
# include <stdlib.h>
# include <assert.h>
# include <ctime>

using namespace std;

//Required constants
//Accuracies are in percent form
const double A_ACCURACY = (1.0/3.0) * 100.0;
const double B_ACCURACY = (1.0/2.0) * 100.0;
const double C_ACCURACY = 100;
const int TOTAL_DUELS = 10000;

int A_wins, B_wins, C_wins;

bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive);
void Aaron_shoots1(bool& B_alive, bool& C_alive);
void Bob_shoots(bool& A_alive, bool& C_alive);
void Charlie_shoots(bool& A_alive, bool& B_alive);
void Aaron_shoots2(bool& B_alive, bool& C_alive);
void test_at_least_two_alive(void);
void Set_true(bool& A_alive, bool& B_alive, bool& C_alive);
void Simulate1(bool& A_alive, bool& B_alive, bool& C_alive);
void Simulate2(bool& A_alive, bool& B_alive, bool& C_alive);

int main() {
   srand(time(0));

   bool A_alive = true;
   bool B_alive = true;
   bool C_alive = true;

   int strategy1, strategy2;

   cout << "*** Welcome to the Duel Simulator ***" << endl;
   test_at_least_two_alive();
   cout << "Press Enter to continue...";
   cin.get();
   cout << "Ready to test strategy 1 (run 10000 times):" << endl;
   cout << "Press Enter to continue...";
   cin.get();

   for (int i = 0; i < TOTAL_DUELS; i++) {
      Simulate1(A_alive, B_alive, C_alive);
      Set_true(A_alive, B_alive, C_alive);
   }
	
   strategy1 = A_wins;

   cout << "Aaron won " << A_wins << "/" << TOTAL_DUELS << " duels or " << (A_wins / 100.0) << "%" << endl;
   cout << "Bob won " << B_wins << "/" << TOTAL_DUELS << " duels or " << (B_wins / 100.0) << "%" << endl;
   cout << "Charlie won " << C_wins << "/" << TOTAL_DUELS << " duels or " << (C_wins / 100.0) << "%" << endl;

   cout << endl << "Ready to test strategy 2 (run 10000 times):" << endl;
   cout << "Press Enter to continue...";
   cin.get();

   A_wins = 0;
   B_wins = 0;
   C_wins = 0;

   for (int i = 0; i < TOTAL_DUELS; i++) {
      Simulate2(A_alive, B_alive, C_alive);
      Set_true(A_alive, B_alive, C_alive);
   }

   strategy2 = A_wins;

   cout << "Aaron won " << A_wins << "/" << TOTAL_DUELS << " duels or " << (A_wins / 100.0) << "%" << endl;
   cout << "Bob won " << B_wins << "/" << TOTAL_DUELS << " duels or " << (B_wins / 100.0) << "%" << endl;
   cout << "Charlie won " << C_wins << "/" << TOTAL_DUELS << " duels or " << (C_wins / 100.0) << "%" << endl;

   if (strategy2 > strategy1) {
      cout << endl << "Strategy 2 is better than strategy 1." << endl;
   }
   else {
      cout << endl << "Strategy 1 is better than strategy 2." << endl;
   }

   return 0;
}


/* Input: A_alive indicates whether Aaron is alive */
/* B_alive indicates whether Bob is alive */
/* C_alive indicates whether Charlie is alive */
/* Return: true if at least two are alive */
/* otherwise return false */
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) {
   if ((A_alive && B_alive) || (A_alive && C_alive) || (B_alive && C_alive)) {
      return true;
   }

   return false;
}

/* Strategy 1: Use call by reference
* Input: B_alive indicates whether Bob alive or dead
* C_alive indicates whether Charlie is alive or dead
* Return: Change B_alive into false if Bob is killed.
* Change C_alive into false if Charlie is killed.
*/
void Aaron_shoots1(bool& B_alive, bool& C_alive) {
   int shoot_target_result = rand() % 100;
   if (shoot_target_result <= A_ACCURACY) {
      if (C_alive) {
         C_alive = false;
      }
      else {
         B_alive = false;
      }
   }
}

/* Call by reference
* Input: A_alive indicates if Aaron is alive or dead
* C_alive indicates whether Charlie is alive or dead
* Return: Change A_alive into false if Aaron is killed.
* Change C_alive into false if Charlie is killed.
*/
void Bob_shoots(bool& A_alive, bool& C_alive) {
   int shoot_target_result = rand() % 100;
   if (shoot_target_result <= B_ACCURACY) {
      if (C_alive) {
         C_alive = false;
      }
      else {
         A_alive = false;
      }
   }
}

/* Call by reference
* Input: A_alive indicates if Aaron is alive or dead
* B_alive indicates whether Bob is alive or dead
* Return: Change A_alive into false if Aaron is killed.
* Change B_alive into false if Bob is killed.
*/
void Charlie_shoots(bool& A_alive, bool& B_alive) {
   if (B_alive) {
      B_alive = false;
   }
   else {
      A_alive = false;
   }
}

/* Strategy 2: Use call by reference
* Input: B_alive indicates whether Bob alive or dead
* C_alive indicates whether Charlie is alive or dead
* Return: Change B_alive into false if Bob is killed.
* Change C_alive into false if Charlie is killed.
*/
void Aaron_shoots2(bool& B_alive, bool& C_alive) {
   if (!B_alive || !C_alive) {
      int shoot_target_result = rand() % 100;
      if (shoot_target_result <= A_ACCURACY) {
         if (C_alive) {
            C_alive = false;
         }
         else {
            B_alive = false;
         }
      }
   }
}

/*
* Sets boolean value for all shooters to true.
*/
void Set_true(bool& A_alive, bool& B_alive, bool& C_alive) {
   A_alive = true;
   B_alive = true;
   C_alive = true;
}

/*
* Simulates 10,000 duels using strategy 1.
*/
void Simulate1(bool& A_alive, bool& B_alive, bool& C_alive) {
   while (at_least_two_alive(A_alive, B_alive, C_alive)) {
      if (A_alive) {
         Aaron_shoots1(B_alive, C_alive);
      }
      if (B_alive) {
         Bob_shoots(A_alive, C_alive);
      }
      if (C_alive) {
         Charlie_shoots(A_alive, B_alive);
      }
   }

   if (A_alive) {
      A_wins++;
   }
   else if (B_alive) {
      B_wins++;
   }
   else {
      C_wins++;
   }
}

/*
* Simulates 10,000 duels using strategy 2.
*/
void Simulate2(bool& A_alive, bool& B_alive, bool& C_alive) {
   while (at_least_two_alive(A_alive, B_alive, C_alive)) {
      if (A_alive) {
         Aaron_shoots2(B_alive, C_alive);
      }
      if (B_alive) {
         Bob_shoots(A_alive, C_alive);
      }
      if (C_alive) {
         Charlie_shoots(A_alive, B_alive);
      }
   }

   if (A_alive) {
      A_wins++;
   }
   else if (B_alive) {
      B_wins++;
   }
   else {
      C_wins++;
   }
}

/*
* Test drivers for at_least_two_alive.
*/
void test_at_least_two_alive(void) {
   cout << "Unit Testing 1: Function – at_least_two_alive()\n";
   cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive\n";
   assert(true == at_least_two_alive(true, true, true));
   cout << "\tCase passed ...\n";
   cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
   assert(true == at_least_two_alive(false, true, true));
   cout << "\tCase passed ...\n";
   cout << "\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
   assert(true == at_least_two_alive(true, false, true));
   cout << "\tCase passed ...\n";
   cout << "\tCase 4: Aaron alive, Bob alive, Charlie dead\n";
   assert(true == at_least_two_alive(true, true, false));
   cout << "\tCase passed ...\n";
   cout << "\tCase 5: Aaron dead, Bob dead, Charlie alive\n";
   assert(false == at_least_two_alive(false, false, true));
   cout << "\tCase passed ...\n";
   cout << "\tCase 6: Aaron dead, Bob alive, Charlie dead\n";
   assert(false == at_least_two_alive(false, true, false));
   cout << "\tCase passed ...\n";
   cout << "\tCase 7: Aaron alive, Bob dead, Charlie dead\n";
   assert(false == at_least_two_alive(true, false, false));
   cout << "\tCase passed ...\n";
   cout << "\tCase 8: Aaron dead, Bob dead, Charlie dead\n";
   assert(false == at_least_two_alive(false, false, false));
   cout << "\tCase passed ...\n";
}

