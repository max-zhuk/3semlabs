
#include "Header.h"
void check(int& a) {
    bool fa = true;
    do
    {
        std::cin >> a;
        if (std::cin.fail())
            std::cout << "error" << std::endl;
        else
            fa = false;
        std::cin.clear();
        std::cin.ignore(std::cin.rdbuf()->in_avail());
    } while (fa);
}
void check(std::string& a) {
    bool fa = true;
    do
    {
        std::cin >> a;
        if (std::cin.fail())
            std::cout << "error" << std::endl;
        else
            fa = false;
        std::cin.clear();
        std::cin.ignore(std::cin.rdbuf()->in_avail());
    } while (fa);
}
void check(double& a) {
    bool fa = true;
    do
    {
        std::cin >> a;
        if (std::cin.fail())
            std::cout << "error" << std::endl;
        else
            fa = false;
        std::cin.clear();
        std::cin.ignore(std::cin.rdbuf()->in_avail());
    } while (fa);
}
int main()
{
    std::string Fname, Stopic, Cbandname, Csongname, FUgenre, FUlocation, Mstudio, Aname, Afam;
    int Frate, Sviews, Csongduration, FUactorsquantity, Mallowedage, Mfps, Aage;
    double Fduration;

    std::cout << std::endl << "----------Film--------" << std::endl;
    std::cout << "Film :";
    check(Fname);
    std::cout << "Duration :";      //film
    check(Fduration);
    std::cout << "Rate :";
    check(Frate);

    std::cout << std::endl << "----------Short-length--------" << std::endl;
    std::cout << "Topic :";
    check(Stopic);
    std::cout << "View :";     //short-length
    check(Sviews);

    std::cout << std::endl << "------------Clip----------- " << std::endl;
    std::cout << "Band name :";
    check(Cbandname);
    std::cout << "Song name :";     //clip
    check(Csongname);
    std::cout << "Song duration :";
    check(Csongduration);

    std::cout << std::endl << "--------------Full-length-------------" << std::endl;
    std::cout << "Genre :";
    check(FUgenre);
    std::cout << "Duration :"; //  Full-Length
    check(FUlocation);
    std::cout << "Actors quantity :";
    check(FUactorsquantity);

    ShortLength s(Stopic, Sviews);
    Clip a(Cbandname, Csongname, Csongduration);
    FullLength m(FUgenre, FUlocation, FUactorsquantity);
    
    Film** mov = new Film * [3];
    mov[0] = &a;
    mov[1] = &m;
    mov[2] = &s;
    for (int i = 0; i < 3; i++)
    {
        mov[i]->Output();
        
        std::cout << std::endl;
    }

}

