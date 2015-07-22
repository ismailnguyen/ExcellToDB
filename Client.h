//---------------------------------------------------------------------------

#ifndef ClientH
#define ClientH
//---------------------------------------------------------------------------

class Client
{
 
 private:
        int m_identifiant;
        char m_adresse[50];
        char m_complement[50];
        char m_ville[50];
        int m_codePostal;
        char m_typeImmeuble[20];
        int m_nombreEtage;


 public:

        Client();
        Client(int identifiant, const char* adresse, const char* complement,
        const char* ville, int codePostal, const char* typeImmeuble, int nombreEtage);
        ~Client();
        void setIdentifiant(int identifiant);
        int getIdentifiant();
        void setAdresse( const char* adresse);
        const char* getAdresse();
        void setComplement(const char* complement);
        const char* getComplement();
        void setVille(const char* ville);
        const char* getVille();
        void setCodePostal(int codePostal);
        int getCodePostal();
        void setTypeImmeuble(const char* typeImmeuble);
        const char* getTypeImmeuble();
        void setNombreEtage(int nombreEtage);
        int getNombreEtage();
        int verifierEtCorrigerCodePostal();
        int mettreAJourBaseDeDonnees();
        void affiche();
        

};

//---------------------------------------------------------------------------
#endif
