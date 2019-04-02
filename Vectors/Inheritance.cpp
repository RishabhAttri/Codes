#include<iostream>
using namespace std;

class Golmaal{
private:
    string MovieType;
public:
    string test;
    Golmaal(){
        MovieType="Comedy";
        test="Test1";
    }
    string virtual getMovieType(){
        return MovieType;
    }

};



class Golmaal1:public Golmaal{

public:
    string getMovieType(){
        return Golmaal::getMovieType() + " Action";
        //return Golmaal::MovieType;
        //return "Comedy Plus Action";
    }

};
class Golmaal2:public Golmaal{

public:
    string getMovieType(){
        return Golmaal::getMovieType() + " Madness";
        //return Golmaal::MovieType;
        //return "Comedy Plus Action";
    }

    string test(){
        return Golmaal::test;
    }

};

int main(){

    /*Golmaal2 g;
    cout<<g.getMovieType()<<endl;
    cout<<g.test();*/

    Golmaal *g;
    g=new Golmaal;
    //cout<<(*g).getMovieType();
    cout<<g->getMovieType()<<endl;
    delete g;
    g=NULL;
    g=new Golmaal1;
    cout<<g->getMovieType()<<endl;

    Golmaal2 *g2=new Golmaal2;
    cout<<g2->getMovieType()<<endl;
    cout<<g2->test()<<endl;

    /*Golmaal g;
    cout<<g.getMovieType()<<endl;

    Golmaal1 g1;
    cout<<g1.getMovieType()<<endl;

    Golmaal2 g2;
    cout<<g2.getMovieType()<<endl;*/


    //Golmaal *g=new Golmaal;
    //cout<<(*g).getMovieType();
    //cout<<g->getMovieType()<<endl;
    /*delete g;
    g=new Golmaal2;
    cout<<g->getMovieType()<<endl;
    //cout<<g->test()<<endl;

    Golmaal2 *g2=new Golmaal2;
    cout<<g2->test()<<endl;*/







}
