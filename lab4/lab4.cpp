
#include "Header.h"

int main()
{
    std::string Fname, Stopic, Cbandname, Csongname, FUgenre, FUlocation, Mstudio, Aname, Afam;
    int Frate, Sviews, Csongduration, FUactorsquantity, Mallowedage, Mfps, Aage;
    double Fduration;

    std::cout << std::endl << "----------Film--------" << std::endl;
    std::cout << "Film :";
    std::cin >> Fname;
    std::cout << "Duration :";      //film
    std::cin >> Fduration;
    std::cout << "Rate :";
    std::cin >> Frate;

    std::cout <<std::endl<< "----------Short-length--------"<<std::endl;
    std::cout << "Topic :";
    std::cin >> Stopic;
    std::cout << "View :" ;     //short-length
    std::cin >> Sviews;

    std::cout << std::endl << "------------Clip----------- " << std::endl;
    std::cout << "Band name :";
    std::cin >> Cbandname;
    std::cout << "Song name :";     //clip
    std::cin >> Csongname;
    std::cout << "Song duration :";
    std::cin >> Csongduration;

    std::cout << std::endl << "--------------Full-length-------------" << std::endl;
    std::cout << "Genre :";
    std::cin >> FUgenre;
    std::cout << "Duration :"; //  Full-Length
    std::cin >> FUlocation;
    std::cout << "Actors quantity :";
    std::cin >> FUactorsquantity;

    std::cout << std::endl << "---------------Mult----------------" << std::endl;
    std::cout << "Allowed age :";
    std::cin >> Mallowedage;
    std::cout << "Frames per second :";   //Mult
    std::cin >> Mfps;
    std::cout << "Studio :";
    std::cin >> Mstudio;

    std::cout << std::endl << "-------------Actor-----------------" << std::endl;
    std::cout << "Name :" ;
    std::cin >> Aname;
    std::cout << "Fam :" ; 
    std::cin >> Afam;               //Actor
    std::cout << "Age :" ;
    std::cin >> Aage;

    Actor   acto(Fname, Fduration, Frate, Stopic, Sviews, Cbandname, 
        Csongname, Csongduration, FUgenre, FUlocation, FUactorsquantity,
        Mallowedage, Mfps, Mstudio, Aname, Afam, Aage);
    acto.OutputFilm();
    acto.OutputShortLength();
    acto.OutputClip();
    acto.OutputFullLength();
    acto.OutputMult();
    acto.OutputActor();



}

