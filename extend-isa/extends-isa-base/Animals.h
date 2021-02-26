
/*
 * @ClassName: animals
 * @Description:    
 * @Author:  Ravitn
 * @Date: 2021-02-26 15:56
*/


#ifndef CPRIMER_DEMO_ANIMALS_H
#define CPRIMER_DEMO_ANIMALS_H

# include <string>

using namespace std;

class Animals {
protected:
    enum ANIMALS_TYPE { CAT = 1, DOG = 2 };
    void setAnimalsType(int animalsType);
private:
    string name;
    int age;
    char * nickName;
    int animalsType{};
public:
    const string &getName() const;
    void setName(const string &name);
    int getAge() const;
    void setAge(int age);
    int getAnimalsType() const;
    Animals() {
        name = "";
        age = 0;
        nickName = new char[1];
        nickName[1] = '\0';
    };
    /**
     *
     * @param nm
     * @param nickNM
     * @param ag
     */
    Animals(string nm, const char * nickNM, int ag);
    /**
     * 复制构造
     * @param animals
     */
    Animals(const Animals & animals);
    /**
     * 析构函数 虚函数，便于销毁时，删除new的空间
     */
    virtual ~Animals();
    /**
     *
     */
    virtual void show() const;
    /**
     * 赋值构造
     * @param animals
     * @return
     */
    Animals & operator=(const Animals & animals);
};


#endif CPRIMER_DEMO_ANIMALS_H
