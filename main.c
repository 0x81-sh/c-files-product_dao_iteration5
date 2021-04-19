#include "product.h"
#include "product_csv.h"

int main() {
    Product products[2] = {
            Product_create(1, "test name", 40.5),
            Product_create(2, "test name 2", 81)
    };
    ProductCSV csv = ProductCSV_create("test.csv", ',');

    ProductCSV_writeAll(csv, products, 2);

    ProductCSV_delete(csv);
    Product_deleteMultiple(products, 2, false);
    return 0;
}