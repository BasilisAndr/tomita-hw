#encoding "utf-8"

OrgDescr -> Word<kwtype="org_descr">;
OrgDescr -> Adj<gnc-agr[1]>+  OrgDescr<gnc-agr[1]>;

QuotedW -> Word<quoted, h-reg1>;
QuotedW -> Word<h-reg1, l-quoted> Word<~r-quoted>* AnyWord<r-quoted>;

//Org -> Word<wff=/[А-ЯA-Z]{2,10}/, kwtype=~"country_short_name"> interp(Object.Name; Object.Type="ORG");
OrgName -> UnknownPOS<wff=/[а-яА-Я]+/>;
OrgName -> Word<h-reg1, GU=["gen"]> Word<GU=["gen"]>*;
OrgName -> Word<h-reg1, GU=["nom"]>;
OrgName -> Word<h-reg1, lat>+;
OrgName -> QuotedW;
OrgName -> 'по' Word<gram="dat">+;

Org -> AnyWord<wff=/.*\.((ru)|(ру)|(com)|(org))/> interp(Object.Name; Object.Type="ORG");


// change
//Org -> (Adj<h-reg1, gnc-agr[1]> interp(Object.Name; Object.Type="ORG")) OrgDescr<gnc-agr[1]> interp(Object.Descr) (OrgName interp(Object.Name; Object.Type="ORG"));

//Org -> Adj<h-reg1, gnc-agr[1]>+ OrgDescr<gnc-agr[1]> interp(Object.Descr) OrgName interp(Object.Name; Object.Type="ORG");
Org -> Word<kwtype="organisation"> interp(Object.Name; Object.Type="ORG");
Org -> Adj<h-reg1, gnc-agr[1]>+ interp(Object.Name; Object.Type="ORG") OrgDescr<gnc-agr[1]> interp(Object.Descr);
Org -> OrgDescr interp(Object.Descr) OrgName interp(Object.Name; Object.Type="ORG");


//Org -> OrgDescr interp(Object.Descr) UnknownPOS<wff=/[а-яА-Я]+/> interp(Object.Name; Object.Type="ORG");
//Org -> OrgDescr interp(Object.Descr) AnyWord<h-reg1, GU=["gen"]|["nom"]> interp(Object.Name; Object.Type="ORG");
//Org -> OrgDescr interp(Object.Descr) AnyWord<h-reg1, lat>+ interp(Object.Name; Object.Type="ORG");
//Org -> OrgDescr interp(Object.Descr) QuotedW interp(Object.Name; Object.Type="ORG");
//Org -> Adj<h-reg1, gnc-agr[1]> interp(Object.Name; Object.Type="ORG") OrgDescr<gnc-agr[1]> interp(Object.Descr);
