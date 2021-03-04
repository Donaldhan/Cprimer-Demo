//
// Created by Ravitn on 2021/2/24.
//

#ifndef CPRIMER_DEMO_GOLF_H
#define CPRIMER_DEMO_GOLF_H

#endif //CPRIMER_DEMO_GOLF_H

namespace golfNameSpace{
    const int Len = 40;
    struct golf
    {
        //
        char fullname[Len];
        //
        int handicap;
    };
/**
 *
 * @param g
 * @param name
 * @param hc
 */
    void setgolf(golf & g, const char * name, int hc);
/**
 *
 * @param g
 * @return
 */
    int setgolf(golf & g);
/**
 *
 * @param g
 * @param hc
 */
    void  handicap(golf & g, int hc);
/**
 *
 * @param g
 */
    void showgolf(const golf & g);
}
