#include <vcl.h>
#include <iostream>
using namespace std;
#include "BasicExcel.h"
#include "Client.h"
using namespace YExcel;
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma argsused

int main(int argc, char* argv[])
{
        BasicExcel MonFichier;
        string contenu;
        AnsiString Case1;
        int ligne, colonne, NbClient, tabEntier[10];
        Client tabClient[100];




        if(!MonFichier.Load("Clients.xls"))
        {
                cout << "Erreur lors de l'ouverture du fichier 1"<< endl;
                cin.get();
                return 0;
        }


        BasicExcelWorksheet* MaFeuille = MonFichier.GetWorksheet("Feuil1");


        for(ligne=1; ligne<MaFeuille->GetTotalRows(); ligne++)
        {
                for(colonne=0; colonne<MaFeuille->GetTotalCols(); colonne++)
                {
                        BasicExcelCell* MaCase = MaFeuille->Cell(ligne, colonne);

                        if(MaCase->Type() == BasicExcelCell::INT)
                                Case1 = MaCase->GetInteger();
                        else if(MaCase->Type() == BasicExcelCell::DOUBLE)
                                Case1 = MaCase->GetDouble();
                        else if(MaCase->Type() == BasicExcelCell::STRING)
                                Case1 = MaCase->GetString();
                        else if(MaCase->Type() == BasicExcelCell::WSTRING)
                                Case1 = MaCase->GetWString();
                        else
                                Case1 = NULL;

                        switch (colonne)
                        {
                                case 0 : tabClient[ligne].setIdentifiant(Case1.ToInt()); break;
                                case 1 : tabClient[ligne].setAdresse(Case1.c_str()); break;
                                case 2 : tabClient[ligne].setComplement(Case1.c_str()); break;
                                case 3 : tabClient[ligne].setVille(Case1.c_str()); break;
                                case 4 : tabClient[ligne].setCodePostal(Case1.ToInt()); break;
                                case 5 : tabClient[ligne].setTypeImmeuble(Case1.c_str()); break;
                                case 6 : tabClient[ligne].setNombreEtage(Case1.ToInt()); break;
                        }


                        
                }
                      tabClient[ligne].verifierEtCorrigerCodePostal();
                      tabClient[ligne].affiche();
                      tabClient[ligne].mettreAJourBaseDeDonnees();

        }

        cin.get();


        return 0;
}
//---------------------------------------------------------------------------


