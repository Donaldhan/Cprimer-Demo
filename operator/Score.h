
/*
 * @ClassName: Score
 * @Description:    
 * @Author:  Ravitn
 * @Date: 2021-02-25 17:11
*/


#ifndef CPRIMER_DEMO_SCORE_H
#define CPRIMER_DEMO_SCORE_H

//# include <cstring>
# include <string>
using namespace std;

class Score {
private:
    string name;
    double english;
    double chinese;

public:
    Score(){
        name = "";
        english = 0.0;
        chinese = 0.0;
    };
    /**
     *
     * @param nm
     * @param en
     * @param chi
     */
    Score(string nm, double en, double chi);
    /**
     *
     */
    ~Score();
    /**
     *
     * @param score
     * @return
     */
    Score operator+(const Score score) const;
    /**
     *
     * @param en
     * @return
     */
    Score operator+(const double en) const;
    /**
     *
     * @param os
     * @param score
     * @return
     */
//    std::ostream & operator<<(std::ostream & os , const Score score) const;
    /**
     *
     * @return
     */
    explicit operator double() const;
    void showScore();

};


#endif CPRIMER_DEMO_SCORE_H
