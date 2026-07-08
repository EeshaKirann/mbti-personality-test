#include <iostream>
#include <string>
using namespace std;

// ---------- STRUCTURE ----------
struct Question {
    string text;
    int posTrait;
    int negTrait;
};

// ---------- FUNCTION DECLARATIONS ----------
void showIntro();
void askQuestions(Question q[], int score[], int size);
string calculateMBTI(int score[]);
void showPersonality(string mbti);

// ---------- MAIN FUNCTION ----------
int main() {
    int score[8] = {0};
    // 0=E, 1=I, 2=S, 3=N, 4=T, 5=F, 6=J, 7=P

    Question q[20] = {
        {"You enjoy being the center of attention.", 0, 1},
        {"You feel energized after social interaction.", 0, 1},
        {"You prefer group discussions over solo work.", 0, 1},
        {"You like making new friends easily.", 0, 1},
        {"You focus more on details than the big picture.", 2, 3},
        {"You trust experience more than imagination.", 2, 3},
        {"You prefer practical solutions over abstract ideas.", 2, 3},
        {"You live more in the present than the future.", 2, 3},
        {"You enjoy observing patterns and possibilities.", 3, 2},
        {"Logic is more important than feelings when deciding.", 4, 5},
        {"You value fairness over kindness.", 4, 5},
        {"You stay objective even in emotional situations.", 4, 5},
        {"You consider emotions before making decisions.", 5, 4},
        {"You like having a clear plan for everything.", 6, 7},
        {"You prefer schedules over flexibility.", 6, 7},
        {"You feel stressed when plans change suddenly.", 6, 7},
        {"You like going with the flow instead of planning.", 7, 6},
        {"You enjoy taking risks and trying new things.", 7, 6},
        {"You reflect deeply on ideas and theories.", 3, 2},
        {"You often help others even if it's inconvenient.", 5, 4}
    };

    char choice;
    showIntro();
    cout << "Do you want to take the test? (y/n): ";
    cin >> choice;

    if(choice != 'y' && choice != 'Y') {
        cout << "\nTest cancelled. Thank you!\n";
        return 0;
    }

    askQuestions(q, score, 20);
    string mbti = calculateMBTI(score);

    cout << "\n=====================================\n";
    cout << "Your MBTI Personality Type: " << mbti << endl;
    cout << "=====================================\n";
    showPersonality(mbti);

    return 0;
}

// ---------- FUNCTIONS ----------
void showIntro() {
    cout << "=====================================\n";
    cout << "         MBTI PERSONALITY TEST        \n";
    cout << "=====================================\n\n";
    cout << "E-I: Extrovert - Introvert\n";
    cout << "S-N: Sensing - Intuition\n";
    cout << "T-F: Thinking - Feeling\n";
    cout << "J-P: Judging - Perceiving\n\n";
}

void askQuestions(Question q[], int score[], int size) {
    char ans;
    for(int i = 0; i < size; i++) {
        cout << "\n" << i+1 << ". " << q[i].text << endl;
        do {
            cout << "1) Strongly Agree\n";
            cout << "2) Agree\n";
            cout << "3) Neutral\n";
            cout << "4) Disagree\n";
            cout << "5) Strongly Disagree\n";
            cout << "Enter your choice (1-5): ";
            cin >> ans;
            if(ans < '1' || ans > '5')
                cout << "Invalid input. Please enter between 1 and 5.\n";
        } while(ans < '1' || ans > '5');

        if(ans == '1')
            score[q[i].posTrait] += 2;
        else if(ans == '2')
            score[q[i].posTrait] += 1;
        else if(ans == '4')
            score[q[i].negTrait] += 1;
        else if(ans == '5')
            score[q[i].negTrait] += 2;
    }
}

string calculateMBTI(int score[]) {
    string mbti = "";
    mbti += (score[0] > score[1]) ? 'E' : 'I';
    mbti += (score[2] > score[3]) ? 'S' : 'N';
    mbti += (score[4] > score[5]) ? 'T' : 'F';
    mbti += (score[6] > score[7]) ? 'J' : 'P';
    return mbti;
}

void showPersonality(string mbti) {
    cout << "\n--- Personality Traits ---\n";
    if(mbti=="INTJ") cout << "Strategic, independent, logical.\n";
    else if(mbti=="INTP") cout << "Analytical, curious, innovative.\n";
    else if(mbti=="ENTJ") cout << "Confident, decisive leader.\n";
    else if(mbti=="ENTP") cout << "Creative, energetic, adaptable.\n";
    else if(mbti=="INFJ") cout << "Insightful, empathetic, principled.\n";
    else if(mbti=="INFP") cout << "Idealistic, loyal, caring.\n";
    else if(mbti=="ENFJ") cout << "Charismatic, supportive.\n";
    else if(mbti=="ENFP") cout << "Enthusiastic, imaginative.\n";
    else if(mbti=="ISTJ") cout << "Responsible, disciplined.\n";
    else if(mbti=="ISFJ") cout << "Caring, detail-oriented.\n";
    else if(mbti=="ESTJ") cout << "Organized, efficient.\n";
    else if(mbti=="ESFJ") cout << "Warm, cooperative.\n";
    else if(mbti=="ISTP") cout << "Logical, practical.\n";
    else if(mbti=="ISFP") cout << "Gentle, artistic.\n";
    else if(mbti=="ESTP") cout << "Bold, action-oriented.\n";
    else if(mbti=="ESFP") cout << "Playful, outgoing.\n";
    cout << "=====================================\n";
}
