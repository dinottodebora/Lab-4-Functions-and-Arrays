#include <iostream>
#include<iomanip>
using namespace std;

void getScores(int scores[], int size){
    int score_test;
    for (int i=0; i < size; i++){
        cout << "Enter score " << i + 1 << " : ";
        cin >> score_test;
        while (score_test < 0 || score_test > 100){
            cout << "Invalid score. Please enter a value between 0 and 100: ";
            cin >> score_test;
        }
        scores[i] = score_test;
    }
}

void printScores(const int scores[], int size){
    cout << "The scores you entered are: ";

    for(int i=0; i < size; i++ ){
        cout << scores[i] << " ";
    }
}

int getLowest(const int scores[], int size){
    int lowest = scores[0];
    for(int i=0; i < size; i++){
        if(scores[i] < lowest){
            lowest = scores[i];
        }
    }
    return lowest;
}

double calculateAverage(const int scores[], int size){
    int sum = 0;
    int lowest = 0;
    for (int i=0; i < size; i++){
        sum = sum + scores[i];
    }
    lowest = getLowest(scores, size);
    sum = sum - lowest;
    return static_cast<double> (sum) / (size - 1);
}


int main(){

    const int number_of_scores=5;
    int scores[number_of_scores];
    double average = 0;

    getScores(scores, number_of_scores);
    cout << endl;
    printScores(scores, number_of_scores);
    cout << endl;
    average = calculateAverage(scores, number_of_scores);
    cout << "After dropping the lowest score, the average is: " << fixed << setprecision(2) << average;

    return 0;
}
