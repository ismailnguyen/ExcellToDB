//---------------------------------------------------------------------------
#include <vcl.h>
#include <iostream>
using namespace std;
#include "BasicExcel.h"
using namespace YExcel;
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{
        BasicExcel MonFichier;

        string ville, codepostal, vide;
        AnsiString Case;
        int ligne, colonne;





        if(!MonFichier.Load("Clients.xls"))
        {
                cout << "Erreur lors de l'ouverture du fichier 1"<< endl;
                cin.get();
                return 0;
        }
        BasicExcelWorksheet* MaFeuille = MonFichier.GetWorksheet("Feuil1");




        for(ligne=0; ligne<MaFeuille->GetTotalRows(); ligne++)
                {

                        BasicExcelCell* MaCase = MaFeuille->Cell(ligne, 3); //on prend la 3ème colonne du fichier XLS qui correspond aux villes

                        if(strcmp(MaCase->GetString(), "Ville") != 0) //si c'est pas le titre
                        {
                                Case = MaCase->GetString();
                                ifstream MonFichier2;
                                MonFichier2.open("CODESPOSTAUX.csv");
                                if(!MonFichier2.is_open())
                                {
                                        cout << "Erreur lors de l'ouverture du fichier 2"<< endl;
                                        cin.get();
                                        return 0;
                                }
                                while(!MonFichier2.eof())
                                {

                                        getline(MonFichier2, ville, ';'); // on recupere le nom de la ville
                                        if(ville.compare(Case.c_str()) == 0)
                                                getline(MonFichier2, codepostal, ';'); // et le code postal

                                        getline(MonFichier2, vide); // le reste on s'en fou

                                }
                                MonFichier2.close();

                                cout << Case.c_str() << " : " << codepostal << "\n" << endl;

                       }

                }


        cin.get();
        return 0;
}
//---------------------------------------------------------------------------
