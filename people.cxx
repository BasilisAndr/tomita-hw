#encoding "utf-8"

PersonName -> Word<kwtype="имя">;

Person -> PersonName interp (Person.Name);

AnimateWord -> Word<GU=~[inan]>;
FirstName -> AnimateWord<gram="имя", h-reg1, ~fw>;

Person -> FirstName interp (Person.Name);
