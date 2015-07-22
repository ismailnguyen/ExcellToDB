#define __WIN__
#include "mysql.h"
#pragma hdrstop
#include "Client.h"
#include <string>
#include <iostream>
#include <fstream>
#include "BasicExcel.h"
using namespace YExcel;
using namespace std;
MYSQL *mySQL;
//---------------------------------------------------------------------------

Client::Client()
{
        mySQL = mysql_init(NULL);
        if(!mysql_real_connect(mySQL, "127.0.0.1", "btsiris", "btsiris", "pme", 0, NULL, 0))
        {
                fprintf(stderr, "Impossible de se connecter � la base de donn�es, erreur : %s\n", mysql_error(mySQL));
               // return 0;
        }

        m_identifiant = NULL;
        strcpy(m_adresse, "");
        strcpy(m_complement, "");
        strcpy(m_ville, "");
        m_codePostal = NULL;
        strcpy(m_typeImmeuble, "");
        m_nombreEtage = NULL;
}

Client :: Client(int identifiant, const char* adresse, const char* complement,
        const char* ville, int codePostal, const char* typeImmeuble, int nombreEtage)
{
        m_identifiant = identifiant;
        strcpy(m_adresse, adresse);
        strcpy(m_complement, complement);
        strcpy(m_ville, ville);
        m_codePostal = codePostal;
        strcpy(m_typeImmeuble, typeImmeuble);
        m_nombreEtage = nombreEtage;
}

Client::~Client()
{
         mysql_close(mySQL);
}

void Client::setIdentifiant(int identifiant)
{
        this->m_identifiant = identifiant;
}

int Client::getIdentifiant()
{
        return this->m_identifiant;
}

void Client::setAdresse(const char* adresse)
{
        strcpy(m_adresse, adresse);
}

const char* Client::getAdresse()
{
        return this->m_adresse;
}

void Client::setComplement(const char* complement)
{
        strcpy(m_complement, complement);
}

const char* Client::getComplement()
{
        return this->m_complement;
}

void Client::setVille(const char* ville)
{
        strcpy(m_ville, ville);

}

const char* Client::getVille()
{
        return this->m_ville;
}

void Client::setCodePostal(int codePostal)
{
        this->m_codePostal = codePostal;
}

int Client::getCodePostal()
{
        return this->m_codePostal;
}

void Client::setTypeImmeuble(const char* typeImmeuble)
{
        strcpy(m_typeImmeuble, typeImmeuble);
}

const char* Client::getTypeImmeuble()
{
        return this->m_typeImmeuble;
}

void Client::setNombreEtage(int nombreEtage)
{
        this->m_nombreEtage = nombreEtage;
}

int Client::getNombreEtage()
{
        return this->m_nombreEtage;
}

void Client::affiche()
{
        cout << m_identifiant << " | "
        << m_adresse << " | " <<
         m_ville << " | " <<
          m_codePostal << " | " <<
           m_typeImmeuble << " | " <<
            m_nombreEtage << endl;
}

int Client::verifierEtCorrigerCodePostal()
{
        string ville, codepostal, vide;
        int icodepostal;
        ifstream MonFichier2;
        MonFichier2.open("CODESPOSTAUX.csv");
        if(!MonFichier2.is_open())
                return -1;

        while(!MonFichier2.eof())
        {
                getline(MonFichier2, ville, ';'); // on recupere le nom de la ville
                if(ville.compare(this->m_ville) == 0)  //si on a 2 villes identiques
                {
                        getline(MonFichier2, codepostal, ';');
                        icodepostal=atoi(codepostal.c_str());
                        if(icodepostal!=this->m_codePostal) // et que les CP sont diff�rents, on les met � egalit�
                        {
                                this->m_codePostal = icodepostal;
                                return 1;
                        }
                        return 0;
                }

                getline(MonFichier2, vide); // le reste on s'en fou
        }
        MonFichier2.close();
        
        return -2;
}

int Client::mettreAJourBaseDeDonnees()
{

        
        MYSQL_RES *result;
        MYSQL_ROW elementsColonne;
        char idAModifier[50], str1[200];
        sprintf(idAModifier, "%d", m_identifiant);
        int req;

        strcpy(str1, "SELECT * FROM client WHERE identifiant=");
        strcat(str1, idAModifier);

        req = mysql_query(mySQL, str1);

        result = mysql_store_result(mySQL);

        cout << str1 <<endl << endl;

        if(result)
        {
                if(mysql_num_rows(result) > 0)
                {
                        char str[200], cp[50], identifiant[50];
                        sprintf(cp, "%d", m_codePostal);
                        sprintf(identifiant, "%d", m_identifiant);

                        strcpy(str, "UPDATE client SET codePostal='");
                        strcat(str, cp);
                        strcat(str, "' WHERE identifiant='");
                        strcat(str, identifiant);
                        strcat(str, "'");

                        mysql_query(mySQL, str);
                        mysql_free_result(result);
                        cout << "Modification du client : " << identifiant <<"\n\n" << endl;
                        return 2;  //modification d'un client d�j� existant
                }
                else
                {
                        char str[200], cp[50], identifiant[50], nombreEtage[50];
                        sprintf(cp, "%d", m_codePostal);
                        sprintf(identifiant, "%d", m_identifiant);
                        sprintf(nombreEtage, "%d", m_nombreEtage);

                        strcpy(str, "INSERT INTO client VALUES('");
                        strcat(str, identifiant);
                        strcat(str, "', '");
                        strcat(str, m_adresse);
                        strcat(str, "', '");
                        strcat(str, m_complement);
                        strcat(str, "', '");
                        strcat(str, m_ville);
                        strcat(str, "', '");
                        strcat(str, cp);
                        strcat(str, "', '");
                        strcat(str, m_typeImmeuble);
                        strcat(str, "', '");
                        strcat(str, nombreEtage);
                        strcat(str, "')");
 
                        mysql_query(mySQL, str);
                        mysql_free_result(result);
                        cout << "Insertion d'un nouveau client : " << identifiant <<"\n\n" << endl;
                        return 1;  //insertion d'un nouveau client
                }
        }
}

//---------------------------------------------------------------------------
#pragma package(smart_init)
