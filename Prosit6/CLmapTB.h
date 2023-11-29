#pragma once
namespace NS_Comp_Mappage
{
	ref class CLmapTB
	{
	private:
		System::String^ sSql;
		int Id;
		System::String^ nom;
		System::String^ prenom;
		System::String^ ville;
		System::String^ adresse;
		int cp;
		
	public:
		System::String^ Select(void);
		System::String^ Insert(void);
		System::String^ Delete(int);
		System::String^ Update(void);
		void setId(int);
		void setNom(System::String^);
		void setPrenom(System::String^);
		void setville(System::String^);
		void setadresse(System::String^);
		void setcp(int);
		int getId(void);
		System::String^ getNom(void);
		System::String^ getPrenom(void);
		System::String^ getville(void);
		System::String^ getAdresse(void);
		int getCP(void);


	};
}	