#encoding "utf-8"

LocDescr -> AnyWord<kwtype="loc_descr">; // словарь дескрипторов (страна, город, ...)
Direction -> AnyWord<kwtype="geo_direction">; // словарь прилагательных, указывающих направление (стороны света)
Country -> AnyWord<kwtype="country">; // словарь стран по Wikidata
Country -> AnyWord<kwtype="country_short_name">; // словарь стран по Wikidata
City -> AnyWord<kwtype="city">; // словарь городов по Wikidata
AstronomicalObj -> AnyWord<kwtype="astronomical_object">; // список объектов в Солнечной системе
OtherLoc -> AnyWord<kwtype="other_location">;

Loc -> LocDescr<gram="sg"> interp(Object.Descr) Word<h-reg1> interp(Object.Name; Object.Type="LOC");
Loc_nointerp -> Adj<gnc-agr[1]> LocDescr<gnc-agr[1], gram="sg", rt> interp(Object.Descr);
Loc_nointerp -> Direction<gnc-agr[1]> Word<gram="S", rt, gnc-agr[1]>;
Loc_nointerp -> Country; // <gram="sg">;
Loc_nointerp -> City;
Loc_nointerp -> AstronomicalObj;
Loc_nointerp -> OtherLoc;

Root -> Loc;
Root -> Loc_nointerp interp(Object.Name; Object.Type="LOC");
