#include <string>
using namespace std;

#ifndef URUN_H
#define URUN_H

/**
 * @brief Ürün bilgilerini saklamak için kullanılan sınıf
 *
 */
class Urun
{
public:
    // Ürün adı
    string urun_adi;
    // Ürünün fiyatı
    double urun_fiyati;
    /**
     * @brief Varsayılan Urun yapıcı metot(default constructor)
     *
     */
    Urun() {}
    /**
     * @brief Urun yapıcı metot(constructor)
     *
     * @param urun_adi Ürün adı
     * @param urun_fiyati Ürün fiyatı
     */
    Urun(string urun_adi, double urun_fiyati) {
        this->urun_adi = urun_adi;
        this->urun_fiyati = urun_fiyati;
    }
};

int urun_sayisi = 77;

Urun urunler[] = {
    Urun("Alice Mutton",39.00),
    Urun("Aniseed Syrup",10.00),
    Urun("Boston Crab Meat",18.40),
    Urun("Camembert Pierrot",34.00),
    Urun("Carnarvon Tigers",62.50),
    Urun("Chai",18.00),
    Urun("Chang",19.00),
    Urun("Chartreuse verte",18.00),
    Urun("Chef Anton's Cajun Seasoning",22.00),
    Urun("Chef Anton's Gumbo Mix",21.35),
    Urun("Chocolade",12.75),
    Urun("Côte de Blaye",263.50),
    Urun("Escargots de Bourgogne",13.25),
    Urun("Filo Mix",7.00),
    Urun("Fløtemysost",21.50),
    Urun("Geitost",2.50),
    Urun("Genen Shouyu",15.50),
    Urun("Gnocchi di nonna Alice",38.00),
    Urun("Gorgonzola Telino",12.50),
    Urun("Grandma's Boysenberry Spread",25.00),
    Urun("Gravad lax",26.00),
    Urun("Guaraná Fantástica",4.50),
    Urun("Gudbrandsdalsost",36.00),
    Urun("Gula Malacca",19.45),
    Urun("Gumbär Gummibärchen",31.23),
    Urun("Gustaf's Knäckebröd",21.00),
    Urun("Ikura",31.00),
    Urun("Inlagd Sill",19.00),
    Urun("Ipoh Coffee",46.00),
    Urun("Jack's New England Clam Chowder",9.65),
    Urun("Konbu",6.00),
    Urun("Lakkalikööri",18.00),
    Urun("Laughing Lumberjack Lager",14.00),
    Urun("Longlife Tofu",10.00),
    Urun("Louisiana Fiery Hot Pepper Sauce",21.05),
    Urun("Louisiana Hot Spiced Okra",17.00),
    Urun("Manjimup Dried Apples",53.00),
    Urun("Mascarpone Fabioli",32.00),
    Urun("Maxilaku",20.00),
    Urun("Mishi Kobe Niku",97.00),
    Urun("Mozzarella di Giovanni",34.80),
    Urun("Nord-Ost Matjeshering",25.89),
    Urun("Northwoods Cranberry Sauce",40.00),
    Urun("NuNuCa Nuß-Nougat-Creme",14.00),
    Urun("Original Frankfurter grüne Soße",13.00),
    Urun("Outback Lager",15.00),
    Urun("Pâté chinois",24.00),
    Urun("Pavlova",17.45),
    Urun("Perth Pasties",32.80),
    Urun("Queso Cabrales",21.00),
    Urun("Queso Manchego La Pastora",38.00),
    Urun("Raclette Courdavault",55.00),
    Urun("Ravioli Angelo",19.50),
    Urun("Rhönbräu Klosterbier",7.75),
    Urun("Röd Kaviar",15.00),
    Urun("Rössle Sauerkraut",45.60),
    Urun("Røgede sild",9.50),
    Urun("Sasquatch Ale",14.00),
    Urun("Schoggi Schokolade",43.90),
    Urun("Scottish Longbreads",12.50),
    Urun("Singaporean Hokkien Fried Mee",14.00),
    Urun("Sir Rodney's Marmalade",81.00),
    Urun("Sir Rodney's Scones",10.00),
    Urun("Sirop d'érable",28.50),
    Urun("Spegesild",12.00),
    Urun("Steeleye Stout",18.00),
    Urun("Tarte au sucre",49.30),
    Urun("Teatime Chocolate Biscuits",9.20),
    Urun("Thüringer Rostbratwurst",123.79),
    Urun("Tofu",23.25),
    Urun("Tourtière",7.45),
    Urun("Tunnbröd",9.00),
    Urun("Uncle Bob's Organic Dried Pears",30.00),
    Urun("Valkoinen sUnited Kingdomlaa",16.25),
    Urun("Vegie-spread",43.90),
    Urun("Wimmers gute Semmelknödel",33.25),
    Urun("Zaanse koeken",9.50)
};
#endif
