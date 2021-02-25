
/*
 * @ClassName: Score
 * @Description:    
 * @Author:  Ravitn
 * @Date: 2021-02-25 17:11
*/

#include "iostream"
#include "Score.h"

using namespace std;

Score::Score(string nm, double en, double chi) {
    name = nm;
    english = en;
    chinese = chi;
    //new

}

Score::~Score() {
    //delete

}

Score Score::operator+(const Score score) const {
    Score result;
    result.chinese = chinese + score.chinese;
    result.english = english + score.english;
    return result;
}

Score Score::operator+(const double en) const {
    Score result;
    result.chinese = chinese + en;
    result.english = english + en;
    return result;
}

Score::operator double() const {
    return chinese + english;
}

void Score::showScore() {
  std::cout << "name:" << name  << " english:" << english<< " chinese:" << chinese << "\n";
}


/*std::ostream &Score::operator<<(ostream &os, const Score score) const {
    return os;
}*/
