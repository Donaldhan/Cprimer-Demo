
/*
 * @ClassName: ScoreMain
 * @Description:    
 * @Author:  Ravitn
 * @Date: 2021-02-25 17:46
*/
#include "iostream"
# include "Score.h"
int  main(){
    Score ravitn = Score("Ravitn", 10.0, 12.0);
    Score vt = Score("VT", 10.0, 12.0);
    Score sum = ravitn + vt;
    sum.showScore();
    sum = sum + ravitn;
    sum.showScore();
    sum = sum + 6;
    sum.showScore();
    double result = (double )sum;
    std::cout << "result:" << result << "\n";
}
