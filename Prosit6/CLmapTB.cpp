//CLmap.CPP*****************************************************************************************
//#include "pch.h"
#include "CLmapTB.h"

System::String^ NS_Comp_Mappage::CLmapTB::Select(void)
{
	return "SELECT C.[id_personne] AS ClientId, C.[nom], C.[prenom], A.[ville], A.[adresse], A.[CP] " +
		"FROM [Prosit6].[dbo].[Client] AS C " +
		"INNER JOIN [Prosit6].[dbo].[Adresse] AS A ON C.id_personne = A.id_personne";
}
System::String^ NS_Comp_Mappage::CLmapTB::Insert(void)
{
	return "INSERT INTO [Prosit6].[dbo].[Client] (nom, prenom) VALUES('" + this->nom + "','" + this->prenom + "');" +
		"DECLARE @ClientId INT = SCOPE_IDENTITY();" +
		"INSERT INTO [Prosit6].[dbo].[Adresse] (id_personne, ville, adresse, CP) VALUES(@ClientId, '" + this->ville + "','" + this->adresse + "','" + this->cp + "');";
}
System::String^ NS_Comp_Mappage::CLmapTB::Delete(int id_personne)
{
	return "BEGIN TRANSACTION; " +
		"DELETE FROM [Prosit6].[dbo].[Adresse] WHERE id_personne = " + id_personne + ";" +
		"DELETE FROM [Prosit6].[dbo].[Client] WHERE id_personne = " + id_personne + ";" +
		"COMMIT;";
}
System::String^ NS_Comp_Mappage::CLmapTB::Update(void)
{
	return "";
}
void NS_Comp_Mappage::CLmapTB::setId(int Id){							this->Id = Id;}
void NS_Comp_Mappage::CLmapTB::setNom(System::String^ nom){				this->nom = nom;}
void NS_Comp_Mappage::CLmapTB::setPrenom(System::String^ prenom){		this->prenom = prenom;}
void NS_Comp_Mappage::CLmapTB::setville(System::String^ vile){			this->ville = vile;}
void NS_Comp_Mappage::CLmapTB::setadresse(System::String^ adrese){		this->adresse = adrese;}
void NS_Comp_Mappage::CLmapTB::setcp(int CP) {							this->cp = CP; }
int NS_Comp_Mappage::CLmapTB::getId(void) {								return this->Id; }
System::String^ NS_Comp_Mappage::CLmapTB::getNom(void) {				return this->nom; }
System::String^ NS_Comp_Mappage::CLmapTB::getPrenom(void) {				return this->prenom; }
System::String^ NS_Comp_Mappage::CLmapTB::getville(void) {				return this->ville; }
System::String^ NS_Comp_Mappage::CLmapTB::getAdresse(void) {			return this->adresse; }
int NS_Comp_Mappage::CLmapTB::getCP(void) {								return this->cp; }
