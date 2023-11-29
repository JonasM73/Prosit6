//CLservice.CPP***************************************************************************************
//#include "pch.h"
#include "CLservices.h"

NS_Comp_Svc::CLservices::CLservices(void)
{
	this->oCad = gcnew NS_Comp_Data::CLcad();
	this->oMappTB = gcnew NS_Comp_Mappage::CLmapTB();
}
System::Data::DataSet^ NS_Comp_Svc::CLservices::selectionnerToutesLesPersonnes(System::String^ dataTableName)
{
	System::String^ sql;

	sql = this->oMappTB->Select();
	return this->oCad->getRows(sql, dataTableName);
}
void NS_Comp_Svc::CLservices::ajouterUnePersonne(System::String^ nom, System::String^ prenom, System::String^ ville, System::String^ adresse, int CP)
{
	System::String^ sql;

	this->oMappTB->setNom(nom);
	this->oMappTB->setPrenom(prenom);
	this->oMappTB->setville(ville);
	this->oMappTB->setadresse(adresse);
	this->oMappTB->setcp(CP);

	sql = this->oMappTB->Insert();

	this->oCad->actionRows(sql);
}


void NS_Comp_Svc::CLservices::deleteuneperssonne(int id) {
	System::String^ sql;
	sql = this->oMappTB->Delete(id);
	this->oCad->actionRows(sql);
}