#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main() {
    srand(time(0));

    int score = 0;
    const int numQuestions = 10;
    cout<<"                                      -----------------------------------";
    cout <<"\n                                      |  Welcome to the Math Quiz Game! |                                        "<< endl;
    cout<<"                                      -----------------------------------";
	cout<<"\n\n";
    cout << "You have " << numQuestions << " questions to answer." << endl;
    cout<<"\n";
    auto startTime = high_resolution_clock::now();

    for (int i = 0; i < numQuestions; ++i) {
           int num1 = rand() % 20 + 1;
        int num2 = rand() % 20 + 1;
        int operation = rand() % 4;
        int correctAnswer;

        char operatorSymbol;

        switch (operation) {
            case 0:
                correctAnswer = num1 + num2;
                operatorSymbol = '+';
                break;
            case 1:
                correctAnswer = num1 - num2;
                operatorSymbol = '-';
                break;
            case 2:
                correctAnswer = num1 * num2;
                operatorSymbol = '*';
                break;
            case 3:
                correctAnswer = num1 / num2;
                operatorSymbol = '/';
                break;
        }

        cout << "Question " << i + 1 << ": ";
        cout << num1 << " " << operatorSymbol << " " << num2 << " = ";
        
        int userAnswer;
        cin >> userAnswer;

        if (userAnswer == correctAnswer) {
            cout << "Correct!" << endl;
            ++score;
        } else {
            cout << "Incorrect. The correct answer is: " << correctAnswer << endl;
        }
    }

    auto endTime = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(endTime - startTime);

    cout << "Quiz complete! Your score is: " << score << " out of " << numQuestions << endl;
    cout << "Time taken: " << duration.count() << " seconds" << endl;

    // Remarks based on performance
    if (score >= 8 && duration.count() < 30) {
        cout << "Excellent! You answered " << score << " questions correctly and completed the quiz in under 30 seconds." << endl;
    } else if (score >= 8) {
        cout << "Great job! You answered " << score << " questions correctly." << endl;
    } else if (score >= 5) {
        cout << "Good effort. You answered " << score << " questions correctly." << endl;
    } else {
        cout << "Keep practicing. You answered " << score << " questions correctly." << endl;
    }

    return 0;
}
