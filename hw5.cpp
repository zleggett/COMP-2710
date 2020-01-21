/*
* Zachary Leggett
* zjl0002
* hw5_zjl0002.cpp
*
* This program creates a trivia game used nodes in a linked list.
* Players are asked a question and rewarded points if answered correctly.
*
* Compile using "g++ hw5_zjl0002.cpp"
* Run using "./a.out"
*
* Used www.fredosaurus.com/notes-cpp/preprocessor/ifdef.html to implement the if defined preprocessor commands.
*/

# include <iostream>
# include <cstring>
# include <assert.h>
# include <cstdlib>
using namespace std;

/**
 * Comment this line to enable production version of code.
 **/
//#define UNIT_TESTING

//structure for trvia node
struct triviaNode {
	string question, answer;
	int points;
	triviaNode *next;
};


//class that links trivia nodes together into linked list
class triviaList
{
public:
	int count;
	triviaNode *head, *root;
	triviaList()
	{
		count = 0;
		head = NULL;
		root = NULL;
	}
};

//Creates the three default questions
void initializeList(triviaList &tQ) {
	triviaNode *q1 = new triviaNode;
	triviaNode *q2 = new triviaNode;
	triviaNode *q3 = new triviaNode;

	//Trivia Question 1
	q1->question = "How long was the shortest war on record? (Hint: how many minutes)";
	q1->answer = "38";
	q1->points = 100;
	q1->next = q2;

	//Trivia Question 2
	q2->question = "What was Bank of America's original name? (Hint: Bank of Italy or Bank of Germany)";
	q2->answer = "Bank of Italy";
	q2->points = 50;
	q2->next = q3;

	//Trivia Question 3
	q3->question = "What is the best-selling video game of all time? (Hint: Minecraft or Tetris)";
	q3->answer = "Tetris";
	q3->points = 20;
	q3->next = NULL;

	tQ.head = q1;
	tQ.root = q3;
	tQ.count += 3;
}

//Prompts user to enter more trivia questions if desired
void addTrivia(triviaList &tQ) {
	string response;
	bool moreQuestions = true;
	do {
		tQ.count++;
		triviaNode *temp = new triviaNode;
		cout << "Enter a question: ";
		getline(cin, temp->question);

		cout << "Enter an answer: ";
		getline(cin, temp->answer);

		cout << "Enter award points: ";
		cin >> temp->points;

		cout << "Continue? (Yes/No): ";
		getline(cin.ignore(), response);

		tQ.root->next = temp;
		tQ.root = temp;

		if (response == "No" || response == "no" || response == "N" || response == "n") {
			moreQuestions = false;
		}

	} while (moreQuestions);
}

//Asks users questions and awards points if correct
int askQuestion(triviaList tQ, int i, int &total) {
	triviaNode *q = tQ.head;

	if (i < 1) { 
		cout << "\nWarning - The number of trivia to be asked must equal to or be larger than 1.";
		return 1;
	}
	if (i > tQ.count) { 
		cout << "\nWarning - There are only " << tQ.count << " trivia in the list";
		i = tQ.count;

	}
	string ans;
	total = 0;

	for (int j = 0; j < i; j++) {
		cout << "\nQuestion: " << q->question << "\nAnswer: ";
		getline(cin, ans);

		if (q->answer == ans) {
			cout << "Your answer is correct. You receive " << q->points << " points.";
			total += q->points;    
		}
		else {
			cout << "Your answer is wrong. The correct answer is: " << q->answer;
		}
		cout << "\nYour Total Points: " << total << endl;
		q = q->next;
	}
	return 0;
}

//Tests for askQuestion(triviaList tQ, int i, int &total)
void testAskQuestion()
{
	triviaList tQ;
	int total;

	initializeList(tQ);

	cout << "\nFunction to test: int askQuestion(triviaList& tQ, int i, int &total)\n";

	//Case 1
	cout << "Unit Test Case 1: Ask no questions. The program should give a warning message.\n";

	assert(1 == askQuestion(tQ, 0, total));
	cout << "\nCase 1 passed...\n";

	// Case 2.1
	cout << "\nUnit Test Case 2.1: Ask 1 question in the linked list. The tester enters the correct answer.\n";

	assert(0 == askQuestion(tQ, 1, total));
	assert(100 == total);
	cout << "Case 2.1 passed...\n";

	// Case 2.2
	cout << "\nUnit Test Case 2.2: Ask 1 question in the linked list. The tester enters an incorrect answer.\n";

	assert(0 == askQuestion(tQ, 1, total));
	assert(0 == total);
	cout << "Case 2.2 passed...\n";

	// Case 3.1
	cout << "\nUnit Test Case 3.1: Ask all of the questions in the linked list. The tester enters the correct answers.\n";

	assert(0 == askQuestion(tQ, 3, total));
	assert(170 == total);
	cout << "Case 3.1 passed...\n";

	// Case 3.2
	cout << "\nUnit Test Case 3.2: Ask all of the questions in the linked list. The tester enters the incorrect answers.\n";

	assert(0 == askQuestion(tQ, 3, total));
	assert(0 == total);
	cout << "Case 3.2 passed...\n";

	// Case 4
	cout << "\nUnit Test Case 4: Attempt to ask 5 questions in the linked list. Program should give a warning message.\n";

	assert(0 == askQuestion(tQ, 5, total));
	cout << "Case 4 passed...\n";
}

//Initializes and runs the trivia game
int main() {

#ifdef UNIT_TESTING
	cout << "*** This is a debugging version ***\n";
	testAskQuestion();
	cout << "\n*** End of the debugging version ***\n";

#else
	cout << "*** Welcome to Zachary Leggett's trivia quiz ***" << endl;
	triviaList game;
	int total;
	initializeList(game);
	addTrivia(game);

	cout << "\n";

	//For loop for asking questions and checking answers is located in askquestion(triviaList tQ, int i, int &total) method
	askQuestion(game, game.count, total);

	cout << "\n";

	cout << "\n*** Thank you for playing the trivia quiz game. Goodbye! ***" << endl;

#endif
	return 0;
}

